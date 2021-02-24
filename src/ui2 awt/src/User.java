
import java.net.*;

import draw.Draw;
import draw.DrawScene;
import draw.form.DCircle;
import draw.form.DClear;
import draw.form.DResize;
import draw.form.DSegment;

import java.io.*;

public class User extends Thread {
    public Socket socket;
    public BufferedReader fluxIn;
    public DrawScene scene;   
    public Draw drawForm;
    
    public User(Socket socket) throws IOException, InterruptedException
    {
        this.socket = socket;
        this.fluxIn = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
        this.drawForm = new Draw();
        
        drawForm.addDetector(new DCircle());
        drawForm.addDetector(new DSegment());
        drawForm.addDetector(new DResize());
        drawForm.addDetector(new DClear());
        
        this.scene = new DrawScene();
    }
    
	@Override
	public void run() {
		  try {
			  String line;
			  BufferedReader fluxIn = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			  while ((line = fluxIn.readLine()) != null) {
				  String[] form = line.split(",");
				  System.out.println(line);
				  drawForm.draw(form, scene);
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
