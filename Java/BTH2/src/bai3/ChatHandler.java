/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package bai3;

import java.awt.TextArea;
import java.io.DataInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author ASUS
 */
public class ChatHandler implements Runnable {

    private MulticastSocket clienSocket;
    private int port;
    private InetAddress ipAddress;
    private TextArea textArea;

    public ChatHandler(MulticastSocket clientSocket, int port, InetAddress ipAddress, TextArea textArea) {
        this.ipAddress = ipAddress;
        this.port = port;
        this.textArea = textArea;
        try {
            this.clienSocket = clientSocket;
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    @Override
    public void run() {
        while (true) {
            try {
                byte[] receiveData = new byte[1024];
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                this.clienSocket.receive(receivePacket);

                String message = new String(receivePacket.getData(), 0, receivePacket.getLength());
                this.textArea.append(message);
            } catch (Exception e) {
                e.printStackTrace();
            }

        }

    }

}
