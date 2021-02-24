package draw;

import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.io.IOException;
import javax.swing.JFrame;

public class DrawScene extends Frame {
	public Graphics graphics;
	
	public DrawScene() throws IOException {
		this.setIgnoreRepaint(true);
		//this.setSize(1380, 980);
		this.setVisible(true);
		this.graphics = this.getGraphics();
	}
}