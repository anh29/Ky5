/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Bai2;

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
public class Server2 {

    private static String reverseString(String data) {
        StringBuilder result = new StringBuilder();
        for (int i = data.length() - 1; i >= 0; i--) {
            result.append(data.charAt(i));
        }
        return result.toString();
    }

    private static String toLowerCaseString(String data) {
        return data.toLowerCase();
    }

    private static String toLowerUpperCaseString(String data) {
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

    private static int numberCharater(String data) {
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

    private static int numberVowel(String data) {
        int count = 0;
        for (int i = 0; i < data.length(); i++) {
            char c = data.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }
        return count;
    }

    private static String toUpperCaseString(String data) {
        return data.toUpperCase();
    }

    public static void main(String[] args) {
        try {
            DatagramSocket serverSocket = new DatagramSocket(9876);
            System.out.println("Server started");
            byte[] receiveData = new byte[1024];

            while (true) {
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                
                serverSocket.receive(receivePacket);
                String message = new String(receivePacket.getData()).trim();
                
                StringBuilder result = new StringBuilder("Chuoi dao nguoc: " + reverseString(message) + "\n");
                result.append("Chuoi hoa: " + toUpperCaseString(message) + "\n");
                result.append("Chuoi thuong: " + toLowerCaseString(message) + "\n");
                result.append("Chuoi vua hoa vua thuong: " + toLowerUpperCaseString(message) + "\n");
                result.append("So tu: " + numberCharater(message) + "\n");
                result.append("So nguyen am: " + numberVowel(message));
                
                byte[] sendData = new byte[1024];
                sendData = result.toString().getBytes();
                InetAddress iAddress = receivePacket.getAddress();
                int port = receivePacket.getPort();
                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, iAddress, port);
                serverSocket.send(sendPacket);
            }
        } catch (SocketException ex) {
            ex.printStackTrace();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
