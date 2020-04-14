import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.util.ArrayList;
import java.awt.Graphics2D;
import java.io.File;
import java.io.*;

class Speaker extends Entity{

	private BufferedImage image;

	Speaker(Common com, String n, String img, int x, int y) throws IOException{
		this.common = com;
		this.name = n;
		this.width = 40;
		this.height = 55;

		this.position = new Vector2D(x, y);
		this.state = new Invisible(common);

		try{ image = ImageIO.read(new File(img));}
		catch(IOException e) {}
	}

	@Override
	public void draw(Graphics2D g2d){
		if (state.stateName.equals("Invisible") == false){
			state.step(this);
			g2d.drawString(name, position.x, position.y - 5);
			g2d.drawImage(image, position.x, position.y, width, height, null);
			g2d.drawString(state.stateName, position.x, position.y + 70);
		}

		if(common.isGraduation == true){ state = new Stationary(common); }
	}
}

