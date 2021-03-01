package draw.cor.expert;

import draw.DrawScene;
import draw.cor.DrawDetector;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;

public class DSegment extends DrawDetector {

	@Override
	public boolean detected(String form, DrawScene scene) {
		if (form.equalsIgnoreCase("Segment"))
			return true;
		return false;
	}

	@Override
	public void draw(String[] form, DrawScene scene) {
		Line line = new Line(Float.parseFloat(form[1]), Float.parseFloat(form[2]), Float.parseFloat(form[3]), Float.parseFloat(form[4]));
		line.setStroke(Color.valueOf(form[5]));
		scene.pane.getChildren().add(line);
	}
}