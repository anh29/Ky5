package Socket;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class AddrLookupApp {

	public static void main(String[] args) {
		try {
			InetAddress host = InetAddress.getLocalHost();
			
			String hostAddr = host.getHostAddress();
			String hostName = host.getHostName();
			
			System.out.println("Host IP: " + host);			
			System.out.println("Host name: " + hostName);
			System.out.println("IP address: " + hostAddr);
			
			System.out.println("==========================");
			
			InetAddress ip = InetAddress.getByName("www.google.com");
			
			String ipAddr = ip.getHostAddress();
			String ipName = ip.getHostName();
			
			System.out.println("IP: " + ip);			
			System.out.println("Name: " + ipName);
			System.out.println("Address: " + ipAddr);
			
			System.out.println("==========================");
			
		} catch (UnknownHostException e) {
			System.out.println("Address not found");
			return;
		}
	}

}
