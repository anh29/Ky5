package TCP_IP.ConnectDB;

import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

public class Server {

	public static void main(String[] args) {
		
	}
	
	public static void ConnectDB() throws Exception{
		ServerSocket serverSocket = new ServerSocket(1234);
		System.out.println("Server is listening...");
		
		while (true) {
			Socket clientSocket = serverSocket.accept();
			
			System.out.println("Client is connected.");
		}
	}
	
	public static StringBuilder getDB(String query) throws Exception {
		StringBuilder result = new StringBuilder();
		
		Connection conn = Connector.getConnection();
			
		Statement statement = conn.createStatement();
		
		ResultSet resultSet = statement.executeQuery(query);

		while (resultSet.next()) {
			result.append(resultSet.getString(1) + ", ");
			result.append(resultSet.getString(2) + ", ");
			result.append(resultSet.getString(3));
			result.append("\n");
		}
				
		
		System.out.println(result.toString());
		return result;
	}

}
