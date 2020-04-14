class ZigZag extends State{

	public ZigZag(Common com){
		this.common = com;
		stateName = new String("ZigZag");
	}

	@Override
	public void step(Entity e){

		e.stateTime = e.stateTime - 1;
		e.position.x = e.position.x + e.xSpeed;
		e.position.y = e.position.y + e.ySpeed;

		if ((e.position.x > common.windowWidth - e.width) || (e.position.x < 0)){ e.xSpeed = -e.xSpeed; }
		if ((e.position.y > common.windowHeight - e.height) || (e.position.y < 0)){ e.ySpeed = -e.ySpeed; }

		if(e.stateTime == 0){
			e.stateTime = common.randomInt(180, 300);
			e.state = common.getRandomState();
			if(e.type.equals("Academician") && e.state.stateName.equals("Closest")){
				e.state = new Rest(common);
			}
		}
	}
}
