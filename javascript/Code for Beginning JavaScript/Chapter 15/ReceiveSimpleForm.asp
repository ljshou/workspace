<%@ LANGUAGE = JavaScript%>
<HTML>
<HEAD>
<%
   var lastName = Request.Form("txtLastName");
%>
</HEAD>
<BODY>
   <P>The value you entered for your first name was 
   <%= Request.Form("txtFirstName") %></P>
   <P>The value you entered for your last name was 
   <%= lastName %></P>
</BODY>
</HTML>
