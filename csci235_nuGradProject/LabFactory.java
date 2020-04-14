class LabFactory extends AssessmentFactory{
	public LabFactory(Common com){ this.common = com; }

	public void create(int x, int y){
		Lab lab = new Lab(x, y, common.randomInt(2, 4));
		common.assessments.add(lab);
	}
}
