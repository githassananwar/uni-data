package com.example.google.etakreeb;

import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Gravity;
import android.view.View;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import com.backendless.Backendless;
import com.backendless.BackendlessCollection;
import com.backendless.async.callback.AsyncCallback;
import com.backendless.exceptions.BackendlessFault;

import org.w3c.dom.Text;

import java.util.Iterator;

public class CustomerRequest extends AppCompatActivity {

    TableLayout tl;
    TableRow tr;
    TextView t1,t2,t3;
    String eName,sName,status,sId;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_customer_request);
        tl = (TableLayout)findViewById(R.id.table1);
        tl.setColumnStretchable(0, true);
        t1 = (TextView)findViewById(R.id.v1);
        t2 = (TextView)findViewById(R.id.v2);
        t3 = (TextView)findViewById(R.id.v3);
        Intent intent= getIntent();
        eName =  intent.getStringExtra("ename");
        sId =intent.getStringExtra("id");
        sName =intent.getStringExtra("sname");
        status =intent.getStringExtra("status");
        Toast.makeText(this, eName + "    " + sId+ "       "+ sName + "      " , Toast.LENGTH_LONG).show();
    }
    @Override
    protected void onResume() {
        super.onResume();
        final AsyncCallback<BackendlessCollection<eventServices>> callback=new AsyncCallback<BackendlessCollection<eventServices>>()
        {

            private boolean firstResponse=true;
            boolean flg = true;

            public void handleResponse( BackendlessCollection<eventServices> criteria )
            {
                System.out.println( "Total  in response - " + criteria.getTotalObjects() );

                if( firstResponse )
                {
                    System.out.println( "Total in first response- " + criteria.getTotalObjects() );
                    firstResponse = true;
                }

                int size = criteria.getCurrentPage().size();
                Iterator<eventServices> userIterator = criteria.getCurrentPage().iterator();


                if(flg == true)
                {
                    while (userIterator.hasNext()) {
                        eventServices user = userIterator.next();

                        if (user.getEobjectId().equals(sId))
                        {
                            //Toast.makeText(getApplicationContext(),user.getvObjectId(),Toast.LENGTH_LONG).show();
                            flg = false;
                            tr = new TableRow(getApplicationContext());
                            t1 = new TextView(getApplicationContext());
                            t2 = new TextView(getApplicationContext());
                            t3 = new TextView(getApplicationContext());
                            t1.setText(user.getEventName());
                            t1.setTextSize(15);
                            t1.setGravity(Gravity.LEFT);
                            t2.setText(sName);
                            t2.setTextSize(15);
                            t2.setGravity(Gravity.CENTER);
                            t3.setText(user.getStatus());
                            t3.setTextSize(15);
                            t3.setGravity(Gravity.RIGHT);
                            t3.setOnClickListener(new View.OnClickListener() {
                                @Override
                                public void onClick(View v) {
                                    final TableRow parent = (TableRow) v.getParent();
                                  //  tl.removeView(parent);


                                }
                            });
                            tr.addView(t1);
                            tr.addView(t2);
                            tr.addView(t3);

                            tl.addView(tr);


                        }


                    }
                }
                if(userIterator.hasNext() == false && flg == true)
                {
                    Toast.makeText(getApplicationContext(), "Didn't Find Any Service", Toast.LENGTH_LONG).show();

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
        Backendless.Data.of( eventServices.class ).find( callback );
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        Intent i = new Intent(this, gridview.class);

        finish();
        startActivity(i);
    }
}
