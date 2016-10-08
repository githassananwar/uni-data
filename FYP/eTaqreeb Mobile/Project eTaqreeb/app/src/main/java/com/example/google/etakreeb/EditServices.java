package com.example.google.etakreeb;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.backendless.Backendless;
import com.backendless.BackendlessCollection;
import com.backendless.async.callback.AsyncCallback;
import com.backendless.exceptions.BackendlessFault;

import java.util.Iterator;

public class EditServices extends AppCompatActivity {
    EditText ed1, ed2,ed3;
    Button b;
    String s1, s2, s3, uName, sObject, cName;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_services);
        ed1 = (EditText)findViewById(R.id.ettt1);
        ed2 = (EditText)findViewById(R.id.ettt2);
        ed3 = (EditText)findViewById(R.id.ettt3);
        b = (Button)findViewById(R.id.submit1);
        Intent intent = getIntent();
        uName = intent.getStringExtra("id");
        cName = intent.getStringExtra("name");

    }
    public void onClick(View v)
    {final AsyncCallback<BackendlessCollection<services>> callback=new AsyncCallback<BackendlessCollection<services>>()
    {

        private boolean firstResponse=true;
        boolean flg = true;

        public void handleResponse( BackendlessCollection<services> criteria )
        {
            System.out.println( "Total  in response - " + criteria.getTotalObjects() );

            if( firstResponse )
            {
                System.out.println( "Total in first response- " + criteria.getTotalObjects() );
                firstResponse = true;
            }

            int size = criteria.getCurrentPage().size();
            Iterator<services> userIterator = criteria.getCurrentPage().iterator();



            if(flg == true)
            {
                while (userIterator.hasNext()) {
                    services user = userIterator.next();
                    if (user.getObjectId().equals(sObject) ) {
                        flg = false;

                        services manage = user;
                        manage.setNam(ed1.getText().toString());
                        manage.setPric(ed2.getText().toString());
                        manage.setTyp(ed3.getText().toString());
                        manage.setvObjectId(uName);


                        Backendless.Persistence.save(manage, new AsyncCallback<services>() {

                            public void handleResponse(services response) {
                                System.out.println("Done is : df" + response);


                            }

                            public void handleFault(BackendlessFault fault) {
                                System.out.println("fault is: fd" + fault);
                                // Toast.makeText(getApplicationContext(), "Hisham Zahid", Toast.LENGTH_LONG).show();
                                // an error has occurred, the error code can be retrieved with fault.getCode()
                            }
                        });
                        Intent i = new Intent(getApplicationContext(), vendorMain.class);
                        i.putExtra("id", uName);
                        i.putExtra("name", cName);

                        // Toast.makeText(getApplicationContext(),uName, Toast.LENGTH_LONG).show();
                           startActivity(i);
                    }


                }

            }
            if(userIterator.hasNext() == false && flg == true)
            {
                Toast.makeText(getApplicationContext(), "List Finished", Toast.LENGTH_LONG).show();

            }
            if( size > 0 ) {
                criteria.nextPage(this);
            }
        }

        @Override
        public void handleFault( BackendlessFault backendlessFault )
        {

        }
    };
        Backendless.Data.of( services.class ).find( callback );



    }

    @Override
    protected void onResume() {
        super.onResume();
        final AsyncCallback<BackendlessCollection<services>> callback=new AsyncCallback<BackendlessCollection<services>>()
        {

            private boolean firstResponse=true;
            boolean flg = true;

            public void handleResponse( BackendlessCollection<services> criteria )
            {
                System.out.println( "Total  in response - " + criteria.getTotalObjects() );

                if( firstResponse )
                {
                    System.out.println( "Total in first response- " + criteria.getTotalObjects() );
                    firstResponse = true;
                }

                int size = criteria.getCurrentPage().size();
                Iterator<services> userIterator = criteria.getCurrentPage().iterator();



                if(flg == true)
                {
                    while (userIterator.hasNext()) {
                        services user = userIterator.next();
                        if (user.getvObjectId().equals(uName) ) {
                            flg = false;
                            ed1.setText(user.getNam());
                            ed2.setText(user.getPric());
                            ed3.setText(user.getTyp());
                            sObject = user.getObjectId();
                        }
                    }
                }
                if(userIterator.hasNext() == false && flg == true)
                {
                    Toast.makeText(getApplicationContext(), "List Finished", Toast.LENGTH_LONG).show();
                }
                if( size > 0 ) {
                    criteria.nextPage(this);
                }
            }
            @Override
            public void handleFault( BackendlessFault backendlessFault )
            {

            }
        };
        Backendless.Data.of( services.class ).find( callback );
    }
}
