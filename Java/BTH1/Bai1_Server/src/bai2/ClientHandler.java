package bai2;

import bai1.*;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

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
        // TODO Auto-generated method stub
        try {

            String message = inputStream.readUTF();
            sendMessages(message);

        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }
    }

    
    public void sendMessages(String message) {
        InfixCalculate infixCalculate = new InfixCalculate();
        double result = infixCalculate.caculatePostfix(message);
        try {
            outputStream.writeUTF(result +"");
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}
