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
		explicit Hex (int board_size, int user);	// normal constructor
		explicit Hex(int board_size, int user, string board_data);	//constructor initializes loaded games (player-computer)
		explicit Hex(int board_size, int user, string board_data, int user_turn); //constructor initializes loaded games (player1- player2)
		//HW4
		Hex(const Hex& temp);	//copy constructor
		~Hex();		//destructor
		Hex& operator=(const Hex& temp);
		Hex operator--();	//UNDO - bilgisayarın ve kullanıcının hamlesini geri alır
		Hex operator--(int ignoreMe);	//en son oynayan kullanıcının hamlesini geri alıp, tekrar o kişiden hamle ister
		
		int cmp=0;	// main'e compare işleminin yapılmak istenip istenmediğini bildirir
		int otherObj; //to compare
		static int object;	//keeps number of objects in the program
		static int ob1, ob2, ob3, ob4, ob5;	//keeps number of marked cell of each object 
		friend bool operator== (const Hex &otherObj, const Hex &currentObj);
  		friend ifstream& operator>>(ifstream& file, Hex& H);
		friend ostream& operator<<(ostream& outS, Hex& H);
		friend ofstream& operator<<(ofstream& file, Hex& H);
		void markedCells();	//to find number of non-empty cells

		class Cell{	//inner class
		public:
			char data;	//to keep data of each cell
		private:	
			int row;	//no need to use	
			int column;
		};
	private:
		Cell ** hexCells=nullptr;
		int **allMoves=nullptr;	//to find winner path
		int **board_won=nullptr;
		int move_counter;
		int marked;
		int size;		
		int player;		
		int turn=0;	//determines who is in turn in the game
		int coord1;
		int coord2;
		int current_size;	//keeps current size
		int insertion=0;
		string fileName;
		string firstWord;			// to keep first word of the command
		string secondWord; 			// to keep second word of the command
		string board_data;

		//HW4 FUNCTIONS
		void play();
		void play(string command);
		void set_move_counter(int m_counter);
		void set_all_moves();
		int get_size(); 
		void find_score();

		//ESKİ FONKSİYONLAR (bazı değişiklikler yapıldı)
		int get_player(); 
		void set_size(int board_size);	
		void set_player(int user);	
		int getNumberOfObjects()	{	return object;	}
		void print_board();		//prints board normally
		void print_board(string finish);	//prints board when the game is over
		void set_board();		//sets the game board according to data entered by the user
		void set_board(string board_data);	//sets the game board according to the information from the loaded game
		void playGame();
		void make_move(int flag);
		void analyze_command(string command);		
		void coordinates_valid_or_not();	//checks the coordinates is valid or not 
		int check_finish_x();	//checks x is won the game or not
		int check_finish_o();	// checks o is won the game or not
		int filled();	//checks if all cells on the board are full
		void make_uppercase(char letter_won);	//makes uppercase the won path
		void game_end(int won);	//reports who won the game
		int generate_random();	//chooses computers random moves
		void choose_different_rand(int &last_x ,int &last_y);	//if all smart move cells is full, makes random move
		int computer_move(int c_first);	

	};
		


#endif
