package bai4;

import bai2.*;
import bai1.*;
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

    public ClientHandler(DatagramSocket serverSocket,JTextArea txtaResult) {
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
                    txtaResult.append("Client: " + message);
                    String result = getResult(message);
                    System.out.println(result);
                    this.address = receivePacket.getAddress();
                    this.port = receivePacket.getPort();
                    this.sendData = result.getBytes("UTF-8");
                    System.out.println("length byte: " + sendData.length);

                    this.sendPacket = new DatagramPacket(sendData, sendData.length, this.address, this.port);
                    this.serverSocket.send(sendPacket);
                    break;
                }

            } catch (IOException ex) {
                System.out.println(ex.getMessage());
                ex.printStackTrace();
            }
        }

    }

    public String getResult(String message) {
        System.out.println(message);
        StringBuilder result = new StringBuilder();
        try (Connection conn = Connector.getConnection()) {
            try (Statement statement = conn.createStatement()) {
                try (ResultSet resultSet = statement.executeQuery(message)) {
                    while (resultSet.next()) {
                        result.append(resultSet.getInt(1) + ", ");
                        result.append(resultSet.getString(2) + ", ");
                        result.append(resultSet.getString(3) + ", ");
                        result.append(resultSet.getString(4));
                        result.append("\n");
                    }
                    
                }
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
        return result.toString();
    }

}