
import java.io.IOException;
import java.net.*;

import javafx.application.Platform;

/**
 * The Class Server.
 */
public class Server extends Thread {
	
	/** The server. */
	static public Server server;
	
	/** The draw server. */
	static public ServerSocket drawServer;
	
	/** The port used for the application. */
	static public int drawPort;
	
	static {
		server = new Server(9111);
	}
	
	/**
	 * Instantiates a new server.
	 *
	 * @param drawPort The port we use for the application
	 */
	Server(int drawPort){
		Server.drawPort = drawPort;
		drawServer = null;
	}
	
	/**
	 * Run the server.
	 */
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












