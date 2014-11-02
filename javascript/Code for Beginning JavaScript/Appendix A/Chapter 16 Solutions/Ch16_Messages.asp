<%@ LANGUAGE=JavaScript %>
<HTML>
<BODY>
<CENTER>
	<H2>Message Board</H2>
	<FORM	NAME="form1" METHOD=post
			ACTION="Ch16_NewMessage.asp" TARGET=_top>

		<INPUT	TYPE="submit"
				VALUE="Create New Message"
				NAME=submit1>
	</FORM>
	<STRONG>
		Click the message subject link to
		view the full message
	</STRONG>

<TABLE BORDER=1>
<TR>
	<TH>Message Subject</TH>
	<TH>Posted By</TH>
	<TH>Posted On</TH>
</TR>
<%
var months = new Array("Jan","Feb","Mar","Apr","May","Jun",
					   "Jul","Aug","Sep","Oct","Nov","Dec");
var postedDate;
var lsSQL = "SELECT MessageId, UserName, MessageSubject, " +
			"DatePosted FROM Message " +
			"ORDER BY MessageId DESC"
var adoRS = Server.CreateObject("ADODB.Recordset")
adoRS.Open(lsSQL,"DSN=MessageBoardDSN")

while (adoRS.EOF == false)
{
	Response.Write("<TR><TD width=400>" +
					"<A href='Ch16_MessageBody.asp?MessageId=" +
					adoRS("MessageId") +
					"' target=messagebody>" +
					adoRS("MessageSubject") +
					"</A></TD>")

	Response.Write("<TD width=100>" +
					adoRS("UserName") +
					"</TD>")

postedDate = new Date(adoRS("DatePosted"))
postedDate =		postedDate.getDate() + " "
				+	months[postedDate.getMonth()] + " "
				+	postedDate.getFullYear();

	Response.Write("<TD width=100>" +
					postedDate +
					"</TD></TR>" )

	adoRS.MoveNext();
}

adoRS.Close()
adoRS = null;

%>

</TABLE>

</CENTER>
</BODY>
</HTML>
