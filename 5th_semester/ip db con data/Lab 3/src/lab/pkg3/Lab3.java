/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab.pkg3;
import java.util.Date;
/**
 *
 * @author Abdul Maroof
 */
public class Lab3 {

    /**
     * @param args the command line arguments
     * @throws lab.pkg3.MembershipException
     */
    public static void main(String[] args) throws MembershipException 
    {
                MemberShip memObj=new MemberShip(4, new Date());
		Payable pObj= new Invoice("ITM123", 2, 10);
		System.out.println(pObj.toString());
		try
		{
		  System.out.print(pObj.getPaymentAmount(memObj));
		}
		catch(MembershipException ex)
		{
                }	
		memObj = new MemberShip(1, new Date());
		pObj = new Invoice("ITM123", -5, 10);
		System.out.print(pObj.getPaymentAmount(memObj));	

        // TODO code application logic here
    }
    
}
