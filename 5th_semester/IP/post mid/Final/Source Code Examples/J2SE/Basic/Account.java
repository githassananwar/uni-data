import java.util.Scanner;

public class Account
{
        public double balance;

      	
  	    public void deposit( double amount )
	{
		balance += amount;
	}

        public double withdraw( double amount )
	{
		if (balance >= amount)
		{
			balance -= amount;
                        return amount;
		}
		else
                        return 0.0;
	}

        public double getbalance()
	{
                return balance;
	}


public static void main(String args[])
	{
        Scanner in = new Scanner(System.in);

        // Create an empty account
        Account my_account = new Account();

        // Deposit money
	System.out.print("Enter the amount that you want to deposit:");
       		
	double deposit_amount = in.nextDouble();      
	my_account.deposit(deposit_amount);
       System.out.println ("After Deposit" + my_account.getbalance());


	System.out.print("Enter the amount that you want to withdraw:");
	double witdraw_amount = in.nextDouble();    
	my_account.withdraw(witdraw_amount);

	System.out.println ("After withdrawing" + my_account.getbalance());
	}


}
