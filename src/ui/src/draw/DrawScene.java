package draw;

import java.awt.Graphics2D;
import java.io.IOException;

import javax.swing.JFrame;

import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

/*
public class DrawScene extends JFrame {
	public Graphics2D graphics;
	
	public DrawScene() throws IOException {
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(1000, 600);
		this.setIgnoreRepaint(true);
		this.setLocationRelativeTo(null);
		this.setVisible(true);
		this.graphics = (Graphics2D) getGraphics();
	}
}
*/

public class DrawScene {
	public Stage stage;
	public AnchorPane pane;
	
	public DrawScene() {
		this.stage = new Stage();
		stage.setTitle("Draw Scene");
		pane = new AnchorPane();
		Scene scene = new Scene(pane);
		stage.setScene(scene);
		System.out.println("Pane : "+pane);
		stage.show();	
	}
}
