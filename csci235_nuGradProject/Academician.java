import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.awt.Graphics2D;
import java.io.File;
import java.io.*;

class Academician extends Entity{

	private BufferedImage image;

	Academician(Common com, String n, String img) throws IOException{
		this.common = com;
		this.name = n; 
		this.width = 40;
		this.height = 55;

		xSpeed = common.randomInt(-2, 2);
		ySpeed = common.randomInt(-2, 2);
		stateTime = common.randomInt(180, 300);

		type = new String("Academician");

		int pos1 = common.randomInt(1, common.windowWidth - this.width);
		int pos2 = common.randomInt(1, common.windowHeight - this.height);

		this.goalX = common.randomInt(1, common.windowWidth - this.width);
		this.goalY = common.randomInt(1, common.windowHeight - this.height);

		position = new Vector2D(pos1 , pos2);

		state = common.getRandomState();

		if(state.stateName.equals("Closest")){
			state = new GotoXY(common);
		}

		try{ image = ImageIO.read(new File(img));}
		catch(IOException e) {}
	}

	@Override
	public void draw(Graphics2D g2d){
		state.step(this);
		g2d.drawString(name, position.x, position.y - 5);
		g2d.drawImage(image, position.x, position.y, width, height, null);
		g2d.drawString(state.stateName, position.x, position.y + 70);

		common.rand.setSeed(System.currentTimeMillis() / (position.x + 10));
		if((common.randomInt(1,50) == 1) && (state.stateName.equals("Rest") == false)){
			common.getRandomFactory().create(position.x, position.y);
		}

		if(common.isGraduation == true){
			state = new Stationary(common);
			position.y = 200;

			if(name.equals("Hans")){
				position.x = 320;
			}else if(name.equals("Selim")){
				position.x = 450;
			}else if(name.equals("Shigeo")){
				position.x = 620;
			}else if(name.equals("Vasya")){
				position.x = 750;
			}
		}
	}
}
