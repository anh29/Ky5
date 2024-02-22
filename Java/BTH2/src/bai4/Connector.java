package bai4;

import java.sql.Connection;
import java.sql.DriverManager;

public class Connector {

    private static String DB_URL = "jdbc:mysql://localhost:3306/dulieu";
    private static String USER_NAME = "root";
    private static String PASSWORD = "";
//	public static Connection conn = getConnection();

    public static Connection getConnection() {
        Connection conn = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
            conn = DriverManager.getConnection(DB_URL, USER_NAME, PASSWORD);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        return conn;
    }
}
