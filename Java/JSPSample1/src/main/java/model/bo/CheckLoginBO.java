package model.bo;

import java.util.ArrayList;

import model.bean.Wife;
import model.dao.CheckLoginDAO;

public class CheckLoginBO {
	CheckLoginDAO checkLoginDAO = new CheckLoginDAO();
	
	public boolean isValidUser(String usernameString, String passwordString) {
		return checkLoginDAO.isExistUser(usernameString, passwordString);
	}
	
	public ArrayList<Wife> getWifeList(String usernameString) {
		return checkLoginDAO.getWifeList(usernameString);
	}
}
