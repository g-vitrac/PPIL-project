package draw.form;

import java.awt.Graphics;

import javax.swing.JPanel;
import javax.swing.JTextField;

import draw.DrawDetector;
import draw.DrawScene;

public class DCircle extends DrawDetector {

	@Override
	public boolean detected(String[] form, DrawScene scene) {
		if (form[0].equalsIgnoreCase("Circle"))
			return true;
		return false;
	}

	@Override
	public void draw(String[] form, DrawScene scene) {
		System.out.println("IN CIRCLE");
		scene.graphics.fillOval(Integer.parseInt(form[1]), Integer.parseInt(form[2]), Integer.parseInt(form[3]), Integer.parseInt(form[3]));
	}
}
