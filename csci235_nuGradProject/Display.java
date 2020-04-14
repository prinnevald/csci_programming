import java.awt.Graphics2D;
import javax.swing.JPanel;
import java.awt.Dimension;
import java.awt.Graphics;
import java.io.*;

class Display extends JPanel{
	
	public Common common;

	Display(Common com){
		this.common = com;
	}

	public Dimension getPreferredSize(){
    	return new Dimension(common.windowWidth, common.windowHeight);
    }
	
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		Graphics2D g2d = (Graphics2D) g;

		common.checkIsGrad();

		common.map.draw(g2d);
		if (common.assessments.size() != 0 && common.isGraduation == false){ for(Assessment a: common.assessments){ a.draw(g2d); } } 
		for(Student s: common.students) { common.rand.setSeed(System.currentTimeMillis()); s.draw(g2d); }
		for(Academician a: common.academicians){ common.rand.setSeed(System.currentTimeMillis()); a.draw(g2d); }
		for(Speaker s: common.speakers) { s.draw(g2d); }

		if(common.isGraduation){g2d.drawString("NU GRADUATION CEREMONY", 450, 100);}

		repaint();
	}
}
