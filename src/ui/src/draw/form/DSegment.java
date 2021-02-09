package draw.form;

import draw.DrawDetector;
import draw.DrawScene;

public class DSegment extends DrawDetector {

	@Override
	public boolean detected(String[] form, DrawScene scene) {
		if (form[0].equalsIgnoreCase("Segment"))
			return true;
		return false;
	}

	@Override
	public void draw(String[] form, DrawScene scene) {	
	}
}
