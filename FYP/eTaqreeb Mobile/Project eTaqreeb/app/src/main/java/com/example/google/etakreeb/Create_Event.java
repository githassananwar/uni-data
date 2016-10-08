package com.example.google.etakreeb;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.location.Criteria;
import android.os.Bundle;
import android.view.View;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import com.backendless.Backendless;
import android.view.animation.DecelerateInterpolator;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import com.backendless.BackendlessCollection;
import com.backendless.async.callback.AsyncCallback;
import com.backendless.exceptions.BackendlessFault;
import com.backendless.persistence.BackendlessDataQuery;
import com.backendless.persistence.QueryOptions;

import java.util.Iterator;
import java.util.concurrent.CountDownLatch;


public class Create_Event extends Activity implements View.OnClickListener {


    String eventName, totalBudget, d;
    Spinner sp1, sp2;
    String s1,s2,s3,s4,s5,uName;
    EditText edt ;

    EditText edt2;
    String YOUR_APP_ID = "A9F16720-F3AC-43F0-FFC4-99CDEAECBF00";
    String YOUR_SECRET_KEY = "2C18F8A2-DD4F-CC4C-FF1D-B562D5D9BC00";
    EditText edt3, edt4,edt5;

    Button b;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_create__event);
        String appVersion = "v1";
        Backendless.initApp(this, YOUR_APP_ID, YOUR_SECRET_KEY, appVersion);

        edt = (EditText) findViewById(R.id.et1);
        edt2 =(EditText) findViewById(R.id.et2);
        edt3 =(EditText) findViewById(R.id.et3);
        sp1 = (Spinner)findViewById(R.id.spin1);
        sp2 = (Spinner)findViewById(R.id.spin2);


        b = (Button) findViewById(R.id.creatEvent);
        Intent intent = getIntent();
        uName = intent.getStringExtra("id");


        //b.setOnClickListener(this);

    }
    @Override
    public void onClick(View v) {


        eventName = edt.getText().toString();
        d = edt2.getText().toString();
        s4 = sp1.toString();
        s5 = sp2.toString();
        totalBudget = edt3.getText().toString();
       ;
        // save object asynchronously
        createEventVariables manage = new createEventVariables();
        manage.settBudget(edt3.getText().toString());
        manage.setEvent(edt.getText().toString());
        manage.setDat(edt2.getText().toString());
        manage.setTyp(sp2.getSelectedItem().toString());
        manage.setSh(sp1.getSelectedItem().toString());
        manage.setcObjectId(uName);
        //Toast.makeText(this,uName,Toast.LENGTH_LONG).show();

        //  System.out.println("Event is:  " + manage.getEvent() + "Dateeeee is:  " + manage.getDat() + "Budget is:  " + manage.getTBudget());

        Backendless.Persistence.save(manage, new AsyncCallback<createEventVariables>() {

            public void handleResponse(createEventVariables response) {
                System.out.println("Done is : df" + response);

            }

            public void handleFault(BackendlessFault fault) {
                System.out.println("fault is: fd" + fault);

                // an error has occurred, the error code can be retrieved with fault.getCode()

            }
        });
        final AsyncCallback<BackendlessCollection<createEventVariables>> callback=new AsyncCallback<BackendlessCollection<createEventVariables>>()
        {

            private boolean firstResponse=true;
            boolean flg = true;

            public void handleResponse( BackendlessCollection<createEventVariables> criteria )
            {
                System.out.println( "Total  in response - " + criteria.getTotalObjects() );

                if( firstResponse )
                {
                    System.out.println( "Total in first response- " + criteria.getTotalObjects() );
                    firstResponse = true;
                }

                int size = criteria.getCurrentPage().size();
                Iterator<createEventVariables> userIterator = criteria.getCurrentPage().iterator();



                if(flg == true)
                {
                    while (userIterator.hasNext()) {
                        createEventVariables user = userIterator.next();
                       // Toast.makeText(getApplicationContext(), user.getUserr(), Toast.LENGTH_LONG).show();
                        if (user.getcObjectId().equals(uName)) {
                            flg = false;
                            Intent intent = new Intent(getApplicationContext(),Select_Vendor.class);
                            intent.putExtra("id", user.getObjectId());
                            intent.putExtra("name", user.getEvent());
                            startActivity(intent);
                            finish();
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
        android.support.v7.app.AlertDialog.Builder builder = new android.support.v7.app.AlertDialog.Builder(this);
        builder.setMessage("Create Event???");
// Add the buttons
        builder.setPositiveButton("Ok", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int id) {
                // User clicked OK button
                Backendless.Data.of( createEventVariables.class ).find( callback );

            }
        });
        builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int id) {
                // User clicked OK button


            }
        });
        builder.show();

    }




    private Animation startBlicking(){
        Animation fadeIn = new AlphaAnimation(1, 0);
        fadeIn.setInterpolator(new DecelerateInterpolator()); //add this
        fadeIn.setDuration(1000);
        fadeIn.setRepeatCount(-1);

        return fadeIn;
    }
    @Override
    public void onBackPressed() {
        new AlertDialog.Builder(this)
                .setTitle("Really Exit?")
                .setMessage("Are you sure you want to exit?")
                .setNegativeButton(android.R.string.no, null)
                .setPositiveButton(android.R.string.yes, new DialogInterface.OnClickListener() {

                    public void onClick(DialogInterface arg0, int arg1) {
                        Create_Event.super.onBackPressed();
                        Intent i = new Intent(getApplicationContext(), customerMain.class);
                        startActivity(i);
                    }
                }).create().show();
    }
}
