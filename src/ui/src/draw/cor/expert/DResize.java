package draw.cor.expert;

import draw.DrawScene;
import draw.cor.DrawDetector;

/**
 * The detector that recognize the resize pattern.
 */
public class DResize extends DrawDetector {

	/**
	 * Try to detect the resize instruction from the information sent by
	 * the user.
	 *
	 * @param form The spliced information sent by the user.
	 * @param scene The DrawScene allocated to the user.
	 * @return true, if the resize instruction is detected.
	 */
	@Override
	public boolean detected(String form, DrawScene scene) {
		if (form.equalsIgnoreCase("Resize"))
			return true;
		return false;
	}

	/**
	 * Draw a circle on the DrawScene allocated to the user.
	 *
	 * @param form The information where the resize instruction pattern has been detected
	 * previously
	 * @param scene The DrawScene allocated to the user.
	 */
	@Override
	public void draw(String[] form, DrawScene scene) {
		scene.stage.setWidth(Double.parseDouble((form[1])));
		scene.stage.setHeight(Double.parseDouble((form[2])));
	}
}