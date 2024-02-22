package Cau2;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.net.ServerSocket;
import java.net.Socket;
import java.awt.event.ActionEvent;
import javax.swing.JTextArea;

public class ServerForm extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField txtPort;
	
	private int port;
	private ServerSocket serverSocket;

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ServerForm frame = new ServerForm();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public ServerForm() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 656, 379);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Input Port");
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 18));
		lblNewLabel.setBounds(45, 52, 94, 35);
		contentPane.add(lblNewLabel);
		
		txtPort = new JTextField();
		txtPort.setBounds(164, 52, 248, 30);
		contentPane.add(txtPort);
		txtPort.setColumns(10);
		
		JButton btnSubmit = new JButton("Listen");
		btnSubmit.setFont(new Font("Tahoma", Font.PLAIN, 18));
		btnSubmit.setBounds(451, 52, 103, 31);
		contentPane.add(btnSubmit);
		
		JTextArea txtaResult = new JTextArea();
		txtaResult.setBounds(45, 124, 509, 133);
		contentPane.add(txtaResult);

		btnSubmit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				port = Integer.parseInt(txtPort.getText());
				System.out.println(port);
				if (btnSubmit.getText().equals("Listen")) {
					try {
						serverSocket = new ServerSocket(port);
						txtaResult.setText("Server started at port " + serverSocket.getLocalPort());
						btnSubmit.setText("Stop listenning");
						Thread thread = new Thread() {
							public void run() {
								while (true) {
									Socket clientSocket;
									try {
										clientSocket = serverSocket.accept();
										ClientHandler clientHandler = new ClientHandler(clientSocket);
										new Thread(clientHandler).start();
									} catch (Exception e2) {
										if (serverSocket.isClosed()) {
											break;
										}
										else {
											e2.printStackTrace();
										}
									}
								}
							}
						};
						thread.start();
					} catch (Exception e2) {
						e2.printStackTrace();
					}
				} 
				else if (btnSubmit.getText().equals("Stop listenning")) {
					try {
						serverSocket.close();
						txtaResult.setText("Server stopped");
						btnSubmit.setText("Listen");
					} catch (Exception e2) {
						e2.printStackTrace();
					}
				}
			}
		});
	}

}
