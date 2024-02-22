package TCP_IP.B2;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {
	Socket socket;
	private String text;
	
	public Client(String text) {
		this.text = text;
	}

	public void connectServer() {
		try {
			socket = new Socket("localhost", 12345); // Kết nối đến Server ở cổng 12345
			PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
			BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

			Scanner scanner = new Scanner(System.in);

			out.println(text);

			String response = in.readLine();

			in.close();
			out.close();
			socket.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	
}
