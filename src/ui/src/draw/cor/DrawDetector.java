package draw.cor;

import draw.DrawScene;

/**
 * This is the actual implementation of the COR
 * design pattern. It is used to understand the different
 * informations sent by the user.
 */
public abstract class DrawDetector {
	
	/** The next detector in the COR. */
	public DrawDetector next;
		
	/**
	 * This abstract method return true if a pattern 
	 * is recognize in the information sent by the user.
	 *
	 * @param form The spliced information sent by the user.
	 * @param scene The drawScene allocated to the user.
	 * @return true, if the pattern is recognize.
	 */
	public abstract boolean detected(String form, DrawScene scene);
	
	/**
	 * Draw the form that has been recognize by the detected()
	 * method.
	 *
	 * @param form The spliced information sent by the user.
	 * @param scene The drawScene allocated to the user.
	 */
	public abstract void draw(String[] form, DrawScene scene);
	
	/**
	 * Set the next detector in the COR.
	 * 
	 * @param next The next detector that needs to be added to the COR.
	 */
	public void setNext(DrawDetector next) {
		this.next = next;
	}
	
	/**
	 * This method ask each detector if they recognize the pattern sent
	 * by the user. In the case a pattern is recognize it will use draw it
	 * on the DrawScene allocated to the user.
	 *
	 * @param form The spliced information sent by the user.
	 * @param scene The DrawScene allocated to the user.
	 */
	public void detector(String[] form, DrawScene scene) {
		if (detected(form[0], scene))
			draw(form, scene);
		else if (next != null)
			next.detector(form, scene);
		else
			System.out.println("Form is not found");
	}
}
