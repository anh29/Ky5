/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai3;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author ASUS
 */
public class ClientHandler implements Runnable {

    private Socket Socket;
    private DataOutputStream dataOutputStream;
    private DataInputStream dataInputStream;
    private ServerForm server;

    public ClientHandler(Socket socket, ServerForm server, DataInputStream dataInputStream, DataOutputStream dataOutputStream) {
        this.Socket = socket;
        this.dataOutputStream = dataOutputStream;
        this.dataInputStream = dataInputStream;
        this.server = server;
    }

    @Override
    public void run() {
        while (true) {
            try {
                String message = dataInputStream.readUTF();
                System.out.println(message);
                //send message to all
                server.broadcastMessage(message);
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }

    }

    public void sendMessage(String message) {
        try {
            this.dataOutputStream.writeUTF(message);
            System.out.println(this.dataOutputStream);
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

}
