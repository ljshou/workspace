<%@ LANGUAGE = JavaScript%>
<HTML>
<BODY>
<P>Your Browser's details</P>
<%
var BrowsCapComponent = Server.CreateObject("MSWC.BrowserType");
%>

Browser Name : <%= BrowsCapComponent.browser %>
<BR>
Browser Version : <%= BrowsCapComponent.version %>
<BR>
Supports JavaScript : <%= BrowsCapComponent.javascript %>
<BR>
Supports Frames : <%= BrowsCapComponent.frames %>
<BR>
Supports Cookies : <%= BrowsCapComponent.cookies %>

<%
BrowsCapComponent = null;
%>

</BODY>
</HTML>
