package TCP_IP.B1;

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
import java.util.ArrayList;
import java.awt.event.ActionEvent;

public class ClientUI extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField txtInput;
	static Client client = new Client();

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ClientUI frame = new ClientUI();
		            client.connectServer();
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
	public ClientUI() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Nhập chuỗi");
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 18));
		lblNewLabel.setBounds(174, 10, 91, 38);
		contentPane.add(lblNewLabel);
		
		txtInput = new JTextField();
		txtInput.setBounds(10, 58, 315, 27);
		contentPane.add(txtInput);
		txtInput.setColumns(10);
		
		JButton btnOK = new JButton("OK");
		btnOK.setFont(new Font("Tahoma", Font.PLAIN, 18));
		btnOK.setBounds(341, 58, 85, 27);
		contentPane.add(btnOK);
		
		JTextArea txtShow = new JTextArea();
		txtShow.setBounds(10, 118, 416, 135);
		contentPane.add(txtShow);
		
		btnOK.addActionListener(new ActionListener() {
		    @Override
		    public void actionPerformed(ActionEvent e) {
		        ((Client) client).setText(txtInput.getText());
		        
		        try {
		            ArrayList<String> result = client.getResult();

		            // Append each element of the result ArrayList to txtShow
		            for (String line : result) {
		                txtShow.append(line + "\n");
		            }
		            
		            client.closeConnect();
		        } catch (Exception e1) {
		            // Handle exception
		        	System.out.print("error: ");
		            e1.printStackTrace();
		            // TODO: Add your exception handling logic here
		        }
		    }
		});
	}
}
