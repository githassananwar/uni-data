package com.example.google.etakreeb;

import android.content.DialogInterface;
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
import android.widget.EditText;
import android.widget.Toast;

import com.backendless.Backendless;
import com.backendless.async.callback.AsyncCallback;
import com.backendless.exceptions.BackendlessFault;

public class Update extends AppCompatActivity {

    EditText ed1,ed2,ed3,ed4,ed5;
    String s1,s2,s3,s4,s5;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_update);
        ed1 = (EditText)findViewById(R.id.et1);
        ed2 = (EditText)findViewById(R.id.et2);
        ed3 = (EditText)findViewById(R.id.et3);
        ed4 = (EditText)findViewById(R.id.et4);
        ed5 = (EditText)findViewById(R.id.et5);


    }
    public void onClick(View v)
    {
        s1 = ed1.getText().toString();
        s2 = ed2.getText().toString();
        s3 = ed3.getText().toString();
        s4 = ed4.getText().toString();
        s5 = ed5.getText().toString();



        if (s1.isEmpty() == true) {
            ed1.setBackgroundColor(Color.WHITE);
            ed1.setAnimation(startBlicking());
            Toast.makeText(this.getApplicationContext(), "Name Field is Empty",
                    Toast.LENGTH_LONG).show();
        } else if (s2.isEmpty() == true) {
            ed2.setBackgroundColor(Color.WHITE);
            ed2.setAnimation(startBlicking());
            Toast.makeText(this.getApplicationContext(), "User Name Field is Empty",
                    Toast.LENGTH_LONG).show();
        } else if (s4.isEmpty() == true) {
            ed3.setBackgroundColor(Color.WHITE);
            ed3.setAnimation(startBlicking());
            Toast.makeText(this.getApplicationContext(), "Password Field is Empty",
                    Toast.LENGTH_LONG).show();
        } else if (s3.isEmpty() == true) {
            ed4.setBackgroundColor(Color.WHITE);
            ed4.setAnimation(startBlicking());
            Toast.makeText(this.getApplicationContext(), "Email Field is Empty",
                    Toast.LENGTH_LONG).show();
        }
        else if (!s3.endsWith(".com"))
        {
            ed4.setBackgroundColor(Color.WHITE);
            ed4.setAnimation(startBlicking());
            Toast.makeText(this.getApplicationContext(), "Email Should contain @server.com",
                    Toast.LENGTH_LONG).show();


        }
        else if (s5.isEmpty() == true) {
            ed5.setBackgroundColor(Color.WHITE);
            ed5.setAnimation(startBlicking());
            Toast.makeText(this.getApplicationContext(), "Contact Field is Empty",
                    Toast.LENGTH_LONG).show();
        }customerVariables manage = new customerVariables();
        manage.setNam(ed1.getText().toString());
        manage.setUserr(ed2.getText().toString());
        manage.setMaill(ed3.getText().toString());
        manage.setPas(ed4.getText().toString());
        manage.setCont(ed5.getText().toString());

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
    }
    private Animation startBlicking(){
        Animation fadeIn = new AlphaAnimation(1, 0);
        fadeIn.setInterpolator(new DecelerateInterpolator()); //add this
        fadeIn.setDuration(1000);
        fadeIn.setRepeatCount(-1);
        return fadeIn;
    }
}
