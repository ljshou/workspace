<%@ LANGUAGE = JavaScript %>
<HTML>
<HEAD>
<SCRIPT>

function form1_onsubmit()
{
   var form = document.form1;
   var returnValue = false;

   if (form.txtUsername.value == "")
   {
      alert("Please enter your username");
      form.txtUsername.focus();
	}
   else if (form.txtPassword.value == "")
   {
      alert("Please enter your password");
      form.txtPassword.focus();
   }
   else
   {
      returnValue = true;
   }

return returnValue;

}

</SCRIPT>
</HEAD>
<BODY>
<%

if (Request.Form.Count != 0)
{
   if (Request.Form("txtUsername") == "SecureUser" && Request.Form("txtPassword") == "letmethrough")
   {
      Response.Cookies("IsValid") = "Yes";
      Response.Redirect("SecureHome.asp");
   }
   else
   {
      Session("LogonTrys") = parseInt(Session("LogonTrys")) + 1;
      Response.Redirect("logon.asp")
   }
}

var invalidTrys = Session("LogonTrys");
if (isNaN(invalidTrys))
{
   invalidTrys = 1;
   Session("LogonTrys") = invalidTrys;
}
else
{
   invalidTrys = parseInt(invalidTrys);
}

if ( invalidTrys != 1 )
{
   Response.Write("<P><FONT color=red size=+2>"+ "Sorry the username/password" + " you entered were invalid</FONT></P>")
   if ( invalidTrys <= 3)
   {
      Response.Write("<P><FONT color=black size=+2>"+ "Please re-enter your details"
+ "</FONT></P>")
   }
}

if ( invalidTrys <= 3)
{
%>
<P> To access this website please enter your username and password in the boxes below</P>

<FORM action="LogOn.asp" method=POST id=form1 name=form1	onsubmit="return form1_onsubmit()">

<P>Username : <INPUT id=txtUsername name=txtUsername></P>
<P>Password : <INPUT id=txtPassword name=txtPassword type=password></P>

<P>
<INPUT id=reset1 name=reset1 type=reset value=Reset>&nbsp;
<INPUT id=submit1 name=submit1 type=submit value="Log On">
</P>

</FORM>
<%
}
%>
</BODY>
</HTML>
