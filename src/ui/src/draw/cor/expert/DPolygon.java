package draw.cor.expert;

import draw.DrawScene;
import draw.cor.DrawDetector;
import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;

public class DPolygon extends DrawDetector {

	@Override
	public boolean detected(String form, DrawScene scene) {
		if (form.equalsIgnoreCase("Polygon"))
			return true;
		return false;
	}

	@Override
	public void draw(String[] form, DrawScene scene) {
		double[] points = new double[form.length-2];
		for (int i = 1; i < form.length-1; i++) points[i-1] = Double.parseDouble(form[i]);
		Polygon polygon = new Polygon(points);
		polygon.setFill(Color.valueOf(form[form.length-1]));
		scene.pane.getChildren().add(polygon);
	}
}
