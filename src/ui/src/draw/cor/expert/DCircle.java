package draw.cor.expert;

import draw.DrawScene;
import draw.cor.DrawDetector;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

public class DCircle extends DrawDetector {

	@Override
	public boolean detected(String form, DrawScene scene) {
		if (form.equalsIgnoreCase("Circle"))
			return true;
		return false;
	}

	@Override
	public void draw(String[] form, DrawScene scene) {
		Circle circle = new Circle(Float.parseFloat(form[1]), Float.parseFloat(form[2]),Float.parseFloat(form[3]), Color.valueOf(form[4]));
		scene.pane.getChildren().add(circle);
	}
}
