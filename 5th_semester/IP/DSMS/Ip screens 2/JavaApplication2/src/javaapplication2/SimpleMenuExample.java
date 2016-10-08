
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;

import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;



public class SimpleMenuExample {

	JDialog dialog;
	JFrame frame;
	JPanel panel;
	
    public SimpleMenuExample() {
    	
    	 //dialog = new JDialog(frame);
    	 frame = new JFrame();
    	 frame.setTitle("DSMS-Departmental Store Management System");
    	 //frame.setVisible(true);
    	 //frame.setVisible(false);
    	 
    	 //frame.setLocationRelativeTo(this);
    	// dialog.setLocation(200, 20);
    	 //frame.setUndecorated(true);
    	//frame.setOpacity(0.9f);
    	panel = new JPanel();
    	panel.setBackground(Color.LIGHT_GRAY);
//
    	frame.setContentPane(panel); 
//    	frame.setOpacity(0.9f);
    	 frame.setSize(1370, 700);
        
    	 loginPage();
    	 
        initUI();
//        setSize(1370 , 700);
//        setLocation(0, 20);
//        //dialog.setModal(true);
//        
//        setVisible(true); 
    }
    
    void viewPurchase()
    {
    	
    	JLabel desc = new JLabel("Atleast fill one of the Entry Below");
    	desc.setLayout(null);
    	desc.setBounds(500 , 70 , 500 , 30);
    	frame.add(desc);
    	
    	JLabel sDate = new JLabel("Search By Date: ");
    	sDate.setLayout(null);
    	sDate.setBounds(100 , 120 , 150 , 30);
    	frame.add(sDate);
    	
    	JLabel fromDate = new JLabel("From: ");
		fromDate.setLayout(null);
		fromDate.setBounds(200 , 171 , 150 , 30);
		
		frame.add(fromDate);
		
		JLabel fDay = new JLabel("DD");
		fDay.setLayout(null);
		fDay.setBounds(250 , 191 , 60 , 30);
		JTextField day = new JTextField(2);
    	day.setLayout(null);
		day.setBounds(250 , 176 , 20 , 20);
		JLabel fMon = new JLabel("MM");
		fMon.setLayout(null);
		fMon.setBounds(310 , 191 , 60 , 30);
		JTextField month = new JTextField(2);
    	month.setLayout(null);
		month.setBounds(310 , 176 , 20 , 20);
		JLabel fYear = new JLabel("YYYY");
		fYear.setLayout(null);
		fYear.setBounds(390 , 191 , 60 , 30);
		JTextField year = new JTextField(2);
    	year.setLayout(null);
		year.setBounds(390 , 176 , 35 , 20);
		
		frame.add(fDay);
		frame.add(day);
		frame.add(fMon);
		frame.add(month);
		frame.add(fYear);
		frame.add(year);
		
		
		
		
    	JLabel toDate = new JLabel("To: ");
		toDate.setLayout(null);
		toDate.setBounds(565 , 171 , 150 , 30);
		
		frame.add(toDate);
		
		JLabel tDay = new JLabel("DD");
		tDay.setLayout(null);
		tDay.setBounds(600 , 191 , 60 , 30);
		JTextField today = new JTextField(2);
    	today.setLayout(null);
		today.setBounds(600 , 176 , 20 , 20);
		JLabel tMon = new JLabel("MM");
		tMon.setLayout(null);
		tMon.setBounds(660 , 191 , 60 , 30);
		JTextField tomonth = new JTextField(2);
    	tomonth.setLayout(null);
		tomonth.setBounds(660 , 176 , 20 , 20);
		JLabel tYear = new JLabel("YYYY");
		tYear.setLayout(null);
		tYear.setBounds(740 , 191 , 60 , 30);
		JTextField toyear = new JTextField(2);
    	toyear.setLayout(null);
		toyear.setBounds(740 , 176 , 35 , 20);
		
		frame.add(tDay);
		frame.add(today);
		frame.add(tMon);
		frame.add(tomonth);
		frame.add(tYear);
		frame.add(toyear);
    	
    	
    	JLabel department = new JLabel("Choose Department: ");
    	department.setLayout(null);
    	department.setBounds(100 , 281 , 150 , 30);
    	
    	frame.add(department);
    	
    	JCheckBox cosmetics = new JCheckBox("Cosmetics");
		cosmetics.setLayout(null);
		cosmetics.setBounds(250 , 285 , 90 , 20);
		cosmetics.setSelected(true);
		frame.add(cosmetics);
    	
		JCheckBox medicine = new JCheckBox("Medicine");
    	medicine.setLayout(null);
    	medicine.setSelected(true);
    	medicine.setBounds(340 , 285 , 90 , 20);
    	
    	frame.add(medicine);
    	
    	JCheckBox food = new JCheckBox("Food");
    	food.setLayout(null);
    	food.setSelected(true);
    	food.setBounds(430 , 285 , 90 , 20);
    	
    	frame.add(food);
    	
    	JCheckBox grocery = new JCheckBox("Grocery");
    	grocery.setLayout(null);
    	grocery.setSelected(true);
    	grocery.setBounds(520 , 285 , 90 , 20);
    	
    	frame.add(grocery);
    	
    	JCheckBox clothing = new JCheckBox("Clothing");
    	clothing.setLayout(null);
    	clothing.setSelected(true);
    	clothing.setBounds(610 , 285 , 90 , 20);
    	
    	frame.add(clothing);
    	
    	JCheckBox electronics = new JCheckBox("Electronics");
    	electronics.setLayout(null);
    	electronics.setSelected(true);
    	electronics.setBounds(700 , 285 , 90 , 20);
    	
    	frame.add(electronics);
    	
    	JCheckBox sports = new JCheckBox("Sports");
    	sports.setLayout(null);
    	sports.setSelected(true);
    	sports.setBounds(790 , 285 , 90 , 20);
    	
    	frame.add(sports);
    	frame.setLayout(null);
    	
    	
		JButton view = new JButton("View");
    	view.setLayout(null);
		view.setBounds(400 , 400 , 90 , 40);
		
		frame.add(view);
    	
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(600 , 400 , 90 , 40);
		
		frame.add(cncl);
		
		
    	
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    	
    }
    
    
    
    
    void viewSale()
    {
    	JLabel desc = new JLabel("Atleast fill one of the Entry Below");
    	desc.setLayout(null);
    	desc.setBounds(500 , 70 , 500 , 30);
    	frame.add(desc);
    	
    	JLabel sDate = new JLabel("Search By Date: ");
    	sDate.setLayout(null);
    	sDate.setBounds(100 , 120 , 150 , 30);
    	frame.add(sDate);
    	
    	JLabel fromDate = new JLabel("From: ");
		fromDate.setLayout(null);
		fromDate.setBounds(200 , 171 , 150 , 30);
		
		frame.add(fromDate);
		
		JLabel fDay = new JLabel("DD");
		fDay.setLayout(null);
		fDay.setBounds(250 , 191 , 60 , 30);
		JTextField day = new JTextField(2);
    	day.setLayout(null);
		day.setBounds(250 , 176 , 20 , 20);
		JLabel fMon = new JLabel("MM");
		fMon.setLayout(null);
		fMon.setBounds(310 , 191 , 60 , 30);
		JTextField month = new JTextField(2);
    	month.setLayout(null);
		month.setBounds(310 , 176 , 20 , 20);
		JLabel fYear = new JLabel("YYYY");
		fYear.setLayout(null);
		fYear.setBounds(390 , 191 , 60 , 30);
		JTextField year = new JTextField(2);
    	year.setLayout(null);
		year.setBounds(390 , 176 , 35 , 20);
		
		frame.add(fDay);
		frame.add(day);
		frame.add(fMon);
		frame.add(month);
		frame.add(fYear);
		frame.add(year);
		
		
		
		
    	JLabel toDate = new JLabel("To: ");
		toDate.setLayout(null);
		toDate.setBounds(565 , 171 , 150 , 30);
		
		frame.add(toDate);
		
		JLabel tDay = new JLabel("DD");
		tDay.setLayout(null);
		tDay.setBounds(600 , 191 , 60 , 30);
		JTextField today = new JTextField(2);
    	today.setLayout(null);
		today.setBounds(600 , 176 , 20 , 20);
		JLabel tMon = new JLabel("MM");
		tMon.setLayout(null);
		tMon.setBounds(660 , 191 , 60 , 30);
		JTextField tomonth = new JTextField(2);
    	tomonth.setLayout(null);
		tomonth.setBounds(660 , 176 , 20 , 20);
		JLabel tYear = new JLabel("YYYY");
		tYear.setLayout(null);
		tYear.setBounds(740 , 191 , 60 , 30);
		JTextField toyear = new JTextField(2);
    	toyear.setLayout(null);
		toyear.setBounds(740 , 176 , 35 , 20);
		
		frame.add(tDay);
		frame.add(today);
		frame.add(tMon);
		frame.add(tomonth);
		frame.add(tYear);
		frame.add(toyear);
    	
    	
    	JLabel department = new JLabel("Choose Department: ");
    	department.setLayout(null);
    	department.setBounds(100 , 281 , 150 , 30);
    	
    	frame.add(department);
    	
    	JCheckBox cosmetics = new JCheckBox("Cosmetics");
		cosmetics.setLayout(null);
		cosmetics.setBounds(250 , 285 , 90 , 20);
		cosmetics.setSelected(true);
		frame.add(cosmetics);
    	
		JCheckBox medicine = new JCheckBox("Medicine");
    	medicine.setLayout(null);
    	medicine.setSelected(true);
    	medicine.setBounds(340 , 285 , 90 , 20);
    	
    	frame.add(medicine);
    	
    	JCheckBox food = new JCheckBox("Food");
    	food.setLayout(null);
    	food.setSelected(true);
    	food.setBounds(430 , 285 , 90 , 20);
    	
    	frame.add(food);
    	
    	JCheckBox grocery = new JCheckBox("Grocery");
    	grocery.setLayout(null);
    	grocery.setSelected(true);
    	grocery.setBounds(520 , 285 , 90 , 20);
    	
    	frame.add(grocery);
    	
    	JCheckBox clothing = new JCheckBox("Clothing");
    	clothing.setLayout(null);
    	clothing.setSelected(true);
    	clothing.setBounds(610 , 285 , 90 , 20);
    	
    	frame.add(clothing);
    	
    	JCheckBox electronics = new JCheckBox("Electronics");
    	electronics.setLayout(null);
    	electronics.setSelected(true);
    	electronics.setBounds(700 , 285 , 90 , 20);
    	
    	frame.add(electronics);
    	
    	JCheckBox sports = new JCheckBox("Sports");
    	sports.setLayout(null);
    	sports.setSelected(true);
    	sports.setBounds(790 , 285 , 90 , 20);
    	
    	frame.add(sports);
    	frame.setLayout(null);
    	
    	
		JButton view = new JButton("View");
    	view.setLayout(null);
		view.setBounds(400 , 400 , 90 , 40);
		
		frame.add(view);
    	
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(600 , 400 , 90 , 40);
		
		frame.add(cncl);
		
		
    	
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    	
    }
    
    void generateInvoice()
    {
		JLabel invoiceDate = new JLabel("Date: ");
		invoiceDate.setLayout(null);
		invoiceDate.setBounds(100 , 71 , 150 , 30);
		
		frame.add(invoiceDate);
		
		JLabel hDay = new JLabel("DD");
		hDay.setLayout(null);
		hDay.setBounds(250 , 91 , 60 , 30);
		JTextField day = new JTextField(2);
    	day.setLayout(null);
		day.setBounds(250 , 76 , 20 , 20);
		JLabel hMon = new JLabel("MM");
		hMon.setLayout(null);
		hMon.setBounds(310 , 91 , 60 , 30);
		JTextField month = new JTextField(2);
    	month.setLayout(null);
		month.setBounds(310 , 76 , 20 , 20);
		JLabel hYear = new JLabel("YYYY");
		hYear.setLayout(null);
		hYear.setBounds(390 , 91 , 60 , 30);
		JTextField year = new JTextField(2);
    	year.setLayout(null);
		year.setBounds(390 , 76 , 35 , 20);
		
		frame.add(hDay);
		frame.add(day);
		frame.add(hMon);
		frame.add(month);
		frame.add(hYear);
		frame.add(year);
		
		
    	JLabel invID = new JLabel("Invoice ID: ");
		invID.setLayout(null);
		invID.setBounds(100 , 130 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(250 , 138 , 90 , 20);
		frame.add(invID);
		frame.add(id);
		
    	JLabel invAmount = new JLabel("Invoice Amount: ");
		invAmount.setLayout(null);
		invAmount.setBounds(100 , 170 , 150 , 30);
    	JTextField amount = new JTextField(10);
    	amount.setLayout(null);
		amount.setBounds(250 , 178 , 90 , 20);
		frame.add(invAmount);
		frame.add(amount);
		
    	JLabel empID = new JLabel("Employee ID: ");
		empID.setLayout(null);
		empID.setBounds(100 , 210 , 150 , 30);
    	JTextField emID = new JTextField(10);
    	emID.setLayout(null);
		emID.setBounds(250 , 218 , 90 , 20);
		frame.add(empID);
		frame.add(emID);
		
    	JLabel cusID = new JLabel("Customer ID: ");
		cusID.setLayout(null);
		cusID.setBounds(450 , 210 , 150 , 30);
    	JTextField cuID = new JTextField(10);
    	cuID.setLayout(null);
		cuID.setBounds(600 , 218 , 90 , 20);
		frame.add(cusID);
		frame.add(cuID);
		
		
		JLabel cusMsg = new JLabel("Only for registered customer ");
		cusMsg.setLayout(null);
		cusMsg.setBounds(700 , 210 , 170 , 30);
		frame.add(cusMsg);
		

		JButton generate = new JButton("Generate");
    	generate.setLayout(null);
		generate.setBounds(200 , 400 , 100 , 40);
		
		frame.add(generate);
    	
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(300 , 400 , 100 , 40);
		
		frame.add(cncl);
		
		JButton clear = new JButton("Clear");
    	clear.setLayout(null);
		clear.setBounds(600 , 400 , 100 , 40);
		
		frame.add(clear);
		
		frame.setLayout(null);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
		
    	
    }
    
    void viewInvoice()
    {
    	
    	JLabel desc = new JLabel("Atleast fill one of the Entry Below");
    	desc.setLayout(null);
    	desc.setBounds(500 , 70 , 500 , 30);
    	frame.add(desc);
    	
    	JLabel sDate = new JLabel("View By Date: ");
    	sDate.setLayout(null);
    	sDate.setBounds(100 , 120 , 150 , 30);
    	frame.add(sDate);
    	
    	JLabel fromDate = new JLabel("From: ");
		fromDate.setLayout(null);
		fromDate.setBounds(200 , 171 , 150 , 30);
		
		frame.add(fromDate);
		
		JLabel fDay = new JLabel("DD");
		fDay.setLayout(null);
		fDay.setBounds(250 , 191 , 60 , 30);
		JTextField day = new JTextField(2);
    	day.setLayout(null);
		day.setBounds(250 , 176 , 20 , 20);
		JLabel fMon = new JLabel("MM");
		fMon.setLayout(null);
		fMon.setBounds(310 , 191 , 60 , 30);
		JTextField month = new JTextField(2);
    	month.setLayout(null);
		month.setBounds(310 , 176 , 20 , 20);
		JLabel fYear = new JLabel("YYYY");
		fYear.setLayout(null);
		fYear.setBounds(390 , 191 , 60 , 30);
		JTextField year = new JTextField(2);
    	year.setLayout(null);
		year.setBounds(390 , 176 , 35 , 20);
		
		frame.add(fDay);
		frame.add(day);
		frame.add(fMon);
		frame.add(month);
		frame.add(fYear);
		frame.add(year);
		
		
		
		
    	JLabel toDate = new JLabel("To: ");
		toDate.setLayout(null);
		toDate.setBounds(565 , 171 , 150 , 30);
		
		frame.add(toDate);
		
		JLabel tDay = new JLabel("DD");
		tDay.setLayout(null);
		tDay.setBounds(600 , 191 , 60 , 30);
		JTextField today = new JTextField(2);
    	today.setLayout(null);
		today.setBounds(600 , 176 , 20 , 20);
		JLabel tMon = new JLabel("MM");
		tMon.setLayout(null);
		tMon.setBounds(660 , 191 , 60 , 30);
		JTextField tomonth = new JTextField(2);
    	tomonth.setLayout(null);
		tomonth.setBounds(660 , 176 , 20 , 20);
		JLabel tYear = new JLabel("YYYY");
		tYear.setLayout(null);
		tYear.setBounds(740 , 191 , 60 , 30);
		JTextField toyear = new JTextField(2);
    	toyear.setLayout(null);
		toyear.setBounds(740 , 176 , 35 , 20);
		
		frame.add(tDay);
		frame.add(today);
		frame.add(tMon);
		frame.add(tomonth);
		frame.add(tYear);
		frame.add(toyear);
		
		
		
    	JLabel invID = new JLabel("Invoice ID: ");
		invID.setLayout(null);
		invID.setBounds(100 , 230 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(250 , 238 , 90 , 20);
		frame.add(invID);
		frame.add(id);
		
    	JLabel invAmount = new JLabel("Invoice Amount: ");
		invAmount.setLayout(null);
		invAmount.setBounds(100 , 270 , 150 , 30);
    	JTextField amount = new JTextField(10);
    	amount.setLayout(null);
		amount.setBounds(250 , 278 , 90 , 20);
		frame.add(invAmount);
		frame.add(amount);
		
		
		
		
		JLabel department = new JLabel("Choose Department: ");
    	department.setLayout(null);
    	department.setBounds(100 , 321 , 150 , 30);
    	
    	frame.add(department);
    	
    	JCheckBox cosmetics = new JCheckBox("Cosmetics");
		cosmetics.setLayout(null);
		cosmetics.setBounds(250 , 325 , 90 , 20);
		cosmetics.setSelected(true);
		frame.add(cosmetics);
    	
		JCheckBox medicine = new JCheckBox("Medicine");
    	medicine.setLayout(null);
    	medicine.setSelected(true);
    	medicine.setBounds(340 , 325 , 90 , 20);
    	
    	frame.add(medicine);
    	
    	JCheckBox food = new JCheckBox("Food");
    	food.setLayout(null);
    	food.setSelected(true);
    	food.setBounds(430 , 325 , 90 , 20);
    	
    	frame.add(food);
    	
    	JCheckBox grocery = new JCheckBox("Grocery");
    	grocery.setLayout(null);
    	grocery.setSelected(true);
    	grocery.setBounds(520 , 325 , 90 , 20);
    	
    	frame.add(grocery);
    	
    	JCheckBox clothing = new JCheckBox("Clothing");
    	clothing.setLayout(null);
    	clothing.setSelected(true);
    	clothing.setBounds(610 , 325 , 90 , 20);
    	
    	frame.add(clothing);
    	
    	JCheckBox electronics = new JCheckBox("Electronics");
    	electronics.setLayout(null);
    	electronics.setSelected(true);
    	electronics.setBounds(700 , 325 , 90 , 20);
    	
    	frame.add(electronics);
    	
    	JCheckBox sports = new JCheckBox("Sports");
    	sports.setLayout(null);
    	sports.setSelected(true);
    	sports.setBounds(790 , 325 , 90 , 20);
    	
    	frame.add(sports);
    	frame.setLayout(null);
    	
    	
		JButton view = new JButton("View");
    	view.setLayout(null);
		view.setBounds(400 , 420 , 90 , 40);
		
		frame.add(view);
    	
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(600 , 420 , 90 , 40);
		
		frame.add(cncl);
		
		
		frame.setLayout(null);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    	
    }
    void viewDepartment()
    {
    	JLabel desc = new JLabel("Atleast fill one of the Entry Below");
    	desc.setLayout(null);
    	desc.setBounds(500 , 70 , 500 , 30);
    	frame.add(desc);
    	
    	JLabel deptID = new JLabel("Department ID: ");
		deptID.setLayout(null);
		deptID.setBounds(100 , 121 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(250 , 129 , 90 , 20);
		frame.add(deptID);
		frame.add(id);
    	
    	JLabel department = new JLabel("Choose Department: ");
    	department.setLayout(null);
    	department.setBounds(100 , 251 , 150 , 30);
    	
    	frame.add(department);
    	
    	JCheckBox cosmetics = new JCheckBox("Cosmetics");
		cosmetics.setLayout(null);
		cosmetics.setBounds(250 , 255 , 90 , 20);
		cosmetics.setSelected(true);
		frame.add(cosmetics);
    	
		JCheckBox medicine = new JCheckBox("Medicine");
    	medicine.setLayout(null);
    	medicine.setSelected(true);
    	medicine.setBounds(340 , 255 , 90 , 20);
    	
    	frame.add(medicine);
    	
    	JCheckBox food = new JCheckBox("Food");
    	food.setLayout(null);
    	food.setSelected(true);
    	food.setBounds(430 , 255 , 90 , 20);
    	
    	frame.add(food);
    	
    	JCheckBox grocery = new JCheckBox("Grocery");
    	grocery.setLayout(null);
    	grocery.setSelected(true);
    	grocery.setBounds(520 , 255 , 90 , 20);
    	
    	frame.add(grocery);
    	
    	JCheckBox clothing = new JCheckBox("Clothing");
    	clothing.setLayout(null);
    	clothing.setSelected(true);
    	clothing.setBounds(610 , 255 , 90 , 20);
    	
    	frame.add(clothing);
    	
    	JCheckBox electronics = new JCheckBox("Electronics");
    	electronics.setLayout(null);
    	electronics.setSelected(true);
    	electronics.setBounds(700 , 255 , 90 , 20);
    	
    	frame.add(electronics);
    	
    	JCheckBox sports = new JCheckBox("Sports");
    	sports.setLayout(null);
    	sports.setSelected(true);
    	sports.setBounds(790 , 255 , 90 , 20);
    	
    	frame.add(sports);
    	frame.setLayout(null);
    	
    	
		JButton view = new JButton("View");
    	view.setLayout(null);
		view.setBounds(400 , 350 , 90 , 40);
		
		frame.add(view);
    	
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(600 , 350 , 90 , 40);
		
		frame.add(cncl);
		
		
    	
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    }
    
    void viewTransaction()
    {
    	JLabel sDate = new JLabel("Search By Date: ");
    	sDate.setLayout(null);
    	sDate.setBounds(100 , 120 , 150 , 30);
    	frame.add(sDate);
    	
    	JLabel fromDate = new JLabel("From: ");
		fromDate.setLayout(null);
		fromDate.setBounds(200 , 171 , 150 , 30);
		
		frame.add(fromDate);
		
		JLabel fDay = new JLabel("DD");
		fDay.setLayout(null);
		fDay.setBounds(250 , 191 , 60 , 30);
		JTextField day = new JTextField(2);
    	day.setLayout(null);
		day.setBounds(250 , 176 , 20 , 20);
		JLabel fMon = new JLabel("MM");
		fMon.setLayout(null);
		fMon.setBounds(310 , 191 , 60 , 30);
		JTextField month = new JTextField(2);
    	month.setLayout(null);
		month.setBounds(310 , 176 , 20 , 20);
		JLabel fYear = new JLabel("YYYY");
		fYear.setLayout(null);
		fYear.setBounds(390 , 191 , 60 , 30);
		JTextField year = new JTextField(2);
    	year.setLayout(null);
		year.setBounds(390 , 176 , 35 , 20);
		
		frame.add(fDay);
		frame.add(day);
		frame.add(fMon);
		frame.add(month);
		frame.add(fYear);
		frame.add(year);
		
		
		
		
    	JLabel toDate = new JLabel("To: ");
		toDate.setLayout(null);
		toDate.setBounds(565 , 171 , 150 , 30);
		
		frame.add(toDate);
		
		JLabel tDay = new JLabel("DD");
		tDay.setLayout(null);
		tDay.setBounds(600 , 191 , 60 , 30);
		JTextField today = new JTextField(2);
    	today.setLayout(null);
		today.setBounds(600 , 176 , 20 , 20);
		JLabel tMon = new JLabel("MM");
		tMon.setLayout(null);
		tMon.setBounds(660 , 191 , 60 , 30);
		JTextField tomonth = new JTextField(2);
    	tomonth.setLayout(null);
		tomonth.setBounds(660 , 176 , 20 , 20);
		JLabel tYear = new JLabel("YYYY");
		tYear.setLayout(null);
		tYear.setBounds(740 , 191 , 60 , 30);
		JTextField toyear = new JTextField(2);
    	toyear.setLayout(null);
		toyear.setBounds(740 , 176 , 35 , 20);
		
		frame.add(tDay);
		frame.add(today);
		frame.add(tMon);
		frame.add(tomonth);
		frame.add(tYear);
		frame.add(toyear);
		
		JLabel department = new JLabel("Transaction of Department: ");
    	department.setLayout(null);
    	department.setBounds(100 , 230 , 250 , 30);
		
    	frame.add(department);
    	
		JCheckBox cosmetics = new JCheckBox("Cosmetics");
		cosmetics.setSelected(true);
		cosmetics.setLayout(null);
		cosmetics.setBounds(300 , 235 , 90 , 20);
		
		frame.add(cosmetics);
    	
		JCheckBox medicine = new JCheckBox("Medicine");
		medicine.setSelected(true);
    	medicine.setLayout(null);
    	medicine.setBounds(390 , 235 , 90 , 20);
    	
    	frame.add(medicine);
    	
    	JCheckBox food = new JCheckBox("Food");
    	food.setSelected(true);
    	food.setLayout(null);
    	food.setBounds(480 , 235 , 90 , 20);
    	
    	frame.add(food);
    	
    	JCheckBox grocery = new JCheckBox("Grocery");
    	grocery.setSelected(true);
    	grocery.setLayout(null);
    	grocery.setBounds(570 , 235 , 90 , 20);
    	
    	frame.add(grocery);
    	
    	JCheckBox clothing = new JCheckBox("Clothing");
    	clothing.setSelected(true);
    	clothing.setLayout(null);
    	clothing.setBounds(660 , 235 , 90 , 20);
    	
    	frame.add(clothing);
    	
    	JCheckBox electronics = new JCheckBox("Electronics");
    	electronics.setSelected(true);
    	electronics.setLayout(null);
    	electronics.setBounds(750 , 235 , 90 , 20);
    	
    	frame.add(electronics);
    	
    	JCheckBox sports = new JCheckBox("Sports");
    	sports.setSelected(true);
    	sports.setLayout(null);
    	sports.setBounds(840 , 235 , 90 , 20);
    	
    	frame.add(sports);
		
		JButton view = new JButton("View");
		view.setLayout(null);
		view.setBounds(120 , 320 , 80 , 30);
		frame.add(view);
		
		JButton cncl = new JButton("Cancel");
		cncl.setLayout(null);
		cncl.setBounds(250 , 320 , 80 , 30);
		frame.add(cncl);
		
		frame.setLayout(null);	
		
		frame.setSize(130, 600);
		frame.setSize(1370, 700);
    }
    
    void addTransaction()
    {
    	JLabel hireDate = new JLabel("Date: ");
		hireDate.setLayout(null);
		hireDate.setBounds(100 , 170 , 150 , 30);
		
		frame.add(hireDate);
		
		JLabel hDay = new JLabel("DD");
		hDay.setLayout(null);
		hDay.setBounds(250 , 190 , 60 , 30);
		JTextField day = new JTextField(2);
    	day.setLayout(null);
		day.setBounds(250 , 170 , 20 , 20);
		JLabel hMon = new JLabel("MM");
		hMon.setLayout(null);
		hMon.setBounds(310 , 190 , 60 , 30);
		JTextField month = new JTextField(2);
    	month.setLayout(null);
		month.setBounds(310 , 170 , 20 , 20);
		JLabel hYear = new JLabel("YYYY");
		hYear.setLayout(null);
		hYear.setBounds(390 , 190 , 60 , 30);
		JTextField year = new JTextField(2);
    	year.setLayout(null);
		year.setBounds(390 , 170 , 35 , 20);
		
		frame.add(hDay);
		frame.add(day);
		frame.add(hMon);
		frame.add(month);
		frame.add(hYear);
		frame.add(year);
    	
    	JLabel transID = new JLabel("Transaction ID: ");
    	transID.setLayout(null);
    	transID.setBounds(100 , 250 , 120 , 20);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(250 , 255 , 90 , 20);
		frame.add(transID);
		frame.add(id);
		
		JLabel transAmount = new JLabel("Transaction Amount:");
		transAmount.setLayout(null);
		transAmount.setBounds(100 , 290 , 120 , 20);
    	JTextField amount = new JTextField(10);
    	amount.setLayout(null);
    	amount.setBounds(250 , 295 , 90 , 20);
		frame.add(transAmount);
		frame.add(amount);
		
		JLabel type = new JLabel("Transaction Type: ");
		type.setLayout(null);
		type.setBounds(100 , 330 , 150 , 30);
		
    	frame.add(type);
    	
		JRadioButton credit = new JRadioButton("Credit");
		credit.setLayout(null);
		credit.setBounds(250 , 335 , 90 , 20);
		
		frame.add(credit);
    	
		JRadioButton debit = new JRadioButton("Debit");
		debit.setLayout(null);
		debit.setBounds(340 , 335 , 90 , 20);
    	
    	frame.add(debit);
    	
		ButtonGroup typ = new ButtonGroup();
		typ.add(debit);
		typ.add(credit);
		
    	JLabel department = new JLabel("POS of Department: ");
    	department.setLayout(null);
    	department.setBounds(100 , 380 , 150 , 30);
		
    	frame.add(department);
    	
		JRadioButton cosmetics = new JRadioButton("Cosmetics");
		cosmetics.setLayout(null);
		cosmetics.setBounds(250 , 385 , 90 , 20);
		
		frame.add(cosmetics);
    	
    	JRadioButton medicine = new JRadioButton("Medicine");
    	medicine.setLayout(null);
    	medicine.setBounds(340 , 385 , 90 , 20);
    	
    	frame.add(medicine);
    	
    	JRadioButton food = new JRadioButton("Food");
    	food.setLayout(null);
    	food.setBounds(430 , 385 , 90 , 20);
    	
    	frame.add(food);
    	
    	JRadioButton grocery = new JRadioButton("Grocery");
    	grocery.setLayout(null);
    	grocery.setBounds(520 , 385 , 90 , 20);
    	
    	frame.add(grocery);
    	
    	JRadioButton clothing = new JRadioButton("Clothing");
    	clothing.setLayout(null);
    	clothing.setBounds(610 , 385 , 90 , 20);
    	
    	frame.add(clothing);
    	
    	JRadioButton electronics = new JRadioButton("Electronics");
    	electronics.setLayout(null);
    	electronics.setBounds(700 , 385 , 90 , 20);
    	
    	frame.add(electronics);
    	
    	JRadioButton sports = new JRadioButton("Sports");
    	sports.setLayout(null);
    	sports.setBounds(790 , 385 , 90 , 20);
    	
    	frame.add(sports);
    	
    	
    	ButtonGroup dept = new ButtonGroup();
    	dept.add(cosmetics);
    	dept.add(medicine);
    	dept.add(food);
    	dept.add(grocery);
    	dept.add(electronics);
    	dept.add(clothing);
    	dept.add(sports);
    	
    	JButton view = new JButton("Add");
		view.setLayout(null);
		view.setBounds(220 , 480 , 80 , 30);
		frame.add(view);
		
		JButton cncl = new JButton("Cancel");
		cncl.setLayout(null);
		cncl.setBounds(360 , 480 , 80 , 30);
		frame.add(cncl);
    	
    	frame.setLayout(null);	
		
		frame.setSize(130, 600);
		frame.setSize(1370, 700);
    }
    
    void viewPOS()
    {
    	JLabel department = new JLabel("POS of Department: ");
    	department.setLayout(null);
    	department.setBounds(100 , 200 , 150 , 30);
		
    	frame.add(department);
    	
		JCheckBox cosmetics = new JCheckBox("Cosmetics");
		cosmetics.setSelected(true);
		cosmetics.setLayout(null);
		cosmetics.setBounds(250 , 205 , 90 , 20);
		
		frame.add(cosmetics);
    	
		JCheckBox medicine = new JCheckBox("Medicine");
		medicine.setSelected(true);
    	medicine.setLayout(null);
    	medicine.setBounds(340 , 205 , 90 , 20);
    	
    	frame.add(medicine);
    	
    	JCheckBox food = new JCheckBox("Food");
    	food.setSelected(true);
    	food.setLayout(null);
    	food.setBounds(430 , 205 , 90 , 20);
    	
    	frame.add(food);
    	
    	JCheckBox grocery = new JCheckBox("Grocery");
    	grocery.setSelected(true);
    	grocery.setLayout(null);
    	grocery.setBounds(520 , 205 , 90 , 20);
    	
    	frame.add(grocery);
    	
    	JCheckBox clothing = new JCheckBox("Clothing");
    	clothing.setSelected(true);
    	clothing.setLayout(null);
    	clothing.setBounds(610 , 205 , 90 , 20);
    	
    	frame.add(clothing);
    	
    	JCheckBox electronics = new JCheckBox("Electronics");
    	electronics.setSelected(true);
    	electronics.setLayout(null);
    	electronics.setBounds(700 , 205 , 90 , 20);
    	
    	frame.add(electronics);
    	
    	JCheckBox sports = new JCheckBox("Sports");
    	sports.setSelected(true);
    	sports.setLayout(null);
    	sports.setBounds(790 , 205 , 90 , 20);
    	
    	frame.add(sports);
		
		JButton view = new JButton("View");
		view.setLayout(null);
		view.setBounds(120 , 290 , 80 , 30);
		frame.add(view);
		
		JButton cncl = new JButton("Cancel");
		cncl.setLayout(null);
		cncl.setBounds(250 , 290 , 80 , 30);
		frame.add(cncl);
		
		frame.setLayout(null);	
		
		frame.setSize(130, 600);
		frame.setSize(1370, 700);
    }
    
    void removeStock()
    {
    	JLabel stkID = new JLabel("Stock ID: ");
    	stkID.setLayout(null);
    	stkID.setBounds(500 , 250 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(650 , 255 , 90 , 20);
		frame.add(stkID);
		frame.add(id);
		
		JButton remove = new JButton("Remove");
		remove.setLayout(null);
		remove.setBounds(580 , 350 , 100 , 50);
		frame.setLayout(null);
		
		frame.add(remove);
		
		frame.setLayout(null);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    }
    
    void updateStock()
    {
    	JLabel stkID = new JLabel("Stock ID: ");
    	stkID.setLayout(null);
    	stkID.setBounds(500 , 250 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(650 , 255 , 90 , 20);
		frame.add(stkID);
		frame.add(id);
		
		JButton remove = new JButton("Update");
		remove.setLayout(null);
		remove.setBounds(580 , 350 , 100 , 50);
		frame.setLayout(null);
		
		frame.add(remove);
		
		frame.setLayout(null);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    }
    
    void viewStock()
    {
    	JLabel desc = new JLabel("Atleast fill one of the Entry Below");
    	desc.setLayout(null);
    	desc.setBounds(400 , 90 , 400 , 20);
    	
    	frame.add(desc);
    	
    	JLabel stockID = new JLabel("Stock ID: ");
    	stockID.setLayout(null);
    	stockID.setBounds(100 , 150 , 90 , 20);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(190 , 152 , 90 , 20);
		frame.add(stockID);
		frame.add(id);
		
		JLabel itemName = new JLabel("Item Name:");
		itemName.setLayout(null);
		itemName.setBounds(100 , 190 , 90 , 20);
    	JTextField itid = new JTextField(10);
    	itid.setLayout(null);
		itid.setBounds(190 , 192 , 90 , 20);
		frame.add(itemName);
		frame.add(itid);
		
		JLabel itemPrice = new JLabel("Item Price:");
		itemPrice.setLayout(null);
		itemPrice.setBounds(100 , 230 , 90 , 20);
    	JTextField price = new JTextField(10);
    	price.setLayout(null);
    	price.setBounds(190 , 232 , 90 , 20);
		frame.add(itemPrice);
		frame.add(price);
		
		JLabel itemQuantity = new JLabel("ItemQuantity:");
		itemQuantity.setLayout(null);
		itemQuantity.setBounds(100 , 270 , 90 , 20);
    	JTextField qty = new JTextField(10);
    	qty.setLayout(null);
		qty.setBounds(190 , 272 , 90 , 20);
		frame.add(itemQuantity);
		frame.add(qty);
		
		JLabel department = new JLabel("Stock of Department: ");
    	department.setLayout(null);
    	department.setBounds(100 , 311 , 150 , 30);
		
    	frame.add(department);
    	
		JCheckBox cosmetics = new JCheckBox("Cosmetics");
		cosmetics.setSelected(true);
		cosmetics.setLayout(null);
		cosmetics.setBounds(250 , 315 , 90 , 20);
		
		frame.add(cosmetics);
    	
		JCheckBox medicine = new JCheckBox("Medicine");
		medicine.setSelected(true);
    	medicine.setLayout(null);
    	medicine.setBounds(340 , 315 , 90 , 20);
    	
    	frame.add(medicine);
    	
    	JCheckBox food = new JCheckBox("Food");
    	food.setSelected(true);
    	food.setLayout(null);
    	food.setBounds(430 , 315 , 90 , 20);
    	
    	frame.add(food);
    	
    	JCheckBox grocery = new JCheckBox("Grocery");
    	grocery.setSelected(true);
    	grocery.setLayout(null);
    	grocery.setBounds(520 , 315 , 90 , 20);
    	
    	frame.add(grocery);
    	
    	JCheckBox clothing = new JCheckBox("Clothing");
    	clothing.setSelected(true);
    	clothing.setLayout(null);
    	clothing.setBounds(610 , 315 , 90 , 20);
    	
    	frame.add(clothing);
    	
    	JCheckBox electronics = new JCheckBox("Electronics");
    	electronics.setSelected(true);
    	electronics.setLayout(null);
    	electronics.setBounds(700 , 315 , 90 , 20);
    	
    	frame.add(electronics);
    	
    	JCheckBox sports = new JCheckBox("Sports");
    	sports.setSelected(true);
    	sports.setLayout(null);
    	sports.setBounds(790 , 315 , 90 , 20);
    	
    	frame.add(sports);
		
		JButton view = new JButton("View");
		view.setLayout(null);
		view.setBounds(120 , 390 , 80 , 30);
		frame.add(view);
		
		JButton cncl = new JButton("Cancel");
		cncl.setLayout(null);
		cncl.setBounds(250 , 390 , 80 , 30);
		frame.add(cncl);
		
		frame.setLayout(null);	
		
		frame.setSize(130, 600);
		frame.setSize(1370, 700);
    }
    
    void addStock()
    {
    	JLabel stockID = new JLabel("Stock ID: ");
    	stockID.setLayout(null);
    	stockID.setBounds(100 , 150 , 90 , 20);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(190 , 152 , 90 , 20);
		frame.add(stockID);
		frame.add(id);
		
		JLabel itemName = new JLabel("Item Name:");
		itemName.setLayout(null);
		itemName.setBounds(100 , 190 , 90 , 20);
    	JTextField itid = new JTextField(10);
    	itid.setLayout(null);
		itid.setBounds(190 , 192 , 90 , 20);
		frame.add(itemName);
		frame.add(itid);
		
		JLabel itemPrice = new JLabel("Item Price:");
		itemPrice.setLayout(null);
		itemPrice.setBounds(100 , 230 , 90 , 20);
    	JTextField price = new JTextField(10);
    	price.setLayout(null);
    	price.setBounds(190 , 232 , 90 , 20);
		frame.add(itemPrice);
		frame.add(price);
		
		JLabel itemQuantity = new JLabel("ItemQuantity:");
		itemQuantity.setLayout(null);
		itemQuantity.setBounds(100 , 270 , 90 , 20);
    	JTextField qty = new JTextField(10);
    	qty.setLayout(null);
		qty.setBounds(190 , 272 , 90 , 20);
		frame.add(itemQuantity);
		frame.add(qty);
		
		JLabel department = new JLabel("Stock of Department: ");
    	department.setLayout(null);
    	department.setBounds(100 , 311 , 150 , 30);
		
    	frame.add(department);
    	
		JRadioButton cosmetics = new JRadioButton("Cosmetics");
		cosmetics.setLayout(null);
		cosmetics.setBounds(250 , 315 , 90 , 20);
		
		frame.add(cosmetics);
    	
    	JRadioButton medicine = new JRadioButton("Medicine");
    	medicine.setLayout(null);
    	medicine.setBounds(340 , 315 , 90 , 20);
    	
    	frame.add(medicine);
    	
    	JRadioButton food = new JRadioButton("Food");
    	food.setLayout(null);
    	food.setBounds(430 , 315 , 90 , 20);
    	
    	frame.add(food);
    	
    	JRadioButton grocery = new JRadioButton("Grocery");
    	grocery.setLayout(null);
    	grocery.setBounds(520 , 315 , 90 , 20);
    	
    	frame.add(grocery);
    	
    	JRadioButton clothing = new JRadioButton("Clothing");
    	clothing.setLayout(null);
    	clothing.setBounds(610 , 315 , 90 , 20);
    	
    	frame.add(clothing);
    	
    	JRadioButton electronics = new JRadioButton("Electronics");
    	electronics.setLayout(null);
    	electronics.setBounds(700 , 315 , 90 , 20);
    	
    	frame.add(electronics);
    	
    	JRadioButton sports = new JRadioButton("Sports");
    	sports.setLayout(null);
    	sports.setBounds(790 , 315 , 90 , 20);
    	
    	frame.add(sports);
    	
    	
    	ButtonGroup dept = new ButtonGroup();
    	dept.add(cosmetics);
    	dept.add(medicine);
    	dept.add(food);
    	dept.add(grocery);
    	dept.add(electronics);
    	dept.add(clothing);
    	dept.add(sports);
		
		JButton add = new JButton("Add");
		add.setLayout(null);
		add.setBounds(120 , 390 , 80 , 30);
		frame.add(add);
		
		JButton cncl = new JButton("Cancel");
		cncl.setLayout(null);
		cncl.setBounds(250 , 390 , 80 , 30);
		frame.add(cncl);
		
		frame.setLayout(null);	
		
		frame.setSize(130, 600);
		frame.setSize(1370, 700);
    }
    
    void removeCustomer()
    {
//    	frame = new JFrame();
//   	 frame.setTitle("DSMS-Departmental Store Management System");
//   	frame.setSize(1370, 700);
   	
   	
    	
    	dialog = new JDialog(frame);
    	//dialog.setVisible(true);
    	dialog.setTitle("Remove Customer");
    	dialog.setSize(1000 , 700);
    	
    	JLabel custID = new JLabel("Customer ID: ");
    	custID.setLayout(null);
    	custID.setBounds(500 , 250 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(650 , 257 , 90 , 20);
		frame.add(custID);
		frame.add(id);
		
		JButton remove = new JButton("Remove");
		remove.setLayout(null);
		remove.setBounds(580 , 350 , 100 , 50);
		//setLayout(null);
		
		frame.add(remove);

		frame.setLayout(null);	
		
		frame.setSize(130, 600);
		frame.setSize(1370, 700);
    }
    
    void updateCustomer()
    {
    	JLabel custID = new JLabel("Customer ID: ");
    	custID.setLayout(null);
    	custID.setBounds(500 , 250 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(650 , 257 , 90 , 20);
		frame.add(custID);
		frame.add(id);
		
		JButton remove = new JButton("Update");
		remove.setLayout(null);
		remove.setBounds(580 , 350 , 100 , 50);
		//setLayout(null);
		
		frame.add(remove);

		frame.setLayout(null);	
		
		frame.setSize(130, 600);
		frame.setSize(1370, 700);
    }
    
    void viewCustomer()
    {
//    	frame = new JDialog(this);
//    	frame.setVisible(true);
//    	frame.setSize(1000 , 700);
    	
//    	frame = new JFrame();
//    	frame.setVisible(true);
//    	frame.setTitle("DSMS-Departmental Store Managment System");
//    	 initUI();
//    	 frame.setSize(1370 , 700);
//    	 frame.setLocation(0, 20);         
//    	 frame.setVisible(true); 
    	
    	JButton viewAll = new JButton("View All");
    	viewAll.setLayout(null);
    	viewAll.setBounds(1000 , 50 , 100 , 40);
		
    	frame.add(viewAll);
    	
    	JLabel desc = new JLabel("Atleast fill one of the Entry Below");
    	desc.setLayout(null);
    	desc.setBounds(500 , 70 , 500 , 30);
    	frame.add(desc);
    	
    	JLabel full = new JLabel("Customer Name: ");
    	full.setLayout(null);
    	full.setBounds(100 , 121 , 150 , 30);
    	JTextField fname = new JTextField(10);
    	fname.setLayout(null);
		fname.setBounds(250 , 129 , 90 , 20);
		frame.add(fname);
		frame.add(full);
		
		JLabel custID = new JLabel("Customer ID: ");
		custID.setLayout(null);
		custID.setBounds(100 , 90 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(250 , 98 , 90 , 20);
		frame.add(custID);
		frame.add(id);
		
		JButton ok = new JButton("View");
    	ok.setLayout(null);
		ok.setBounds(100 , 250 , 70 , 40);
		
		frame.add(ok);
		
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(400 , 250 , 90 , 40);
		
		frame.add(cncl);
    	
		frame.setLayout(null);
		
		frame.setSize(130, 600);
		frame.setSize(1370, 700);
    }
    
    void addCustomer()
    {
    	JLabel custID = new JLabel("Customer ID: ");
    	custID.setLayout(null);
    	custID.setBounds(100 , 59 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(250 , 67 , 90 , 20);
		frame.add(custID);
		frame.add(id);
    	
    	JLabel first = new JLabel("First Name: ");
    	first.setLayout(null);
    	first.setBounds(100 , 104 , 150 , 30);
    	JTextField fname = new JTextField(10);
    	fname.setLayout(null);
		fname.setBounds(250 , 112 , 90 , 20);
		frame.add(fname);
		frame.add(first);
		
		JLabel last = new JLabel("Last Name: ");
		last.setLayout(null);
		last.setBounds(100 , 149 , 150 , 30);
    	JTextField lname = new JTextField(10);
    	lname.setLayout(null);
		lname.setBounds(250 , 157 , 90 , 20);
		frame.add(lname);
		frame.add(last);
		
		JLabel creditID = new JLabel("Credit ID: ");
		creditID.setLayout(null);
		creditID.setBounds(100 , 194 , 150 , 30);
    	JTextField cid = new JTextField(10);
    	cid.setLayout(null);
		cid.setBounds(250 , 202 , 90 , 20);
		frame.add(creditID);
		frame.add(cid);
		
		JButton ok = new JButton("Add");
    	ok.setLayout(null);
		ok.setBounds(110 , 260 , 70 , 30);
		
		frame.add(ok);
		
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(340 , 260 , 90 , 30);
		
		frame.add(cncl);
		
		JButton frgt = new JButton("Forgot Your Password?");
    	frgt.setLayout(null);
		frgt.setBounds(535 , 330 , 0 , 0);
		frame.setLayout(null);
		
		frame.add(frgt);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    }
    
    void removeSupp()
    {
    	JLabel suppID = new JLabel("Supplier ID: ");
    	suppID.setLayout(null);
    	suppID.setBounds(500 , 250 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(650 , 257 , 90 , 20);
		frame.add(suppID);
		frame.add(id);
		
		JButton remove = new JButton("Remove");
		remove.setLayout(null);
		remove.setBounds(580 , 350 , 100 , 50);
		frame.setLayout(null);
		
		frame.add(remove);
		
		JButton frgt = new JButton("Forgot Your Password?");
    	frgt.setLayout(null);
		frgt.setBounds(535 , 330 , 0 , 0);
		frame.setLayout(null);
		
		frame.add(frgt);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    }
    
    void updateSupp()
    {
    	JLabel suppID = new JLabel("Supplier ID: ");
    	suppID.setLayout(null);
    	suppID.setBounds(500 , 250 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(650 , 257 , 90 , 20);
		frame.add(suppID);
		frame.add(id);
		
		JButton remove = new JButton("Update");
		remove.setLayout(null);
		remove.setBounds(580 , 350 , 100 , 50);
		frame.setLayout(null);
		
		frame.add(remove);
		
		frame.setLayout(null);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    }
    
    void viewSupp()
    {
    	JButton viewAll = new JButton("View All");
    	viewAll.setLayout(null);
    	viewAll.setBounds(1000 , 50 , 100 , 40);
		
    	frame.add(viewAll);
    	
    	JLabel desc = new JLabel("Atleast fill one of the Entry Below");
    	desc.setLayout(null);
    	desc.setBounds(500 , 70 , 500 , 30);
    	frame.add(desc);
    	
    	JLabel full = new JLabel("Supplier Name: ");
    	full.setLayout(null);
    	full.setBounds(100 , 121 , 150 , 30);
    	JTextField fname = new JTextField(10);
    	fname.setLayout(null);
		fname.setBounds(250 , 129 , 90 , 20);
		frame.add(fname);
		frame.add(full);
		
		JLabel suppID = new JLabel("Supplier ID: ");
		suppID.setLayout(null);
		suppID.setBounds(100 , 90 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(250 , 98 , 90 , 20);
		frame.add(suppID);
		frame.add(id);
		
		JLabel stid = new JLabel("Stock ID: ");
		stid.setLayout(null);
		stid.setBounds(100 , 151 , 150 , 30);
    	JTextField stockID = new JTextField(10);
    	stockID.setLayout(null);
    	stockID.setBounds(250 , 159 , 90 , 20);
    	frame.add(stockID);
    	frame.add(stid);
		
		JButton ok = new JButton("View");
    	ok.setLayout(null);
		ok.setBounds(100 , 250 , 70 , 40);
		
		frame.add(ok);
		
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(400 , 250 , 90 , 40);
		
		frame.add(cncl);
    	
    	JButton frgt = new JButton("Forgot Your Password?");
    	frgt.setLayout(null);
		frgt.setBounds(535 , 330 , 0 , 0);
		frame.setLayout(null);
		
		frame.add(frgt);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    }
    
    void addSupp()
    {
    	JLabel suppID = new JLabel("Supplier ID: ");
		suppID.setLayout(null);
		suppID.setBounds(100 , 59 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(250 , 67 , 90 , 20);
		frame.add(suppID);
		frame.add(id);
    	
    	JLabel full = new JLabel("Name: ");
    	full.setLayout(null);
    	full.setBounds(100 , 100 , 150 , 50);
    	JTextField fname = new JTextField(15);
    	fname.setLayout(null);
		fname.setBounds(250 , 113 , 140 , 20);
		frame.add(fname);
		frame.add(full);
		
		JLabel stockID = new JLabel("Stock ID: ");
		stockID.setLayout(null);
		stockID.setBounds(100 , 150 , 150 , 30);
    	JTextField stid = new JTextField(10);
    	stid.setLayout(null);
		stid.setBounds(250 , 157 , 90 , 20);
		frame.add(stockID);
		frame.add(stid);
		
		JButton ok = new JButton("Add");
    	ok.setLayout(null);
		ok.setBounds(170 , 280 , 70 , 40);
		
		frame.add(ok);
		
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(270 , 280 , 100 , 40);
		
		frame.add(cncl);
		
		JButton frgt = new JButton("Forgot Your Password?");
    	frgt.setLayout(null);
		frgt.setBounds(535 , 330 , 0 , 0);
		frame.setLayout(null);
		
		frame.add(frgt);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
		
    }
    
    void removeEmp()
    {
    	JLabel empID = new JLabel("Employee ID: ");
		empID.setLayout(null);
		empID.setBounds(500 , 250 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(650 , 257 , 90 , 20);
		frame.add(empID);
		frame.add(id);
		
		JButton remove = new JButton("Remove");
		remove.setLayout(null);
		remove.setBounds(580 , 350 , 100 , 50);
		frame.setLayout(null);
		
		frame.add(remove);
		
		JButton frgt = new JButton("Forgot Your Password?");
    	frgt.setLayout(null);
		frgt.setBounds(535 , 330 , 0 , 0);
		frame.setLayout(null);
		
		frame.add(frgt);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
		
    }
    
    void updateEmp()
    {
    	JLabel empID = new JLabel("Employee ID: ");
    	empID.setLayout(null);
    	empID.setBounds(500 , 250 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(650 , 257 , 90 , 20);
		frame.add(empID);
		frame.add(id);
		
		JButton remove = new JButton("Update");
		remove.setLayout(null);
		remove.setBounds(580 , 350 , 100 , 50);
		frame.setLayout(null);
		
		frame.add(remove);
		
		JButton frgt = new JButton("Forgot Your Password?");
    	frgt.setLayout(null);
		frgt.setBounds(535 , 330 , 0 , 0);
		frame.setLayout(null);
		
		frame.add(frgt);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    	
//    	JButton updateName = new JButton("Update Name of Employee");
//    	updateName.setLayout(null);
//    	updateName.setBounds(500 , 50 , 300 , 40);
//		
//    	frame.add(updateName);
//		
//		JButton updateSalary = new JButton("Update Salary of Employee");
//    	updateSalary.setLayout(null);
//		updateSalary.setBounds(500 , 150 , 300 , 40);
//		
//		frame.add(updateSalary);
//		
//		JButton updateAddress = new JButton("Update Address of Employee");
//		updateAddress.setLayout(null);
//		updateAddress.setBounds(500 , 250 , 300 , 40);
//		
//		frame.add(updateAddress);
//		
//		JButton updateCity = new JButton("Update City of Employee");
//		updateCity.setLayout(null);
//		updateCity.setBounds(500 , 350 , 300 , 40);
//		
//		frame.add(updateCity);
//		
//		JButton updateDept = new JButton("Update Department of Employee");
//		updateDept.setLayout(null);
//		updateDept.setBounds(500 , 450 , 300 , 40);
//		
//		frame.add(updateDept);
//		
//		JButton updateCtg = new JButton("Update Employee Catagorey");
//		updateCtg.setLayout(null);
//		updateCtg.setBounds(500 , 550 , 300 , 40);
//		
//		frame.add(updateCtg);
//		
//		JButton frgt = new JButton("Forgot Your Password?");
//    	frgt.setLayout(null);
//		frgt.setBounds(535 , 330 , 0 , 0);
//		frame.setLayout(null);
//		
//		frame.add(frgt);
//		
//		frame.setSize(1400, 1400);
//		frame.setSize(1370 , 700);
    }
    
    void viewEmp()
    {
    	
    	
    	//initUI();
    	
    	
    	JButton viewAll = new JButton("View All");
    	viewAll.setLayout(null);
    	viewAll.setBounds(1000 , 50 , 100 , 40);
		
    	frame.add(viewAll);
    	
    	JLabel desc = new JLabel("Atleast fill one of the Entry Below");
    	desc.setLayout(null);
    	desc.setBounds(500 , 70 , 500 , 30);
    	frame.add(desc);
    	
    	JLabel full = new JLabel("Employee Name: ");
    	full.setLayout(null);
    	full.setBounds(100 , 90 , 150 , 30);
    	JTextField fname = new JTextField(10);
    	fname.setLayout(null);
		fname.setBounds(250 , 98 , 90 , 20);
		frame.add(fname);
		frame.add(full);
		
		JLabel empID = new JLabel("Employee ID: ");
		empID.setLayout(null);
		empID.setBounds(100 , 121 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(250 , 129 , 90 , 20);
		frame.add(empID);
		frame.add(id);
		
		JLabel hireDate = new JLabel("Hire Date: ");
		hireDate.setLayout(null);
		hireDate.setBounds(100 , 171 , 150 , 30);
		
		frame.add(hireDate);
		
		JLabel hDay = new JLabel("DD");
		hDay.setLayout(null);
		hDay.setBounds(250 , 191 , 60 , 30);
		JTextField day = new JTextField(2);
    	day.setLayout(null);
		day.setBounds(250 , 176 , 20 , 20);
		JLabel hMon = new JLabel("MM");
		hMon.setLayout(null);
		hMon.setBounds(310 , 191 , 60 , 30);
		JTextField month = new JTextField(2);
    	month.setLayout(null);
		month.setBounds(310 , 176 , 20 , 20);
		JLabel hYear = new JLabel("YYYY");
		hYear.setLayout(null);
		hYear.setBounds(390 , 191 , 60 , 30);
		JTextField year = new JTextField(2);
    	year.setLayout(null);
		year.setBounds(390 , 176 , 35 , 20);
		
		frame.add(hDay);
		frame.add(day);
		frame.add(hMon);
		frame.add(month);
		frame.add(hYear);
		frame.add(year);
		
		JLabel salary = new JLabel("Salary: ");
		salary.setLayout(null);
		salary.setBounds(100 , 221 , 150 , 30);
		JTextField sal = new JTextField(2);
    	sal.setLayout(null);
		sal.setBounds(250 , 225 , 90 , 20);
		
		frame.add(salary);
		frame.add(sal);
		
		JLabel city = new JLabel("City: ");
		city.setLayout(null);
		city.setBounds(100 , 281 , 150 , 30);
		JTextField tCity = new JTextField(2);
    	tCity.setLayout(null);
		tCity.setBounds(250 , 286 , 90 , 20);
		
		frame.add(tCity);
		frame.add(city);
		
    	JLabel department = new JLabel("Hiring Department: ");
    	department.setLayout(null);
    	department.setBounds(100 , 311 , 150 , 30);
		
    	frame.add(department);
    	
		JRadioButton cosmetics = new JRadioButton("Cosmetics");
		cosmetics.setLayout(null);
		cosmetics.setBounds(250 , 315 , 90 , 20);
		
		frame.add(cosmetics);
    	
    	JRadioButton medicine = new JRadioButton("Medicine");
    	medicine.setLayout(null);
    	medicine.setBounds(340 , 315 , 90 , 20);
    	
    	frame.add(medicine);
    	
    	JRadioButton food = new JRadioButton("Food");
    	food.setLayout(null);
    	food.setBounds(430 , 315 , 90 , 20);
    	
    	frame.add(food);
    	
    	JRadioButton grocery = new JRadioButton("Grocery");
    	grocery.setLayout(null);
    	grocery.setBounds(520 , 315 , 90 , 20);
    	
    	frame.add(grocery);
    	
    	JRadioButton clothing = new JRadioButton("Clothing");
    	clothing.setLayout(null);
    	clothing.setBounds(610 , 315 , 90 , 20);
    	
    	frame.add(clothing);
    	
    	JRadioButton electronics = new JRadioButton("Electronics");
    	electronics.setLayout(null);
    	electronics.setBounds(700 , 315 , 90 , 20);
    	
    	frame.add(electronics);
    	
    	JRadioButton sports = new JRadioButton("Sports");
    	sports.setLayout(null);
    	sports.setBounds(790 , 315 , 90 , 20);
    	
    	frame.add(sports);
    	
    	
    	ButtonGroup dept = new ButtonGroup();
    	dept.add(cosmetics);
    	dept.add(medicine);
    	dept.add(food);
    	dept.add(grocery);
    	dept.add(electronics);
    	dept.add(clothing);
    	dept.add(sports);
    	
		JLabel catagorey = new JLabel("Employee Catagorey:");
    	catagorey.setLayout(null);
		catagorey.setBounds(100 , 341 , 150 , 30);
    	JRadioButton mgr = new JRadioButton("Manager");
    	mgr.setLayout(null);
		mgr.setBounds(250 , 345 , 90 , 20);
    	
		frame.add(catagorey);
		frame.add(mgr);
		
    	JRadioButton cashier = new JRadioButton("Cashier");
    	cashier.setLayout(null);
    	cashier.setBounds(340 , 345 , 90 , 20);
    	
    	frame.add(cashier);
    	
    	JButton ok = new JButton("View");
    	ok.setLayout(null);
		ok.setBounds(100 , 400 , 70 , 40);
		
		frame.add(ok);
		
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(800 , 400 , 90 , 40);
		
		frame.add(cncl);
    	
    	JButton frgt = new JButton("Forgot Your Password?");
    	frgt.setLayout(null);
		frgt.setBounds(535 , 330 , 0 , 0);
		frame.setLayout(null);
		
		frame.add(frgt);
    	
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    }
    
    void addEmp()
    {
    	JLabel empID = new JLabel("*  Employee ID: ");
		empID.setLayout(null);
		empID.setBounds(90 , 59 , 150 , 30);
    	JTextField id = new JTextField(10);
    	id.setLayout(null);
		id.setBounds(250 , 67 , 90 , 20);
		frame.add(empID);
		frame.add(id);
    	
    	JLabel first = new JLabel("*  First Name: ");
    	first.setLayout(null);
    	first.setBounds(90 , 90 , 150 , 30);
    	JTextField fname = new JTextField(10);
    	fname.setLayout(null);
		fname.setBounds(250 , 98 , 90 , 20);
		frame.add(fname);
		frame.add(first);
		
		JLabel last = new JLabel("*  Last Name: ");
		last.setLayout(null);
		last.setBounds(90 , 135 , 150 , 30);
    	JTextField lname = new JTextField(10);
    	lname.setLayout(null);
		lname.setBounds(250 , 143 , 90 , 20);
		frame.add(lname);
		frame.add(last);
		
		JLabel hireDate = new JLabel("*  Hire Date: ");
		hireDate.setLayout(null);
		hireDate.setBounds(90 , 171 , 150 , 30);
		
		frame.add(hireDate);
		
		JLabel hDay = new JLabel("DD");
		hDay.setLayout(null);
		hDay.setBounds(250 , 191 , 60 , 30);
		JTextField day = new JTextField(2);
    	day.setLayout(null);
		day.setBounds(250 , 176 , 20 , 20);
		JLabel hMon = new JLabel("MM");
		hMon.setLayout(null);
		hMon.setBounds(310 , 191 , 60 , 30);
		JTextField month = new JTextField(2);
    	month.setLayout(null);
		month.setBounds(310 , 176 , 20 , 20);
		JLabel hYear = new JLabel("YYYY");
		hYear.setLayout(null);
		hYear.setBounds(390 , 191 , 60 , 30);
		JTextField year = new JTextField(2);
    	year.setLayout(null);
		year.setBounds(390 , 176 , 35 , 20);
		
		frame.add(hDay);
		frame.add(day);
		frame.add(hMon);
		frame.add(month);
		frame.add(hYear);
		frame.add(year);
		
		JLabel salary = new JLabel("*  Salary: ");
		salary.setLayout(null);
		salary.setBounds(90 , 221 , 150 , 30);
		JTextField sal = new JTextField(2);
    	sal.setLayout(null);
		sal.setBounds(250 , 225 , 90 , 20);
		
		frame.add(salary);
		frame.add(sal);
		
		JLabel addr = new JLabel("Address: ");
		addr.setLayout(null);
		addr.setBounds(100 , 251 , 150 , 30);
		JTextField address = new JTextField(2);
    	address.setLayout(null);
		address.setBounds(250 , 256 , 450 , 20);
		
		frame.add(addr);
		frame.add(address);
		
		JLabel city = new JLabel("*  City: ");
		city.setLayout(null);
		city.setBounds(90 , 281 , 150 , 30);
		JTextField tCity = new JTextField(2);
    	tCity.setLayout(null);
		tCity.setBounds(250 , 286 , 90 , 20);
		
		frame.add(tCity);
		frame.add(city);
		
    	JLabel department = new JLabel("*  Hiring Department: ");
    	department.setLayout(null);
    	department.setBounds(90 , 311 , 150 , 30);
		
    	frame.add(department);
    	
		JRadioButton cosmetics = new JRadioButton("Cosmetics");
		cosmetics.setLayout(null);
		cosmetics.setBounds(250 , 315 , 90 , 20);
		
		frame.add(cosmetics);
    	
    	JRadioButton medicine = new JRadioButton("Medicine");
    	medicine.setLayout(null);
    	medicine.setBounds(340 , 315 , 90 , 20);
    	
    	frame.add(medicine);
    	
    	JRadioButton food = new JRadioButton("Food");
    	food.setLayout(null);
    	food.setBounds(430 , 315 , 90 , 20);
    	
    	frame.add(food);
    	
    	JRadioButton grocery = new JRadioButton("Grocery");
    	grocery.setLayout(null);
    	grocery.setBounds(520 , 315 , 90 , 20);
    	
    	frame.add(grocery);
    	
    	JRadioButton clothing = new JRadioButton("Clothing");
    	clothing.setLayout(null);
    	clothing.setBounds(610 , 315 , 90 , 20);
    	
    	frame.add(clothing);
    	
    	JRadioButton electronics = new JRadioButton("Electronics");
    	electronics.setLayout(null);
    	electronics.setBounds(700 , 315 , 90 , 20);
    	
    	frame.add(electronics);
    	
    	JRadioButton sports = new JRadioButton("Sports");
    	sports.setLayout(null);
    	sports.setBounds(790 , 315 , 90 , 20);
    	
    	frame.add(sports);
    	
    	
    	ButtonGroup dept = new ButtonGroup();
    	dept.add(cosmetics);
    	dept.add(medicine);
    	dept.add(food);
    	dept.add(grocery);
    	dept.add(electronics);
    	dept.add(clothing);
    	dept.add(sports);
    	
		JLabel catagorey = new JLabel("*  Employee Catagorey:");
    	catagorey.setLayout(null);
		catagorey.setBounds(90 , 341 , 150 , 30);
    	JRadioButton mgr = new JRadioButton("Manager");
    	mgr.setLayout(null);
		mgr.setBounds(250 , 345 , 90 , 20);
    	
		frame.add(catagorey);
		frame.add(mgr);
		
    	JRadioButton cashier = new JRadioButton("Cashier");
    	cashier.setLayout(null);
    	cashier.setBounds(340 , 345 , 90 , 20);
    	
    	frame.add(cashier);
    	
    	JButton ok = new JButton("Add");
    	ok.setLayout(null);
		ok.setBounds(100 , 400 , 70 , 40);
		
		frame.add(ok);
		
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(800 , 400 , 90 , 40);
		
		frame.add(cncl);
		
		JButton frgt = new JButton("Forgot Your Password?");
    	frgt.setLayout(null);
		frgt.setBounds(535 , 330 , 0 , 0);
		frame.setLayout(null);
		
		frame.add(frgt);
		
		ButtonGroup ctg = new ButtonGroup();
		ctg.add(mgr);
		ctg.add(cashier);
		
		frame.setSize(1400, 1400);
		frame.setSize(1370 , 700);
    }

    private void initUI() {

        JMenuBar menubar = new JMenuBar();
       //ImageIcon icon = new ImageIcon("exit.png");

        JMenu file = new JMenu("File");
        JMenuItem exit = new JMenuItem("Exit");
        exit.setToolTipText("Exit application");
        exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                System.exit(0);
            }
        });
        JMenuItem save = new JMenuItem("Save All");
        save.setToolTipText("Save all your Work");
        save.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                System.exit(0);
            }
        });
        file.add(save);
        file.add(exit);
        
        JMenu employee = new JMenu("Employee");
        JMenuItem addEmployee = new JMenuItem("Add Employee");
        addEmployee.setToolTipText("Add a New Employee");
        addEmployee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
            	addEmp();
            }
        });
        JMenuItem viewEmployee = new JMenuItem("View Employee Detail");
        viewEmployee.setToolTipText("View Existing Employees Detail");
        viewEmployee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
            	viewEmp();
            }
        });
        JMenuItem updateEmployee = new JMenuItem("Update Employee");
        updateEmployee.setToolTipText("Update an Existing Employee Detail");
        updateEmployee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                updateEmp();
            }
        });
        JMenuItem removeEmployee = new JMenuItem("Remove Employee");
        removeEmployee.setToolTipText("Remove an Existing Employee");
        removeEmployee.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                removeEmp();
            }
        });
        employee.add(addEmployee);
        employee.add(viewEmployee);
        employee.add(updateEmployee);
        employee.add(removeEmployee);
        
        JMenu purchase = new JMenu("Purchase");
        JMenuItem viewPurchase = new JMenuItem("View Purchase");
        viewPurchase.setToolTipText("View Your Purchases");
        viewPurchase.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                viewPurchase();
            }
        });
        purchase.add(viewPurchase);
        
        JMenu sale = new JMenu("Sale");
        JMenuItem viewSale = new JMenuItem("View Sale");
        viewSale.setToolTipText("View Your Sales");
        viewSale.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                viewSale();
            }
        });
        sale.add(viewSale);
        
        JMenu invoice = new JMenu("Invoice");
        JMenuItem generateInvoice = new JMenuItem("Generate Invoice");
        generateInvoice.setToolTipText("Generate a New Invoice");
        generateInvoice.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                generateInvoice();
            }
        });
        JMenuItem viewInvoice = new JMenuItem("View Invoice");
        viewInvoice.setToolTipText("View Your Invoices");
        viewInvoice.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                viewInvoice();
            }
        });
        invoice.add(generateInvoice);
        invoice.add(viewInvoice);
        
        JMenu department = new JMenu("Department");
        JMenuItem viewDepartment = new JMenuItem("View Department");
        viewDepartment.setToolTipText("View Your Departments");
        viewDepartment.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                viewDepartment();
            }
        });
        department.add(viewDepartment);
        
        JMenu stock = new JMenu("Stock");
        JMenuItem addStock = new JMenuItem("Add Stock");
        addStock.setToolTipText("Add a new Stock to your Department");
        addStock.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                addStock();
            }
        });
        JMenuItem viewStock = new JMenuItem("View Stock");
        viewStock.setToolTipText("View Existing Stock of your Department");
        viewStock.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
            	viewStock();
            }
        });
        JMenuItem updateStock = new JMenuItem("Update Stock");
        updateStock.setToolTipText("Update your Existing Stock of a Department");
        updateStock.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
            	updateStock();
            }
        });
        JMenuItem removeStock = new JMenuItem("Remove Stock");
        removeStock.setToolTipText("Remove an Existing Stock of your Department");
        removeStock.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
            	removeStock();
            }
        });
        stock.add(addStock);
        stock.add(viewStock);
        stock.add(updateStock);
        stock.add(removeStock);
        
        JMenu supplier = new JMenu("Supplier");
        JMenuItem addSupplier = new JMenuItem("Add Supplier");
        addSupplier.setToolTipText("Add a new Supplier");
        addSupplier.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                addSupp();
            }
        });
        JMenuItem viewSupplier = new JMenuItem("View Supplier");
        viewSupplier.setToolTipText("View Existing Suppliers");
        viewSupplier.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                viewSupp();
            }
        });
        JMenuItem updateSupplier = new JMenuItem("Update Supplier");
        updateSupplier.setToolTipText("Update Existing Suppliers");
        updateSupplier.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                updateSupp();
            }
        });
        JMenuItem removeSupplier = new JMenuItem("Remove Supplier");
        removeSupplier.setToolTipText("Remove an Existing Supplier");
        removeSupplier.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                removeSupp();
            }
        });
        supplier.add(addSupplier);
        supplier.add(viewSupplier);
        supplier.add(updateSupplier);
        supplier.add(removeSupplier);
        
        JMenu pos = new JMenu("POS");
        JMenuItem viewPos = new JMenuItem("View POS");
        viewPos.setToolTipText("View your Point Of Sales");
        viewPos.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                viewPOS();
            }
        });
        pos.add(viewPos);
        
        JMenu customer = new JMenu("Customer");
        JMenuItem addCustomer = new JMenuItem("Add Customer");
        addCustomer.setToolTipText("Register a new Customer");
        addCustomer.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                addCustomer();
            }
        });
        JMenuItem viewCustomer = new JMenuItem("View Customer");
        viewCustomer.setToolTipText("View Registered Customer Details");
        viewCustomer.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
            	viewCustomer();
            }
        });
        JMenuItem updateCustomer = new JMenuItem("Update Customer");
        updateCustomer.setToolTipText("Update a Registered Customer Detail");
        updateCustomer.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
            	updateCustomer();
            }
        });
        JMenuItem removeCustomer = new JMenuItem("Remove Customer");
        removeCustomer.setToolTipText("Remove a Registered Customer");
        removeCustomer.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.revalidate();
            	frame.repaint();
            	removeCustomer();
            }
        });
        customer.add(addCustomer);
        customer.add(viewCustomer);
        customer.add(updateCustomer);
        customer.add(removeCustomer);
        
        JMenu transaction = new JMenu("Transaction");
        JMenuItem addTransaction = new JMenuItem("Add Transaction");
        addTransaction.setToolTipText("Add a new Transaction to POS");
        addTransaction.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                addTransaction();
            }
        });
        JMenuItem viewTransaction = new JMenuItem("View Transaction");
        viewTransaction.setToolTipText("View Transactions of a POS");
        viewTransaction.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent event) {
            	frame.getContentPane().removeAll();
            	frame.validate();
            	frame.repaint();
                viewTransaction();
            }
        });
        transaction.add(addTransaction);
        transaction.add(viewTransaction);
        
        file.setMnemonic(KeyEvent.VK_F);
        
        exit.setMnemonic(KeyEvent.VK_E);
        

        menubar.add(file);
        menubar.add(employee);
        menubar.add(purchase);
        menubar.add(sale);
        menubar.add(invoice);
        menubar.add(department);
        menubar.add(stock);
        menubar.add(supplier);
        menubar.add(pos);
        menubar.add(customer);
        menubar.add(transaction);
        frame.setJMenuBar(menubar);


        //setSize(300, 200);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
    

    void loginPage()
    {
    	JDialog loginPage = new JDialog(frame);
    	//loginPage.setModal(true);
    	loginPage.setSize(300 , 300);
    	loginPage.setTitle("Login");
    	//loginPage.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	loginPage.setVisible(true);
    	loginPage.setLocation(550 , 200);
    	
    	
    	JLabel user = new JLabel("User Name: ");
    	user.setLayout(null);
		user.setBounds(70 , 20 , 70 , 20);
    	JTextField name = new JTextField(10);
    	name.setLayout(null);
		name.setBounds(141 , 20 , 90 , 20);
    	JLabel password = new JLabel("Password: ");
    	password.setLayout(null);
		password.setBounds(70 , 50 , 70 , 20);
    	JTextField pass = new JTextField(10);
    	pass.setLayout(null);
		pass.setBounds(141 , 50 , 90 , 20);
    	
    	JRadioButton mgr = new JRadioButton("Manager");
    	mgr.setLayout(null);
		mgr.setBounds(70 , 80 , 130 , 20);
    	
    	JRadioButton admin = new JRadioButton("Cashier");
    	admin.setLayout(null);
		admin.setBounds(70 , 100 , 130 , 20);
    	
    	JButton ok = new JButton("Login");
    	ok.setLayout(null);
		ok.setBounds(70 , 160 , 70 , 20);
		
		JButton cncl = new JButton("Cancel");
    	cncl.setLayout(null);
		cncl.setBounds(160 , 160 , 90 , 20);
		
		JButton frgt = new JButton("Forgot Your Password?");
    	frgt.setLayout(null);
		frgt.setBounds(75 , 200 , 170 , 20);
		loginPage.setLayout(null);
		
		ButtonGroup g = new ButtonGroup();
		g.add(mgr);
		g.add(admin);
		
		loginPage.add(user);
		loginPage.add(name);
		loginPage.add(password);
		loginPage.add(pass);
		loginPage.add(mgr);
		loginPage.add(admin);
		loginPage.add(ok);
		loginPage.add(cncl);
		loginPage.add(frgt);
		
		loginPage.setSize(1400, 1400);
    	loginPage.setSize(300 , 300);

    }
//    
//    static void addSupplierPage()
//    {
//    	JFrame loginPage = new JFrame();
//    	loginPage.setSize(300 , 300);
//    	loginPage.setTitle("Add Supplier");
//    	loginPage.setDefaultCloseOperation(EXIT_ON_CLOSE);
//    	loginPage.setVisible(true);
//    	loginPage.setLocation(550 , 200);
//    	
//    	
//    	JLabel suppID = new JLabel("Supplier ID: ");
//    	suppID.setLayout(null);
//    	suppID.setBounds(50 , 20 , 90 , 20);
//    	JTextField iD = new JTextField(10);
//    	iD.setLayout(null);
//    	iD.setBounds(141 , 20 , 90 , 20);
//    	JLabel suppName = new JLabel("Supplier Name: ");
//    	suppName.setLayout(null);
//    	suppName.setBounds(50 , 50 , 90 , 20);
//    	JTextField name = new JTextField(10);
//    	name.setLayout(null);
//		name.setBounds(141 , 50 , 90 , 20);
//    	    	
//    	JButton ok = new JButton("Add");
//    	ok.setLayout(null);
//		ok.setBounds(70 , 160 , 70 , 20);
//		
//		JButton cncl = new JButton("Cancel");
//    	cncl.setLayout(null);
//		cncl.setBounds(160 , 160 , 90 , 20);
//		
//		loginPage.setLayout(null);
//		
//		
//		loginPage.add(suppID);
//		loginPage.add(iD);
//		loginPage.add(suppName);
//		loginPage.add(name);
//		loginPage.add(ok);
//		loginPage.add(cncl);
//		
//		loginPage.setSize(1400, 1400);
//    	loginPage.setSize(300 , 300);
//
//    }
    
    public static void main(String[] args) {
    	//loginPage();
    	//addSupplierPage();
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                SimpleMenuExample ex = new SimpleMenuExample();
                //ex.setVisible(true);
            }
        });
    }
}