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
class MemberShip
{
	int membershipType;
	String membershipTitle;
	Date membershipDate; 
	MemberShip(int type, Date startdate)
	{
		membershipType = type;
		membershipDate =startdate;
	}
	void setMembershipTitle()
	{
		if(membershipType==1)
			membershipTitle = "Gold";
		else if(membershipType==2)
			membershipTitle = "Silver";
		else if(membershipType==3)
			membershipTitle = "Bronze";
		else
			System.out.print("Invalid Type");
	}
	public int getMembershipType() {
		return membershipType;
	}
	public Date getMembershipDate() {
		return membershipDate;
	}
}
