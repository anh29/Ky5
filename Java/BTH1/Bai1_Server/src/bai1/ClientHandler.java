package bai1;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class ClientHandler implements Runnable {

    private Socket socket;

    private DataInputStream inputStream;

    private DataOutputStream outputStream;

   

    public ClientHandler(Socket socket) {
        super();
        this.socket = socket;

        try {
            this.inputStream = new DataInputStream(this.socket.getInputStream());
            this.outputStream = new DataOutputStream(this.socket.getOutputStream());
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }

    @Override
    public void run() {
        // TODO Auto-generated method stub
        try {
            String message = inputStream.readUTF();
            sendMessages(message);
        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }
    }

    private String reverseString(String data) {
        StringBuilder result = new StringBuilder();
        for (int i = data.length() - 1; i >= 0; i--) {
            result.append(data.charAt(i));
        }
        return result.toString();
    }

    private String toLowerCaseString(String data) {
        return data.toLowerCase();
    }

    private String toLowerUpperCaseString(String data) {
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

    private int numberCharater(String data) {
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

    private int numberVowel(String data) {
        int count = 0;
        for (int i = 0; i < data.length(); i++) {
            char c = data.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }
        return count;
    }

    private String toUpperCaseString(String data) {
        return data.toUpperCase();
    }

    public void sendMessages(String message) {
        StringBuilder result = new StringBuilder("Chuoi dao nguoc: " + reverseString(message) + "\n");
        result.append("Chuoi hoa: " + toUpperCaseString(message) + "\n");
        result.append("Chuoi thuong: " + toLowerCaseString(message) + "\n");
        result.append("Chuoi vua hoa vua thuong: " + toLowerUpperCaseString(message) + "\n");
        result.append("So tu: " + numberCharater(message) + "\n");
        result.append("So nguyen am: " + numberVowel(message));

        try {
            outputStream.writeUTF((result.toString()));
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}
