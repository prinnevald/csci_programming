import java.awt.Graphics2D;

class Entity{
	public String name;
	public String type;
	public Vector2D position;
	public State state;
	public Common common;

	public int xSpeed;
	public int ySpeed;
	public int stateTime;
	public int width;
	public int height;
	public int grade;

	public int goalX;
	public int goalY;

	public void draw(Graphics2D g2d){}
	public void step(){}

}
