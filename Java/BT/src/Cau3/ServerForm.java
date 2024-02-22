package Cau3;

import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.LayoutStyle.ComponentPlacement;

public class ServerForm extends JFrame {

    private static final long serialVersionUID = 1L;
    private JTextField txtPort;

    public ServerForm() {
        initComponents();
    }

    private void initComponents() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("UDP String Handle Server");
        
        JPanel contentPane = new JPanel();

        JLabel lblNewLabel = new JLabel("Input Port:");
        lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 18));

        txtPort = new JTextField();
        txtPort.setColumns(10);

        JButton btnSubmit = new JButton("Listen");
        btnSubmit.setFont(new Font("Tahoma", Font.PLAIN, 18));
        btnSubmit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                startServerActionPerformed(e);
            }
        });

        JTextArea txtaResult = new JTextArea();

        GroupLayout groupLayout = new GroupLayout(contentPane);
        groupLayout.setHorizontalGroup(
            groupLayout.createParallelGroup(Alignment.LEADING)
                .addGroup(groupLayout.createSequentialGroup()
                    .addGap(55, 55, 55)
                    .addComponent(lblNewLabel)
                    .addPreferredGap(ComponentPlacement.RELATED)
                    .addComponent(txtPort, GroupLayout.PREFERRED_SIZE, 157, GroupLayout.PREFERRED_SIZE)
                    .addPreferredGap(ComponentPlacement.RELATED)
                    .addComponent(btnSubmit, GroupLayout.PREFERRED_SIZE, 103, GroupLayout.PREFERRED_SIZE)
                    .addContainerGap(298, Short.MAX_VALUE))
                .addGroup(groupLayout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(txtaResult, GroupLayout.DEFAULT_SIZE, 630, Short.MAX_VALUE)
                    .addContainerGap())
        );
        groupLayout.setVerticalGroup(
            groupLayout.createParallelGroup(Alignment.LEADING)
                .addGroup(groupLayout.createSequentialGroup()
                    .addGap(52, 52, 52)
                    .addGroup(groupLayout.createParallelGroup(Alignment.BASELINE)
                        .addComponent(lblNewLabel)
                        .addComponent(txtPort, GroupLayout.PREFERRED_SIZE, 30, GroupLayout.PREFERRED_SIZE)
                        .addComponent(btnSubmit, GroupLayout.PREFERRED_SIZE, 31, GroupLayout.PREFERRED_SIZE))
                    .addGap(18, 18, 18)
                    .addComponent(txtaResult, GroupLayout.DEFAULT_SIZE, 210, Short.MAX_VALUE)
                    .addContainerGap())
        );
        contentPane.setLayout(groupLayout);
        setContentPane(contentPane);
        pack();
    }

    private void startServerActionPerformed(ActionEvent evt) {
        DatagramSocket serverSocket;
        try {
            int port = Integer.parseInt(txtPort.getText());
            serverSocket = new DatagramSocket(port);
            System.out.println("Server is started");
            Thread acceptThread = new Thread(() -> {
                try {
                    while (true) {
                        byte[] receiveData = new byte[1024];
                        byte[] sendData = new byte[1024];
                        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                        serverSocket.receive(receivePacket);
                        InetAddress clientAddress = receivePacket.getAddress();
                        int clientPort = receivePacket.getPort();
                        String request = new String(receivePacket.getData());
                        System.out.println(request);
                        if (request != null) {
                            request = request.trim();
                            Integer num = Integer.parseInt(request);
                            sendData = FibonacciCheck(num).getBytes();
                            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, clientAddress,
                                    clientPort);
                            serverSocket.send(sendPacket);
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });
            acceptThread.start();
        } catch (SocketException ex) {
            Logger.getLogger(ServerForm.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static String FibonacciCheck(int K) {
    	if (K == 1) {
            return K + " là phần tử thứ 1 và 2 trong dãy Fibonacci.";
		}
            if (isFibonacci(K)) {
                int position = fibonacciPosition(K);
                return K + " là phần tử thứ " + position + " trong dãy Fibonacci.";
            } else {
                return K + " không thuộc dãy Fibonacci.";
            }
        }

        // Hàm kiểm tra xem một số có thuộc dãy Fibonacci hay không
        private static boolean isFibonacci(int number) {
            int a = 0, b = 1;
            while (b < number) {
                int temp = b;
                b = a + b;
                a = temp;
            }
            return b == number;
        }

        // Hàm tìm vị trí của số trong dãy Fibonacci
        private static int fibonacciPosition(int number) {
            int a = 0, b = 1, position = 2;
            while (b < number) {
                int temp = b;
                b = a + b;
                a = temp;
                position++;
            }
            return (b == number) ? position : -1;
        }

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            new ServerForm().setVisible(true);
        });
    }
}
