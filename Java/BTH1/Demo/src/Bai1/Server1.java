/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Bai1;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Date;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author ASUS
 */
public class Server1 {
    public static void main(String[] args) {
        try {
            DatagramSocket serverSocket = new DatagramSocket(9876);
            System.out.println("Server started");
            byte[] receiveData = new byte[1024];
            byte[] sendData = new byte[1024];
            while(true){
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                serverSocket.receive(receivePacket);
                InetAddress iAddress = receivePacket.getAddress();
                int port = receivePacket.getPort();
                String request = new String(receivePacket.getData());
                System.out.println(request);
                if(request.trim().equals("getDate")){
                    sendData = new Date().toString().getBytes();
                }else{
                    sendData = "Server do not know what you want".getBytes();
                }
                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length,iAddress, port);
                serverSocket.send(sendPacket);
            }
        } catch (SocketException ex) {
            ex.printStackTrace();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
