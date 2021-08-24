#include "all_func.h"


int main(){
		char board[12][12];
		int size, i, j;
		char coord2_ch;		// to get horizontal coordinates from the user A, B C...
		int coord1;			// to get vertical coordinates from the user 1,2,3...
		int return_flag;	//to see if coordinates is valid	
		int ret_move;		// to see if move is make
		int end=0; 		 //to see if the game is over
		int last_x, last_y; 
		int x_won, o_won;
		int first=1; //gotodan önce
		int all_filled;
		cout << "WELCOME TO HEX GAME" << endl;	

resize:

		cout << "Please enter the board size between 6 and 12..." << endl;
		cin >> size;
		if(size<6 || size>12){		//if the board size is invalid
			cerr << "!! Please enter a valid board size !!" << endl << endl;
			goto resize;
		}
		else{		// if the board size is valid
reselect_player:

			int player;
			cout << "Press 1 for single player game, 2 for two player game..."<< endl;
			cin >> player;

				for(i=0; i<12; i++){		//to fill the board with .'s
					for(j=0; j<12; j++){
						board[i][j] = '.';	
					}
				}
//START USER - COMPUTER PART
			if(player==1){	
				print_board(board, size);

				while(end!=1){	
					cout << "It's your turn. Enter a coordinate to move..." << endl;
		recoord1:		// to enter new coordinates	
					cin.clear();
					cin.ignore(100, '\n');
					cin >> coord2_ch >> coord1;
					return_flag = coordinates_valid_or_not(coord1, coord2_ch, size);	 //if coordinates are valid
					if( return_flag != 0){
						ret_move = make_move(board, coord2_ch, coord1, return_flag, 1);	//make move
						if(ret_move == 1)	//if move cannot make
							goto recoord1;
						print_board(board, size);
						end = check_finish_x(board, size, &x_won);
						if(filled(board, size) == 1){
							all_filled=1;
							break;
						}
						if(end != 1){
							ret_move = computer_move(board, first, &last_x, &last_y,size);
							first=0;
							if(ret_move == 1)	//if move cannot make
								goto recoord1;
							print_board(board, size);
							end = check_finish_o(board, size, &o_won);
							if(filled(board, size) == 1){
								all_filled=1;
								break;
							}
						}
					}
					else{	//if coordinates are invalid
						cerr << "Coordinates you entered is invalid, please enter new coordinates..."<< endl;
						goto recoord1;
					}
				}
			}
//END OF THE USER COMPUTER PART

//START OF THE USER1-USER2 PART
			else if(player==2){
				print_board(board, size);
			while(end!=1){
				cout << "It's user1's turn. Enter a coordinate to move..." << endl;
recoord2:			// to enter new coordinates
				cin.clear();
				cin.ignore(100, '\n');
				cin >> coord2_ch >> coord1;
				return_flag = coordinates_valid_or_not(coord1, coord2_ch, size);		//if coordinates are valid
				if( return_flag != 0){
					ret_move = make_move(board, coord2_ch, coord1, return_flag, 1);			//make move
					if(ret_move == 1)	//if move cannot make
						goto recoord2;
					print_board(board, size);
					end = check_finish_x(board, size, &x_won);
					if(filled(board, size) == 1){
						all_filled=1;
						break;
					}
				}else{		//if coordinates are invalid
					cerr << "Coordinates you entered is invalid, please enter new coordinates..."<< endl;
					goto recoord2;
				}
			 	if(end!= 1){
					cout << "It's user2's turn. Enter a coordinate to move..." << endl;
recoord3:		// to enter new coordinates	
					cin.clear();
					cin.ignore(100, '\n');
					cin >> coord2_ch >> coord1;
					return_flag = coordinates_valid_or_not(coord1, coord2_ch, size);		//if coordinates are valid
					if( return_flag != 0){
						ret_move = make_move(board, coord2_ch, coord1, return_flag, 2);		//make move
						if(ret_move == 1)	//if move cannot make
							goto recoord3;
						print_board(board, size);
						end = check_finish_o(board, size, &o_won);
						if(filled(board, size) == 1){
							all_filled=1;
							break;
						}
					}else{		//if coordinates are invalid
						cerr << "Coordinates you entered is invalid, please enter new coordinates..."<< endl;
						goto recoord3;		
					}
				}
			}
		}
//END OF THE USER1-USER2 PART
			else{	//if entered invalid number of players
				cerr << "!! Please enter a valid number of players !!" << endl << endl; 
				goto reselect_player;
			}
		}
		if(end == 1){
			if(x_won == 1)
				cout << "\n!!! GAME OVER!!! \nX WON THIS GAME"<< endl;
			if(o_won == 1)
				cout << "\n!!! GAME OVER!!! \nO WON THIS GAME"<< endl;	
		}
		else if(all_filled == 1)
			cout << "\n!!! GAME OVER!!! \nAll cells are filled, nobody won..."<< endl;
		
			return 0;
	}
