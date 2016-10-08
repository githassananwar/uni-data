import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

 




public class Driver {
	

	public static void main(String args[]){

		JFrame window = new JFrame("Testing") ;
		window.setVisible(true) ;
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE) ;
		window.setSize(300,300) ;
		window.setLayout(new BorderLayout()) ;
		
		final JButton b = new JButton("white") ;
		b.setSize(50, 50) ;
		b.setBackground(Color.cyan) ;
		final JButton b1 = new JButton("black") ;
		b.setSize(50, 50) ;
		
		JPanel p1 = new JPanel() ;
		p1.setLayout(new FlowLayout()) ;
		
		JPanel p2 = new JPanel() ;
		p2.setLayout(new GridLayout(0,2,10,10)) ;
		
		class myButtonActionListener implements ActionListener{
			public void actionPerformed(ActionEvent e) {
				if(e.getActionCommand() == "white"){
					b.setBackground(Color.cyan) ;
				}
				if(e.getActionCommand() == "black"){
					b1.setBackground(Color.green) ;
				}
			}
		}
		
		b.addActionListener(new myButtonActionListener());
		b1.addActionListener(new myButtonActionListener());
		
		JTextField t = new JTextField("Thsi is ", 20) ;
		
		final JRadioButton blue = new JRadioButton("blue") ;
		JRadioButton red = new JRadioButton("red") ;
		
		JCheckBox c1 = new JCheckBox("Bold") ;
		JCheckBox c2 = new JCheckBox("Italoc") ;
		
		class mycheckbuttonListener implements ItemListener{

			public void itemStateChanged(ItemEvent e) {
				if (e.getSource() == blue) {
					System.out.println(e.getSource()) ;
					b.setBackground(Color.black) ;
				}
				else{
					b.setBackground(Color.red) ;
				}
			}	
		}	
		
		blue.addItemListener(new mycheckbuttonListener()) ;
		red.addItemListener(new mycheckbuttonListener()) ;
		ButtonGroup gp = new ButtonGroup() ;
		gp.add(blue) ;
		gp.add(red) ;

		p1.add(b) ;
		p1.add(b1) ;
		p1.add(t) ;
		
		p2.add(red) ;
		p2.add(blue) ;
		p2.add(c1) ;
		p2.add(c2) ;
		
		
		window.add(p2,BorderLayout.CENTER) ;
		window.add(p1,BorderLayout.CENTER) ;
	}
	}
