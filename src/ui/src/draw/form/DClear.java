package draw.form;

import java.awt.geom.Ellipse2D;

import draw.DrawDetector;
import draw.DrawScene;
import javafx.application.Platform;

public class DClear extends DrawDetector {

	@Override
	public boolean detected(String[] form, DrawScene scene) {
		if (form[0].equalsIgnoreCase("Clear"))
			return true;
		return false;
	}

	@Override
	public void draw(String[] form, DrawScene scene) {
		Platform.runLater(() -> {
			scene.pane.getChildren().clear();
		});
	}
}