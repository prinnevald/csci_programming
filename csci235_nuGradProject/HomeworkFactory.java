class HomeworkFactory extends AssessmentFactory{
	public HomeworkFactory(Common com){ this.common = com; }

	public void create(int x, int y){
		Homework hw = new Homework(x, y, common.randomInt(1, 3));
		common.assessments.add(hw);
	}
}
