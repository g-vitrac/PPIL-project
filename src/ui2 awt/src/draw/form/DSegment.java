package draw.form;

import draw.DrawDetector;
import draw.DrawScene;
import javafx.application.Platform;
import javafx.scene.shape.Line;

public class DSegment extends DrawDetector {

	@Override
	public boolean detected(String[] form, DrawScene scene) {
		if (form[0].equalsIgnoreCase("Segment"))
			return true;
		return false;
	}

	@Override
	public void draw(String[] form, DrawScene scene) {
		scene.graphics.drawLine(Integer.parseInt(form[1]), Integer.parseInt(form[2]), Integer.parseInt(form[3]), Integer.parseInt(form[4]));
	}
}
