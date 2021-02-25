package draw;

import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

public class DrawScene {
	public Stage stage;
	public AnchorPane pane;
	
	public DrawScene() {
		this.stage = new Stage();
		stage.setTitle("Draw Scene");
		pane = new AnchorPane();
		Scene scene = new Scene(pane);
		stage.setScene(scene);
		stage.show();	
	}
}
