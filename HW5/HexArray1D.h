#include "AbstractHex.h"

#ifndef HEXARRAY1D
#define HEXARRAY1D 1

namespace sevraHexGame{
	class HexArray1D : public AbstractHex{
	public:
		HexArray1D(): HexArray1D(6,1){/*Intentionally empty*/	} //default constructor
		HexArray1D(int boardSize, int user);	//constructor with two parameter
		HexArray1D(int board_size, int user, string board_data); //load komutu için (computer-user)
		HexArray1D(int board_size, int user, string board_data, int user_turn); //load komutu için (player1-player2));
		
		//BIG THREE
		~HexArray1D();	//destructor
		HexArray1D(const HexArray1D& copy); //copy constructor
		HexArray1D& operator=(const HexArray1D& assign); //copy assignment operator

		//setters and getters
		void setSize (int boardSize);
		int getSize() const{	return size; }
		void setPlayer(int user){ player = user; }
		int getPlayer()const{	return player; }
		void setBoard();
		void setBoard(string board_data);

		//other functions
		void print();
		void print(string x);

		void enterCommand();		
		void analyze_command(string command);
		void coordinates_valid_or_not();	//checks the coordinates is valid or not 
		void make_move(int flag);

		int computerMove(int c_first);	
		void choose_different_rand(int &last_x, int &last_y);
		
		int filled();
		void game_end(int won);
		void make_uppercase( char letter_won);	

		int check_finish_o();
		int check_finish_x();
		bool isEnd(int player);		
		
		void reset();
		void writeToFile(string fileName);
		void readFromFile(string fileName);
		int* lastMove();

		char operator() (int i1, int i2);
		bool operator==(AbstractHex& other);

		class Cell{	//inner class
		public: 
			void setData(char x){	data = x; }
			char getData() {	return data;	}
			void setRow(int r){	row=r; }
			int getRow(){ return row;}
			void setColumn(int c) { column = c;}
			int getColumn(){ return column;}
		private:
			char data;	//to keep data of each cell
			int row;
			int column;
		};
	private:
		Cell * hexCells=nullptr;
		int *allMoves=nullptr;	//to find winner path
		vector<vector<int> > board_won;	//to find winner path

		int size;
		int player;
		int coord1;
		int coord2;
		int turn=0;	//determines who is in turn in the game
		string fileName;
		int edge;
	};

}
#endif