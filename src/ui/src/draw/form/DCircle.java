package draw.form;

import java.awt.geom.Ellipse2D;

import draw.DrawDetector;
import draw.DrawScene;
import javafx.scene.shape.Circle;

public class DCircle extends DrawDetector {

	@Override
	public boolean detected(String[] form, DrawScene scene) {
		if (form[0].equalsIgnoreCase("Circle"))
			return true;
		return false;
	}

	@Override
	public void draw(String[] form, DrawScene scene) {
		//Ellipse2D circle = new Ellipse2D.Double(Double.parseDouble(form[1]), Double.parseDouble(form[2]), Double.parseDouble(form[3]), Double.parseDouble(form[3]));
		//scene.graphics.fill(circle);
		Circle circle = new Circle(Float.parseFloat(form[1]), Float.parseFloat(form[2]),Float.parseFloat(form[3]));
		System.out.println(scene.primaryStage);
		System.out.println(scene.stage);
		System.out.println(scene.pane);
		scene.pane.getChildren().add(circle);
	}
}
