package ChatGroup;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.Socket;

public class ClientUI {
    private Client client;
    private JFrame frame;
    private JTextArea chatArea;
    private JTextField messageField;
    private String username;

    public ClientUI() {
        frame = new JFrame("Chat Client");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400);

        chatArea = new JTextArea();
        chatArea.setEditable(false);

        JScrollPane chatScrollPane = new JScrollPane(chatArea);
        chatScrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
        chatScrollPane.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);

        messageField = new JTextField();

        JButton sendButton = new JButton("Send");
        sendButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                sendMessage();
            }
        });

        messageField.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    sendMessage();
                }
            }
        });

        JButton leaveButton = new JButton("Leave");
        leaveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                leaveChat();
            }
        });

        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new BorderLayout());
        inputPanel.add(messageField, BorderLayout.CENTER);
        inputPanel.add(sendButton, BorderLayout.EAST);
        inputPanel.add(leaveButton, BorderLayout.WEST);

        frame.add(chatScrollPane, BorderLayout.CENTER);
        frame.add(inputPanel, BorderLayout.SOUTH);
        frame.setVisible(true);

        username = JOptionPane.showInputDialog("Enter your name for group chat:");
        if (username != null && !username.isEmpty()) {
            this.username = username;
            client = new Client(username);
            client.connectToServer();
            displayMessage("SERVER: " + username + " has entered the chat!");

            new Thread(new Runnable() {
                @Override
                public void run() {
                    while (true) {
                        String message = client.receiveMessage();
                        displayMessage(message);
                    }
                }
            }).start();
        } else {
            frame.dispose();
        }
    }

    private void sendMessage() {
        String messageToSend = messageField.getText();
        if (!messageToSend.isEmpty()) {
            client.sendMessage(messageToSend);
            messageField.setText("");
        }
    }

    private void displayMessage(String message) {
        chatArea.append(message + "\n");
    }

    private void leaveChat() {
        client.disconnect();
        frame.dispose();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new ClientUI();
            }
        });
    }
}
