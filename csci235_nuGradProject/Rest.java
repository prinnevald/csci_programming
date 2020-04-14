class Rest extends State{

	public Rest(Common com){
		this.common = com;
		stateName = new String("Rest");
	}

	@Override
	public void step(Entity e){
		e.stateTime = e.stateTime - 1;
		
		if(e.stateTime == 0){
			e.stateTime = common.randomInt(180, 300);
			e.state = common.getRandomState();
			if(e.type.equals("Academician") && e.state.stateName.equals("Closest")){
				e.state = new ZigZag(common);
			}
		}
	}
}
