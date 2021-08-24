#include "functions.h"


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
		int first=1; //gotodan Ã¶nce
		int all_filled;
		string command;
		int user_turn;

		cout << "WELCOME TO HEX GAME" << endl;	

resize:

		cout << "Please enter the board size between 6 and 12..." << endl;
		cin >> size;
		if(size<6 || size>12){		//if the board size is invalid
			cerr << "!! Please enter a valid board size !!" << endl << endl;
			goto resize;
		}
		else{		// if the board size is valid

			//cout<< endl;
reselect_player:

			int player;
			cout << "Press 1 for single player game, 2 for two player game..."<< endl;
			cin >> player;	cout<<endl;

				for(i=0; i<12; i++){		//to fill the board with .'s
					for(j=0; j<12; j++){
						board[i][j] = '.';	
				}}

			cout<<"REMINDING!!\nUse the 'SAVE' command if you want to save the game, or use the 'LOAD' command if you want to continue the game you previously saved."<<endl<<endl;
			switch(size){
				case 6:cout <<"[6x6]"<<endl;break;		case 7: cout<<"[7x7]"<<endl;break;		case 8: cout<<"[8x8]"<<endl;break;		case 9: cout<<"[9x9]"<<endl;break;
				case 10:cout<<"[10x10]"<<endl;break;		case 11: cout<<"[11x11]"<< endl;break;		case 12:cout<<"[12x12]"<<endl;break;
			
			}

//START USER - COMPUTER PART
			if(player==1){	
				print_board(board, size);
				cin.clear();
				cin.ignore(100, '\n');
				while(end!=1){	
					cout << "It's your turn. Enter a coordinate to move..." << endl;
		recoord1:		// to enter new coordinates	
					cin.clear();
					getline(cin, command);
					auto ret_file_func = file_operations(command, coord2_ch, coord1, board, size, player, user_turn);

					if(ret_file_func == 1){
						cout<< "\nTHE GAME HAS BEEN SAVED SUCCESSFULLY!\nYou can access this game whenever you want with the LOAD command." << endl;	
						break;					
					}else if(ret_file_func == 2){
						cout << "\nTHE FILE HAS BEEN LOADED SUCCESSFULLY!\nYou can continue playing the game where you left off." << endl<<endl;
							cout << "It's your turn. Enter a coordinate to move..." << endl;
							goto recoord1;
					}else if(ret_file_func ==3)
						cout << coord2_ch << coord1<< endl;
					else if(ret_file_func ==4){}

					if(ret_file_func != 4)
						return_flag = coordinates_valid_or_not(coord1, coord2_ch, size);	 //if coordinates are valid
					
					if( return_flag != 0){
						ret_move = make_move(board, coord2_ch, coord1, return_flag, 1);	//make move
						if(ret_move == 1)	//if move cannot make
							goto recoord1;
						end = check_finish_x(board, size, x_won);
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
							end = check_finish_o(board, size, o_won);
							if(filled(board, size) == 1){
								all_filled=1;
								break;
				}}}else{	//if coordinates are invalid
						cerr << "Coordinates you entered is invalid, please enter new coordinates..."<< endl;
						goto recoord1;
					}}}
//END OF THE USER COMPUTER PART

//START OF THE USER1-USER2 PART
			else if(player==2){
				print_board(board, size);
			while(end!=1){
				cout << "It's user1's turn. Enter a coordinate to move..." << endl;
recoord2:			// to enter new coordinates
					getline(cin>>ws, command);
					auto ret_file_func = file_operations(command, coord2_ch, coord1, board, size, player,user_turn);
					if(ret_file_func == 1){
						cout<< "\nTHE GAME HAS BEEN SAVED SUCCESSFULLY!\nYou can access this game whenever you want with the LOAD command." << endl;	
						break;					
					}else if(ret_file_func == 2){
						cout << "\nTHE FILE HAS BEEN LOADED SUCCESSFULLY!\nYou can continue playing the game where you left off." << endl<<endl;
							if(user_turn == 1){
							cout << "It's user1's turn. Enter a coordinate to move..." << endl;
								goto recoord2;
							}else if(user_turn== 2){
							cout << "It's user2's turn. Enter a coordinate to move..." << endl;
								goto recoord3;
					}}else if(ret_file_func ==3)
						cout << coord2_ch << coord1<< endl;
					else if(ret_file_func ==4){	}

					if(ret_file_func != 4)
						return_flag = coordinates_valid_or_not(coord1, coord2_ch, size);	 //if coordinates are valid

				if( return_flag != 0){
					ret_move = make_move(board, coord2_ch, coord1, return_flag, 1);			//make move
					if(ret_move == 1)	//if move cannot make
						goto recoord2;
					print_board(board, size);
					end = check_finish_x(board, size, x_won);
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
					getline(cin, command);
					auto ret_file_func = file_operations(command, coord2_ch, coord1, board, size, player, user_turn);

					if(ret_file_func == 1){
						cout<< "\nTHE GAME HAS BEEN SAVED SUCCESSFULLY!\nYou can access this game whenever you want with the LOAD command." << endl;	
						break;					
					}else if(ret_file_func == 2){
						cout << "\nTHE FILE HAS BEEN LOADED SUCCESSFULLY!\nYou can continue playing the game where you left off." << endl<< endl;
								if(user_turn == 1){
							cout << "It's user1's turn. Enter a coordinate to move..." << endl;
								goto recoord2;
							}else if(user_turn== 2){
							cout << "It's user2's turn. Enter a coordinate to move..." << endl;
								goto recoord3;
					}}
					else if(ret_file_func ==3)
						cout << coord2_ch << coord1<< endl;
					else if(ret_file_func ==4){	}

					if(ret_file_func != 4)
						return_flag = coordinates_valid_or_not(coord1, coord2_ch, size);	 //if coordinates are valid


					if( return_flag != 0){
						ret_move = make_move(board, coord2_ch, coord1, return_flag, 2);		//make move
						if(ret_move == 1)	//if move cannot make
							goto recoord3;
						print_board(board, size);
						end = check_finish_o(board, size, o_won);
						if(filled(board, size) == 1){
							all_filled=1;
							break;
						}
					}else{		//if coordinates are invalid
						cerr << "Coordinates you entered is invalid, please enter new coordinates..."<< endl;
						goto recoord3;		
				}}}}
//END OF THE USER1-USER2 PART
			else{	//if entered invalid number of players
				cerr << "!! Please enter a valid number of players !!" << endl << endl; 
				goto reselect_player;
		}}
		if(end == 1){
			if(x_won == 1)
				cout << "\n!!! GAME OVER!!! \nX WON THIS GAME"<< endl;
			if(o_won == 1)
				cout << "\n!!! GAME OVER!!! \nO WON THIS GAME"<< endl;	
		}else if(all_filled == 1)
			cout << "\n!!! GAME OVER!!! \nAll cells are filled, nobody won..."<< endl;
			return 0;
	}
