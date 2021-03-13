package draw;

import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

/**
 * This class modelize the window on which
 * the user as access to draw the different form wanted.
 */
public class DrawScene {
	
	public Stage stage;
	
	public AnchorPane pane;
	
	/**
	 * Instantiates a new draw scene.
	 */
	public DrawScene() {
		this.stage = new Stage();
		stage.setTitle("Draw Scene");
		pane = new AnchorPane();
		Scene scene = new Scene(pane);
		stage.setScene(scene);
		stage.show();	
	}
}
