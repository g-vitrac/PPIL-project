

import draw.DrawScene;
import javafx.application.Platform;

public class DrawSceneBuilder{
	
	public DrawScene scene;

	public DrawSceneBuilder() throws InterruptedException {
		Platform.runLater(() -> {
			synchronized(Semaphore.semaphore) {
				scene = new DrawScene();
				Semaphore.semaphore.notifyAll();
			}
		});
		synchronized (Semaphore.semaphore) {
			while(scene == null) {
				Semaphore.semaphore.wait();
			}
		}
	}
}
