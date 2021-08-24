#ifndef ABSTRACTHEX
#define ABSTRACTHEX 1


#include <iostream>
#include <vector>
#include<random>
#include <string>
#include<fstream>
#include<deque>

using namespace std;

namespace sevraHexGame{
	 bool board_validity(string boardData, int size);

	class AbstractHex{
	public:
		//common functions
		void play();
		void play(string command);
		void setNumberOfMoves(){ move_counter++; }
		int numberOfMoves(){return move_counter; }
		int  generate_random();

		//setters and getters
		virtual void setSize(int boardSize)=0;
		virtual int getSize()const = 0;
		virtual void setPlayer(int user) = 0;
		virtual int getPlayer()const = 0;
		virtual void setBoard()=0;
		virtual void setBoard(string board_data) = 0;

		//other functions
		virtual void print() = 0;
		virtual void print(string x) = 0;

		virtual void enterCommand()=0;
		virtual void analyze_command(string command)=0;
		virtual void coordinates_valid_or_not()=0;	//checks the coordinates is valid or not 
		virtual void make_move(int flag)=0;

		virtual int computerMove(int c_first) = 0;	
		virtual void choose_different_rand(int &last_x, int &last_y)=0;
		
		virtual int filled()=0;
		virtual void game_end(int won)=0;
		virtual void make_uppercase( char letter_won)=0;	

		virtual int check_finish_o()=0;
		virtual int check_finish_x()=0;
		virtual bool isEnd(int player)=0;

		virtual void reset() = 0;
		virtual void writeToFile(string fileName)=0;
		virtual void readFromFile(string fileName) = 0;
		virtual int* lastMove()=0;

		virtual char operator()(int x, int y)=0;
		virtual bool operator==(AbstractHex& other)=0;

	private:
		int move_counter=0;
	};


}
#endif