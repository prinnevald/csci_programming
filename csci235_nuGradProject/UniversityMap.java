import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.awt.Graphics2D;
import java.io.File;
import java.io.*;

class UniversityMap extends Entity{

	private BufferedImage image;

	UniversityMap(Common com) throws IOException{
		this.common = com;
		name = new String("map");
		position = new Vector2D(0, 0);

		state = new Stationary(common);

		try{ image = ImageIO.read(new File("source/NUMap-Faded.jpg"));}
		catch(IOException e) {}
	}

	@Override
	public void draw(Graphics2D g2d){
		state.step(this);
		g2d.drawImage(image, position.x, position.y, common.windowWidth, common.windowHeight, null);
	}
}
