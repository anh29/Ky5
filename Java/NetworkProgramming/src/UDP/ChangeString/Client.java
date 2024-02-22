package UDP.ChangeString;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class Client {

	public static void main(String[] args) throws Exception {
		// Nhờ DatagramSocket gửi DatagramPacket
		DatagramSocket clientSocket = new DatagramSocket();
		
		// Lấy port của server có name muốn gửi tới
		InetAddress IPAddress = InetAddress.getByName("localhost");
		
		//Tao cac array byte chua data gui & nhan
		byte[] sendData = new byte[1024];
		byte[] receiveData = new byte[1024];
		
		// Tạo string cần gửi cho server
		Scanner scanner = new Scanner(System.in);
        System.out.print("Nhập chuỗi: ");
        String string = scanner.next();
        
        
	}

}
