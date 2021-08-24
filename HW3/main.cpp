#include "functions.h"

	int main(){
		int player, board_size;
		char stop_cont;
		cout << "WELCOME TO HEX GAME1" << endl;	
		cout << "Please enter the board size... (It must be bigger than 5)" << endl;
		cin>>board_size;
		cout << "Press 1 for single player game, 2 for two player game..."<< endl;
		cin>>player;
		Hex game1(board_size,player);
		
		do{
			cout<<endl<<"Do you want to play another game? (y/n)"<< endl;
			cin>>stop_cont;
			if(stop_cont=='y' || stop_cont=='Y'){
				cout << endl << "WELCOME TO HEX GAME2" << endl;	
				cout << "Please enter the board size...(It must be bigger than 5)" << endl;
				cin>>board_size;
				cout << "Press 1 for single player game, 2 for two player game..."<< endl;
				cin>>player;
				Hex game2(board_size,player);
				break;
			}else if(stop_cont!='n' && stop_cont!='y' && stop_cont!='Y' && stop_cont !='N')
				cerr<<"Invalid answer!!"<<endl;
		}while(stop_cont!='n' && stop_cont != 'N');

		while(stop_cont !='n' && stop_cont != 'N'){
				cout<<endl<<"Do you want to play another game? (y/n)"<< endl;
				cin>>stop_cont;
				if(stop_cont=='y' || stop_cont =='Y'){
					cout << endl << "WELCOME TO HEX GAME3" << endl;	
					cout << "Please enter the board size...(It must be bigger than 5)" << endl;
					cin>>board_size;
					cout << "Press 1 for single player game, 2 for two player game..."<< endl;
					cin>>player;
					Hex game3(board_size,player);
					break;
			}else if(stop_cont!='n' && stop_cont!='y' && stop_cont!='Y' && stop_cont !='N')
				cerr<<"Invalid answer!!"<<endl;
		}
		while(stop_cont !='n' && stop_cont != 'N'){
				cout<<endl<<"Do you want to play another game? (y/n)"<< endl;
				cin>>stop_cont;
				if(stop_cont=='y' || stop_cont =='Y'){
					cout << endl << "WELCOME TO HEX GAME4" << endl;	
					cout << "Please enter the board size...(It must be bigger than 5)" << endl;
					cin>>board_size;
					cout << "Press 1 for single player game, 2 for two player game..."<< endl;
					cin>>player;
					Hex game4(board_size,player);
					break;
				}else if(stop_cont!='n' && stop_cont!='y' && stop_cont!='Y' && stop_cont !='N')
				cerr<<"Invalid answer!!"<<endl;
		}
		while(stop_cont !='n' && stop_cont != 'N'){
				cout<<endl<<"Do you want to play another game? (y/n)"<< endl;
				cin>>stop_cont;
				if(stop_cont=='y' || stop_cont == 'Y'){
					cout << endl << "WELCOME TO HEX GAME5" << endl;	
					cout << "Please enter the board size...(It must be bigger than 5)" << endl;
					cin>>board_size;
					cout << "Press 1 for single player game, 2 for two player game..."<< endl;
					cin>>player;
					Hex game5(board_size,player);
					break;
				}else if(stop_cont!='n' && stop_cont!='y' && stop_cont!='Y' && stop_cont !='N')
					cerr<<"Invalid answer!!"<<endl;		
		}

		cout<<endl<<"\tSEE YOU LATER!!"<<endl;
		return 0;
	}

