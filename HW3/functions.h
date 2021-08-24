#ifndef _FUNC_H
#define _FUNC_H







#include<iostream>
#include<vector>
#include<random>
#include<fstream>
#include<string>
using namespace std;


enum cell_states{empty='.', firstPlayer='x', secondPlayer ='o'};

	class Hex{
	public:
		Hex (int board_size, int user);	// normal constructor
		Hex(int board_size, int user, string board_data);	//constructor initializes loaded games (player-computer)
		Hex(int board_size, int user, string board_data, int user_turn); //constructor initializes loaded games (player1- player2)
	
		static int object;	//keeps number of objects in the program
		static int ob1, ob2, ob3, ob4, ob5;	//keeps number of marked cell of each object 
		bool compare_objects(int another_obj);	//to compare number of marked cells of current game and another game
		void markedCells();	//to find number of non-empty cells
		static int get_markedCells(int obj){	//returns number of marked cells
			if(obj==1)		return ob1;
			else if(obj==2)	return ob2;
			else if(obj==3)	return ob3;
			else if(obj==4)	return ob4;
			else			return ob5;
		}
	private:		
		class Cell{	//inner class
		public:
			char data;	//to keep data of each cell
		private:	
			int row;	//no need to use	
			int column;
		};
		
		vector<vector<int> > board_won;	//to find winner path
		vector<vector<Cell> > hexCells;	// game board
		vector<vector<int> > allMoves;	//to find winner path

		
		int get_size(); 
		int get_player(); 
		void set_size(int board_size);	
		void set_player(int user);	
		
		int getNumberOfObjects()	{	return object;	}
		int get_heig_widt()		{	return current_size=hexCells.size();	}

		void print_board();		//prints board normally
		void print_board(string finish);	//prints board when the game is over
	
		void set_board();		//sets the game board according to data entered by the user
		void set_board(string board_data);	//sets the game board according to the information from the loaded game

		void playGame();
		void make_move(int flag);
		void analyze_command();
	
		void save_game(string fileName);	//opens file and write game data 
		void load_game(string fileName);	//reads the data in the file
		
		void coordinates_valid_or_not();	//checks the coordinates is valid or not 
		
		int check_finish_x();	//checks x is won the game or not
		int check_finish_o();	// checks o is won the game or not
		
		int filled();	//checks if all cells on the board are full
		void make_uppercase(char letter_won);	//makes uppercase the won path
		void game_end(int won);	//reports who won the game
		
		int generate_random();	//chooses computers random moves
		void choose_different_rand(int &last_x ,int &last_y);	//if all smart move cells is full, makes random move
		int computer_move(int c_first);	
		
		int size;		
		int player;		
		int turn=0;	//determines who is in turn in the game
		int coord1;
		int coord2;
		int current_size;	//keeps current size

		string firstWord;			// to keep first word of the command
		string secondWord; 			// to keep second word of the command
		string command;	

	};
		


#endif
