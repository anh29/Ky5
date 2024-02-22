package TCP_IP.B1;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

public class Client {
    public String text;
    private Socket clientSocket;
    private DataInputStream dis;
    private DataOutputStream dos;
    
    public Client() {
		this.text = "";
	}

	public void setText(String text) {
        this.text = text;
    }

    public void connectServer() throws Exception {
        int port = 2923;
        // kết nối với server
        clientSocket = new Socket("localhost", port);
        System.out.println("Ket noi thanh cong server!");

        dis = new DataInputStream(clientSocket.getInputStream());
        dos = new DataOutputStream(clientSocket.getOutputStream());

        // tạo string cần gửi cho server xử lý
        Scanner sc = new Scanner(System.in);

        dos.writeUTF(text);

        dos.flush();
    }

    public void closeConnect() throws Exception {
        System.out.println("Ngat ket noi server!");
        clientSocket.close();
    }

//    public String getResult() throws Exception {
//        ArrayList<String> result = new ArrayList<>();
//        // Nhận string từ server sau khi server xử lý xong
//        String r;
//
//        while((r = dis.readUTF())!=null) {
//            result.add(r);
//        }
//
//        return result;
//    }
}























