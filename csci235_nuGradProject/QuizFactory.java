class QuizFactory extends AssessmentFactory{
	public QuizFactory(Common com){ this.common = com; }

	public void create(int x, int y){
		Quiz q = new Quiz(x, y, common.randomInt(3, 5));
		common.assessments.add(q);
	}
}
