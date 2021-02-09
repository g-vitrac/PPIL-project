
import java.net.*;

import draw.Draw;
import draw.DrawScene;
import draw.form.DCircle;
import draw.form.DSegment;

import java.io.*;

public class User extends Thread {
	public Socket socket;
	public BufferedReader fluxIn;
	public DrawScene scene;
	
	public User(Socket socket, DrawScene scene) throws IOException
	{
		this.socket = socket;
		this.scene = scene;
		this.fluxIn = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
		System.out.println(scene.primaryStage);
		System.out.println(scene.stage);
	}

	@Override
	public void run()
	{
		String line;
		try {
			System.out.println("avant");
			
			Draw drawForm = new Draw();
			drawForm.addDetector(new DCircle());
			drawForm.addDetector(new DSegment());
			
			System.out.println("apres");
			while ((line = fluxIn.readLine()) != null) {			 
			    System.out.println("Le client à envoyer : ["+line+"]");
			    drawForm.draw(line.split(","), scene);
			}
		}
		catch(IOException e) {
			e.printStackTrace();
		}
		finally {
			System.out.println("La session de dessin est terminé");
		}
	}
}

