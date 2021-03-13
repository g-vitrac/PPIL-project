package draw.cor.expert;

import draw.DrawScene;
import draw.cor.DrawDetector;
import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;

/**
 * The detector that recognize the polygon pattern.
 */
public class DPolygon extends DrawDetector {

	/**
	 * Try to detect a polygon from the information sent by
	 * the user.
	 *
	 * @param form The spliced information sent by the user.
	 * @param scene The DrawScene allocated to the user.
	 * @return true, if a polygon is detected.
	 */
	@Override
	public boolean detected(String form, DrawScene scene) {
		if (form.equalsIgnoreCase("PolygonG"))
			return true;
		return false;
	}

	/**
	 * Draw a circle on the DrawScene allocated to the user.
	 *
	 * @param form The information where the polygon pattern has been detected
	 * previously
	 * @param scene The DrawScene allocated to the user.
	 */
	@Override
	public void draw(String[] form, DrawScene scene) {
		double[] points = new double[form.length-2];
		for (int i = 1; i < form.length-1; i++) points[i-1] = Double.parseDouble(form[i]);
		Polygon polygon = new Polygon(points);
		polygon.setFill(Color.valueOf(form[form.length-1]));
		scene.pane.getChildren().add(polygon);
	}
}
