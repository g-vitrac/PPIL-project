package draw;

public class Draw {
	private DrawDetector cor;
	
	public void draw(String[] form, DrawScene scene) {			
		cor.detector(form, scene);		
	}
	
	public void addDetector(DrawDetector d) {
        assert d != null : "Detector is null";
        d.setSuivant(cor);
        cor = d;
    }
}
