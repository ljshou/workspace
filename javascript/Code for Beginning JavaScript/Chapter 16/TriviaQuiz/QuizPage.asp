<%@ LANGUAGE = JavaScript%>
<HTML>
<HEAD>
<META HTTP-EQUIV="expires" CONTENT="Mon, 1 Jan 1980 00:00:00 GMT">
<SCRIPT LANGUAGE=JavaScript>

function cmdStartQuiz_onclick() 
{
     var timeLimit = document.frmQuiz.cboTimeLimit.options[document.frmQuiz.cboTimeLimit.selectedIndex].value
   window.top.fraTopFrame.fraGlobalFunctions.startTimer(timeLimit);

   document.frmQuiz.submit();
}

</SCRIPT>
</HEAD>

<BODY BACKGROUND="bluewash.jpg">
<H2 ALIGN="center">
   <FONT COLOR=coral FACE="Comic Sans MS" SIZE=6>
      Welcome to the Wrox Online Trivia Quiz
   </FONT>
</H2>
<P>
<FONT COLOR=darkslateblue FACE="Comic Sans MS" >
   <STRONG>
      Click the Start Quiz button below to challenge your trivia knowledge.
   </STRONG>
</FONT>
</P>
<P>
<FORM NAME="frmQuiz" METHOD="post" ACTION="NoteUserSelections.asp">
<P>
Number of Questions <BR>
<SELECT NAME=cboNoQuestions SIZE=1>
   <OPTION VALUE=3>3
   <OPTION VALUE=5
   <%
      if (Session("NoQsToAsk") == 5)
      {
         Response.Write(" SELECTED ");
      }
   %>
   >5
</SELECT>
</P>
<P>
Time Limit <BR>
<SELECT name=cboTimeLimit size=1>
   <OPTION value=-1>No Time Limit
   <OPTION value=60
   <%
      if (Session("TimeLimit") == 60)
      {
         Response.Write(" SELECTED ");
      }
   %>
   >1 Minute
   <OPTION value=180
   <%
      if (Session("TimeLimit") == 180)
      {
         Response.Write(" SELECTED ");
      }
   %>
   >3 Minutes
   <OPTION value=300
   <%
      if (Session("TimeLimit") == 300)
      {
         Response.Write(" SELECTED ");
      }
   %>
   >5 Minutes
</SELECT>
</P>
   <INPUT NAME=cmdStartQuiz TYPE=button VALUE="Start Quiz"
      onclick="return cmdStartQuiz_onclick()">
</FORM>
</P>
</BODY>
</HTML>
