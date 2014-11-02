<%@ LANGUAGE = Jscript%>

<%

if (Request.Cookies("IsValid") != "Yes")
{
	Response.Redirect("logon.htm")
}

%>
<HTML>
<BODY>

<P align=center>
	<FONT size=5>This page is for valid users only</FONT>
</P>

</BODY>
</HTML>
