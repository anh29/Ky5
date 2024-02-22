package UDP.Time;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Client {

	public static void main(String[] args) throws Exception {
		// nhờ datagramSocket gửi DatagramPacket
		DatagramSocket clientSocket = new DatagramSocket();
		
		// lấy port của server muốn gửi
		InetAddress IPAddress = InetAddress.getByName("localhost");
		
		byte[] sendData = new byte[1024];
		byte[] receiveData = new byte[1024];
		
		// gửi request "getDate"
		sendData = "getDate".getBytes();
		
		//Tao datagram co context y/c loai data de gui cho server
		DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, 2923);
		
		clientSocket.send(sendPacket); // gui data cho server
		
		//Tao datagram rong de nhan data từ server trả về
		DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
		
		//Nhan data tu server
		clientSocket.receive(receivePacket);
		
		//Lay data tu packet nhan duoc
		String str = new String(receivePacket.getData());
		
		System.out.println(str.trim());
		clientSocket.close();
	}

}
