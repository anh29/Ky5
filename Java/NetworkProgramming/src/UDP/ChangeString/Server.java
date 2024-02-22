package UDP.ChangeString;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.net.SocketException;
import java.util.Random;

public class Server {

	public static void main(String[] args) throws Exception {
		// Gán port 1713 cho server
		DatagramSocket serverSocket = new DatagramSocket(1713);
		
		System.out.println("Server is started");
		
		// Tạo các array byte chứa data gửi và nhận
		byte[] receiveData = new byte[1024];
		byte[] sendData = new byte[1024];
		
		// Liên tục nhận data từ client
		while (true) {
			// Tạo packet rỗng để nhận data từ client
			DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
			
			// Nhận data từ client vào receivePacket nhờ serverSocket
			serverSocket.receive(receivePacket);
			
			// Lấy IP của client
			InetAddress ipAddress = receivePacket.getAddress();
			
			// Lấy port của chương trình client
			int port = receivePacket.getPort();
			
			// Lấy context từ data của client truyền đến
			String requeString = new String(receivePacket.getData());
			
			
		}
	}

}

class ClientHandler implements Runnable {
    private Socket clientSocket;

    public ClientHandler(Socket socket) {
        this.clientSocket = socket;
    }

    @Override
    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

            String clientMessage = in.readLine();
            System.out.println("Client gửi: " + clientMessage);

            // Xử lý yêu cầu
            String reversed = new StringBuilder(clientMessage).reverse().toString();
            String upperCase = clientMessage.toUpperCase();
            String lowerCase = clientMessage.toLowerCase();
            String mixedCase = "";
            for (int i = 0; i < clientMessage.length(); i++) {
                char c = clientMessage.charAt(i);
                Random random = new Random();
                int randomChoice = random.nextInt(2);

                if (randomChoice == 0) {
                    mixedCase += Character.toLowerCase(c);
                } else {
                    mixedCase += Character.toUpperCase(c);
                }
            }
            int wordCount = clientMessage.split("\\s+").length;
            int vowelCount = clientMessage.replaceAll("[^AEIOUaeiou]", "").length();

            // Trả kết quả cho Client
            out.println("Chuỗi đảo ngược: " + reversed);
            out.println("Chuỗi in hoa: " + upperCase);
            out.println("Chuỗi in thường: " + lowerCase);
            out.println("Chuỗi vừa hoa vừa thường: " + mixedCase);
            out.println("Số từ: " + wordCount);
            out.println("Số nguyên âm: " + vowelCount);

            in.close();
            out.close();
            clientSocket.close();
            System.out.println("Kết thúc kết nối với Client.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
