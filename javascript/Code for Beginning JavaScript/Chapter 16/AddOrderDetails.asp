<%@ LANGUAGE = JavaScript%>
<HTML>
<HEAD>
</HEAD>
<BODY>
<%
   // Array to hold names of months 
   // used for creating date in format day month year
   var month = new Array("Jan","Feb","Mar","Apr","May","Jun","Jul",
      "Aug","Sep","Oct","Nov","Dec");
   var nowDate = new Date();
   var nowDate = nowDate.getDate() + " " + month[nowDate.getMonth()] + " " + 
      nowDate.getFullYear();
   var orderNo;

   // Connect to database
   var adoConnection = Server.CreateObject("ADODB.Connection");
   adoConnection.Open("DSN=CompBitsCoDB");
   var adoRecordset;

   // Create SQL to insert new order into CustomerOrder table
   var mySQL = "INSERT INTO CustomerOrder " + 
      "(CustomerName, CustomerAddress, TelNumber, OrderDate)";
   mySQL = mySQL + " VALUES ('" + Request.Form("txtCustomerName") + "','";
   mySQL = mySQL + Request.Form("txtCustomerAddress") + "','";
   mySQL = mySQL + Request.Form("txtTelNumber") + "','";
   mySQL = mySQL + nowDate + "')";

   // Execute SQL to add new order 
   adoConnection.Execute(mySQL);

   // Create SQL to get autonumber generated OrderNo from CustomerOrder table
   // for order just added
   mySQL = "SELECT Max(OrderNo) AS MaxOrderNo FROM CustomerOrder WHERE ";
   mySQL = mySQL + " OrderDate = #" + nowDate + "# AND ";
   mySQL = mySQL + " CustomerName = '" + Request.Form("txtCustomerName") + "'";

   // Populate recordset with SQL to get OrderNo
   adoRecordset = adoConnection.Execute(mySQL);

   orderNo = adoRecordset("MaxOrderNo").Value;

   // Recordset not needed after this so close it and allow release of memory
   adoRecordset.Close();
   adoRecordset = null;

   // Create SQL to insert item ordered into OrderItem table
   var mySQL = "INSERT INTO OrderItem (OrderNo, StockId, QtyOrdered)"
   mySQL = mySQL + " VALUES (" + orderNo + ","
   mySQL = mySQL + Request.Form("txtStockId") + ","
   mySQL = mySQL + "1)"
   
   // Execute SQL to insert details of order item purchased
   adoConnection.Execute(mySQL);

   // No more database access
   // so close connection and indicate memory no longer needed
   adoConnection.Close();
   adoConnection = null;

   Response.Write("<H2><CENTER>Your order was completed successfully" +
      "</CENTER></H2>");
%>
</BODY>
</HTML>
