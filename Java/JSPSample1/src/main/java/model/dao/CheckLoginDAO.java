package model.dao;

import java.util.ArrayList;

import model.bean.Wife;

public class CheckLoginDAO {
	public boolean isExistUser(String usernameString, String passwordString) {
		// Connect vao db lam mo so viec
		// Tat ca nhung cau SQL deu phai dat o DAO
		return true;
	}
	
	public ArrayList<Wife> getWifeList(String usernameString) {
		ArrayList<Wife> resultArrayList = new ArrayList<Wife>();
		
		// Connect vao db lam mo so viec
		Wife wife = new Wife();
		wife.setName("Thi No");
		wife.setAddress("Lo gach");
		wife.setAlive(false);
		resultArrayList.add(wife);
		
		wife = new Wife();
		wife.setName("Chi Pheo");
		wife.setAddress("Ho ca");
		wife.setAlive(true);
		resultArrayList.add(wife);
		
		return resultArrayList;
	}
}
