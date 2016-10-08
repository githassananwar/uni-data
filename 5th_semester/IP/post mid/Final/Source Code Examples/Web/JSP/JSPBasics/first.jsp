<html>
<body>

<%! 
String global_var="Class Wide variables are declared here";

public int sum(int no,int no1){
int s=no+no1;
return s;
}
%>

<%= "Output of sum function is " + sum(7,3) %>

<br>

<%
String local_var="Local variables are declared here";
%>

<h1> This is heading</h1>

<% out.println(local_var);%>

</body>
</html>