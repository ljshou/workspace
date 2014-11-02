<%@ LANGUAGE=JavaScript %>
<HTML>
<HEAD>
<TITLE>Buy System</TITLE>

<SCRIPT>

function checkForm()
{
   var regExp = /[^\d ]/
   var formValid = true;
   var theForm = document.form1;
   var elementIndex;
   var element;
   var nowDate = new Date();
   var expMonth = parseInt(theForm.selMonth.value)
   var expYear = parseInt(theForm.selYear.value)

   for (elementIndex = 0; elementIndex < theForm.length; elementIndex++)
   {
      element = theForm[elementIndex];
      if (element.type == "text")
      {
         if (element.value == "")
         {
            formValid = false;
            element.focus();
            alert("Please complete all of the boxes");
            break;
         }
      }
   }

   if (formValid == true && expYear <= parseInt(nowDate.getFullYear()) && parseInt(nowDate.getMonth()) > expMonth)
   {
      formValid = false;
      theForm.selMonth.focus();
      alert("The credit card expiry date you selected has expired")
   }
   else if (regExp.test(theForm.txtCCNumber.value) == true)
   {
      formValid = false;
      alert("Please enter a valid credit card number");
      theForm.txtCCNumber.focus();
      theForm.txtCCNumber.select();
   }

   return formValid;
}

</SCRIPT>

</HEAD>
<BODY>
<H2>Purchase System</H2>
<P>Please enter you name, address and credit card details below</P>
<FORM action="ch15Q2_FinalStage.asp" method=POST name=form1 onsubmit="return checkForm()">
<P>
Your Full Name:
<BR>
<INPUT type="text" name=txtName>
</P>
<P>
House Name/Number
<BR>
<INPUT type="text" name=txtHouse>
</P>
<P>
Street:
<BR>
<INPUT type="text" name=txtStreet>
</P>
<P>
City:
<BR>
<INPUT type="text" name=txtCity>
</P>
<P>
<P>
Credit Card Number:
<BR>
<INPUT type="text" name=txtCCNumber>
<P>
Expiry Date
<BR>
<SELECT name=selMonth>
<OPTION value="01">01</OPTION>
<OPTION value="02">02</OPTION>
<OPTION value="03">03</OPTION>
<OPTION value="04">04</OPTION>
<OPTION value="05">05</OPTION>
<OPTION value="06">06</OPTION>
<OPTION value="07">07</OPTION>
<OPTION value="08">08</OPTION>
<OPTION value="09">09</OPTION>
<OPTION value="10">10</OPTION>
<OPTION value="11">11</OPTION>
<OPTION value="12">12</OPTION>
</SELECT>
<SELECT name=selYear>
<%

var yearCount;
var nowYear = new Date();
nowYear = parseInt(nowYear.getFullYear());

for (yearCount = nowYear; yearCount < nowYear + 5; yearCount++)
{
   Response.Write("<OPTION value='" + yearCount + "'>")
   Response.Write(yearCount + "</OPTION>");
}

%>

</SELECT>

<INPUT type="hidden" name="txtCost" value="<%=Request.Form("txtCost")%>">

<INPUT type="hidden" name="txtDescription" value="<%=Request.Form("txtDescription")%>">
<P>
<INPUT type="submit" value="Submit" name=submit1>
</P>
</FORM>
</BODY>
</HTML>
