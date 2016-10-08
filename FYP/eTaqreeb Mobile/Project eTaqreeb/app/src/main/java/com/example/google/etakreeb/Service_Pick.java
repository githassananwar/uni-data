package com.example.google.etakreeb;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import com.backendless.Backendless;
import com.backendless.BackendlessCollection;
import com.backendless.async.callback.AsyncCallback;
import com.backendless.exceptions.BackendlessFault;

import java.util.Iterator;

public class Service_Pick extends AppCompatActivity {
    CheckBox cb ;
    Button b;
    TextView t,tv1 ;
    TableLayout tl;
    TableRow tr;
    String vendorId, eventId, serviceId, serviceName, status, eventName;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_service__pick);

        tl = (TableLayout)findViewById(R.id.table2);
        tl.setColumnStretchable(0, true);
        tl.setColumnStretchable(1, true);
        Intent intent = getIntent();
        vendorId = intent.getStringExtra("id");
        eventId = intent.getStringExtra("eid");
        tv1 = (TextView)findViewById(R.id.dTextView1);
        cb = (CheckBox) findViewById(R.id.cb1);
        b = (Button)findViewById(R.id.servicePick);
        eventName = intent.getStringExtra("name");


    }
    public void onClick(View v)
    {

        eventServices manage = new eventServices();
        manage.setvSObjectId(serviceId);
        manage.setEobjectId(eventId);
        manage.setStatus("pending");
        manage.setvObjectId(vendorId);
        manage.setEventName(eventName);
        //  System.out.println("Event is:  " + manage.getEvent() + "Dateeeee is:  " + manage.getDat() + "Budget is:  " + manage.getTBudget());

        Backendless.Persistence.save(manage, new AsyncCallback<eventServices>() {

            public void handleResponse(eventServices response) {
                System.out.println("Done is : df" + response);

            }

            public void handleFault(BackendlessFault fault) {
                System.out.println("fault is: fd" + fault);

                // an error has occurred, the error code can be retrieved with fault.getCode()
            }
        });

        Intent intent = new Intent(getApplicationContext(), CustomerRequest.class);
            intent.putExtra("sname", serviceName);
            intent.putExtra("ename", eventName);
            intent.putExtra("status", status);
            intent.putExtra("id",eventId);

            startActivity(intent);

    }

    @Override
    public void onBackPressed() {
        new android.app.AlertDialog.Builder(this)
                .setTitle("Really Exit?")
                .setMessage("Are you sure you want to exit?")
                .setNegativeButton(android.R.string.no, null)
                .setPositiveButton(android.R.string.yes, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface arg0, int arg1) {
                        Service_Pick.super.onBackPressed();
                        Intent i = new Intent(getApplicationContext(), customerMain.class);
                        i.putExtra("id", vendorId);
                        finish();
                        startActivity(i);
                    }
                }).create().show();
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
                        if (user.getvObjectId().equals(vendorId) ) {
                            flg = false;
                            serviceId = user.getObjectId();
                            serviceName = user.getNam();
                            tr = new TableRow(getApplicationContext());
                            tv1 = new TextView(getApplicationContext());
                            cb = new CheckBox(getApplicationContext());
                            tv1.setText(user.getNam());
                            tv1.setTextSize(15);
                            tv1.setGravity(Gravity.CENTER);
                            cb.setGravity(Gravity.CENTER);
                            cb.setOnClickListener(new View.OnClickListener() {
                                @Override
                                public void onClick(View v) {
                                    final TableRow parent = (TableRow) v.getParent();
                                }
                            });
                            tr.addView(tv1);
                            tr.addView(cb);
                            tl.addView(tr);

                        }


                    }

                }
                if(userIterator.hasNext() == false && flg == true)
                {
                    Toast.makeText(getApplicationContext(), "Did not find any service", Toast.LENGTH_LONG).show();

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
