package draw.cor.expert;

import draw.DrawScene;
import draw.cor.DrawDetector;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

/**
 * The detector that recognize the circle pattern.
 */
public class DCircle extends DrawDetector {

	/**
	 * Try to detect a circle from the information sent by
	 * the user.
	 *
	 * @param form The spliced information sent by the user.
	 * @param scene The DrawScene allocated to the user.
	 * @return true, if a circle is detected.
	 */
	@Override
	public boolean detected(String form, DrawScene scene) {
		if (form.equalsIgnoreCase("Circle"))
			return true;
		return false;
	}

	/**
	 * Draw a circle on the DrawScene allocated to the user.
	 *
	 * @param form The information where the circle pattern has been detected
	 * previously
	 * @param scene The DrawScene allocated to the user.
	 */
	@Override
	public void draw(String[] form, DrawScene scene) {
		Circle circle = new Circle(Float.parseFloat(form[1]), Float.parseFloat(form[2]),Float.parseFloat(form[3]), Color.valueOf(form[4]));
		scene.pane.getChildren().add(circle);
	}
}
