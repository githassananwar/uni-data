package com.example.google.etakreeb;

import android.animation.ArgbEvaluator;
import android.animation.ObjectAnimator;
import android.animation.ValueAnimator;
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
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.Toast;

import com.backendless.Backendless;
import com.backendless.BackendlessCollection;
import com.backendless.async.callback.AsyncCallback;
import com.backendless.exceptions.BackendlessFault;
import com.backendless.persistence.BackendlessDataQuery;
import com.backendless.persistence.QueryOptions;

import java.util.Iterator;
import java.util.concurrent.atomic.AtomicInteger;

public class login extends AppCompatActivity {
    Button b;
    EditText ed, ed2;
    TextView t;
    RadioButton r, r1;
    int id;
    String s1, s2;
 //   static int i = 1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        b = (Button)findViewById(R.id.loginButton);
        t = (TextView)findViewById(R.id.textSignUp);
        r = (RadioButton)findViewById(R.id.cust1);
        r1 = (RadioButton)findViewById(R.id.vend2);
        ed = (EditText)findViewById(R.id.et1);
        ed2 = (EditText)findViewById(R.id.et2);


    }
    public void onClick(View v) {
        if (R.id.textSignUp == v.getId()) {
            Intent i = new Intent(this, dialog.class);
            startActivity(i);
        }
        if ((r.isChecked() == true )&& (R.id.loginButton == v.getId())  )
        {


                s1 = ed.getText().toString();
                s2 = ed2.getText().toString();
                if(s1.isEmpty() == true)
                {

                    ed.setBackgroundColor(Color.WHITE);

                    ed.setAnimation(startBlicking());
                    Toast.makeText(this.getApplicationContext(), "User Name Field is Empty",
                            Toast.LENGTH_LONG).show();
                }
                else if(s2.isEmpty() == true)
                {

                    ed2.setBackgroundColor(Color.WHITE);

                    ed2.setAnimation(startBlicking());
                    Toast.makeText(this.getApplicationContext(), "Password Field is Empty",
                            Toast.LENGTH_LONG).show();
                }
                else {

                    final AsyncCallback<BackendlessCollection<customerVariables>> callback=new AsyncCallback<BackendlessCollection<customerVariables>>()
                    {

                        private boolean firstResponse=true;
                        boolean flg = true;

                        public void handleResponse( BackendlessCollection<customerVariables> criteria )
                        {
                            System.out.println( "Total  in response - " + criteria.getTotalObjects() );

                            if( firstResponse )
                            {
                                System.out.println( "Total in first response- " + criteria.getTotalObjects() );
                                firstResponse = true;
                            }

                            int size = criteria.getCurrentPage().size();
                            Iterator<customerVariables> userIterator = criteria.getCurrentPage().iterator();



                            if(flg == true)
                            {
                                while (userIterator.hasNext()) {
                                    customerVariables user = userIterator.next();
                                   // Toast.makeText(getApplicationContext(), user.getUserr(), Toast.LENGTH_LONG).show();
                                    if (user.getUserr().equals(s1) && user.getPas().equals(s2)) {
                                        flg = false;
                                        Intent intent = new Intent(getApplicationContext(), customerMain.class);
                                        intent.putExtra("id", user.getObjectId());
                                        finish();
                                        startActivity(intent);

                                    }


                                }

                            }
                            if(userIterator.hasNext() == false && flg == true)
                            {
                               // Toast.makeText(getApplicationContext(), "List Finished", Toast.LENGTH_LONG).show();
                                AlertDialog.Builder builder = new AlertDialog.Builder(login.this);
                                builder.setTitle("Login Error ");
                                builder.setMessage("User Name Or Password Incorrect");
// Add the button
                                builder.setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                                    public void onClick(DialogInterface dialog, int id) {
                                    ed.setText(null);
                                        ed2.setText(null);


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
                    Backendless.Data.of( customerVariables.class ).find( callback );
                   // Toast.makeText(getApplicationContext(),"Next Activity", Toast.LENGTH_LONG).show();
                }



        }

            if ((r1.isChecked() == true )&& (R.id.loginButton == v.getId())) {

                s1 = ed.getText().toString();
                s2 = ed2.getText().toString();
                if(s1.isEmpty() == true)
                {

                    ed.setBackgroundColor(Color.WHITE);

                    ed.setAnimation(startBlicking());
                    Toast.makeText(this.getApplicationContext(), "User Name Field is Empty",
                            Toast.LENGTH_LONG).show();
                }
                else if(s2.isEmpty() == true)
                {

                    ed2.setBackgroundColor(Color.WHITE);

                    ed2.setAnimation(startBlicking());
                    Toast.makeText(this.getApplicationContext(), "Password Field is Empty",
                            Toast.LENGTH_LONG).show();
                }
                else {

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
                                    if (user.getUserr().equals(s1) && user.getPas().equals(s2)) {
                                        flg = false;
                                        Intent intent = new Intent(getApplicationContext(), vendorMain.class);
                                        intent.putExtra("id", user.getObjectId());
                                        intent.putExtra("name", user.getcName());
                                        finish();
                                        startActivity(intent);
                                    }


                                }

                            }
                            if(userIterator.hasNext() == false && flg == true)
                            {
                                AlertDialog.Builder builder = new AlertDialog.Builder(login.this);
                                builder.setTitle("Login Error ");
                                builder.setMessage("User Name Or Password Incorrect");
// Add the buttons
                                builder.setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                                    public void onClick(DialogInterface dialog, int id) {

                                        ed.setText(null);
                                        ed2.setText(null);

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
                    Backendless.Data.of( vendorVariables.class ).find( callback );

                }
            }
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
        super.onBackPressed();
        Intent i = new Intent(this, gridview.class);
        finish();
        startActivity(i);

    }
}

