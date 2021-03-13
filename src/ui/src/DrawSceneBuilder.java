
import draw.DrawScene;
import javafx.application.Platform;

/**
 * This class makes it possible for the users
 * to create windows thanks to the Platform.runLater()
 * method.
 */
public class DrawSceneBuilder{
	
	/** The scene the will be generated. */
	public DrawScene scene;

	/**
	 * Instantiates a new draw scene builder.
	 *
	 * @throws InterruptedException Throws this exception
	 * if the javafx thread never execute the code in the
	 * Platform.runLater() method. See Platform.runLeter()
	 * from javafx for more information.
	 */
	public DrawSceneBuilder() throws InterruptedException {
		Platform.runLater(() -> {
			synchronized(Semaphore.getInstance()) {
				scene = new DrawScene();
				Semaphore.getInstance().notifyAll();
			}
		});
		synchronized (Semaphore.getInstance()) {
			while(scene == null) {
				Semaphore.getInstance().wait();
			}
		}
	}
}
