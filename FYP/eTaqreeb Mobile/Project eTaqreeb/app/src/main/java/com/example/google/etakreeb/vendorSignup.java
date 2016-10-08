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
import java.util.concurrent.atomic.AtomicInteger;

public class vendorSignup extends AppCompatActivity {

    EditText e1, e2, e3, e4, e5, e6, e7, e8;
    Button b;
    String s1, s2, s3, s4, s5, s6, s7, s8;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_vendor_signup);
        e1 = (EditText) findViewById(R.id.t1);
        e2 = (EditText) findViewById(R.id.t2);
        e3 = (EditText) findViewById(R.id.t3);
        e4 = (EditText) findViewById(R.id.t4);
        e5 = (EditText) findViewById(R.id.t5);
        e6 = (EditText) findViewById(R.id.t6);
        e7 = (EditText) findViewById(R.id.t7);
        e8 = (EditText) findViewById(R.id.t8);


    }

    public void onClick(View v) {

            s1 = e1.getText().toString();
            s2 = e2.getText().toString();
            s3 = e3.getText().toString();
            s4 = e4.getText().toString();
            s5 = e5.getText().toString();
            s6 = e6.getText().toString();
            s7 = e7.getText().toString();
            s8 = e8.getText().toString();
            if (s1.isEmpty() == true) {
                e1.setBackgroundColor(Color.WHITE);
                e1.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Name Field is Empty",
                        Toast.LENGTH_LONG).show();
            } else if (s2.isEmpty() == true) {
                e1.setBackgroundColor(Color.WHITE);
                e2.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Company Name Field is Empty",
                        Toast.LENGTH_LONG).show();
            } else if (s3.isEmpty() == true) {
                e1.setBackgroundColor(Color.WHITE);
                e3.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Address Field is Empty",
                        Toast.LENGTH_LONG).show();
            } else if (s4.isEmpty() == true) {
                e1.setBackgroundColor(Color.WHITE);
                e4.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Landline Number Field is Empty",
                        Toast.LENGTH_LONG).show();
            } else if (s5.isEmpty() == true) {
                e1.setBackgroundColor(Color.WHITE);
                e5.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Mobile Number Field is Empty",
                        Toast.LENGTH_LONG).show();
            } else if (s6.isEmpty() == true) {
                e1.setBackgroundColor(Color.WHITE);
                e6.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Email Field is Empty",
                        Toast.LENGTH_LONG).show();
            }
            else if (!s6.endsWith(".com"))
            {
                e4.setBackgroundColor(Color.WHITE);
                e4.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Email Should contain @server.com",
                        Toast.LENGTH_LONG).show();


            }else if (s7.isEmpty() == true) {
                e1.setBackgroundColor(Color.WHITE);
                e7.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "User Name Field is Empty",
                        Toast.LENGTH_LONG).show();
            } else if (s8.isEmpty() == true) {
                e1.setBackgroundColor(Color.WHITE);
                e8.setAnimation(startBlicking());
                Toast.makeText(this.getApplicationContext(), "Password Field is Empty",
                        Toast.LENGTH_LONG).show();
            } else
            {
                vendorVariables manage = new vendorVariables();
                manage.setvName(e1.getText().toString());
                manage.setcName(e2.getText().toString());
                manage.setcAddress(e3.getText().toString());
                manage.setLandline(e4.getText().toString());
                manage.setMobileNum(e5.getText().toString());
                manage.setEmaill(e6.getText().toString());
                manage.setUserr(e7.getText().toString());
                manage.setPas(e8.getText().toString());

                //  System.out.println("Event is:  " + manage.getEvent() + "Dateeeee is:  " + manage.getDat() + "Budget is:  " + manage.getTBudget());

                Backendless.Persistence.save(manage, new AsyncCallback<vendorVariables>() {

                    public void handleResponse(vendorVariables response) {
                        System.out.println("Done is : df" + response);

                    }

                    public void handleFault(BackendlessFault fault) {
                        System.out.println("fault is: fd" + fault);

                        // an error has occurred, the error code can be retrieved with fault.getCode()
                    }
                });
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

                                if (user.getUserr().equals(s7)) {
                                    flg = false;
                                    Intent intent = new Intent(getApplicationContext(), vendorServices.class);
                                    intent.putExtra("id", user.getObjectId());
                                    intent.putExtra("name", user.getcName());
                                    startActivity(intent);
                                }
                            }

                        }
                        if(userIterator.hasNext() == false && flg == true)
                        {
                            AlertDialog.Builder builder = new AlertDialog.Builder(getApplicationContext());
                            builder.setMessage("User Name or Password is Incorrect");
                            // Add the buttons
                            builder.setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog, int id) {
                                    // User clicked OK button


                                }
                            });
                            builder.show();

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

                AlertDialog.Builder builder = new AlertDialog.Builder(this);
                builder.setMessage("Signup Successful");
// Add the buttons
                builder.setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        // User clicked OK button
                        // save object asynchronously

                        Backendless.Data.of( vendorVariables.class ).find( callback );
                    }
                });
                builder.show();
            }



            }



    private Animation startBlicking() {
        Animation fadeIn = new AlphaAnimation(1, 0);
        fadeIn.setInterpolator(new DecelerateInterpolator()); //add this
        fadeIn.setDuration(1000);
        fadeIn.setRepeatCount(-1);

        return fadeIn;
    }

}