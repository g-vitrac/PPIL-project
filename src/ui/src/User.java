
import java.net.*;

import draw.DrawScene;
import draw.cor.Cor;
import javafx.application.Platform;

import java.io.*;

// TODO: Auto-generated Javadoc
/**
 * The Class User.
 */
public class User extends Thread {
    
    /** The socket. */
    private Socket socket;
    
    /** The flux in. */
    private BufferedReader fluxIn;
    
    /** The scene. */
    private DrawScene scene;
    
    /**
     * Instantiates a new user.
     *
     * @param socket the socket
     * @throws IOException Signals that an I/O exception has occurred.
     * @throws InterruptedException the interrupted exception
     */
    public User(Socket socket) throws IOException, InterruptedException
    {
        this.socket = socket;
        this.fluxIn = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));            
        this.scene = new DrawSceneBuilder().scene;
    }

	/**
	 * Run a thread waiting for information from the client.
	 */
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
