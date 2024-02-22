<%@page import="model.bean.Wife"%>
<%@page import="java.util.ArrayList"%>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Welcome</title>
</head>
<body>
	<%
		ArrayList<Wife> wifeArrayList = (ArrayList<Wife>) request.getAttribute("wifeArrayList");
		for(int i =0; i< wifeArrayList.size(); i++) {
	%>
		<tr>
			<td><%= wifeArrayList.get(i).getName() %></td>
			<td><%= wifeArrayList.get(i).getAddress() %></td>
			<td><%= wifeArrayList.get(i).isAlive() %></td>
		</tr>
	<% } %>
</body>
</html>