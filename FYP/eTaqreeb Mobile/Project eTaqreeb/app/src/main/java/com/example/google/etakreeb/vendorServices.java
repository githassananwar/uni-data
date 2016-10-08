package com.example.google.etakreeb;

import android.content.DialogInterface;
import android.content.Intent;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.backendless.Backendless;
import com.backendless.BackendlessCollection;
import com.backendless.async.callback.AsyncCallback;
import com.backendless.exceptions.BackendlessFault;

import java.util.Iterator;

public class vendorServices extends AppCompatActivity {

    String uName, cName, s1, s2,s3;
    EditText e1,e2,e3;
    Button b;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_vendor_services);

        b = (Button)findViewById(R.id.submit);
        e1 =(EditText)findViewById(R.id.ett1);
        e2 =(EditText)findViewById(R.id.ett2);
        e3 =(EditText)findViewById(R.id.ett3);
        b = (Button)findViewById(R.id.submit);

        Intent intent = getIntent();
        uName = intent.getStringExtra("id");
        cName = intent.getStringExtra("name");
    }
    public void onClick(View v) {
        if (b.getId() == R.id.submit) {
            s1 = e1.getText().toString();
            s2 = e2.getText().toString();
            s3 = e3.getText().toString();
            services manage = new services();
            manage.setNam(e1.getText().toString());
            manage.setPric(e2.getText().toString());
            manage.setTyp(e3.getText().toString());
            manage.setvObjectId(uName);
            //  System.out.println("Event is:  " + manage.getEvent() + "Dateeeee is:  " + manage.getDat() + "Budget is:  " + manage.getTBudget());

            Backendless.Persistence.save(manage, new AsyncCallback<services>() {

                public void handleResponse(services response) {
                    System.out.println("Done is : df" + response);

                }

                public void handleFault(BackendlessFault fault) {
                    System.out.println("fault is: fd" + fault);

                    // an error has occurred, the error code can be retrieved with fault.getCode()
                }
            });


            final AsyncCallback<BackendlessCollection<services>> callback = new AsyncCallback<BackendlessCollection<services>>() {

                private boolean firstResponse = true;
                boolean flg = true;

                public void handleResponse(BackendlessCollection<services> criteria) {

                    System.out.println("Total  in response - " + criteria.getTotalObjects());

                    if (firstResponse) {
                        System.out.println("Total in first response- " + criteria.getTotalObjects());
                        firstResponse = true;
                    }

                    int size = criteria.getCurrentPage().size();
                    Iterator<services> userIterator = criteria.getCurrentPage().iterator();


                    if (flg == true) {
                        while (userIterator.hasNext()) {
                            services user = userIterator.next();
                            if (user.getvObjectId().equals(uName)) {
                                flg = false;
                                Intent intent = new Intent(getApplicationContext(), vendorMain.class);
                               intent.putExtra("id", uName);
                               intent.putExtra("name", cName);
                                finish();
                                startActivity(intent);
                            }


                        }

                    }
                    if (userIterator.hasNext() == false && flg == true) {
                        /*AlertDialog.Builder builder = new AlertDialog.Builder(getApplicationContext());
                        builder.setMessage("Service updation error");
                        // Add the buttons
                        builder.setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog, int id) {
                                // User clicked OK button


                            }
                        });
                        builder.show();*/

                    }
                    if (size > 0) {
                        criteria.nextPage(this);
                    }
                }

                @Override
                public void handleFault(BackendlessFault backendlessFault) {

                }
            };
            Backendless.Data.of(services.class).find(callback);
        }
    }
}
