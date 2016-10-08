package com.example.google.etakreeb;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;

public class vendorDetails extends AppCompatActivity {

    String name, price, type;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_vendor_details);
       // Intent intent = getIntent();
        //name = intent.getStringExtra("name");
        //price = intent.getStringExtra("price");
       // type = intent.getStringExtra("type");


    }
}

