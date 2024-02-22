package bai3;


import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Server {
    private List<ClientHandler> clients = new ArrayList<>();
    public Server(){
      
    }
    public void startServer() {
        ServerSocket serverSocket = null;
        try {
            serverSocket = new ServerSocket(6688);
            System.out.println("Server started!");
            while (true) {
                Socket clientSocket = serverSocket.accept();
                DataInputStream dataInputStream = new DataInputStream(clientSocket.getInputStream());
                DataOutputStream dataOutputStream = new DataOutputStream(clientSocket.getOutputStream());
//                ClientHandler clientHandler = new ClientHandler(clientSocket, this, dataInputStream, dataOutputStream);
//                clients.add(clientHandler);
//                new Thread(clientHandler).start();
            }
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } finally {
            try {
                serverSocket.close();
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }
    public void broadcastMessage(String message){
        for (ClientHandler client : clients) {
            client.sendMessage(message);
        }
    }

    public static void main(String[] args) {
        Server server = new Server(); server.startServer();
//        Thread  startThread = new Thread(()->{
//            
//        });
       
    }
}
