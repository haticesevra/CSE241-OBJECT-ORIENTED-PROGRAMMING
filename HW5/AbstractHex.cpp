#include "AbstractHex.h"
using namespace sevraHexGame;
	void AbstractHex :: play(){
		int c_first=1;
		computerMove(c_first);	
	}

	void AbstractHex :: play(string command){
		analyze_command(command);
	}


	/* This function generates random number to choose a move in computer_move function*/
	int AbstractHex:: generate_random(){	// 
		int number;
		random_device rd;  
    	mt19937 gen(rd()); 
    	uniform_int_distribution<> distrib(1, 15);
		number =  distrib(gen);
		return number;
	}



