<%@ LANGUAGE = JavaScript %>
<HTML>
<HEAD>
<TITLE>Final Summary</TITLE>
</HEAD>
<BODY>

<H3>Order Summary</H3>

<%

var description = Request.Form("txtDescription").item;
var cost = Request.Form("txtCost").Item
var name = Request.Form("txtName").Item
var houseNo = Request.Form("txtHouse").Item
var street = Request.Form("txtStreet").Item
var city = Request.Form("txtCity").Item
var ccNumber = Request.Form("txtCCNumber").Item

var expiryDate = Request.Form("selMonth") + "/" +Request.Form("selYear")

Response.Write ("<P>" + description + "</P>")
Response.Write ("<P>Will be delivered to </P>")
Response.Write ("<P>Name : " + name + "</P>")
Response.Write ("<P>At address</P>")
Response.Write ("<P>" + houseNo + " " + street + "<BR>")
Response.Write (city)
Response.Write ("<P>Your credit card " + ccNumber)
Response.Write (" expiry date " + expiryDate)
Response.Write (" will be debited by $" + cost)

%>

<FORM action="ch15Q2_PurchaseOrder.asp" method=POST name=form1>
<INPUT type="hidden" name="txtName" value ="<%=name%>">
<INPUT type="hidden" name="txtDescription" value ="<%=description%>">
<INPUT type="hidden" name="txtCost" value ="<%=cost%>">
<INPUT type="hidden" name="txtHouseNo" value ="<%=houseNo%>">
<INPUT type="hidden" name="txtStreet" value ="<%=street%>">
<INPUT type="hidden" name="txtCity" value ="<%=city%>">
<INPUT type="hidden" name="txtCCNumber" value ="<%=ccNumber%>">
<INPUT type="hidden" name="txtExpiryDate" value ="<%=expiryDate%>">
<INPUT type="submit" value="Purchase System" name=submit1>
<P>
<INPUT type="button" value="Cancel Purchase" onclick="window.location.replace('Ch15Q2_TopFrame.htm')"name=butCancel>
</P>
</FORM>

</BODY>
</HTML>
