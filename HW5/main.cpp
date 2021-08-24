	#include "AbstractHex.h"
	#include "HexVector.h"
	#include "HexArray1D.h"
	#include "HexAdapter.h"
	#include "HexAdapter.cpp"
	using namespace sevraHexGame;

  
	namespace sevraHexGame{
	 bool board_validity(string boardData, int size){
		cout<<"gloabal"<<endl;
		int k=0;
		for(int i=0; i<size*size; i++){ 
			if(boardData[i] == 'x' || boardData[i] == 'o' || boardData[i] == '.'){}

			else
				return false;
		}

		return true;

	}
}


	void menu(){
		cout<<endl<<"WELCOME TO HEX GAME" << endl;
		cout<<"MENU"<<endl;
		cout<<"--If you want to SAVE the game into the file, use command -> 'SAVE FILENAME.TXT'  "<<endl;
		cout<<"--If you want to LOAD the game from the file, use command -> 'LOAD FILENAME.TXT'  "<<endl;
		cout<<"--If you want to EXIT the game, use command 'EXIT' "<<endl;
		cout<<"--You can try () operator overloading after EXIT/END game "<<endl;
		cout<<"--You can try == operator overloading after EXIT/END both games"<<endl;
		cout<<"--numberOfMoves() function prints output every move, you can check it"<<endl;
		cout<<"--lastMove() funciton prints output every move, you can check it"<<endl;
	}


	int main(){
		int player, boardSize;

	
		//HEXVECTOR TEST
		menu();
		cout <<endl <<"Please enter the board size (format -> 6, 7, 8..) (It must be bigger than 5)" << endl;
		cin>>boardSize;
		cout << "Press 1 for single player game, 2 for two player game..."<< endl;
		cin>>player;
		HexVector game1(boardSize ,player);
	
		cout<<endl<<"() OPERATOR OVERLOADING"<<endl; 
		cout<<game1(1,0)<<endl;	//you can change indexes

		//HEXARRAY1D TEST
		menu();
		cout <<endl <<"Please enter the board size (format -> 6, 7, 8..) (It must be bigger than 5)" << endl;
		cin>>boardSize;
		cout << "Press 1 for single player game, 2 for two player game..."<< endl;
		cin>>player;
		HexArray1D game2(boardSize ,player);
		
		cout<<endl<<"() OPERATOR OVERLOADING"<<endl; 
		cout<<game2(-1,1)<<endl;	//exception test	

		cout<<" == OPERATOR OVERLOADING"<<endl;
		if(game1==game2)
			cout<<"Two boards are equal"<<endl;
		else
			cout<<"!! Two board are not equal !!"<<endl;



//HEXADAPTER<VECTOR> TEST
		menu();
		cout <<endl <<"Please enter the board size (format -> 6, 7, 8..) (It must be bigger than 5)" << endl;
		cin>>boardSize;
		cout << "Press 1 for single player game, 2 for two player game..."<< endl;
		cin>>player;
		HexAdapter<vector> game3(boardSize, player);

		menu();
		cout <<endl <<"Please enter the board size (format -> 6, 7, 8..) (It must be bigger than 5)" << endl;
		cin>>boardSize;
		cout << "Press 1 for single player game, 2 for two player game..."<< endl;
		cin>>player;
		HexAdapter<vector> game4(boardSize, player);

		cout<<endl<<"() OPERATOR OVERLOADING"<<endl; 
		cout<<game4(3,2)<<endl;	//you can change indexes	

		cout<<" == OPERATOR OVERLOADING"<<endl;
		if(game3==game4)
			cout<<"Two boards are equal"<<endl;
		else
			cout<<"!! Two board are not equal !!"<<endl;

//HEXADAPTER<DEQUE> TEST
		menu();
		cout <<endl <<"Please enter the board size (format -> 6, 7, 8..) (It must be bigger than 5)" << endl;
		cin>>boardSize;
		cout << "Press 1 for single player game, 2 for two player game..."<< endl;
		cin>>player;
		HexAdapter<deque> game5(boardSize, player);

		menu();
		cout <<endl <<"Please enter the board size (format -> 6, 7, 8..) (It must be bigger than 5)" << endl;
		cin>>boardSize;
		cout << "Press 1 for single player game, 2 for two player game..."<< endl;
		cin>>player;
		HexAdapter<deque> game6(boardSize, player);

		cout<<endl<<"() OPERATOR OVERLOADING"<<endl; 
		cout<<game5(3,2)<<endl;	//you can change indexes	

		cout<<" == OPERATOR OVERLOADING"<<endl;
		if(game5==game6)
			cout<<"Two boards are equal"<<endl;
		else
			cout<<"!! Two board are not equal !!"<<endl;


		//GLOBAL FUNCTION TEST
		AbstractHex *hex = new HexVector();
		hex->readFromFile("INVALID.TXT");
		



		return 0;
	}