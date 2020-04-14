import java.awt.Color;
import java.awt.Graphics2D;

class Homework extends Assessment{
	public Homework(int xx, int yy, int pt){
		this.position = new Vector2D(xx, yy);
		this.points = pt;
		this.isVisible = true;
	}

	public void draw(Graphics2D g2d){
		if(isVisible == true){
			g2d.setColor(Color.green);
			g2d.fillRect(position.x, position.y, 30, 30);
			g2d.setColor(Color.white);
			g2d.drawString(Integer.toString(this.points), position.x + 10, position.y + 20);
		}	
	}
}
