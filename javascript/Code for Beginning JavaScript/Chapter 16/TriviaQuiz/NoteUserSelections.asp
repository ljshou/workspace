<%@ LANGUAGE = JavaScript%>

<%
   Session("NoQsToAsk") = parseInt(Request.Form("cboNoQuestions"));
   Session("TimeLimit") = parseInt(Request.Form("cboTimeLimit"));
   Session("totalQuestionsAsked") = 0;
   Session("AskedQuestions") = "0";
   Session("numberOfQuestionsCorrect") = 0;


   Response.Redirect("AskQuestion.asp");
%>
