package draw;

import draw.cor.DrawDetector;

public class DrawForm {
	private DrawDetector cor;
	
	public void draw(String[] form, DrawScene scene) {			
		cor.detector(form, scene);		
	}
	
	public void addDetector(DrawDetector d) {
        assert d != null : "addDetector : detector is null";
        d.setNext(cor);
        cor = d;
    }
}
