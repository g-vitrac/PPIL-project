
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.*;
import java.util.Vector;

import draw.Draw;
import draw.DrawScene;
import draw.form.DCircle;
import draw.form.DSegment;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.concurrent.Task;
import javafx.stage.Stage;

public class Server extends Thread{

	@Override
	public void run() {
		int drawPort = 9111;
		try {
			ServerSocket drawServer = new ServerSocket(drawPort);
			System.out.println("server is open");
			do{
				Socket newClient = drawServer.accept();
				System.out.println("connection success");
					Platform.runLater(() -> {
						try {
							User user = new User(newClient);
							user.start();
						} catch (IOException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					});
				
				System.out.println("User started");
				
				//System.out.println("User created");
			}while(true);
		}
		catch (IOException e) { 
			System.err.println("Un problème est survenu sur le serveur\n"+e);
		}
	}
}









