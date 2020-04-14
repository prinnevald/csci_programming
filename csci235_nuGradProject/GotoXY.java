class GotoXY extends State{

	public GotoXY(Common com){
		this.common = com;
		stateName = new String("GotoXY");
	}

	@Override
	public void step(Entity e){

		if(e.position.x < e.goalX){
			e.position.x = e.position.x + 1;
		} else if(e.position.x > e.goalX){
			e.position.x = e.position.x - 1;
		}

		if(e.position.y < e.goalY){
			e.position.y = e.position.y + 1;
		} else if(e.position.y > e.goalY){
			e.position.y = e.position.y - 1;
		}

		if((e.position.x == e.goalX) && (e.position.y == e.goalY)){
			e.state = common.getRandomState();
			if(e.type.equals("Academician") && e.state.stateName.equals("Closest")){
				e.state = new GotoXY(common);
			}
		}
	}
}
