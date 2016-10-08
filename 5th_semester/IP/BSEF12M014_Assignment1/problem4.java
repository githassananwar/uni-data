import java.util.*;

class Account
{

private int accountId; //Account ID
private String accountTitle; //Name of the account holder
private double openingBal; //Minimum Bal should be Rs.5000
private String emailID; //Optional attribute. If user do not provide assign "Email ID Not Available"
private double accountBal; //The accountBal should never go below the minBalLimit i.e. 100

Account()
{
	accountId=0;
	accountTitle="";
	openingBal=0;
	emailID="";
	accountBal=0;
}

public Account(int accountId, String accountTitle, double openingBal, String emailID)
{
	this.accountId=accountId;
	this.accountTitle=accountTitle;
	if(openingBal>=5000)
	{
		this.openingBal=openingBal;
	}
	else
	{
		this.openingBal=0;
	}
	this.emailID=emailID;
	this.accountBal=this.openingBal;


}

public Account(int accountId, String accountTitle, double openingBal)
{
	this.accountId=accountId;
	this.accountTitle=accountTitle;
	if(openingBal>=5000)
	{
		this.openingBal=openingBal;
	}
	else
	{
		this.openingBal=0;
	}
	this.emailID="Email ID Not Available";
	this.accountBal=this.openingBal;

}

public void setAccountId(int accountId)
{
	this.accountId=accountId;
}

public void setAccountTitle(String accountTitle)
{
	this.accountTitle=accountTitle;
}

public void setOpeningBal(double openingBal)
{
	if(openingBal>=5000)
	{
		this.openingBal=openingBal;
		this.accountBal=this.openingBal;
	}
	else
	{
		System.out.println("Error! Minimum Opening Balance should be Rs. 5000.");
	}
}

public boolean setAccountBal(double newAccountBal)
{
	if(newAccountBal<100)
	{
		System.out.println("Error! Minimum Account Balance can be Rs. 100.");
		return false;
	}
	else
	{
		this.accountBal=newAccountBal;
		return true;
	}


}

public void setEmailID(String emailID)
{
	this.emailID=emailID;
}

//-----------------------------------------------------------------------------------------

public int getAccountId()
{
	return this.accountId;
}

public String getAccountTitle()
{
	return this.accountTitle;
}

public double getOpeningBal()
{
	return this.openingBal;
}

public String getEmailID()
{
	return this.emailID;
}


public double getAccountBal()
{
	return this.accountBal;
}

//-----------------------------------------------------------------------------------------

public boolean deposit(double amount)
{
	if(amount>0)
	{	
		this.accountBal=this.accountBal+amount;
		return true;
	}
	
	return false;
		
}

public boolean withdraw(double amount)
{
	if(amount<this.accountBal && amount>0)
	{
		if(this.accountBal-amount<100)
		{
			return false;
		}
		else
		{
			this.accountBal=this.accountBal-amount;
			return true;
		}
	}
	else
	{
		return false;
	}

}


	

}


class Driver
{
public static void main(String [] args)
{

Account a= new Account();
a.setAccountId(453803);
a.setAccountTitle("Hassan Anwar");
a.setOpeningBal(10000);
a.setAccountBal(15000);
a.setEmailID("hassan@gmail.com");


System.out.println("Account ID: "+a.getAccountId());
System.out.println("Account Title: "+a.getAccountTitle());
System.out.println("Opening Balance: "+a.getOpeningBal());
System.out.println("Email ID: "+a.getEmailID());
System.out.println("Account Balance: "+a. getAccountBal());

if (a.deposit(5000))
{
	System.out.println("Successful Deposit.");

}
else
{
	System.out.println("Unsuccessful Deposit.");	
}

System.out.println("Account Balance: "+a. getAccountBal());

if(a.withdraw(200))
{
	System.out.println("Successful Withdrawl.");
}
else
{
	System.out.println("Unsuccessful Withdrawl.");
}

System.out.println("Account Balance: "+a. getAccountBal());




}


}

