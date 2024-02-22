package Cau1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

public class WebClient {
    public static void main(String[] args) {
        try {
            // Kết nối tới máy chủ web Google qua cổng 80 (HTTP)
            Socket socket = new Socket("www.google.com", 80);

            // Tạo luồng đọc từ socket
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            String httpRequest = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
            socket.getOutputStream().write(httpRequest.getBytes("UTF-8"));

            String line = "";
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }

            socket.close();
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
