<%@ LANGUAGE = JavaScript%>
<HTML>
<BODY>
<TABLE BORDER=1>
<THEAD>
   <TR>
   <TH>Product</TH>
   <TH>Quantity In Stock</TH>
   <TH>Cost per Item</TH>
   <TH></TH>
   </TR>
</THEAD>

<%
// Open connection to database, then populate a recordset with list of stock
   var adoConnection = Server.CreateObject("ADODB.Connection");
   var adoRecordSet;
   var mySQL;
   adoConnection.Open("DSN=CompBitsCoDB");
   var mySQL = "SELECT StockId, ItemDescription, NumberInStock, ItemCost" + 
      " FROM Stock";
   adoRecordSet = adoConnection.Execute(mySQL);

// Loop through recordset and write stock details out to page
   while ( adoRecordSet.Eof == false )
   {
%>
<TR>
   <TD><%=adoRecordSet("ItemDescription").Value%></TD>
   <TD><%=adoRecordSet("NumberInStock").Value%></TD>
   <TD><%=adoRecordSet("ItemCost").Value%></TD>
   <TD><A HREF="buyitem.asp?StockId=<%=adoRecordSet("StockId").Value%>">
      Buy this</A></TD>
</TR>
<%
   adoRecordSet.MoveNext();
   }

// Close Recordset and connections 
// and release memory used by Recordset and Connection objects
   adoRecordSet.Close();
   adoRecordSet = null;
   adoConnection.Close();
   adoConnection = null;
%>
</TABLE>
</BODY>
</HTML>
