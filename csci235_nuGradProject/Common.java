import java.util.ArrayList;
import java.util.Random;
import java.io.*;

class Common{

	public Random rand;
	
	public int windowWidth;
	public int windowHeight;
	public boolean isGraduation;
	private boolean tempGrad;

	public UniversityMap map;
	public ArrayList<Academician> academicians;
	public ArrayList<Assessment> assessments;
	public ArrayList<Speaker> speakers;
	public ArrayList<Student> students;
	public ArrayList<State> states;
	public ArrayList<AssessmentFactory> factories;

	public String[] studentNames = {"Aldamzhar", "Dinke", "Anchik", "Aida", "Danel",
									"Abay", "Aneliya", "Nurda", "Aika", "Chechen"};

	public Common() throws IOException{
		rand = new Random();

		windowHeight = 400;
		windowWidth = 800;
		isGraduation = false;

		try { map = new UniversityMap(this); }
		catch(IOException e) {}

		academicians = new ArrayList<>();
		speakers = new ArrayList<>();
		students = new ArrayList<>();
		states = new ArrayList<>();
		factories = new ArrayList<>();
		assessments = new ArrayList<>();

		states.add(new Rest(this));
		states.add(new ZigZag(this));
		states.add(new GotoXY(this));
		states.add(new Closest(this));
	
		factories.add(new LabFactory(this));
		factories.add(new HomeworkFactory(this));
		factories.add(new QuizFactory(this));

		academicians.add(new Academician(this, "Hans", "source/HansDeNivelle.gif"));
		academicians.add(new Academician(this, "Selim", "source/SelimTemizer.gif"));
		academicians.add(new Academician(this, "Vasya", "source/VassiliosTourassis.gif"));
		academicians.add(new Academician(this, "Shigeo", "source/ShigeoKatsu.gif"));

		speakers.add(new Speaker(this, "Tokayev", "source/KassymJomartTokayev.gif", 450, 300));
		speakers.add(new Speaker(this, "Nazarbayev", "source/NursultanNazarbayev.gif", 620, 300));

		for(String n: studentNames){ students.add(new Student(this, n)); }
	}

	public AssessmentFactory getRandomFactory(){
		return factories.get(randomInt(0, factories.size()));
	}

	public State getRandomState(){	//w/o stationary
		return states.get(randomInt(0, states.size()));
	}

	public void checkIsGrad(){
		tempGrad = true;
		for(Student s: students){ if(s.hasGraduated == false){ tempGrad = false; } }
		if (tempGrad == true) { isGraduation = true; } 
	}
	
	public int randomInt(int from, int to){
    	if (from < to)
        	return from + rand.nextInt(Math.abs(to - from));
    	return from - rand.nextInt(Math.abs(to - from));
	}

	public double checkDist(int x, int y, Entity e){
		return Math.sqrt((e.position.x - x) * (e.position.x - x) + (e.position.y - y) * (e.position.y - y));
	}

}
