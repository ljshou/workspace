<%@ LANGUAGE = JavaScript%>
<HTML>
<HEAD>
<SCRIPT>

function form1_onsubmit() 
{
   var form = document.form1
   var controlCounter;
   var returnValue = true;
   var formControl;

// Check that all text boxes on form have not been left empty by user
// Cancel form post if form is not complete by returning false
   for (controlCounter = 0; controlCounter < form.length; controlCounter++)
   {
      formControl = form.elements[controlCounter];
      if (formControl.type == "text" && formControl.value == "")
      {
         alert("Please complete all of the form");
         formControl.focus();
         returnValue = false;
         break;
      }
   }

   return returnValue;
}

</SCRIPT>
</HEAD>
<BODY>
Please enter your customer details
<BR>
<FORM ACTION="AddOrderDetails.asp" METHOD=POST NAME=form1 LANGUAGE=JavaScript 
   onsubmit="return form1_onsubmit()">
<INPUT TYPE="hidden" NAME=txtStockId
   VALUE="<%=Request.QueryString("StockId")%>">
Name 
<BR>
<INPUT TYPE="text" NAME=txtCustomerName MAXLENGTH=50>
<BR>
Address
<BR>
<INPUT TYPE="text" NAME=txtCustomerAddress MAXLENGTH=255>
<BR>
Telephone Number 
<BR>
<INPUT TYPE="text" NAME=txtTelNumber MAXLENGTH=25>
<BR>
<INPUT TYPE="submit" VALUE="Send Order" ID=submit1 NAME=submit1>
</FORM>

</BODY>
</HTML>
