#include "functions.h"


	/*It's an utility function that prints the current board*/ 		
	void print_board(char board[12][12], int size_of_board){
		int i,j,k; 	//to use in loops
		char ch = 'a'; 
		cout << endl << "  "; 
		for(i=0; i<size_of_board; i++){	//to print upper frame of the board (a b c d e....)
			cout << ch << " ";
			ch++;
		}
		cout<<endl;
		for(i=0; i<size_of_board; i++){		//prints the board
			cout << i+1;	// prints side frame of the board (1 2 3 4 5 ... )
			for(k=0; k<i+1; k++)
				cout << " ";
			for(j=0; j<size_of_board; j++){
				cout << board[i][j] << " "; 
			}
			cout<< endl;
		}	
	} 	// end of the print_board function

																			
/*	It's an utility function to check the coordinates valid or not. Include uppercase and lowercase conditions. Returns 0 if invalid, returns 1 or 2 if valid */
	int coordinates_valid_or_not(int coord1, char coord2_ch, int size){			
		int flag; // to return an integer if it is valid or not and lowercase or uppercase
		int uppercase='A', lowercase = 'a';		//to use ASCII values of these letters
		if( (int)coord2_ch >= lowercase && (int)coord2_ch <= lowercase+size && coord1>0 && coord1<=size) 
			flag=1;	//lowercase, valid
		else if((int)coord2_ch >= uppercase && (int)coord2_ch <= uppercase+size && coord1>0 && coord1<=size)
			flag=2;	//uppercase, valid
		else
			flag=0;	//invalid

		return flag;
	} // end of the coordinates_valid_or_not function

																		
/* This function makes users move on the board*/
	int make_move(char board[12][12], char vertical, int horizontal, int upper_lower, int user){ 
		int vertical_int; // to convert character vertical value to integer 
		if(upper_lower == 1)// 1 means it is lowercase
			vertical_int = vertical-'a';	//converts to int
		else	//uppercase
			vertical_int = vertical-'A';	// converts to int

		if(board[horizontal-1][vertical_int] == cells::empty){ 	//if the coordinate is empty
			switch(user){
			case 1:	board[horizontal-1][vertical_int] = cells::firstPlayer; //user1's move
					break;
			case 2: board[horizontal-1][vertical_int] = cells::secondPlayer; //user2's move
					break;
			case 3:	//computer moveeeeeeee
					break;
			}
			return 0;
		}else{	//coordinate has already been moved
			cerr << "The coordinate you choose is filled!! Please enter new coordinates..."<< endl;
			return 1;	//tells to main function that the move was not made.
		}	
	}	// end of the make_move function


/* This is an utility function to check the game is end or not for USER1 */
	int check_finish_x(char board[12][12], const int& size, int& x_won){
		int board_won[12][12];	//this board keeps the winning path  - to track 1's you can find the path
		int counter=1, x=0, y=0,i, j;
		int x_before=0, y_before=0, ctr=0;		// to keep previous values of the x and y
		int up=0, down=0;		// to prevent infinite loop, (up-down up-down)
		for(i=0; i<size; i++){
			for(j=0; j<size; j++)
				board_won[i][j] = 0;	//to fill the board with 0's
		}
		for(i=0; i<size; i++){
			x=i;
			if(board[x][y] == 'x'){	//checks the coordinate's value is 'x' or not
				board_won[x][y] = 1;	//fill the cell with 1
check:			
				if(board[x-1][y] == 'x' && x!=0 && down==0 ){	//A move -> northwest
					x_before = x, y_before = y;
					x = x-1;							
					up=1;
					board_won[x][y] = 1;		//fill the cell with 1
					goto check;
				}
				if(board[x-1][y+1]== 'x'){	//B move -> northest
					counter++;
					x_before = x, y_before = y;
					x=x-1,
					y=y+1;
					board_won[x][y] = 1;
					goto check;
				}
				if(board[x][y+1]== 'x'){		//C move -> east
					counter++;
					x_before = x, y_before = y;
					y=y+1;
					board_won[x][y] = 1;
					goto check;
				}
				if(board[x+1][y]== 'x' && x!=0 && up ==0){		//D move -> southeast
					x_before = x, y_before = y;
					x=x+1;
					down=1;
					board_won[x][y] = 1;
					goto check;
				}
				if(y == size-1)
					break;
				counter--;	//to not count moves which is not finish
				x = x_before;		//to go back the coordinates before did the last move
				y= y_before;
				board_won[x][y] = 0;	//to undo the move
			}x++;}
			if(y == size-1){	// if x is winner
				make_uppercase(board, board_won, size, 'x');	//to make uppercase the winning path
				x_won = 1;
				return 1;
			}else
				return 0; 
	}		// end of the check_finish_x function



int check_finish_o(char board[12][12], const int& size, int& o_won){
		int board_won[12][12];			//this board keeps the winning path  - to track 1's you can find the path
		int counter=1, x=0, y=0,i,j;
		int x_before=0, y_before=0, ctr=0;		// to keep previous values of the x and y
		int up=0, down=0;
		for(i=0; i<size; i++){
			for(j=0; j<size; j++)
				board_won[i][j] = 0;	//to fill the board with 0's
		}
		for(i=0; i<size; i++){
			y=i;
			if(board[x][y] == 'o'){	//checks the coordinate's value is 'o' or not
				board_won[x][y] = 1;		//fill the cell with 1
check:			
				if(board[x][y-1] == 'o' && y!=0 && down==0){	//A move -> northwest
					x_before = x, y_before = y;
					y = y-1;
					up=1;
					board_won[x][y] = 1;		//fill the cell with 1
					goto check;
				}
				if(board[x+1][y-1]== 'o'){	//B moved -> northeast
					counter++;
					x_before = x, y_before = y;
					x=x+1;
					y=y-1;
					board_won[x][y] = 1;
					goto check;
					}
					if(board[x+1][y]== 'o'){		//C move -> east
						counter++;
						x_before = x, y_before = y;
						x=x+1;
					board_won[x][y] = 1;
						goto check;
					}
					if(board[x][y+1]== 'o'&& y!=0 && up ==0){		//D move -> southeast
						x_before = x, y_before = y;
						y=y+1;
						down=1;
					board_won[x][y] = 1;
						goto check;
					}
					if(x== size-1)
						break;
					counter--;	//to not count moves which is not finish
					x = x_before;		//to go back the coordinates before did the last move
					y= y_before;
					board_won[x][y] = 0;
			}
			y++;
		}
			if(x == size-1){	// if o is winner
				make_uppercase(board, board_won, size, 'o');		//to make uppercase the winning path
				o_won=1;
				return 1;
			}
			else
				return 0;	
	}		// end of the check_finish_x function


/* This function generates random number to choose a move in computer_move function*/
/* I got this part from the internet */
	int generate_random(){	// 
		int number;
		random_device rd;  
    	mt19937 gen(rd()); 
    	uniform_int_distribution<> distrib(1, 15);
		number =  distrib(gen);
		return number;
	}

/* This function generates random coordinates for computer's move*/
	void choose_different_rand(char board[12][12], int size, int *last_x_ptr, int* last_y_ptr){
		int last_x, last_y;
		last_x_ptr = &last_x, last_y_ptr = &last_y;
		int rand_numb, i;
		int rand_move[2];	
		random_device rd;  
    	mt19937 gen(rd()); 
    	uniform_int_distribution<> distrib(0, size-1);
randomly_move:		
			for(i=0; i<2; i++)
				rand_move[i] = distrib(gen);	
			if(board[rand_move[0]][rand_move[1]] =='.'){ //if the coordinate is empty
				board[rand_move[0]][rand_move[1]] = 'o'; //fill the cell with 'o'
				last_x = rand_move[0];	// to keep last coordinates to use in next coordinate choosing
				last_y = rand_move[1];	
			}
			else
				goto randomly_move;
	}


/* This function makes users move on the board*/
	int computer_move(char board[12][12], int first , int *last_x_ptr, int *last_y_ptr, int size){ 
		int last_x, last_y;	// to keep coordinates of last move
		last_x_ptr = &last_x, last_y_ptr = &last_y;	
		int rand_numb, i;
		int first_move[2];
		int moved;
		if(first == 1){		
			random_device rd;  //Will be used to obtain a seed for the random number engine
    		mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    		uniform_int_distribution<> distrib(0, size-1);
first_again:		
			for(i=0; i<2; i++)
				first_move[i] = distrib(gen);
			if(board[first_move[0]][first_move[1]] =='.'){
				board[first_move[0]][first_move[1]] = 'o';
				last_x = first_move[0];
				last_y = first_move[1];	
			}
			else
				goto first_again;
			moved=1;
		}

		else{
rand_again:
			rand_numb = generate_random();
			//  1. MOVE
			if(rand_numb == 1 || rand_numb == 11 ){		// there is 2 random number to increase the chances of making moves up and down								
				if(board[last_x+1][last_y-1]== '.' && (last_x+1)<=size-1 && (last_y-1)<=size-1 && 0<=(last_x+1) && 0<=(last_y-1) ){					
					board[last_x+1][last_y-1] = 'o';			// 	  o
					last_x = last_x+1;							//	 /        //
 					last_y = last_y-1;							//  o(new)
					moved=1;
				}else{
					moved=0;
					goto rand_again;
				}
			}
			// 2. MOVE
			else if(rand_numb == 2 || rand_numb == 12  ){	// there is 2 random number to increase the chances of making moves up and down						 
				if(board[last_x+1][last_y]  == '.' && last_x+1<=size-1 && last_y<=size-1 && 0<=(last_x+1) && 0<=(last_y)){					
					board[last_x+1][last_y] = 'o';			 	// 	  o
					last_x = last_x+1;							//	   \      	//
					moved=1;									//      o(new)
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 3  ){							// 3. MOVE
				if(board[last_x][last_y-1] == '.' && last_x<=size-1 && last_y-1<=size-1 && 0<=(last_x) && 0<=(last_y-1)){				
					board[last_x][last_y-1] = 'o';			 		  	// 	 o(new) <-- o
 					last_y = last_y-1; 
					moved=1;
				}
				else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 4){							// 4. MOVE
				if(board[last_x][last_y+1] == '.'&& last_x<=size-1 && last_y+1<=size-1 && 0<=(last_x) && 0<=(last_y+1) ){					
					board[last_x][last_y+1] = 'o';			 	// 	 o --> o(new)	  
 					last_y = last_y+1; 
					moved=1;
				}else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 5){							// 5. MOVE
				if(board[last_x+1][last_y-2] == '.' && last_x+1<=size-1 && last_y-2<=size-1 && 0<=(last_x+1) && 0<=(last_y-2) ){					
					board[last_x+1][last_y-2] = 'o';			
 					last_x = last_x+1;							// 	. o .
 					last_y = last_y-2; 							// 	o . .  
					moved=1;									// (new)
				}else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 6){							// 6.MOVE
				if(board[last_x+1][last_y+1]== '.' && last_x+1<=size-1 && last_y+1<=size-1 && 0<=(last_x+1) && 0<=(last_y+1) ){					// 	. o .
					board[last_x+1][last_y+1] = 'o';			// 	. . o  
 					last_x = last_x+1;							//     (new)
 					last_y = last_y+1; 
					moved=1;
				}else{
					moved=0;
					goto rand_again;
				}
			}
			// 7.MOVE
			else if(rand_numb == 7 || rand_numb == 13){			// there is 2 random number to increase the chances of making moves up and down			
				if(board[last_x-1][last_y]== '.' && last_x-1<=size-1 && last_y<=size-1 && 0<=(last_x-1) && 0<=(last_y) ){					
					board[last_x-1][last_y] = 'o';				//  (new)
 					last_x = last_x-1;							//    o . .
					moved=1; 									//   . o .
				}else{
					moved=0;
					goto rand_again;
				}
			}

			// 8.MOVE
			else if(rand_numb == 8 || rand_numb == 14){			// there is 2 random number to increase the chances of making moves up and down	
				if(board[last_x-1][last_y+1]== '.' && last_x-1<=size-1 && last_y+1<=size-1 && 0<=(last_x-1) && 0<=(last_y+1) ){					
					board[last_x-1][last_y+1] = 'o';			//     (new)
 					last_x = last_x-1;							//  . . o
					last_y = last_y+1;							//   . o .
					moved=1; 									
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 9){							// 9.MOVE
				if(board[last_x-1][last_y-1]== '.' && last_x-1<=size-1 && last_y-1<=size-1 && 0<=(last_x-1) && 0<=(last_y-1) ){					
					board[last_x-1][last_y-1] = 'o';			// (new)
 					last_x = last_x-1;							//   o . . .
					last_y = last_y-1;							//    . o .
					moved=1; 									
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 10){							// 10.MOVE
				if(board[last_x-1][last_y+2]== '.' && last_x-1<=size-1 && last_y+2<=size-1 && 0<=(last_x-1) && 0<=(last_y+2) ){					
					board[last_x-1][last_y+2] = 'o';				//       (new)
 					last_x = last_x-1;								//  . . . o
					last_y = last_y+2;								//   . o .
					moved=1; 									
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 15){
				choose_different_rand(board, size, last_x_ptr, last_y_ptr); // to choose independet coordinates from last move
				moved=1;
			}
	}
		if(moved == 1){ 	//if the coordinate is empty
			char y;
			switch(last_y){
				case 0: y='a';break;		case 1: y='b';break; 	case 2: y='c';break; 		case 3: y='d';break; 
				case 4: y='e';break; 		case 5: y='f';break; 	case 6: y='g';break; 		case 7: y='h';break; 
				case 8: y='i';break; 		case 9: y='j';break; 	case 10: y='k';break; 		case 11: y='l';break;
			}
			cout << endl << "Computer's Move -> " << y << last_x+1<< endl;
			return 0;
		}else{	//coordinate has already been moved
			cerr << "The coordinate you choose is filled!! Please enter new coordinates..."<< endl;
			return 1;	//tells to main function that the move was not made.
		}	
	}	// end of the computer_move function


/*This function checks all cells are filled or not*/
	int filled(char board[12][12], int size){
		int ret;	// to keep return value
		int i, j;
		for(i=0; i<size-1; i++){
			for(j=0; j<size-1; j++){
				if(board[i][j] == '.'){	//if the cell is '.' it means its empty, so board is not filled
					ret = 0;	//return 0 - board is not filled
					goto finish;	//no need to check other cells
				}
				else
					ret=1;	// there is no cells with '.' all cells are filled, return 1
			}
		} 	
finish:
		return ret;
	}

/* This function capitalizes the winning path */
void make_uppercase(char game_board[12][12], int board_won[12][12], int size, char letter_won){
	int i, j;
	if(letter_won == 'x'){	//if the winner is 'x'
		for(i=0; i<size; i++){
			for(j=0; j<size; j++){
				if(board_won[i][j] == 1)
					game_board[i][j]='X';	
			}
		}
	}
	else if(letter_won == 'o'){		//if the winner is 'o'
		for(i=0; i<size; i++){
			for(j=0; j<size; j++){
				if(board_won[i][j] == 1)
					game_board[i][j]='O';
			}
		}
	}
	print_board(game_board, size);
}


//	*******HW2 FUNCTIONS******

		/*This function run, when user entered SAVE command. Opens a file with the name entered by the user. And open another file to copy the informations in the first file.*/
		void save_game(string fileName, char game_board[12][12], int size, int player_number){
			ofstream saveFile;	//open a file
			saveFile.open(fileName.c_str());
	 		for (int x = 0; x < size; x++){
  	  			for (int y = 0; y < size; y++)
   					saveFile << game_board[x][y];	
  		 	}
  		 	saveFile<< " " << size << " " << player_number;	
  		 	string gameData ;
  			saveFile.close();
			ifstream readSaveFile(fileName);	//open another file and copy the first file
			while (getline (readSaveFile, gameData)) {	}
			readSaveFile.close();
			ofstream loadFile("previous_game.txt");
			loadFile << gameData;
			loadFile.close();
		}


		/*This function load the previous data from the previous_game.txt file. Because this file contains the information saved after the SAVE command.
		  The function transfers this information to the game, allowing the user to continue the game from where she/he left off.*/
		void load_game(string secondWord, char game_board[12][12], int& size, int& player_number, int& user_turn){
			string previous_data;	
			ifstream readDataFile("previous_game.txt");
			while (getline (readDataFile, previous_data)) {}
			readDataFile.close();
		
			string board_data;
			string size_data_ch;
			int a=0, b=0 ;

			string word = "";
			for (auto iter : previous_data){
				if (iter == ' '){
					if(a==0){
						board_data=word;
						a++;//to sp
					}else if(a!=0 && b==0){
						size_data_ch=word;
						b++;
					}
					word = "";
				}else 
					word = word + iter;
			}
			player_number = stoi(word);
			size = stoi(size_data_ch);
			int k=0 ,i, j;
			for(i=0; i<size; i++){
				for( j=0; j<size; j++){
					game_board[i][j] = board_data[k]; 
					k++;
			}}
			if(player_number ==2){
				int x=0, y=0;
				for( i=0; i<size; i++){
					for( j=0; j<size; j++){
						if(game_board[i][j] == 'x')		x++;
						else if(game_board[i][j] == 'o')	y++;			
				}}
					if(x>y)		user_turn=2;
					else if(x<=y)		user_turn=1;
			}
							
			print_board(game_board,size);
		}


/*This function performs the necessary operations on the received string. Like save, load, send coordinate etc. */
int file_operations(const string command ,char& coordinate1, int& coordinate2, char game_board[12][12], int& size, int& player, int& user_turn){
	int return_value; // 1- saved, 2-loaded, 3-entered coordinate, 4-invalid
		auto save = "SAVE";	
		auto load = "LOAD ";
		string firstWord, secondWord;
		int a=0;
		string word = "";		//to split the string
    	for (auto x : command){
        	if (x ==  ' '){
            	string temp = word;
            	word = "";
        		if(a==0)	
        			firstWord=temp;//keep the first word
        		else if(a==x)  		
        			a++;
      		}else
            	word = word + x;
    	}
    	secondWord =word;
		if( save == firstWord){	//if first word is save, do save file operations
			save_game(secondWord, game_board, size, player);
  			return_value = 1;	
		}else if(load == firstWord ){	//if first word is load, do load file operations
			load_game(secondWord, game_board, size, player, user_turn);
  			return_value=2;
		}else if(command.size() == 2){	//if user entered a coordinete
			coordinate1 = command.at(0);	
			coordinate2 = command.at(1)-48;	//convert char to int
			return_value = 3;
		}else{	//invalid input
			cerr << "Coordinates are invalid" << endl;
			return_value = 4;
		}
		return return_value;
	}
