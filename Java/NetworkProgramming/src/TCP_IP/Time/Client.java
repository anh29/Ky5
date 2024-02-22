package TCP_IP.Time;

import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 4321); // Kết nối đến địa chỉ localhost và cổng 12345
            
            // Đọc dữ liệu từ server
            InputStream is = socket.getInputStream();
            DataInputStream dis = new DataInputStream(is);
            String dateString = dis.readUTF();
            
            System.out.println("Ngày hiện tại từ server: " + dateString);
            
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
