import java.awt.Color;
import java.awt.Graphics2D;

class Quiz extends Assessment{
	public Quiz(int xx, int yy, int pt){
		this.position = new Vector2D(xx, yy);
		this.points = pt;
		this.isVisible = true;
	}

	public void draw(Graphics2D g2d){
		if(isVisible == true){

			int[] xpts = {position.x + 15, position.x, position.x + 30};
			int[] ypts = {position.y, position.y + 30, position.y + 30};

			g2d.setColor(Color.blue);
			g2d.fillPolygon(xpts, ypts, 3);
			g2d.setColor(Color.white);
			g2d.drawString(Integer.toString(this.points), position.x + 10, position.y + 20);
		}
	}
}
