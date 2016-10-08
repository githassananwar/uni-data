package com.example.google.etakreeb;

import android.app.Dialog;
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
import android.view.animation.AnimationUtils;
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

public class signup extends AppCompatActivity {

    Button b;
    EditText e1,e2,e3,e4,e5;
    String s1, s2, s3, s4, s5;
    String YOUR_APP_ID = "A9F16720-F3AC-43F0-FFC4-99CDEAECBF00";
    String YOUR_SECRET_KEY = "2C18F8A2-DD4F-CC4C-FF1D-B562D5D9BC00";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_signup);
        b = (Button) findViewById(R.id.signUpCustomer);
        e1 = (EditText)findViewById(R.id.et11);
        e2 = (EditText)findViewById(R.id.et22);
        e3 = (EditText)findViewById(R.id.et33);
        e4 = (EditText)findViewById(R.id.et44);
        e5 = (EditText)findViewById(R.id.et55);
        String appVersion = "v1";
        Backendless.initApp(this, YOUR_APP_ID, YOUR_SECRET_KEY, appVersion);


    }

   public void onClick(View v) {

       s1 = e1.getText().toString();
       s2 = e2.getText().toString();
       s3 = e3.getText().toString();
       s4 = e4.getText().toString();
       s5 = e5.getText().toString();
       if (s1.isEmpty() == true) {
           e1.setBackgroundColor(Color.WHITE);
           e1.setAnimation(startBlicking());
           Toast.makeText(this.getApplicationContext(), "Name Field is Empty",
                   Toast.LENGTH_LONG).show();
       } else if (s2.isEmpty() == true) {
           e2.setBackgroundColor(Color.WHITE);
           e2.setAnimation(startBlicking());
           Toast.makeText(this.getApplicationContext(), "User Name Field is Empty",
                   Toast.LENGTH_LONG).show();
       } else if (s3.isEmpty() == true) {
           e3.setBackgroundColor(Color.WHITE);
           e3.setAnimation(startBlicking());
           Toast.makeText(this.getApplicationContext(), "Password Field is Empty",
                   Toast.LENGTH_LONG).show();
       } else if (s4.isEmpty() == true) {
           e4.setBackgroundColor(Color.WHITE);
           e4.setAnimation(startBlicking());
           Toast.makeText(this.getApplicationContext(), "Email Field is Empty",
                   Toast.LENGTH_LONG).show();
       }
       else if (!s4.endsWith(".com"))
       {
           e4.setBackgroundColor(Color.WHITE);
           e4.setAnimation(startBlicking());
           Toast.makeText(this.getApplicationContext(), "Email Should contain @server.com",
                   Toast.LENGTH_LONG).show();


       }
       else if (s5.isEmpty() == true) {
           e5.setBackgroundColor(Color.WHITE);
           e5.setAnimation(startBlicking());
           Toast.makeText(this.getApplicationContext(), "Contact Field is Empty",
                   Toast.LENGTH_LONG).show();
       }
       else
       {
           //  System.out.println("Event is:  " + manage.getEvent() + "Dateeeee is:  " + manage.getDat() + "Budget is:  " + manage.getTBudget());

           customerVariables manage = new customerVariables();
           manage.setNam(e1.getText().toString());
           manage.setUserr(e2.getText().toString());
           manage.setPas(e3.getText().toString());
           manage.setMaill(e4.getText().toString());
           manage.setCont(e5.getText().toString());

           Backendless.Persistence.save(manage, new AsyncCallback<customerVariables>() {

               public void handleResponse(customerVariables response) {
                   System.out.println("Done is : df" + response);


               }

               public void handleFault(BackendlessFault fault) {
                   System.out.println("fault is: fd" + fault);
                   // Toast.makeText(getApplicationContext(), "Hisham Zahid", Toast.LENGTH_LONG).show();
                   // an error has occurred, the error code can be retrieved with fault.getCode()
               }
           });
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
                           if (user.getUserr().equals(s2)) {
                               flg = false;
                               Intent intent = new Intent(getApplicationContext(), customerMain.class);
                               intent.putExtra("id", user.getObjectId());
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

                   Backendless.Data.of( customerVariables.class ).find( callback );

               }
           });
           builder.show();
       }

   }
    private Animation startBlicking(){
        Animation fadeIn = new AlphaAnimation(1, 0);
        fadeIn.setInterpolator(new DecelerateInterpolator()); //add this
        fadeIn.setDuration(1000);
        fadeIn.setRepeatCount(-1);
        return fadeIn;
    }
}
