<%@ LANGUAGE = JavaScript%>

<%
   Session("NoQsToAsk") = parseInt(Request.Form("cboNoQuestions"));
   Session("TimeLimit") = parseInt(Request.Form("cboTimeLimit"));
   Response.Redirect("AskQuestion.htm");
%>
