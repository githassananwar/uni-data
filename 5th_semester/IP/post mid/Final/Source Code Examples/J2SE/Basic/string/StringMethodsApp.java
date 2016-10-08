public class StringMethodsApp {
   public static void main (String args[]) {

	String str1 = "Pakistan";
	String str2 = new String("Pakistan");

        char c = str1.charAt(0);
	System.out.println("char of str1 at 0 index: " + c);
	System.out.println();

	String conByMethod = str1.concat(str2);
	String conByOperator = str1 + str2;
	System.out.println("concatenate by method: " + conByMethod);
	System.out.println("concatenate by method: " + conByOperator);
	System.out.println();

	System.out.println( "comapring strings");


	if (str2 == "Pakistan")
	System.out.println("strings equal using ==");


	if (str2.equals("Pakistan"))
	System.out.println("strings equal using equals method");
	System.out.println();


        String sub = str1.substring(5);
        System.out.println("substring of str1: "+sub);
        System.out.println();

	String lower = str1.toLowerCase();
	System.out.println("str1 in lower case: "+ lower);

}

	}