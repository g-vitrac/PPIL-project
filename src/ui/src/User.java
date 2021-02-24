
import java.net.*;

import draw.Draw;
import draw.DrawScene;
import draw.DrawSceneBuilder;
import draw.form.DCircle;
import draw.form.DClear;
import draw.form.DResize;
import draw.form.DSegment;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.beans.Observable;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableStringValue;
import javafx.beans.value.ObservableValue;
import javafx.concurrent.Service;
import javafx.concurrent.Task;
import javafx.stage.Stage;

import java.io.*;

public class User extends Thread {
    public Socket socket;
    public BufferedReader fluxIn;
    DrawScene scene;
    
    public Draw drawForm = new Draw();
    
    public User(Socket socket) throws IOException, InterruptedException
    {
        this.socket = socket;

        this.fluxIn = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));

        drawForm.addDetector(new DCircle());
        drawForm.addDetector(new DSegment());
        drawForm.addDetector(new DResize());
        drawForm.addDetector(new DClear());
        
        scene = new DrawScene();
        
        //DrawSceneBuilder builder = new DrawSceneBuilder();
        //Platform.runLater(builder);
        //System.err.println("Avant join");
        //scene = builder.scene;
        //System.err.println(scene);
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
