package draw.cor;

import draw.DrawScene;

public abstract class DrawDetector {
	public DrawDetector next;
		
	public abstract boolean detected(String form, DrawScene scene);
	
	public abstract void draw(String[] form, DrawScene scene);
	
	public void setNext(DrawDetector next) {
		this.next = next;
	}
	
	public void detector(String[] form, DrawScene scene) {
		if (detected(form[0], scene))
			draw(form, scene);
		else if (next != null)
			next.detector(form, scene);
		else
			System.out.println("Form is not found");
	}
}
