

/**
 * Singleton used for the synchronization between the javafx
 * thread and the server/users threads
 */
public class Semaphore {
	
	/** The static member of the singleton. */
	private static Semaphore semaphore;
	
	/** The draw scene created. */
	public boolean drawSceneCreated;
	
	/**
	 * Instantiates a new semaphore.
	 *
	 * @param drawSceneCreated the draw scene created
	 */
	private Semaphore(boolean drawSceneCreated){
		this.drawSceneCreated = drawSceneCreated;
	}
	
	/**
	 * Gives the instances of the semaphore singleton
	 * 
	 * @return The instances of the semaphore.
	 */
	public static Semaphore getInstance() {
		return semaphore;
	}
	
	static {
		semaphore = new Semaphore(false);
	}
}
