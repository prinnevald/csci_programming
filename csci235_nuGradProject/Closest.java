class Closest extends State{

	public Closest(Common com){
		this.common = com;
		stateName = new String("Closest");
	}
	
	public void step(Entity e){
		e.stateTime = e.stateTime - 1;
	
		Assessment clo = new Lab(9999, 9999, 0);
		
		if (common.assessments.size() != 0){

			for(Assessment a : common.assessments){
				if(common.checkDist(a.position.x, a.position.y, e) < common.checkDist(clo.position.x, clo.position.y, e)
				   && a.isVisible == true){ clo = a; }
			}

		if(e.position.x < clo.position.x){
			e.position.x = e.position.x + 1;
		} else if(e.position.x > clo.position.x){
			e.position.x = e.position.x - 1;
		}

		if(e.position.y < clo.position.y){
			e.position.y = e.position.y + 1;
		} else if(e.position.y > clo.position.y){
			e.position.y = e.position.y - 1;
		}

		if(e.stateTime == 0){e.stateTime = common.randomInt(180,300); e.state = common.getRandomState(); }

		} else { e.state = common.getRandomState(); }
	}
}
