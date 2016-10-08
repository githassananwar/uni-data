package com.example.google.etakreeb;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Color;
import android.media.Image;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Gravity;
import android.view.Menu;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.GridView;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import com.backendless.Backendless;
import com.backendless.BackendlessCollection;
import com.backendless.async.callback.AsyncCallback;
import com.backendless.exceptions.BackendlessFault;

import java.util.ArrayList;
import java.util.Iterator;

public class gridview extends AppCompatActivity {

    Context context;
    Context c = this;
    String YOUR_APP_ID = "A9F16720-F3AC-43F0-FFC4-99CDEAECBF00";
    String s;
    String YOUR_SECRET_KEY = "2C18F8A2-DD4F-CC4C-FF1D-B562D5D9BC00";
    TableRow tr;
    EditText ed;
    Button b;
    ImageView i;
    TableLayout tl;
    TextView tv1,t2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_gridview);
        tl = (TableLayout)findViewById(R.id.table4);
        tv1 = (TextView)findViewById(R.id.searchText);
        t2 = (TextView)findViewById(R.id.searchVendor);
        tl.setColumnStretchable(0, true);
        b = (Button)findViewById(R.id.loginMain);
        b = (Button)findViewById(R.id.signUpMain);
        ed = (EditText)findViewById(R.id.getVendor1);
        b = (Button)findViewById(R.id.checkDetails);
        String appVersion = "v1";
        Backendless.initApp(this, YOUR_APP_ID, YOUR_SECRET_KEY, appVersion);
       // sp =(Spinner)findViewById(R.id.spinner1);
        i = (ImageView)findViewById(R.id.img1);

        final Animation a1 = AnimationUtils.loadAnimation(getBaseContext(), R.anim.rotate);
        i.startAnimation(a1);
        a1.setAnimationListener(new Animation.AnimationListener() {
            @Override
            public void onAnimationStart(Animation animation) {

            }

            @Override
            public void onAnimationEnd(Animation animation) {

            }

            @Override
            public void onAnimationRepeat(Animation animation) {

            }
        });


    }
    public void onClick(View v)
    {
        if(R.id.loginMain == v.getId())
        {
            Intent i = new Intent(this,login.class );
            finish();
            startActivity(i);
        }
        if(R.id.signUpMain == v.getId()) {
            Intent i = new Intent(this, dialog.class);
            finish();
            startActivity(i);
        }
        if(R.id.checkDetails == v.getId())
        {
            final Animation an = AnimationUtils.loadAnimation(getBaseContext(), R.anim.scale);
            b.startAnimation(an); s = ed.getText().toString();

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
                                tr = new TableRow(getApplicationContext());
                                tv1 = new TextView(getApplicationContext());
                                tv1.setText(user.getcName());
                                tv1.setTextColor(Color.BLUE);
                                tv1.setOnClickListener(new View.OnClickListener() {
                                    @Override
                                    public void onClick(View v) {
                                        final TableRow parent = (TableRow) v.getParent();
                                       // tl.removeView(parent);

                                    }
                                });
                                tr.addView(tv1);

                                tl.addView(tr);
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
            an.setAnimationListener(new Animation.AnimationListener() {
                @Override
                public void onAnimationStart(Animation animation) {

                }

                @Override
                public void onAnimationEnd(Animation animation) {
                    finish();
                }

                @Override
                public void onAnimationRepeat(Animation animation) {

                }
            });

        }
        if(R.id.img1 == v.getId())
        {
            Intent i = new Intent(this, Contactus.class);
            finish();
            startActivity(i);
        }
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }
}
