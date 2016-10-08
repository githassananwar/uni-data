package com.example.google.etakreeb;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.backendless.Backendless;
import com.backendless.BackendlessCollection;
import com.backendless.async.callback.AsyncCallback;
import com.backendless.exceptions.BackendlessFault;

import java.util.Iterator;

public class Select_Vendor extends AppCompatActivity {

    EditText ed;
    String uName, eName,s;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_select__vendor);
        Intent intent = getIntent();
        uName = intent.getStringExtra("id");
        eName = intent.getStringExtra("name");
        ed = (EditText)findViewById(R.id.getVendor);

    }
    public void onClick(View v)
    {
        s = ed.getText().toString();

        final AsyncCallback<BackendlessCollection<vendorVariables>> callback=new AsyncCallback<BackendlessCollection<vendorVariables>>()
        {

            private boolean firstResponse=true;
            boolean flg = true;

            public void handleResponse( BackendlessCollection<vendorVariables> criteria )
            {
                System.out.println( "Total  in response - " + criteria.getTotalObjects() );

                if( firstResponse )
                {
                    System.out.println( "Total in first response- " + criteria.getTotalObjects() );
                    firstResponse = true;
                }

                int size = criteria.getCurrentPage().size();
                Iterator<vendorVariables> userIterator = criteria.getCurrentPage().iterator();



                if(flg == true)
                {
                    while (userIterator.hasNext()) {
                        vendorVariables user = userIterator.next();
                       // Toast.makeText(getBaseContext(),user.getcName().toString(),Toast.LENGTH_LONG).show();
                        if (user.getcName().equals(s) ) {
                            flg = false;
                            Intent intent = new Intent(getApplicationContext(), Service_Pick.class);
                            intent.putExtra("id", user.getObjectId());
                            intent.putExtra("eid", uName);
                            intent.putExtra("name", eName);

                            startActivity(intent);
                        }


                    }

                }
                if(userIterator.hasNext() == false && flg == true)
                {
                    Toast.makeText(getApplicationContext(), "Did not Find any Vendor", Toast.LENGTH_LONG).show();

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
        Backendless.Data.of( vendorVariables.class ).find( callback );

    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
        new android.app.AlertDialog.Builder(this)
                .setTitle("Really Exit?")
                .setMessage("Are you sure you want to exit?")
                .setNegativeButton(android.R.string.no, null)
                .setPositiveButton(android.R.string.yes, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface arg0, int arg1) {
                        Select_Vendor.super.onBackPressed();
                        Intent i = new Intent(getApplicationContext(), customerMain.class);
                        i.putExtra("id", uName);
                        finish();
                        startActivity(i);
                    }
                }).create().show();
    }
}
