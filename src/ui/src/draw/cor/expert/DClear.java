package draw.cor.expert;

import draw.DrawScene;
import draw.cor.DrawDetector;

public class DClear extends DrawDetector {

	@Override
	public boolean detected(String form, DrawScene scene) {
		if (form.equalsIgnoreCase("Clear"))
			return true;
		return false;
	}

	@Override
	public void draw(String[] form, DrawScene scene) {
		scene.pane.getChildren().clear();
	}
}