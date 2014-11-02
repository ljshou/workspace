<%@ LANGUAGE = JavaScript%>

<%

if (Request.Cookies("IsValid") != "Yes")
{
   Response.Redirect("logon.htm")
}

%>
<HTML>
<BODY>

<P ALIGN=center>
<FONT SIZE=5>This page is for valid users only</FONT>
</P>

</BODY>
</HTML>



