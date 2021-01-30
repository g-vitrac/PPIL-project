
import java.net.*;
import java.io.*;

public class Server {

	public static void main(String[] args)throws Exception {
		int drawPort = 9111;
		try {
			ServerSocket drawServer = new ServerSocket(drawPort);
			System.out.println("serveur d�marr�");
				
			//ThreadGroup grp = new ThreadGroup("socketClients");
			while (true) {
				Socket newClient = drawServer.accept();
				System.out.println("Connexion r�ussie");
				
				DrawUser user = new DrawUser(newClient);
				user.start();
			}
		}
		catch (IOException e) { 
			System.err.println("Un probl�me est survenu sur le serveur\n"+e);
	    }		
	}

}
