package draw.form;

import draw.DrawDetector;
import draw.DrawScene;

public class DClear extends DrawDetector {

	@Override
	public boolean detected(String[] form, DrawScene scene) {
		if (form[0].equalsIgnoreCase("Clear"))
			return true;
		return false;
	}

	@Override
	public void draw(String[] form, DrawScene scene) {
		scene.pane.getChildren().clear();
	}
}