package com.example.google.etakreeb;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.RadioButton;

public class dialog extends AppCompatActivity {

    RadioButton r;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dialog);
        r = (RadioButton) findViewById(R.id.ascust);
        r = (RadioButton) findViewById(R.id.asvend);
    }

    public void onClick(View v)
    {
        if(R.id.ascust == v.getId())
        {
            Intent i = new Intent(this, signup.class);
            startActivity(i);
        }
        if (R.id.asvend == v.getId())
        {
            Intent i = new Intent(this, vendorSignup.class);
            startActivity(i);
        }
    }

}
