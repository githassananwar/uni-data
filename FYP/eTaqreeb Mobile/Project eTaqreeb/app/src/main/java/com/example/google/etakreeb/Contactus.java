package com.example.google.etakreeb;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;

public class Contactus extends AppCompatActivity {

    Button b;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_contactus);
    }

    @Override
    protected void onResume() {
        super.onResume();

        Intent i = new Intent(getApplicationContext(), gridview.class);
        finish();
        startActivity(i);
    }
}
