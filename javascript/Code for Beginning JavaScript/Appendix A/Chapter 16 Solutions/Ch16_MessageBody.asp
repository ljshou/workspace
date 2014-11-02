<%@ LANGUAGE=JavaScript%>
<HTML>
<BODY>
<CENTER>
<FORM>
<%
var lsMessageBody = "";
if (isNaN(Request.QueryString("MessageId")) == false)
{
	var lsSQL = "SELECT MessageBody FROM Message " + 
				"WHERE MessageId = " + 
				Request.QueryString("MessageId")
	var adoRS = Server.CreateObject("ADODB.Recordset")
	adoRS.Open(lsSQL,"DSN=MessageBoardDSN")
	lsMessageBody = adoRS("MessageBody").Value;
	
	adoRS.Close();
	adoRS = null;
}
%>
	<TEXTAREA	rows=8 cols=60 
				name=textarea1><%=lsMessageBody%></TEXTAREA>				
</FORM>
</CENTER>
</BODY>
</HTML>
