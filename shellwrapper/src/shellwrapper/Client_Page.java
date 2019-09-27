package shellwrapper;
import shellwrapper.*;

//AWT imports
import java.awt.Dimension;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

//File handling imports
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

//Swing imports
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;



public class Client_Page extends Thread 
{
	
	private JFrame f = new JFrame("Mailer Page");
	JPanel p1;
	JButton b1;
	String to;
	
	Client_Page() 
	{		 
			 start();
	}
		 
	public void start() 
	{
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(800,800);
		f.setVisible(true);
		
		//Labels for the text fields
		JLabel l1,l2,l3,l4;  
		l1=new JLabel("TO:");  
		l1.setBounds(10,20,200,30);
		l2=new JLabel("FROM:");  
		l2.setBounds(10,70,200,30);
		l3=new JLabel("SUBJECT:");  
		l3.setBounds(10,120,200,30);
		l4=new JLabel("MESSAGE:");  
		l4.setBounds(10,170,200,30);
		
		//TextFields
		TextField t1,t2,t3,t4;  
	    
		//TO TEXT FIELD
		t1=new TextField(""); 
	    t1.setBounds(80,20, 200,30);
	    //To get the entered String
	    t1.addActionListener(new ActionListener() 
	    {
	    	public void actionPerformed(ActionEvent e) 
	    	{
	    		String filename = "mailer.txt";
			append(filename, "TO: "+t1.getText());
	    		to = t1.getText();
	    		System.out.println("To: "+ t1.getText());
	    	}
	    });
	    
	    //FROM TEXT FIELD
	    t2=new TextField("");
	    t2.setBounds(80,70, 200,30);
	    //Action listener for field 2
	    t2.addActionListener(new ActionListener() 
	    {
	    	public void actionPerformed(ActionEvent e) 
	    	{
	    		String filename = "mailer.txt";
	    		append(filename, "\nFrom: "+t2.getText());
	    		System.out.println("From: "+ t2.getText());
	    	}
	    });
	    
	    t3=new TextField("");  
	    t3.setBounds(80,120, 400,30);
	    //Action Listener created
	    t3.addActionListener(new ActionListener() 
	    {
	    	public void actionPerformed(ActionEvent e) 
	    	{
	    		String filename = "mailer.txt";
	    		append(filename, "\nSubject: "+t3.getText());
	    		System.out.println("Subject: "+ t3.getText());
	    	}
	    });
	
	    t4 = new TextField("");
	    t4.setBounds(80,170, 650, 350);
	    //Action Listener created
	    t4.addActionListener(new ActionListener() 
	    {
	    	public void actionPerformed(ActionEvent e) 
	    	{
	    		String filename = "mailer.txt";
			append(filename, "\nMessage: "+t4.getText());
	    		System.out.println("Message: "+ t4.getText());
	    	}
	    });
	        
	    //Send Button
		b1 = new JButton("Send");
		b1.setSize(new Dimension(90, 30));
		b1.setLocation(650,600);
		b1.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent e) 
			{
				f.dispose();
			}
		});
		
		//TextFields and TextAreas
		f.add(t1); 
		f.add(t2);
		f.add(t3);
		f.add(t4);
		
		//Adding labels for textFields and textAreas
		f.add(l1);
		f.add(l2);
		f.add(l3);
		f.add(l4);
		
		//adding Button
		f.add(b1);
	}
	
	//To do file handling of the content
	private static void append(String filePath, String text) {
		File file = new File(filePath);
		FileWriter fr = null;
		try {
			// Below constructor argument decides whether to append or override
			fr = new FileWriter(file, true);
			fr.write(text);

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				fr.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	
	public static void main(String[] args) 
	{
		//RunningSS obj = new RunningSS();			//To generate instance of package
		//obj.console();								//To call the script defined in the package
		Client_Page caller = new Client_Page();
		//To store the text to new file -> mailer.txt
		String fileName = "mailer.txt"; 
        	try { 
            		BufferedWriter out = new BufferedWriter( new FileWriter(fileName)); 
            		out.close(); 
        	}	 
        	catch (IOException e) { 
            		System.out.println("Exception Occurred" + e); 
        	} 

        System.out.println("DONE");
	}
}
