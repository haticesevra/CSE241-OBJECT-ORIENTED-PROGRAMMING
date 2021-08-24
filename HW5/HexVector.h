#include "AbstractHex.h"


#ifndef HEXVECTOR
#define HEXVECTOR 1

namespace sevraHexGame{
/*	This class is derived class from AbstractHex class.	*/
	class HexVector : public AbstractHex{
	public: 
		HexVector(): HexVector(6,1){/*Intentionally empty*/	} //default constructor
		HexVector(int boardSize, int user);	//constructor with two parameter
		HexVector(int board_size, int user, string board_data); //load komutu için (computer-user)
		HexVector(int board_size, int user, string board_data, int user_turn); //load komutu için (player1-player2)
		HexVector(const HexVector& temp);

		void setSize (int boardSize);
		int getSize() const{	return size; }
		void setPlayer(int user){ player = user; }
		int getPlayer()const{	return player; }
		void setBoard();
		void setBoard(string board_data);
		
		void setFileName(int name){fileName = name;};
		string getFileName()const {return fileName;};
		
		void print();
		void print(string x);
		
		void enterCommand();		
		void analyze_command(string command);
		void coordinates_valid_or_not();	//checks the coordinates is valid or not 
		void make_move(int flag);

		int computerMove(int c_first);	
		void choose_different_rand(int &last_x, int &last_y);

		void game_end(int won);
		int filled();
		void make_uppercase( char letter_won);	

		int check_finish_o();
		int check_finish_x();
		bool isEnd(int player);

		void reset();
		void writeToFile(string fileName);
		void readFromFile(string fileName);
		int* lastMove();

		char operator() (int x, int y) ;
		bool operator==(AbstractHex& other);

		/*	This inner class holds position of the board. I leave this as previous homeworks	*/
		class Cell{	//inner class
		public: 
			void setData(char x){	data = x; }
			char getData() const{	return data;	}
			void setRow(int r){	row=r; }
			int getRow() const{ return row;}
			void setColumn(int c) { column = c;}
			int getColumn() const{ return column;}
		private:
			char data;	//to keep data of each cell
			int row;
			int column;
		};

	private:
		vector<vector<Cell> > hexCells;
		vector<vector<int> > board_won;	//to find winner path
		vector<vector<int> > allMoves;	

		int size;
		int player;
		int coord1;
		int coord2;
		int turn=0;	//determines who is in turn in the game
		string fileName;
		string board_data;
	};
}
#endif