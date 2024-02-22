package bai4;

import bai2.*;
import bai1.*;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Server {

    public void startServer() {
        DatagramSocket serverSocket = null;
        try {
            serverSocket = new DatagramSocket(8080);
            System.out.println("Server started!");
            int i = 0;
            while (i++ < 100) {
                System.out.println(i);
//                ClientHandler clientHandler = new ClientHandler(serverSocket);
//                new Thread(clientHandler).start();
                Thread.sleep(1000);
            }
            serverSocket.close();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (InterruptedException ex) {
            ex.printStackTrace();
        } finally {
        }
    }

    public static void main(String[] args) {
        Server server = new Server();
        server.startServer();
    }
}
