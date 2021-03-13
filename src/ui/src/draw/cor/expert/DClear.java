package draw.cor.expert;

import draw.DrawScene;
import draw.cor.DrawDetector;

/**
 * The detector that recognize the clear pattern.
 */
public class DClear extends DrawDetector {

	/**
	 * Try to detect the clear instruction from the information sent by
	 * the user.
	 *
	 * @param form The spliced information sent by the user.
	 * @param scene The DrawScene allocated to the user.
	 * @return true, if the clear instruction is detected.
	 */
	@Override
	public boolean detected(String form, DrawScene scene) {
		if (form.equalsIgnoreCase("Clear"))
			return true;
		return false;
	}

	/**
	 * Draw a circle on the DrawScene allocated to the user.
	 *
	 * @param form The information where the clear instruction pattern has been detected
	 * previously
	 * @param scene The DrawScene allocated to the user.
	 */
	@Override
	public void draw(String[] form, DrawScene scene) {
		scene.pane.getChildren().clear();
	}
}