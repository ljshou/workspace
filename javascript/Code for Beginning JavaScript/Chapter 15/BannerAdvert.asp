<%@ LANGUAGE = JavaScript%>
<HTML>
<HEAD>
<%
   var randomAdvertNumber = parseInt(Math.random() * 3) + 1;
   var imgName = 'AdvertImage' + randomAdvertNumber + '.jpg';
%>
</HEAD>
<BODY>

<IMG SRC="<%= imgName %>">

</BODY>
</HTML>
