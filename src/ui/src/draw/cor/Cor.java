package draw.cor;

import draw.DrawForm;
import draw.cor.expert.DCircle;
import draw.cor.expert.DClear;
import draw.cor.expert.DPolygon;
import draw.cor.expert.DResize;
import draw.cor.expert.DSegment;

/**
 * This is the singleton that instantiates the COR design
 *  pattern.
 */
public class Cor {
	
	/** The actual COR. */
	static public Cor cor;
	
	/** The draw detector. */
	static public DrawForm drawDetector;
	
	static {
		cor = new Cor();
	}
		
	/**
	 * Instantiates a new COR for the singleton.
	 */
	private Cor(){
		drawDetector = new DrawForm();
        drawDetector.addDetector(new DCircle());
        drawDetector.addDetector(new DClear());
        drawDetector.addDetector(new DPolygon());
        drawDetector.addDetector(new DResize());
        drawDetector.addDetector(new DSegment());
	}
}
