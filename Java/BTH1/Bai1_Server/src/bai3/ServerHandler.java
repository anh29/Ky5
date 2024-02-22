/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai3;

import java.awt.TextArea;
import java.io.DataInputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author ASUS
 */
public class ServerHandler implements Runnable {

    private Socket socket;
    private DataInputStream dataInputStream;
    private TextArea textArea;

    public ServerHandler(Socket socket, TextArea textArea) {
        this.socket = socket;
        this.textArea = textArea;
        try {
            this.dataInputStream = new DataInputStream(socket.getInputStream());
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    @Override
    public void run() {
        while (true) {
            String message;
            try {
                message = dataInputStream.readUTF();
                this.textArea.append(message);
                System.out.println(message);
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }

    }

}
