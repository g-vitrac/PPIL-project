
import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;

public class App extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		Platform.setImplicitExit(false);
	}

	public static void main(String[] args) {
		Server.server.start();
		launch(args);
	}

}
