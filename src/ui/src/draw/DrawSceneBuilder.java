package draw;

public class DrawSceneBuilder extends Thread {
	
	public DrawScene scene;

	@Override
	public void run() {
		scene = new DrawScene();
		System.err.println("Fin builder");
	}

}
