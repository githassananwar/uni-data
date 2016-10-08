package com.example.google.etakreeb;

import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.animation.DecelerateInterpolator;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.backendless.Backendless;
import com.backendless.BackendlessCollection;
import com.backendless.async.callback.AsyncCallback;
import com.backendless.exceptions.BackendlessFault;

import java.util.Iterator;

public class Update_Vendor extends AppCompatActivity {

    EditText e1,e2,e3,e4,e5,e6,e7,e8;
    Button b;
    String s1,s2,s3,s4,s5,s6,s7,s8;
    String uName;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_update__vendor);
        b = (Button)findViewById(R.id.updateVendor);
        e1 = (EditText)findViewById(R.id.e11);
        e2 = (EditText)findViewById(R.id.e22);
        e3 = (EditText)findViewById(R.id.e33);
        e4 = (EditText)findViewById(R.id.e44);
        e5 = (EditText)findViewById(R.id.e55);
        e6 = (EditText)findViewById(R.id.e66);
        e7 = (EditText)findViewById(R.id.e77);
        e8 = (EditText)findViewById(R.id.e88);
        Intent intent = getIntent();
         uName = intent.getStringExtra("id");
        //Toast.makeText(this, uName, Toast.LENGTH_LONG).show();
    }
    public void onClick(View v)
    {

            s1 = e1.getText().toString();
            s2 = e2.getText().toString();
            s3 = e3.getText().toString();
            s4 = e4.getText().toString();
            s5 = e5.getText().toString();
            s6 = e6.getText().toString();
            s7 = e7.getText().toString();
            s8 = e8.getText().toString();
            if(s1.isEmpty() == true)
            {
                e1.setBackgroundColor(Color.WHITE);
                e1.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Name Field is Empty",
                        Toast.LENGTH_LONG).show();
            }
            else if(s2.isEmpty() == true)
            {
                e2.setBackgroundColor(Color.WHITE);
                e2.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Company Name Field is Empty",
                        Toast.LENGTH_LONG).show();
            }
            else if(s3.isEmpty() == true)
            {
                e3.setBackgroundColor(Color.WHITE);
                e3.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Address Field is Empty",
                        Toast.LENGTH_LONG).show();
            }
            else if(s4.isEmpty() == true)
            {
                e4.setBackgroundColor(Color.WHITE);
                e4.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Landline Number is Empty",
                        Toast.LENGTH_LONG).show();
            }
            else if(s5.isEmpty() == true)
            {
                e5.setBackgroundColor(Color.WHITE);
                e5.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Mobile Number is Empty",
                        Toast.LENGTH_LONG).show();
            }
            else if(s6.isEmpty() == true)
            {
                e6.setBackgroundColor(Color.WHITE);
                e6.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Email Field is Empty",
                        Toast.LENGTH_LONG).show();
            }
            else if(s7.isEmpty() == true)
            {
                e7.setBackgroundColor(Color.WHITE);
                e7.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "User Name Field is Empty",
                        Toast.LENGTH_LONG).show();
            }
           else if(s8.isEmpty() == true)
            {
                e8.setBackgroundColor(Color.WHITE);
                e8.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Password Number Field is Empty",
                        Toast.LENGTH_LONG).show();
            }
            else{
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

                                if (user.getObjectId().equals(uName)) {
                                    Toast.makeText(getApplicationContext(), "Ok",
                                            Toast.LENGTH_LONG).show();
                                    vendorVariables manage = user;
                                    manage.setvName(e1.getText().toString());
                                    manage.setcName(e2.getText().toString());
                                    manage.setcAddress(e3.getText().toString());
                                    manage.setLandline(e4.getText().toString());
                                    manage.setMobileNum(e5.getText().toString());
                                    manage.setEmaill(e6.getText().toString());
                                    manage.setUserr(e7.getText().toString());
                                    manage.setPas(e8.getText().toString());

                                    Backendless.Persistence.save(manage, new AsyncCallback<vendorVariables>() {

                                        public void handleResponse(vendorVariables response) {
                                            System.out.println("Done is : df" + response);

                                        }

                                        public void handleFault(BackendlessFault fault) {
                                            System.out.println("fault is: fd" + fault);

                                            // an error has occurred, the error code can be retrieved with fault.getCode()
                                        }
                                    });

                                }
                                Intent i = new Intent(getApplicationContext(), vendorMain.class);
                                i.putExtra("id", uName);
                                startActivity(i);
                            }

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
    }

    @Override
    protected void onResume() {
        super.onResume();
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
                        if (user.getObjectId().equals(uName)) {
                            flg = false;
                            e1.setText(user.getvName());
                            e2.setText(user.getcName());
                            e3.setText(user.getcAddress());
                            e4.setText(user.getLandline());
                            e5.setText(user.getMobileNum());
                            e6.setText(user.getEmaill());
                            e7.setText(user.getUserr());
                            e8.setText(user.getPas());


                        }


                    }

                }
                if(userIterator.hasNext() == false && flg == true)
                {
                    Toast.makeText(getApplicationContext(), "Could not Find any Vendor", Toast.LENGTH_LONG).show();

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

    private Animation startBlicking(){
        Animation fadeIn = new AlphaAnimation(1, 0);
        fadeIn.setInterpolator(new DecelerateInterpolator()); //add this
        fadeIn.setDuration(1000);
        fadeIn.setRepeatCount(-1);

        return fadeIn;
    }

}
