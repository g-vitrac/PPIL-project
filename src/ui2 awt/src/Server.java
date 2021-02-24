
import java.io.IOException;
import java.net.*;

public class Server {
	public static void main(String[] args) throws InterruptedException, IOException {
		int drawPort = 9111;
		ServerSocket drawServer = new ServerSocket(drawPort);
		try {
			System.out.println("server is open");
			while(true) {
				Socket newClient = drawServer.accept();
				System.out.println("connection success");
				new User(newClient).start();
			}
		}
		catch (IOException e) { 
			System.err.println("Un problème est survenu sur le serveur\n"+e);
		}
		finally {
			drawServer.close();
		}
	}
}









