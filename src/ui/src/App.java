import java.io.IOException;

import javafx.application.Application;
import javafx.stage.Stage;

public class App extends Application {

	@Override
	public void start(Stage primaryStage) throws IOException {
		
		System.out.println("App is running");
		
		try {
		Server serv = new Server();
		serv.start();
		}catch(Exception e) {
			e.printStackTrace();
		}
		//primaryStage.show();
	}

	public static void main(String[] args) {
		launch(args);
	}

}
