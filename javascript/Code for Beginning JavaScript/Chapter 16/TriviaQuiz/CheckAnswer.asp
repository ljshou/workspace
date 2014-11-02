<%@ LANGUAGE = JavaScript%>
<% Response.Buffer = "True" %>
<HTML>
<HEAD>
</HEAD>
<BODY BACKGROUND="bluewash.jpg">
<%
   var answer;
   var mySQL;
   mySQL = "SELECT QuestionType, Answer FROM Question ";
   mySQL = mySQL + " WHERE QuestionId = " + Request.Form("txtQuestionId");

   var adoRecordset = Server.CreateObject("ADODB.Recordset");

   adoRecordset.Open(mySQL, "Provider=Microsoft.Jet.OLEDB.4.0;Data" +
                " Source=C:\\Temp\\TriviaQuestions.mdb");

   if (adoRecordset("QuestionType").Value == 2)
   {
      answer = new String(Request.Form("txtAnswer"));
   }
   else
   {
      answer = new String(Request.Form("radQuestionChoice"));
   }

   var answerRegExp = new RegExp(adoRecordset("Answer").Value,"i");

   adoRecordset.Close();
   adoRecordset = null;

   if (answer.search(answerRegExp) != -1)
   {
      Session("numberOfQuestionsCorrect") =
            parseInt(Session("numberOfQuestionsCorrect")) + 1;
%>
      <CENTER><IMG SRC="Correct.gif"></CENTER>
<%
   }
   else
   {
%>
      <CENTER><IMG SRC="Incorrect.gif"></CENTER>
<%
   }

   if (Session("totalQuestionsAsked") != Session("NoQsToAsk"))
   {
%>
      <FORM NAME="quizForm" ACTION="" METHOD="post">
      <INPUT TYPE="button" VALUE="Next Question" NAME=butNext
         onclick="window.location.replace('AskQuestion.asp')">
      </FORM>
<%
   }
   else
   {
%>
      <!-- #include file="FinalResults.asp" -->
<%
   }
%>

</FONT>
</BODY>
</HTML>
