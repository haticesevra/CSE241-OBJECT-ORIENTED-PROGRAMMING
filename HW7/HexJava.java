


import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Path;
import java.util.Random;
import java.util.Scanner;

import javax.swing.*;

public class HexJava extends JFrame implements ActionListener,HexGame,Cloneable{
	private static final long serialVersionUID = 7526472295622776147L;  	
	private char[] hexCells;

	private String fileName;
	private String data;
	private String allMovesData;
	
	private int player;	
	private int turn=0;
	private int[] allMoves;
	private int move_counter=0;
	private int oneDSize;
	private int size;
	private int iter=0;
	private	int counter=0;
	private	int up=0;
	private int down=0;
	
	private JRadioButton type1;
	private	JRadioButton type2;
	private JTextField getFileName;
	private JTextField fName;
	
	private JButton fileButton;
	private JButton save;
	private JButton load;
	private	JButton reset;
	private	JButton undo;
	private	JButton[] cell;
	private JButton ok;

	private JPanel board;
	private JPanel frame;
	private JPanel buttons;
    private JLabel positionLabel;
	
	private JTextField inputSize;
	
	
    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }


	public boolean set_size(int board_size)	{
		if(board_size <=5) {
			return false;
		}
		size=board_size; 
		oneDSize = size*size;
		return true;
	}
	
	public int get_size() { return size; }
	public void set_player(int user)  { player=user; }
	public int get_player() { return player;}
	
	
	public void set_board(){
		hexCells = new char [oneDSize];
		for (int i=0; i<oneDSize; i++)
			hexCells[i] = '.';  // Initialize the cell
		allMoves = new int[oneDSize];
		board = new JPanel();
		cell = new JButton[oneDSize];
    	for(int i=0; i<oneDSize; i++) {
    		cell[i] = new JButton(".");
        	cell[i].setBackground(new Color	(255,248,220));
        	cell[i].setPreferredSize(new Dimension(40, 40));
        	board.add(cell[i]);
    	}
		play();	
	}
	
	
	public void set_board(String data){
		hexCells = new char [oneDSize];
		char[] chData = new char[data.length()];
		 
        for (int i = 0; i < data.length(); i++)
            chData[i] = data.charAt(i); 
        
        int x=0,y=0;
		for (int i=0; i<oneDSize; i++){
			hexCells[i] = chData[i];  // Initialize the cell
			if(hexCells[i] == 'x') //detect whose turn
				x++;
			else
				y++;
		}
		
		if(x>y)	turn=1; //provides continue whose turn
		else 	turn=0;

		
		allMoves = new int[oneDSize];;
		char[] chAllData = new char[data.length()];
		
		for (int i = 0; i < allMovesData.length(); i++)
          chAllData[i] = allMovesData.charAt(i); 
       
		for (int i=0; i<oneDSize; i++)
			allMoves[i] = chAllData[i];  // Initialize the cell		
		
		board.removeAll();	
		board = new JPanel();
		cell = new JButton[oneDSize];
        board.setBackground(new Color(255,255,255)); 
        board.setLayout(new GridLayout(size, size, 10, 10));
    	
        for(int i=0; i<oneDSize; i++) {
    		if(hexCells[i]=='x') {
    			cell[i] = new JButton("...");
        		cell[i].setBackground(new Color(255,69,0));
        		cell[i].setPreferredSize(new Dimension(40, 40));	
    		}
    		else if(hexCells[i] == 'o') {
    			cell[i] = new JButton("...");
        		cell[i].setBackground(new Color(47,79,79));
        		cell[i].setPreferredSize(new Dimension(40, 40));
    		}
    		else {
      			cell[i] = new JButton(".");
        		cell[i].setBackground(new Color(255,248,220));
        		cell[i].setPreferredSize(new Dimension(40, 40));
    		}
        	board.add(cell[i]);	
    	}

         this.add(board, BorderLayout.SOUTH);        
		 this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		 this.setSize(550, 525);
		 this.setLayout(new FlowLayout());
		 this.setVisible(true);
		 play();
	}


	public void play() {
        for (int i = 0; i < size*size; i++){
        	if(player==2) {
	        	cell[i].setFocusable(false);
	        	cell[i].addActionListener(new ActionListener(){
	                public void actionPerformed(ActionEvent ae){                  	
	                	for(int i=0; i<size*size; i++) {
	                    	if(ae.getSource() == cell[i]) {
	                    		if(turn%2==0) {
	                    			if(cell[i].getText() == ".") {
	                    				cell[i].setBackground(new Color(255,69,0));
	                    				cell[i].setText("..."); //not empty
	                    				hexCells[i]='x';
	                    				allMoves[i] = ++move_counter;
	                    				iter=0;
	                    				counter=0;
	                    				if((check_finish_x(iter,counter, 'x', 0, 0) == size-1)) {
	                    					//JOptionPane.showMessageDialog(null, "O WON THE GAME!!", "GAME OVER", JOptionPane.PLAIN_MESSAGE);
	                    				}
	                    				turn++;
	                    				printBoard();
	                    	}}else{
	                        		if(cell[i].getText() == ".") {
	                        			cell[i].setBackground(new Color(47,79,79));
	                        			cell[i].setText("...");
	                        			hexCells[i]='o';
	                        			allMoves[i] = ++move_counter;
	                    				if((check_finish_o(iter,counter, 'o', 0, 0) == size-1)) {
	                    					//JOptionPane.showMessageDialog(null, "O WON THE GAME!!", "GAME OVER", JOptionPane.PLAIN_MESSAGE);
	                    				}
	                        			turn++;
	                        			printBoard();	
	                 }}}}}});
        	}
        	else {        
	        	cell[i].setFocusable(false);
	        	if(turn%2==0) {
		        	cell[i].addActionListener(new ActionListener(){
	                    public void actionPerformed(ActionEvent ae){                  	
	                    	for(int i=0; i<size*size; i++) {
	                        	if(ae.getSource() == cell[i]) {
	                        		if(turn%2==0) {
	                        			if(cell[i].getText() == ".") {
	                        				cell[i].setBackground(new Color(255,69,0));
	                        				cell[i].setText("..."); //not empty
	                        				hexCells[i]='x';
	                        				allMoves[i] = ++move_counter;
	                        				computer_move();
	                        				if(check_finish_x(iter,counter, 'x', 0, 0) == 1)
	                        					JOptionPane.showMessageDialog(null, "X WON THE GAME!!", "GAME OVER", JOptionPane.PLAIN_MESSAGE);
	                        				turn++;
	                        				printBoard();
	                        	}}}}}});	
	        	}
	        	else 
	        		computer_move();
	       }}}

 
    

	
	HexJava(){
			this.getContentPane().setBackground(new Color(255,255,255)); 
			frame= new JPanel();
			frame.setLayout(new FlowLayout(FlowLayout.LEFT, 20, 20));
			frame.setBorder(BorderFactory.createLineBorder(Color.RED, 2));
			
	        inputSize = new JTextField();
			inputSize.setPreferredSize(new Dimension(50,30));
			frame.add(inputSize);
	        
			ok = new JButton("OK");
			ok.setBackground(new Color	(244,164,96));
			ok.addActionListener(this); 
	        frame.add(ok);
	 
			 type1 = new JRadioButton("Player-Computer");
			 type1.setBackground(new Color(255,255,255)); 
			 type2 = new JRadioButton("Player1-Player2");
			 type2.setBackground(new Color(255,255,255)); 
			 
			 ButtonGroup gameType = new ButtonGroup();
			 gameType.add(type1);
			 gameType.add(type2);
			 type1.addActionListener(this);
			 type2.addActionListener(this);		 
			 frame.add(type1);
			 frame.add(type2);
			 frame.setBackground(new Color(255,255,255)); 
			 this.add(frame);
		
			 buttons = new JPanel();
			 buttons.setBorder(BorderFactory.createLineBorder(Color.BLUE, 2));
			 buttons.setLayout(new FlowLayout(FlowLayout.RIGHT, 20, 20)); 
			 save = new JButton("SAVE");
			 load = new JButton("LOAD");
			 reset = new JButton("RESET");
			 undo = new JButton ("UNDO");
			 
			 save.setBackground(new Color(200,210,238));
			 load.setBackground(new Color(255,200,203));
			 reset.setBackground(new Color(144,200,144));
			 undo.setBackground(new Color(255,215,100));
			
			 save.addActionListener(this);
			 load.addActionListener(this);
			 reset.addActionListener(this);
			 undo.addActionListener(this);
			 buttons.add(save);
			 buttons.add(load);
			 buttons.add(reset);
			 buttons.add(undo);

			 buttons.setBackground(new Color(255,255,255)); 
			 this.add(buttons, BorderLayout.SOUTH);
			 this.pack();
			 this.setResizable(true);
			 this.setVisible(true);
	}
	
	
	
	
	
	public void actionPerformed(ActionEvent e) {
		
		if(e.getSource()== type1) { //computer-user
			set_player(1);
		}
		
		else if(e.getSource()==type2) { //user1-user2
			set_player(2);
		}
			
		else if(e.getSource() == ok) {
			size = Integer.parseInt(inputSize.getText());		
			if(set_size(size)) {
				set_board();
				int flag=0;
			    board.setBackground(new Color(255,255,255)); 
		        board.setLayout(new GridLayout(size, size, 10, 10));
		        this.add(board, BorderLayout.SOUTH);
		        play();
			}
			else 
				JOptionPane.showMessageDialog(null, "Board size must be bigger than 5!!", "ERROR", JOptionPane.PLAIN_MESSAGE);
	        
			this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			this.setSize(550, 525);
			this.setLayout(new FlowLayout());	
			this.setVisible(true);
		}
		
		else if(e.getSource() == save) {
			JOptionPane.showMessageDialog(null, "Enlarge the frame to see the SAVE dialog. !", "ENLARGE THE FRAME", JOptionPane.PLAIN_MESSAGE);
			
			fName = new JTextField();
			this.add(fName);
			fName.setPreferredSize(new Dimension (250,40));
	
			JButton fileButton = new JButton("Create File");
			this.add(fileButton);
			fileButton.addActionListener(new ActionListener(){
                public void actionPerformed(ActionEvent fe){       
                	fileName = fName.getText();
       			 try {
 				 if(fileName!=null) {
 			      File saveFile = new File(fileName);
 			      if (saveFile.createNewFile()) {
 			    	 System.out.println(saveFile.getName()+" is created");
 			    	
 			      } else {
 			        System.out.println("File already exists.");
 			      }
 			      FileWriter save = new FileWriter(fileName);
 			      printBoard();
 			      for(int j=0; j<oneDSize; j++)
 			    	  save.write(hexCells[j]);
 			      save.write("\n" + size + "\n" + player + "\n");
 			      for(int j=0; j<oneDSize; j++)
 			    	  save.write(allMoves[j]);
 			      save.close();
 			      JOptionPane.showMessageDialog(null, "The file is saved successfully, you can reset the game!", "SAVE COMMAND", JOptionPane.PLAIN_MESSAGE);
 			      System.out.println("Successfully wrote to the file.");
 				 }
 			    } catch (IOException io) {
 			      System.out.println("Something went wrong when file is creating.");
 			      io.printStackTrace();
 			    }}});		
		}
		else if(e.getSource() == load) {
			JOptionPane.showMessageDialog(null, "Enlarge the frame to see the LOAD dialog. !", "ENLARGE THE FRAME", JOptionPane.PLAIN_MESSAGE);
				
			fName = new JTextField();
			this.add(fName);
			fName.setPreferredSize(new Dimension (250,40));
			
			JButton fileButton = new JButton("Load File");
			this.add(fileButton);
			fileButton.addActionListener(new ActionListener(){
                public void actionPerformed(ActionEvent fe){ 
                	fileName = fName.getText();
            		try {
  				      File loadFile = new File(fileName);
  				      Scanner readfromFile = new Scanner(loadFile);
  				      int i=0;
  				      while (readfromFile.hasNextLine()) {
  				    	  if(i==0) {
  				    		 data = readfromFile.nextLine();
  				    	  }
  				    	  else if(i==1) {
  				    		  size =  Integer.parseInt( readfromFile.nextLine());
  				    		  oneDSize=size*size;
  				    	  }
  				    	  else if(i==2){
  				    		player =  Integer.parseInt( readfromFile.nextLine());
  				    	  }
  				    	  else {
  				    		  allMovesData = readfromFile.nextLine();
  				    	  }	  
  				       i++;
  				      }
  				    System.out.println(data);
  					System.out.println(size);
  					System.out.println(player);
  					set_board(data);
  					printBoard();
  				      readfromFile.close();
  				    } catch (FileNotFoundException e) {
  				      System.out.println("There is no file have the name you entered.");
  				      e.printStackTrace();
  				    }}});	
		
		}
		else if(e.getSource() == reset) {
			while(move_counter!=0) 
				undo();
		}
		else if(e.getSource() == undo) {	
			if(move_counter==0)
				JOptionPane.showMessageDialog(null, "Invalid command.There is no move to remove!", "ERROR", JOptionPane.PLAIN_MESSAGE);
			else
				undo();
			printBoard();			
		}	       
	}

		
		//other functions
		public void printBoard() {
			System.out.println();
			for(int i=0; i<oneDSize; i++){		//prints the board
				System.out.print(hexCells[i] + " ");  
				if( (i+1)%size == 0 )
					System.out.println();
			}
			
			System.out.println("printAllMoves");
			for(int i=0; i<oneDSize; i++){		//prints the board
				System.out.print(allMoves[i] + " ");  
				if( (i+1)%size == 0 )
					System.out.println();
			}
		}
		
		
		public void undo() {
			if(player==1) {
			for(int k=0; k<2; k++) {	
				for(int i=0; i<oneDSize; i++) {	
					if(allMoves[i] == move_counter) {
						hexCells[i]='.';
						allMoves[i]=0;
						cell[i].setBackground(new Color	(255,248,220));
						cell[i].setText("."); //not empty
						move_counter--;
						turn--;
						break;
			}}}}
			else {
				for(int i=0; i<oneDSize; i++) {	
					if(allMoves[i] == move_counter) {
						hexCells[i]='.';
						allMoves[i]=0;
						cell[i].setBackground(new Color	(255,248,220));
						cell[i].setText("."); //not empty
						move_counter--;
						turn--;
						break;
			}}}
		}
		
	/* This is an utility function to check the game is end or not for USER1 */
		public int check_finish_x(int i, int counter, char letter, int up, int down){			
			int t;
			if(counter == size-1){
				JOptionPane.showMessageDialog(null, "X WON THE GAME!!", "GAME OVER", JOptionPane.PLAIN_MESSAGE);	
				return size;
			}
			else{
				if(counter!=size-1){
			if( (i-size)>=0 && hexCells[i-size] == letter && up==0 ){		
				i=i-size;
				t=1;
				down=1;
				check_finish_x(i,counter, letter,up, down);
				//up_down=0;
		
			}
		
			if(  hexCells[i+1] == letter ){
				i=i+1;
				counter++;
				t=2;
				check_finish_x(i,counter,letter,up,down);
			}
		
			if((i+size)<=oneDSize && hexCells[i+size] == letter && down==0  ){				
				i=i+size;
				//counter++;
				up=1;
				t=3;
				check_finish_x(i,counter,letter,up, down);
				//up_down=0;
			}
		
				}
			return counter;
			}
		}
		
		public int check_finish_o(int i, int counter, char letter, int up, int down){
			System.out.println("c  " + counter);
			
			int t;
			if(counter == size-1){
				JOptionPane.showMessageDialog(null, "X WON THE GAME!!", "GAME OVER", JOptionPane.PLAIN_MESSAGE);	
				return size;
			}
			else{
				if(counter!=size-1){
			if( (i-size)>=0 && hexCells[i+size] == letter && up==0 ){		
				i=i-size;
				t=1;
				down=1;
				check_finish_o(i,counter, letter,up, down);
				//up_down=0;
			}
		
			if(  hexCells[i+1] == letter ){
				i=i+1;
				counter++;
				t=2;
				check_finish_o(i,counter,letter,up,down);
			}
			if((i+size)<=oneDSize && hexCells[i+size] == letter && down==0  ){				
				i=i+size;
				//counter++;
				up=1;
				t=3;
				check_finish_o(i,counter,letter,up, down);
				//up_down=0;
			}
		
				}
			return counter;
			}
		}	
		
			public boolean computer_move() {	
		        Random rand = new Random(); 	              
		        int randCoord = rand.nextInt(oneDSize);
					if(hexCells[randCoord] =='.'){ //if the coordinate is empty
							hexCells[randCoord] ='o' ; //fill the cell with 'o'
							cell[randCoord].setBackground(new Color(47,79,79));
							allMoves[randCoord] = ++move_counter;
							printBoard();
							turn++;
							return true;
					}
					computer_move();
					return false;
			}	
	}