
import java.io.IOException;
import java.net.*;

import javafx.application.Platform;

public class Server extends Thread {
	
	static public Server server;
	static public ServerSocket drawServer;
	static public int drawPort;
	
	static {
		server = new Server(9111);
	}
	
	Server(int drawPort){
		Server.drawPort = drawPort;
		drawServer = null;
	}
	
	@Override
	public void run() {
		try {
			drawServer = new ServerSocket(drawPort);
			System.out.println("server is open");
			while(true) {
				Socket newClient = drawServer.accept();
				System.out.println("connection success");
				new User(newClient).start();
			}
		}
		catch (IOException | InterruptedException e) { 
			System.err.println("Un problème est survenu sur le serveur\n"+e);
		}
		finally {
			try {
				drawServer.close();
				Platform.exit();
			} catch (IOException e) {
				System.err.println("Problème fermeture serveur");
			}
		}
	}
}












