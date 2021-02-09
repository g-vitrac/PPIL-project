
import java.io.IOException;
import java.net.*;

import draw.DrawScene;
import javafx.application.Application;
import javafx.stage.Stage;

/*
public class Server {
	public static void main(String[] args) throws IOException {
		int drawPort = 9111;
		ServerSocket drawServer = new ServerSocket(drawPort);
		System.out.println("server is open");
		try {
			while (true) {
				Socket newClient = drawServer.accept();
				System.out.println("connection success");
				
				User user = new User(newClient);
				user.start();
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
*/
public class Server extends Application {
	@Override
	public void start(Stage primaryStage) throws Exception {
		int drawPort = 9111;
		ServerSocket drawServer = new ServerSocket(drawPort);
		System.out.println("server is open");
		System.out.println(primaryStage);
		try {
			while (true) {
				Socket newClient = drawServer.accept();
				System.out.println("connection success");
				
				User user = new User(newClient, new DrawScene(primaryStage, new Stage()));
				user.start();
			}
		}
		catch (IOException e) { 
			System.err.println("Un problème est survenu sur le serveur\n"+e);
		}
		finally {
			drawServer.close();
		}	
	} 
	public static void main(String args[]){           
		launch(args);      
	}
}