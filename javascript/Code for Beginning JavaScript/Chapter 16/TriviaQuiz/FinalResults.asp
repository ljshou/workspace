<FORM NAME="quizForm" ACTION="" METHOD="post">

<SCRIPT LANGUAGE=JavaScript>
   window.top.fraTopFrame.fraGlobalFunctions.stopTimer();
</SCRIPT>

<FONT COLOR=darkslateblue FACE="Comic Sans MS">
<P><IMG SRC="quizcomplete.gif"></P>
You got <%=Session("numberOfQuestionsCorrect")%>
questions correct out of <%= Session("NoQsToAsk") %>
<BR><BR>Your trivia rating is

<%
   var numberOfQuestionsCorrect = parseInt(Session("numberOfQuestionsCorrect"));
   var numberOfQuestionsAsked = parseInt(Session("NoQsToAsk"));
   switch(Math.round(((numberOfQuestionsCorrect / numberOfQuestionsAsked)
      * 10)))
   {
      case 0:
      case 1:
      case 2:
      case 3:
         Response.Write("Beyond embarrasing");
         break;
      case 4:
      case 5:
      case 6:
      case 7:
         Response.Write("Average");
         break;
      default:
         Response.Write("Excellent");
   }

   var previousNoCorrect = Math.floor(Request.Cookies("previousNoCorrect"));
   var previousNoAsked = Math.floor(Request.Cookies("previousNoAsked"));
   var currentAvgScore = Math.round(numberOfQuestionsCorrect /
      numberOfQuestionsAsked * 100);

   Response.Write("<BR>The percentage you've " +
      " answered correctly in this quiz is " + currentAvgScore + "%");

   if (previousNoAsked == 0)
   {
      previousNoCorrect = 0;
   }

   previousNoCorrect = previousNoCorrect + numberOfQuestionsCorrect;
   previousNoAsked = previousNoAsked + numberOfQuestionsAsked;

   currentAvgScore = Math.round(previousNoCorrect / previousNoAsked * 100);

   var nowDate = new Date();
   nowDate.setMonth(nowDate.getMonth() + 3);
   cookieExpires = nowDate.toGMTString();
   cookieExpires = cookieExpires.slice(5,cookieExpires.length - 4);

   Response.Cookies("previousNoAsked") = previousNoAsked;
   Response.Cookies("previousNoAsked").Expires = cookieExpires;

   Response.Cookies("previousNoCorrect") =  previousNoCorrect;
   Response.Cookies("previousNoCorrect").Expires = cookieExpires;

   Response.Cookies("AverageScore") = currentAvgScore;
   Response.Cookies("AverageScore").Expires = cookieExpires;

   Response.Write("<BR>This brings your average todate to " +
      currentAvgScore + "%");

%>

<P>
<INPUT TYPE=button VALUE='Reset Stats' NAME=buttonReset
   onclick="window.top.fraTopFrame.fraGlobalFunctions.setCookie('previousNoAsked', 0,'','Mon, 1 Jan 1970')" >

<P>
<INPUT TYPE=button VALUE='Restart Quiz' NAME=buttonRestart
   onclick="window.location.replace('quizpage.asp')" >
</FORM>
