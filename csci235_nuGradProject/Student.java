import java.util.ArrayList;
import java.awt.Graphics2D;
import java.awt.Color;
import java.io.File;
import java.io.*;

class Student extends Entity{
	public boolean hasGraduated;
	public ArrayList<Assessment> temp;

	Student(Common com, String n) throws IOException{
		this.common = com;
		this.name = n; 
		this.width = 20;
		this.height = 20;

		grade = 0;
		hasGraduated = false;

		xSpeed = common.randomInt(-2, 2);
		ySpeed = common.randomInt(-2, 2);
		stateTime = common.randomInt(180, 300);

		int pos1 = common.randomInt(1, common.windowWidth - this.width);
		int pos2 = common.randomInt(1, common.windowHeight - this.height);

		this.goalX = common.randomInt(1, common.windowWidth - this.width);
		this.goalY = common.randomInt(1, common.windowHeight - this.height);

		position = new Vector2D(pos1 , pos2);
		type = new String("Student");
		
		state = common.getRandomState();
		if(state.stateName == "Closest" && common.assessments.size() == 0){state = new Rest(common); }
	}

	@Override
	public void draw(Graphics2D g2d){
			state.step(this);
			g2d.setColor(Color.black);
			g2d.drawString(name, position.x, position.y - 5);
			g2d.fillOval(position.x, position.y, 30, 30);
			g2d.drawString(state.stateName, position.x, position.y + 45);
			g2d.setColor(Color.white);
			g2d.drawString(Integer.toString(grade), position.x + 10, position.y + 20);
			g2d.setColor(Color.black);

			if (common.assessments.size() != 0){
				for(Assessment a : common.assessments){
					if(common.checkDist(a.position.x, a.position.y, this) < 15 && a.isVisible == true){
						a.isVisible = false;
						grade = grade + a.points;
					}
				}
			}

			if(grade > 99){ hasGraduated = true; 
							state = new Stationary(common); 
							position.x = 565 + xSpeed*10;
							position.y = 315 + ySpeed*10; }
	}


}
