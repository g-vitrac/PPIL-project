package draw.form;

import draw.DrawDetector;
import draw.DrawScene;

public class DResize extends DrawDetector {

	@Override
	public boolean detected(String[] form, DrawScene scene) {
		if (form[0].equalsIgnoreCase("Resize"))
			return true;
		return false;
	}

	@Override
	public void draw(String[] form, DrawScene scene) {
		scene.stage.setWidth(Double.parseDouble((form[1])));
		scene.stage.setHeight(Double.parseDouble((form[2])));
	}
}