package draw.cor;

import draw.DrawForm;
import draw.cor.expert.DCircle;
import draw.cor.expert.DClear;
import draw.cor.expert.DPolygon;
import draw.cor.expert.DResize;
import draw.cor.expert.DSegment;

public class Cor {
	
	static public Cor cor;
	
	static public DrawForm drawDetector;
	
	static {
		cor = new Cor();
	}
		
	Cor(){
		drawDetector = new DrawForm();
        drawDetector.addDetector(new DCircle());
        drawDetector.addDetector(new DClear());
        drawDetector.addDetector(new DPolygon());
        drawDetector.addDetector(new DResize());
        drawDetector.addDetector(new DSegment());
	}
}
