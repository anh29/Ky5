package Controller;

import java.io.IOException;
import java.rmi.ServerException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import model.bean.Wife;
import model.bo.CheckLoginBO;

@WebServlet("/CheckLoginServlet")
public class CheckLoginServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	
	protected void doGet(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}
	
	protected void doPost(HttpServletRequest request,
			HttpServletResponse response) throws IOException, ServletException {
		String destinationString = null;
		
		String usernameString = request.getParameter("username");
		String passwordString = request.getParameter("password");
		
		CheckLoginBO checkLoginBO = new CheckLoginBO();
		ArrayList<Wife> wifeArrayList = null;
		
		if (checkLoginBO.isValidUser(usernameString, passwordString)) {
			wifeArrayList = checkLoginBO.getWifeList(usernameString);
			request.setAttribute("wifeArray", wifeArrayList);
			destinationString = "/welcome.jsp";
			RequestDispatcher rd = getServletContext().getRequestDispatcher(destinationString);
			rd.forward(request, response);
		} else {
			destinationString = "/login.jsp";
			RequestDispatcher rd = getServletContext().getRequestDispatcher(destinationString);
			rd.forward(request, response);
		}
	}
}
