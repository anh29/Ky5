package bai4;

import bai2.*;
import bai1.*;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;

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

    public String getResult(String message) {
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

    public void sendMessages(String message) {

//        double result = 
        try {
            outputStream.writeUTF(getResult(message));
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}
