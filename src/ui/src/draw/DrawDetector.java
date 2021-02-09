package draw;

public abstract class DrawDetector {
	public DrawDetector suivant;
		
	public abstract boolean detected(String[] form, DrawScene scene);
	
	public abstract void draw(String[] form, DrawScene scene);
	
	public void setSuivant(DrawDetector suivant) {
		this.suivant = suivant;
	}
	
	public void detector(String[] form, DrawScene scene) {
		if (detected(form, scene))
			draw(form, scene);
		else if (suivant != null)
			suivant.detector(form, scene);
		else
			System.out.println("Form is not found");
	}
}
