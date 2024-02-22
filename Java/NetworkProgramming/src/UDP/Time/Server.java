package UDP.Time;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Date;

public class Server {

	public static void main(String[] args) throws Exception {
		//Gan port 2923
		DatagramSocket serverSocket = new DatagramSocket(2923);
		
		System.out.println("Server is started");
		
		//Tao cac array byte chua data gui & nhan
		byte[] receiveData = new byte[1024];
		byte[] sendData = new byte[1024];
		
		// lien tuc nhan data tu client
		while (true) {
			//Tao packet rong de nhan data tu client
			DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
			
			//Nhan data tu client vào receivePacket
			serverSocket.receive(receivePacket);
			
			//Lay IP cua may client
			InetAddress IPAddress = receivePacket.getAddress();
			
			//Lay port cua chuong trinh client
			int port = receivePacket.getPort();
			
			// request chứa context của client truyền đến
			String request = new String(receivePacket.getData()); 
			System.out.println(request);
			
			if (request.trim().equals("getDate")) {
				//Lay date de gui lai client
				sendData = new Date().toString().getBytes();
			}
			else {
				sendData = "Server is not know what you want.".getBytes();
			}
			DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);
			
			//Gui data lai cho client
			serverSocket.send(sendPacket);
		}
	}

}
