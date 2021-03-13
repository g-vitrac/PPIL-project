package draw;

import draw.cor.DrawDetector;

/**
 * Implement the COR design pattern to detect the different
 * form send by the user.
 */
public class DrawForm {
	
	/** The COR. */
	private DrawDetector cor;
	
	/**
	 * Ask the COR to draw the form on the scene
	 * @param form The form send by the user
	 * @param scene The scene which will host the drawing
	 */
	public void draw(String[] form, DrawScene scene) {			
		cor.detector(form, scene);		
	}
	
	/**
	 * Add a specific detector to the COR. 
	 * @param d The new detector to add to the COR.
	 */
	public void addDetector(DrawDetector d) {
        assert d != null : "addDetector : detector is null";
        d.setNext(cor);
        cor = d;
    }
}
