/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lab.pkg3;
/**
 *
 * @author Abdul Maroof
 */
    interface Payable
{
     double getPaymentAmount(MemberShip obj) throws MembershipException;
     public int getDiscountPercentage(MemberShip obj) throws MembershipException;
} 
    
