
public class Semaphore {
	
	public static Semaphore semaphore;
	
	public boolean drawSceneCreated;
	
	Semaphore(boolean drawSceneCreated){
		this.drawSceneCreated = drawSceneCreated;
	}
	
	static {
		semaphore = new Semaphore(false);
	}
}
