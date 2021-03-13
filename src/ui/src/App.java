
import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;


/**
 * The Class App.
 */
public class App extends Application {

	
	/**
	 * Start the javafx thread and change the implicit exit
	 * to prevent the javafx thread to stop if the server isn't stoped
	 * before
	 */
	@Override
	public void start(Stage primaryStage) {
		Platform.setImplicitExit(false);
	}

	/**
	 * The main method, start the server then run the javafx thread.
	 */
	public static void main(String[] args) {
		Server.server.start();
		launch(args);
	}

}
