package TCP_IP.ConnectDB;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import java.awt.Color;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class Client extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField txtQuery;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Client frame = new Client();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public Client() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 701, 388);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("What do you want to see?");
		lblNewLabel.setBackground(new Color(255, 255, 255));
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 18));
		lblNewLabel.setBounds(238, 10, 221, 35);
		contentPane.add(lblNewLabel);
		
		JButton btnDepartment = new JButton("Phòng ban");
		btnDepartment.setFont(new Font("Tahoma", Font.PLAIN, 16));
		btnDepartment.setBounds(58, 73, 146, 35);
		contentPane.add(btnDepartment);
		
		JButton btnAll = new JButton("Tất cả");
		btnAll.setFont(new Font("Tahoma", Font.PLAIN, 16));
		btnAll.setBounds(492, 73, 146, 35);
		contentPane.add(btnAll);
		
		JButton btnStaff = new JButton("Nhân viên");
		btnStaff.setFont(new Font("Tahoma", Font.PLAIN, 16));
		btnStaff.setBounds(281, 73, 146, 35);
		contentPane.add(btnStaff);
		
		txtQuery = new JTextField();
		txtQuery.setBounds(58, 129, 478, 48);
		contentPane.add(txtQuery);
		txtQuery.setColumns(10);
		
		JButton btnOK = new JButton("OK");
		btnOK.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String query = txtQuery.getText();
				if (query == null || query.trim().length()==0) {
					JOptionPane.showMessageDialog(null,
			                "Error query",
			                "Error",
			                JOptionPane.ERROR_MESSAGE);
				} else {
					JOptionPane.showMessageDialog(null,
			                query,
			                "Title Example",
			                JOptionPane.INFORMATION_MESSAGE);
				}
			}
		});
		btnOK.setFont(new Font("Tahoma", Font.PLAIN, 18));
		btnOK.setBounds(546, 136, 92, 35);
		contentPane.add(btnOK);
	}

	public static void connectServer() {
		
	}
}
