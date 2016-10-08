class ConvertStringTest{

    public static void main(String[] args){

	String intString = "20";
	String doubleString = "35.573";

      System.out.println("converting string into int");
      int num1 = Integer.parseInt (intString);
      System.out.println(num1);

	int num2 = new Integer(intString).intValue();
	System.out.println(num2);


	System.out.println("converting string into double");
	double double1 = Double.parseDouble (doubleString);
	System.out.println(double1);

	double double2 = new Double(doubleString).doubleValue();
	System.out.println(double2);

} }