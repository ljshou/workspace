<%@ LANGUAGE = JavaScript%>
<HTML>
<HEAD>
<META HTTP-EQUIV="Expires" CONTENT="1 Jan 1980">
</HEAD>

<BODY BACKGROUND="bluewashqs.jpg">
<TABLE ALIGN=center BORDER="2" WIDTH="70%">
<TR>
<TD BGCOLOR=RoyalBlue>
<FORM NAME="QuestionForm" METHOD=post ACTION="CheckAnswer.asp">

<%
   Session("totalQuestionsAsked") = parseInt(Session("totalQuestionsAsked")) + 1;
   var questionId;
   var mySQL;
   var adoConnection = Server.CreateObject("ADODB.Connection");
   adoConnection.Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\\Temp\\TriviaQuestions.mdb")

   mySQL = "SELECT TOP 1 QuestionId, QuestionHTML, QuestionType FROM Question ";
   mySQL = mySQL + " WHERE QuestionId NOT IN (" + Session("AskedQuestions") + ")";
   var adoRecordset = adoConnection.Execute(mySQL);

   questionId = adoRecordset("QuestionId").Value;
   Session("AskedQuestions") = Session("AskedQuestions") + "," + questionId;

   if (adoRecordset("QuestionType").Value == 1)
   {
      mySQL = "SELECT OptionOrder, AnswerOption FROM QuestionOptions ";
      mySQL = mySQL + " WHERE QuestionId = " + questionId;
      mySQL = mySQL + " ORDER BY OptionOrder"
      var adoOptionsRecordset = adoConnection.Execute(mySQL);
   }

   Response.Write("<H4>Question " + Session("totalQuestionsAsked") + "</H4>");

   Response.Write("<INPUT TYPE=hidden NAME=txtQuestionId VALUE=" + adoRecordset("QuestionId").Value + ">");

   // Check QuestionType field - if 2 then text based question
   if (adoRecordset("QuestionType").Value == 2)
   {
      Response.Write("<P>" + adoRecordset("QuestionHTML").Value + "</P>");
      Response.Write("<P><INPUT TYPE=text NAME=txtAnswer");
      Response.Write(" MAXLENGTH=100 SIZE=35></P>");
   }
   else
   {
      Response.Write("<P>" + adoRecordset("QuestionHTML").Value + "</P>");
      while (adoOptionsRecordset.Eof == false)
      {
         Response.Write("<INPUT TYPE=radio NAME=radQuestionChoice");
         if (adoOptionsRecordset("OptionOrder").Value == 1)
         {
            Response.Write(" CHECKED");
         }
         Response.Write(" VALUE=" + adoOptionsRecordset("OptionOrder").Value);
         Response.Write(">" + adoOptionsRecordset("AnswerOption"));
         Response.Write("<BR>");
         adoOptionsRecordset.MoveNext();
      }

      adoOptionsRecordset.Close();
      adoOptionsRecordset = null;
   }

   adoRecordset.Close();
   adoRecordset = null;
   adoConnection.Close();
   adoConnection == null;
%>
<BR>
<INPUT TYPE="submit" VALUE="Answer Question" ID=submit1 NAME=submit1>


</FORM>
</TD>
</TR>
</TABLE>
</BODY>
</HTML>
