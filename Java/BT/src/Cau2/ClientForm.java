package Cau2;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JTextArea;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.awt.event.ActionEvent;

public class ClientForm extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField txtPort;
	private JTextField txtText;

	private int port;
	private Socket clientSocket;
	private DataInputStream dataInputStream;
	private DataOutputStream dataOutputStream;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ClientForm frame = new ClientForm();
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
	public ClientForm() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 724, 439);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Port Server");
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 18));
		lblNewLabel.setBounds(40, 32, 125, 33);
		contentPane.add(lblNewLabel);
		
		txtPort = new JTextField();
		txtPort.setBounds(150, 32, 354, 29);
		contentPane.add(txtPort);
		txtPort.setColumns(10);
		
		JButton btnConnect = new JButton("Connect");
		btnConnect.setFont(new Font("Tahoma", Font.PLAIN, 18));
		btnConnect.setBounds(528, 32, 134, 31);
		contentPane.add(btnConnect);
		
		JLabel lblNewLabel_1 = new JLabel("Input int");
		lblNewLabel_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		lblNewLabel_1.setBounds(40, 100, 125, 22);
		contentPane.add(lblNewLabel_1);
		
		txtText = new JTextField();
		txtText.setColumns(10);
		txtText.setBounds(150, 93, 354, 29);
		contentPane.add(txtText);
		
		JButton btnSubmit = new JButton("Submit");
		btnSubmit.setFont(new Font("Tahoma", Font.PLAIN, 18));
		btnSubmit.setBounds(528, 91, 134, 31);
		contentPane.add(btnSubmit);
		
		JTextArea txtaResult = new JTextArea();
		txtaResult.setBounds(40, 164, 622, 202);
		contentPane.add(txtaResult);
		

		btnConnect.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (btnConnect.getText().equals("Connect")) {
					try {
						port = Integer.parseInt(txtPort.getText());
						btnConnect.setText("Disconnect");
					} catch (Exception e2) {
						e2.printStackTrace();
					}
				} else if (btnConnect.getText().equals("Disconnect")){
					try {
						clientSocket.close();
						btnConnect.setText("Connect");
					} catch (Exception e2) {
						e2.printStackTrace();
					}
				}
			}
		});

		btnSubmit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ConnectServer();
				String inputString = txtText.getText();
				try {
					dataOutputStream.writeUTF(inputString);
					String resultString = dataInputStream.readUTF();
					txtaResult.setText(resultString);
					
					if (resultString.equals("STOP")) {
						btnSubmit.setEnabled(false);
					}
					clientSocket.close();
				} catch (Exception e1) {
					e1.printStackTrace();
				}
			}
		});
	}
	
	public void ConnectServer() {
		try {
			this.clientSocket = new Socket("localhost", this.port);
			this.dataInputStream = new DataInputStream(this.clientSocket.getInputStream());
			this.dataOutputStream = new DataOutputStream(this.clientSocket.getOutputStream());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
}
