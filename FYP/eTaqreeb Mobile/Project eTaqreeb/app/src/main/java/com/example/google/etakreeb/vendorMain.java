package com.example.google.etakreeb;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Gravity;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import com.backendless.Backendless;
import com.backendless.BackendlessCollection;
import com.backendless.async.callback.AsyncCallback;
import com.backendless.exceptions.BackendlessFault;

import org.w3c.dom.Text;

import java.util.ArrayList;
import java.util.Iterator;

public class vendorMain extends AppCompatActivity {

    String uName, price, type;
    String password;
    String cName;
    TextView text1,text2,text3,text4;
    TextView tv1,tv2,tv3,tv4,cp;
    TableLayout tl;
    TableRow tr;
    Button b;
    String k;



    @Override

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_vendor_main);
        b = (Button)findViewById(R.id.updateven);
        b = (Button)findViewById(R.id.logout2);

        tv2 = (TextView)findViewById(R.id.dTextView2);
        tv3 = (TextView)findViewById(R.id.dTextView3);
        tv4 = (TextView)findViewById(R.id.dTextView4);

        cp = (TextView)findViewById(R.id.companyName);
        tl = (TableLayout)findViewById(R.id.table);
        tv1 = (TextView)findViewById(R.id.dTextView1);
        tl.setColumnStretchable(0, true);
        tl.setColumnStretchable(1, true);
        tl.setColumnStretchable(2, true);
        tl.setColumnStretchable(3, true);
        b = (Button)findViewById(R.id.newSevices);

        Intent intent = getIntent();
        uName = intent.getStringExtra("id");
        cName = intent.getStringExtra("name");
      //Toast.makeText(this,cName,Toast.LENGTH_LONG).show();
       /* type= intent.getStringExtra("type");
        price = intent.getStringExtra("price");*/

    }

    public void onClick(View v) {
        if (R.id.updateven == v.getId()) {

            Intent i = new Intent(this, Update_Vendor.class);
            i.putExtra("id", uName);
            finish();

            startActivity(i);
        }
        if(R.id.logout2 == v.getId())
        {
            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setMessage("Signup Successful");
// Add the buttons
            builder.setPositiveButton("Ok", new DialogInterface.OnClickListener() {
                public void onClick(DialogInterface dialog, int id) {
                    // User clicked OK button
                    // save object asynchronously
                    Intent i = new Intent(getApplicationContext(), gridview.class);
                    finish();
                    startActivity(i);

                }
            });
            builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                public void onClick(DialogInterface dialog, int id) {
                    // User clicked OK button
                    // save object asynchronously

                }
            });
            builder.show();

        }
        if(R.id.newSevices == v.getId())
        {
            Intent i = new Intent(this, vendorServices.class);
            i.putExtra("id", uName);
            i.putExtra("name", cName);
            finish();
            startActivity(i);
        }
    }
    @Override
    protected void onResume() {
        super.onResume();
        cp.setText(cName);
        final AsyncCallback<BackendlessCollection<services>> callback=new AsyncCallback<BackendlessCollection<services>>()
        {

            private boolean firstResponse=true;
            boolean flg = true;

            public void handleResponse( BackendlessCollection<services> criteria )
            {
                System.out.println( "Total  in response - " + criteria.getTotalObjects() );

                if( firstResponse )
                {
                    System.out.println( "Total in first response- " + criteria.getTotalObjects() );
                    firstResponse = true;
                }

                int size = criteria.getCurrentPage().size();
                Iterator<services> userIterator = criteria.getCurrentPage().iterator();


                if(flg == true)
                {
                    while (userIterator.hasNext()) {
                        services user = userIterator.next();

                        if (user.getvObjectId().equals(uName))
                        {
                           // Toast.makeText(getApplicationContext(),user.getvObjectId(),Toast.LENGTH_LONG).show();
                            flg = false;
                            tr = new TableRow(getApplicationContext());
                            text1 = new TextView(getApplicationContext());
                            text2 = new TextView(getApplicationContext());
                            text3 = new TextView(getApplicationContext());
                            text4 = new TextView(getApplicationContext());
                            text1.setText(user.getNam());
                            text1.setTextSize(15);
                            text1.setGravity(Gravity.CENTER);
                            text2.setText(user.getPric());
                            text2.setTextSize(15);
                            text2.setGravity(Gravity.CENTER);
                            text3.setText(user.getTyp());
                            text3.setTextSize(15);
                            text3.setGravity(Gravity.CENTER);
                            text4.setTextSize(15);
                            text4.setGravity(Gravity.CENTER);
                            text4.setText("Edit");
                            text4.setTextColor(Color.BLUE);
                            text4.setOnClickListener(new View.OnClickListener() {
                                @Override
                                public void onClick(View v) {
                                    final TableRow parent = (TableRow) v.getParent();
                                    tl.removeView(parent);
                                    Intent intent = new Intent(getApplicationContext(), EditServices.class);
                                    intent.putExtra("id", uName);
                                    intent.putExtra("name", cName);
                                    startActivity(intent);
                                }
                            });
                            tr.addView(text1);
                            tr.addView(text2);
                            tr.addView(text3);
                            tr.addView(text4);
                            tl.addView(tr);

                        }


                    }
                }
                if(userIterator.hasNext() == false && flg == true)
                {
                    Toast.makeText(getApplicationContext(), "Didn't Find Any Service", Toast.LENGTH_LONG).show();

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
        Backendless.Data.of( services.class ).find( callback );
    }
}
