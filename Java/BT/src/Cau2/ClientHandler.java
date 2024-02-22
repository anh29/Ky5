package Cau2;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Random;

public class ClientHandler implements Runnable {

    private Socket socket;

    private DataInputStream inputStream;

    private DataOutputStream outputStream;

   

    public ClientHandler(Socket socket) {
        super();
        this.socket = socket;

        try {
            this.inputStream = new DataInputStream(this.socket.getInputStream());
            this.outputStream = new DataOutputStream(this.socket.getOutputStream());
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }

    @Override
    public void run() {
        try {
            String message = inputStream.readUTF();
            int intValue = Integer.parseInt(message);

            // Kiểm tra xem biểu diễn nhị phân của số đó có đối xứng hay không
            int result = isBinarySymmetric(intValue);

            // Nếu kết quả là đối xứng, đóng kết nối
            if (result == 1) {
            	sendMessages("STOP");
                closeConnection();
            }
            else {
				sendMessages(message);
			}
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static Integer isBinarySymmetric(int number) {
        String binaryRepresentation = Integer.toBinaryString(number);
        int length = binaryRepresentation.length();

        // Kiểm tra từng cặp ký tự đối xứng
        for (int i = 0; i < length / 2; i++) {
            if (binaryRepresentation.charAt(i) != binaryRepresentation.charAt(length - 1 - i)) {
                return 0; // Nếu có ít nhất một cặp không đối xứng, trả về false
            }
        }

        return 1; // Nếu tất cả các cặp đều đối xứng, trả về true
    }

    private void closeConnection() {
        try {
            inputStream.close();
            outputStream.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public void sendMessages(String message) {
        try {
            outputStream.writeUTF(message);
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}
