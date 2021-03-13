package draw.cor.expert;

import draw.DrawScene;
import draw.cor.DrawDetector;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;

/**
 * The detector that recognize the segment pattern.
 */
public class DSegment extends DrawDetector {

	/**
	 * Try to detect a segment from the information sent by
	 * the user.
	 *
	 * @param form The spliced information sent by the user.
	 * @param scene The DrawScene allocated to the user.
	 * @return true, if a segment is detected.
	 */
	@Override
	public boolean detected(String form, DrawScene scene) {
		if (form.equalsIgnoreCase("Segment"))
			return true;
		return false;
	}

	/**
	 * Draw a circle on the DrawScene allocated to the user.
	 *
	 * @param form The information where the segment pattern has been detected
	 * previously
	 * @param scene The DrawScene allocated to the user.
	 */
	@Override
	public void draw(String[] form, DrawScene scene) {
		Line line = new Line(Float.parseFloat(form[1]), Float.parseFloat(form[2]), Float.parseFloat(form[3]), Float.parseFloat(form[4]));
		line.setStroke(Color.valueOf(form[5]));
		scene.pane.getChildren().add(line);
	}
}
