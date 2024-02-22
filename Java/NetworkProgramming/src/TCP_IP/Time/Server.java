package TCP_IP.Time;

import java.io.DataOutputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

public class Server {

	public static void main(String[] args) throws Exception{
		ServerSocket server = new ServerSocket(4321);
		while (true) {
			Socket clientSocket = server.accept();
            System.out.println("Client đã kết nối: " + clientSocket.getInetAddress().getHostAddress());
            
            // Lấy ngày hiện tại
            Date currentDate = new Date();
            String dateString = currentDate.toString();
            
            // Gửi dữ liệu ngày hiện tại cho client
            OutputStream os = clientSocket.getOutputStream();
            DataOutputStream dos = new DataOutputStream(os);
            dos.writeUTF(dateString);
            
            clientSocket.close();
		}
	}

}
