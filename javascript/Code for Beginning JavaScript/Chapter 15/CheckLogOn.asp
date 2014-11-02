<%@ LANGUAGE = JavaScript%>

<%
if (Request.Form("txtUsername") == "SecureUser" && 
   Request.Form("txtPassword") == "letmethrough")
{
   Response.Cookies("IsValid") = "Yes";
   Response.Redirect("SecureHome.asp");
}
else
{
   Response.Redirect("Logon.htm")
}

%>


