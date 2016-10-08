/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab.pkg3;

import java.lang.Exception;
/**
 *
 * @author Abdul Maroof
 */
final class Invoice implements Payable
{
	private String itemNumber; 
	private int quantity;
	private double pricePerItem;
	
	public Invoice(String number, int count, double price) {
		setItemNumber (number);
		setQuantity(count); 
		setPricePerItem(price); 
	} 
        
	public void setItemNumber(String num) {
		itemNumber = num; 
	} 
	public String getItemNumber() {
		return itemNumber;
	} 	
	public void setQuantity(int count)
        {
                   quantity = count;
                   try{
                        if(this.quantity < 0)
                        {
                             throw new IllegalArgumentException(); 
                        }
                   }
            catch (IllegalArgumentException a)
            {
                
            }
	} 
	public int getQuantity() {
		return quantity;
	}	
	public void setPricePerItem(double price) {
		pricePerItem = price;
                try{
                        if(this.pricePerItem < 0)
                        {
                             throw new IllegalArgumentException(); 
                        }
                   }
            catch (IllegalArgumentException a)
            {
                
            }
	}

       
        public int getDiscountPercentage(MemberShip obj) throws MembershipException
        {
           if(obj.membershipType==1)
			return (int) (this.pricePerItem * 0.3);
		else if(obj.membershipType==2)
			return (int) (this.pricePerItem * 0.15);
		else if(obj.membershipType==3)
			return (int) (this.pricePerItem * 0.05);
		else
            return 0;
        }
        
	public double getPricePerItem() {
		return pricePerItem;
	} 

	public String toString() {
		return String.format("%s: \n%s: %s  \n%s: %d \n%s: %f", 
				"invoice", "part number", getItemNumber(), 
				"quantity", getQuantity(), "price per item", getPricePerItem());
	} 
	
	public double getPaymentAmount(MemberShip obj) throws MembershipException{
		double amt = getQuantity() * getPricePerItem() ; 
		amt = amt + (amt*getDiscountPercentage(obj)/100);
		return amt;
	} 

   // public int getDiscountPercentage(MemberShip obj) throws MembershipException {
    //    throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    //}
}