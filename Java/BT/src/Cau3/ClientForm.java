package Cau3;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.*;
import java.awt.Font;

public class ClientForm extends JFrame {

    private InetAddress serverAddress;
    private DatagramSocket socket;
    private int port;

    private JTextField inputPort;
    private JTextField inputText;
    private JTextArea textArea;
    JButton sendButton = new JButton("Send");

    public ClientForm() {
        initComponents();
    }

    private void initComponents() {
        setTitle("UDP String Handle Client");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 400);
        getContentPane().setLayout(null);

        inputPort = new JTextField();
        inputPort.setBounds(20, 20, 150, 30);
        getContentPane().add(inputPort);

        inputText = new JTextField();
        inputText.setBounds(20, 70, 150, 30);
        getContentPane().add(inputText);

        textArea = new JTextArea();
        textArea.setBounds(20, 120, 450, 200);
        getContentPane().add(textArea);

        JButton connectButton = new JButton("Connect");
        connectButton.setFont(new Font("Tahoma", Font.PLAIN, 18));
        connectButton.setBounds(200, 20, 100, 30);
        getContentPane().add(connectButton);

        sendButton.setFont(new Font("Tahoma", Font.PLAIN, 18));
        sendButton.setBounds(200, 70, 100, 30);
        getContentPane().add(sendButton);

        connectButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                connect();
            }
        });

        sendButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                sendMessage();
            }
        });
    }

    private void connect() {
        try {
            serverAddress = InetAddress.getByName("localhost");
            port = Integer.parseInt(inputPort.getText());
            socket = new DatagramSocket();
            // Update status or perform other tasks if needed
        } catch (ConnectException e) {
            System.out.println("Connection error");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void sendMessage() {
        try {
            byte[] sendData = (inputText.getText()).getBytes();
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverAddress, port);
            socket.send(sendPacket);

            byte[] receiveData = new byte[1024];
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
            socket.receive(receivePacket);

            String receivedMessage = new String(receivePacket.getData());
            textArea.append(receivedMessage + "\n");
            if (!receivedMessage.contains("không")) {
                sendButton.setEnabled(false);
			}
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ClientForm().setVisible(true);
            }
        });
    }
}
