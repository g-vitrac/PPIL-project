
import java.net.*;

import draw.Draw;
import draw.DrawScene;
import draw.cor.expert.DCircle;
import draw.cor.expert.DClear;
import draw.cor.expert.DResize;
import draw.cor.expert.DSegment;
import javafx.application.Platform;

import java.io.*;

public class User extends Thread {
    private Socket socket;
    private BufferedReader fluxIn;
    private DrawScene scene;
    private Draw drawForm;
    
    public User(Socket socket) throws IOException, InterruptedException
    {
        this.socket = socket;
        this.fluxIn = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
        this.drawForm = new Draw();
        
        drawForm.addDetector(new DCircle());
        drawForm.addDetector(new DSegment());
        drawForm.addDetector(new DResize());
        drawForm.addDetector(new DClear());
                
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
					  drawForm.draw(form, scene);
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
