import java.awt.Graphics2D;
import java.awt.FlowLayout;
import javax.swing.JFrame;
import java.awt.Container;
import java.awt.Graphics;
import java.util.Random;
import javax.swing.*;
import java.io.*;

public class NURunner extends JFrame{

	private Display display;
	public Common common;

	public NURunner() throws IOException{
		setSize(800, 400);
		setTitle("NUGrad by prinnevald");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		try{common = new Common();
			display = new Display(common);
		} catch(IOException e) {}

		Container cp = getContentPane();
		cp.setLayout(new FlowLayout());
		cp.add(display);

		pack();
	}

    public static void main(String [] args) throws IOException{

	    SwingUtilities.invokeLater(new Runnable(){
			@Override public void run (){ 
				try{new NURunner().setVisible(true);}
				catch(IOException e) {}
			}
		});
    }
}
