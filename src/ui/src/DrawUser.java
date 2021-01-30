
import java.net.*;
import java.io.*;

public class DrawUser extends Thread {
	Socket socket;
	BufferedReader fluxIn;
	
	public DrawUser(Socket socket) throws IOException
	{
		this.socket = socket;
		this.fluxIn = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));	
	}
	
	@Override
	public void run()
	{
		String line;
		try {
			 while ((line = fluxIn.readLine()) != null) {			 
			     System.out.println("Le client à envoyer : ["+line+"]");
			     String[] arr = line.split(",");
			     //Remplacer switch par cor
			     switch(arr[0]) {
			     case "Circle":
			    	 System.out.println("On dessine un cercle");
			    	 //drawOval(Float.parseFloat(arr[1]), Float.parseFloat(arr[2]), Float.parseFloat(arr[3]), Float.parseFloat(arr[4]));
			    	 break;
			     case "Segment":
			    	 System.out.println("On dessine un segment");
			    	 break;
			     case "aaaa":
			    	 //drawLine(Float.parseFloat(arr[1]), Float.parseFloat(arr[2]), Float.parseFloat(arr[3]), Float.parseFloat(arr[4]));
			    	 //drawLine(Float.parseFloat(arr[1]), Float.parseFloat(arr[4]), Float.parseFloat(arr[3]), Float.parseFloat(arr[2]));
			    	 break;
			     default:
			    	 break;	
			     }
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

