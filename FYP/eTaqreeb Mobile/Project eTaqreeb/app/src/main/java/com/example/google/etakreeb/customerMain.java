package com.example.google.etakreeb;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.Button;
import android.widget.GridView;

import java.util.ArrayList;

public class customerMain extends AppCompatActivity {

    GridView gv;
    Context context;
    Context c = this;
    ArrayList prgmName;
    public static String [] prgmNameList = {"Avari Hotel Lahore","pearl continental ", "Holiday Inn", "Gourmet"};
    public static int[] prgmImages = {R.drawable.av,R.drawable.pc,R.drawable.hi,R.drawable.g};
    Button b;
    String uName;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_customer_main);
        gv = (GridView) findViewById(R.id.gridView1);
        gv.setAdapter(new CustomAdapter(this, prgmNameList, prgmImages));
        b = (Button)findViewById(R.id.updatecust);
        b = (Button)findViewById(R.id.checkDetails1);
        b = (Button)findViewById(R.id.createMainEvent1);
        Intent intent = getIntent();
        uName = intent.getStringExtra("id");
    }
    public void onClick(View v)
    {
        if(R.id.createMainEvent1 == v.getId())
        {
            Intent intent = new Intent(getApplicationContext(), Create_Event.class);
            intent.putExtra("id", uName);
            finish();
            startActivity(intent);

        }
        if(R.id.checkDetails == v.getId())
        {
            Intent i = new Intent(getApplicationContext(), vendorDetails.class);
            finish();
            startActivity(i);

        }
        if(R.id.updatecust == v.getId())
        {
            Intent i = new Intent(getApplicationContext(), Update.class);
            finish();
            startActivity(i);

        }
        if(R.id.logout == v.getId())
        {
            Intent i = new Intent(getApplicationContext(), gridview.class);
            finish();
            startActivity(i);

        }

    }
    @Override
    public void onBackPressed() {
        new AlertDialog.Builder(this)
                .setTitle("Really Exit?")
                .setMessage("Are you sure you want to exit?")
                .setNegativeButton(android.R.string.no, null)
                .setPositiveButton(android.R.string.yes, new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface arg0, int arg1) {
                        customerMain.super.onBackPressed();
                        Intent i = new Intent(getApplicationContext(), gridview.class);
                        startActivity(i);
                    }
                }).create().show();
    }

}
