package TCP_IP.B1;

import java.io.*;
import java.net.*;
import java.util.Random;

public class Server {
	public static void main(String[] args) throws Exception {

		// server mở port
		int port = 2923;
		ServerSocket serverSocket = new ServerSocket(port);
		System.out.println("Server is started!");

		// cho phép client truy cập
		Socket clientSocket = serverSocket.accept();

		DataInputStream dis = new DataInputStream(clientSocket.getInputStream());
		DataOutputStream dos = new DataOutputStream(clientSocket.getOutputStream());

		// Luôn nhận data từ client
		while (true) {
			// Lấy context từ data client gửi
			String text = dis.readUTF();

			String result = UpperCase(text) + "," + LowerCase(text) + "," + FirstUpperCase(text) + "," + MixCase(text) + "," + Integer.toString(CountWord(text)) + "," + Integer.toString(CountVowel(text));
		
			dos.writeUTF(result);
			dos.flush();
		}
	}

	public static String ReverseCase(String text) {
		String s = "";
		for (int i = text.length() - 1; i >= 0; i--) {
			s += (char) text.codePointAt(i);
		}
		return s;
	}

	public static String UpperCase(String text) {
		String s = "";
		for (int i = 0; i < text.length(); i++) {
			int code = text.codePointAt(i);
			if (97 <= code && code <= 122) {
				code -= 32;
			}
			s += (char) code;
		}
		return s;
	}

	public static String LowerCase(String text) {
		String s = "";
		for (int i = 0; i < text.length(); i++) {
			int code = text.codePointAt(i);
			if (65 <= code && code <= 90) {
				code += 32;
			}
			s += (char) code;
		}
		return s;
	}

	public static String FirstUpperCase(String text) {
		String s = "";
		String[] word = text.split(" ");
		for (int i = 0; i < word.length; i++) {
			s += UpperWord(word[i]) + " ";
		}
		return s;
	}

	public static String UpperWord(String word) {
		String w = "";
		w = UpperCase(String.valueOf(word.charAt(0))) + LowerCase(word.substring(1));
		return w;
	}

	public static String MixCase(String text) {
		String s = "";
		for (int i = 0; i < text.length(); i++) {
			char c = text.charAt(i);
			Random random = new Random();
			int randomChoice = random.nextInt(2);

			if (randomChoice == 0) {
				s += Character.toLowerCase(c);
			} else {
				s += Character.toUpperCase(c);
			}
		}
		return s;
	}

	public static int CountWord(String text) {
		int d = 0;
		text.trim();
		for (int i = 0; i < text.length(); ++i) {
			if (text.charAt(i) == ' ' && text.charAt(i + 1) != ' ') {
				++d;
			}
		}
		++d;
		return d;
	}

	public static int CountVowel(String text) {
		int d = 0;
		String vowelString = "UEOAI";
		text = UpperCase(text);

		for (int i = 0; i < text.length(); i++) {
			char c = text.charAt(i);
			String s = Character.toString(c);

			if (vowelString.contains(s)) {
				++d;
			}
		}
		return d;
	}
}
