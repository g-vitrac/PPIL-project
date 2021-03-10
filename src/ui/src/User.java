
import java.net.*;

import draw.DrawScene;
import draw.cor.Cor;
import javafx.application.Platform;

import java.io.*;

public class User extends Thread {
    private Socket socket;
    private BufferedReader fluxIn;
    private DrawScene scene;
    
    public User(Socket socket) throws IOException, InterruptedException
    {
        this.socket = socket;
        this.fluxIn = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));            
        this.scene = new DrawSceneBuilder().scene;
    }
    
	@Override
	public void run() {
		  try {
			  String line;
			  fluxIn = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			  while ((line = fluxIn.readLine()) != null) {
				  String[] form = line.split(",");
				  System.out.println(line);
				  Platform.runLater(()->{
					  Cor.drawDetector.draw(form, scene);
				  });
			  }
		  }
		  catch (IOException e) { 
			  	System.err.println("Un problème est survenu sur le serveur\n"+e);
		  }
		  finally {
				System.out.println("La session de dessin est terminé");
		  }
	};
	
}
