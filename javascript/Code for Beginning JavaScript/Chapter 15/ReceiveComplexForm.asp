<%@ LANGUAGE = JavaScript%>
<HTML>
<BODY>
   <P>Name is <%= Request.Form("txtName") %></P>
   <P>E-mail is <%= Request.Form("txtEmail") %></P>
   <P>Gender is <%= Request.Form("radGender") %></P>
   <P>Response is <%= Request.Form("chkResponse") %></P>
   <P>Age Range is <%= Request.Form("selAgeRange") %></P>
   <PRE>
      <P>Suggestion is <%= Request.Form("txtaSuggestion") %></P>
   </PRE>
</BODY>
</HTML>
