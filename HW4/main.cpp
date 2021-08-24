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

		if(game1.cmp == 1){
			cerr<<"This is first game, there is no other game to compare !!"<<endl;
		}
		//cout<<"cmp "<<game1.cmp<<endl;
		//cout<<"glob   "<<global_return<<endl;

		
		//do{
		//Hex test_explicit;
		//test_explicit=(Hex)8;

			cout<<endl<<"Do you want to play another game? (y/n)"<< endl;
			cin>>stop_cont;

		if(stop_cont=='n' || stop_cont=='N')
			return 0;				
				cout << endl << "WELCOME TO HEX GAME2" << endl;	
				cout << "Please enter the board size...(It must be bigger than 5)" << endl;
				cin>>board_size;
				cout << "Press 1 for single player game, 2 for two player game..."<< endl;
				cin>>player;
				Hex game2(board_size,player);

				if(game2.cmp == 1){
					if(game2.otherObj == 1){
						if(game1==game2)
								cout<<endl<<"Current game (game2) has more marked cells than game"<<game2.otherObj<<" !!!"<< endl<<endl;
						else
							cout<<endl<<"Game"<<game2.otherObj<<" has more marked cells than the current game (game2) !!!"<<endl<<endl;
					}
					else if(game2.otherObj ==2)
						cerr<<"You are already playing this game, you cannot compare."<<endl;
					else if(game2.otherObj<=5 && game2.otherObj>=1)
						cerr<<"You haven't played this game yet, you can't compare."<<endl;
					else
						cerr<<"There is no game to compare."<<endl;
				
			}
			//	break;
			//}else if(stop_cont!='n' && stop_cont!='y' && stop_cont!='Y' && stop_cont !='N')
			//	cerr<<"Invalid answer!!"<<endl;
		//}while(stop_cont!='n' && stop_cont != 'N');



			cout<<endl<<"Do you want to play another game? (y/n)"<< endl;
			cin>>stop_cont;

		if(stop_cont=='n' || stop_cont=='N')
			return 0;
			
					cout << endl << "WELCOME TO HEX GAME3" << endl;	
					cout << "Please enter the board size...(It must be bigger than 5)" << endl;
					cin>>board_size;
					cout << "Press 1 for single player game, 2 for two player game..."<< endl;
					cin>>player;
					Hex game3(board_size,player);
					cout<<"hibitches"<<endl;
				cout<<"cmp3 "<<game3.cmp<<endl;

				if(game3.cmp == 1){
					if(game3.otherObj == 1){
						if(game1==game3)
								cout<<endl<<"Current game (game3) has more marked cells than game"<<game3.otherObj<<" !!!"<< endl<<endl;
						else
							cout<<endl<<"Game"<<game3.otherObj<<" has more marked cells than the current game (game3) !!!"<<endl<<endl;
					}					
					else if(game3.otherObj == 2){
						if(game2==game3)
								cout<<endl<<"Current game (game3) has more marked cells than game"<<game3.otherObj<<" !!!"<< endl<<endl;
						else
							cout<<endl<<"Game"<<game3.otherObj<<" has more marked cells than the current game (game3) !!!"<<endl<<endl;
					}
					else if(game3.otherObj ==3)
						cerr<<"You are already playing this game, you cannot compare."<<endl;
					else if(game3.otherObj<=5 && game3.otherObj>=1)
						cerr<<"You haven't played this game yet, you can't compare."<<endl;
					else
						cerr<<"There is no game to compare."<<endl;
				
				}



					
	

			cout<<endl<<"Do you want to play another game? (y/n)"<< endl;
			cin>>stop_cont;

		if(stop_cont=='n' || stop_cont=='N')
			return 0;

					cout << endl << "WELCOME TO HEX GAME4" << endl;	
					cout << "Please enter the board size...(It must be bigger than 5)" << endl;
					cin>>board_size;
					cout << "Press 1 for single player game, 2 for two player game..."<< endl;
					cin>>player;
					Hex game4(board_size,player);

				if(game4.cmp == 1){
					cout<<"cc"<<endl;
					if(game4.otherObj == 1){
						if(game1==game4)
								cout<<endl<<"Current game (game4) has more marked cells than game"<<game4.otherObj<<" !!!"<< endl<<endl;
						else
							cout<<endl<<"Game"<<game4.otherObj<<" has more marked cells than the current game (game4) !!!"<<endl<<endl;
					}					
					else if(game4.otherObj == 2){
						if(game2==game4)
								cout<<endl<<"Current game (game4) has more marked cells than game"<<game4.otherObj<<" !!!"<< endl<<endl;
						else
							cout<<endl<<"Game"<<game4.otherObj<<" has more marked cells than the current game (game4) !!!"<<endl<<endl;
					}					
					else if(game4.otherObj == 3){
						if(game3==game4)
								cout<<endl<<"Current game (game4) has more marked cells than game"<<game4.otherObj<<" !!!"<< endl<<endl;
						else
							cout<<endl<<"Game"<<game4.otherObj<<" has more marked cells than the current game (game4) !!!"<<endl<<endl;
					}
					else if(game4.otherObj ==4)
						cerr<<"You are already playing this game, you cannot compare."<<endl;
					else if(game4.otherObj==5 )
						cerr<<"You haven't played this game yet, you can't compare."<<endl;
					else
						cerr<<"There is no game to compare."<<endl;
				
				}




	

			cout<<endl<<"Do you want to play another game? (y/n)"<< endl;
			cin>>stop_cont;

		if(stop_cont=='n' || stop_cont=='N')
			return 0;
					cout << endl << "WELCOME TO HEX GAME5" << endl;	
					cout << "Please enter the board size...(It must be bigger than 5)" << endl;
					cin>>board_size;
					cout << "Press 1 for single player game, 2 for two player game..."<< endl;
					cin>>player;
					Hex game5(board_size,player);


				if(game5.cmp == 1){
					if(game5.otherObj == 1){
						if(game1==game5)
								cout<<endl<<"Current game (game5) has more marked cells than game"<<game5.otherObj<<" !!!"<< endl<<endl;
						else
							cout<<endl<<"Game"<<game5.otherObj<<" has more marked cells than the current game (game5) !!!"<<endl<<endl;
					}					
					else if(game5.otherObj == 2){
						if(game2==game5)
								cout<<endl<<"Current game (game5) has more marked cells than game"<<game5.otherObj<<" !!!"<< endl<<endl;
						else
							cout<<endl<<"Game"<<game5.otherObj<<" has more marked cells than the current game (game5) !!!"<<endl<<endl;
					}					
					else if(game5.otherObj == 3){
						if(game3==game5)
								cout<<endl<<"Current game (game5) has more marked cells than game"<<game5.otherObj<<" !!!"<< endl<<endl;
						else
							cout<<endl<<"Game"<<game5.otherObj<<" has more marked cells than the current game (game5) !!!"<<endl<<endl;
					}
					else if(game5.otherObj == 4){
						if(game4==game5)
								cout<<endl<<"Current game (game5) has more marked cells than game"<<game5.otherObj<<" !!!"<< endl<<endl;
						else
							cout<<endl<<"Game"<<game5.otherObj<<" has more marked cells than the current game (game5) !!!"<<endl<<endl;
					}
					else if(game5.otherObj ==5)
						cerr<<"You are already playing this game, you cannot compare."<<endl;
					else
						cerr<<"There is no game to compare."<<endl;
				
				}

		if(stop_cont=='y' || stop_cont=='Y')
			return 0;


		cout<<endl<<"\tSEE YOU LATER!!"<<endl;
	}


