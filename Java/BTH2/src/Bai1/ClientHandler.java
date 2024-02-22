package Bai1;

import Bai2.*;
import bai4.*;

import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.Socket;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JTextArea;

public class ClientHandler implements Runnable {

    private DatagramSocket serverSocket;

    private DatagramPacket receivePacket;
    private byte[] receiveData;

    private DatagramPacket sendPacket;
    private byte[] sendData;
    private InetAddress address;
    private int port;
    private JTextArea txtaResult;

    public ClientHandler(DatagramSocket serverSocket, JTextArea txtaResult) {
        super();
        this.serverSocket = serverSocket;
        this.txtaResult = txtaResult;
        sendData = new byte[1024];
    }

    @Override
    public void run() {
        // TODO Auto-generated method stubwhi
        while (true) {
            try {
                receiveData = new byte[1024];
                this.receivePacket = new DatagramPacket(receiveData, receiveData.length);
                serverSocket.receive(receivePacket);

                String message = new String(receivePacket.getData(), 0, receivePacket.getLength()).trim();
                if (message.length() != 0) {
                    txtaResult.append("\nClient: " + message);
                    String result = getResult(message);
                    System.out.println(result);
                    this.address = receivePacket.getAddress();
                    this.port = receivePacket.getPort();
                    this.sendData = result.getBytes("UTF-8");
                    this.sendPacket = new DatagramPacket(sendData, sendData.length, this.address, this.port);
                    this.serverSocket.send(sendPacket);
                }

            } catch (IOException ex) {
                System.out.println(ex.getMessage());
                ex.printStackTrace();
            } catch (Exception ex) {
                System.out.println(ex.getMessage());
                ex.printStackTrace();
            }

        }
    }

    private String reverseString(String data) {
        StringBuilder result = new StringBuilder();
        for (int i = data.length() - 1; i >= 0; i--) {
            result.append(data.charAt(i));
        }
        return result.toString();
    }

    private String toLowerCaseString(String data) {
        return data.toLowerCase();
    }

    private String toLowerUpperCaseString(String data) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            char c = data.charAt(i);
            if (Character.isUpperCase(c)) {
                c = Character.toLowerCase(c);
            } else {
                c = Character.toUpperCase(c);
            }
            result.append(c);
        }
        return result.toString();
    }

    private int numberCharater(String data) {
        data = ' ' + data;
        int cnt = 0;
        for (int i = 1; i < data.length(); i++) {
            char c = data.charAt(i);
            char c1 = data.charAt(i - 1);
            if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) && (c1 == ' ')) {
                cnt++;
            }
        }
        return cnt;
//        int count = 0;
//        for (int i = 0; i < data.length(); i++) {
//            if (Character.isAlphabetic(data.charAt(i))) {
//                count++;
//                while (i < data.length() && Character.isAlphabetic(data.charAt(i++)));
//                i--;
//            }
//        }
//        return count;
    }

    private int numberVowel(String data) {
        int count = 0;
        for (int i = 0; i < data.length(); i++) {
            char c = data.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }
        return count;
    }

    private String toUpperCaseString(String data) {
        return data.toUpperCase();
    }

    public String getResult(String message) {
        StringBuilder result = new StringBuilder("Chuoi dao nguoc: " + reverseString(message) + "\n");
        result.append("Chuoi hoa: " + toUpperCaseString(message) + "\n");
        result.append("Chuoi thuong: " + toLowerCaseString(message) + "\n");
        result.append("Chuoi vua hoa vua thuong: " + toLowerUpperCaseString(message) + "\n");
        result.append("So tu: " + numberCharater(message) + "\n");
        result.append("So nguyen am: " + numberVowel(message));
        return result.toString();
    }

}
