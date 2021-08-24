#include "functions.h"


int Hex:: object=0;		int Hex:: ob1=0;			//Initialization of static variables
int Hex:: ob2=0;		int Hex:: ob3=0;
int Hex:: ob4=0;		int Hex:: ob5=0;



		Hex :: Hex (int board_size, int user){
			if(board_size<=5){		//checks validity of entered board size
				cerr << "!! Please enter a valid board size !!" << endl << endl;
				cout << "Please enter the board size between (like 6x6, 7x7)" << endl;
				cin>>board_size;
				Hex(board_size,user);	//enter new board size
				exit(1);
			}else
				set_size(board_size); 

			if(user!=1 && user!=2){
				cerr << "!! Please enter a valid number of players !!" << endl << endl; 
				cout << "Press 1 for single player game, 2 for two player game..."<< endl;
				cin>>player;
				Hex(board_size,user);	
				exit(1);
			}else
				set_player(user);
			object++;
			set_board();
		}

		Hex::Hex(int board_size, int user, string board_data){
			set_size(board_size);
			set_player(user);
			set_board(board_data);
		}

		Hex::Hex(int board_size, int user, string board_data, int user_turn) : turn(user_turn){
			set_size(board_size);
			set_player(user);
			set_board(board_data);
		}


	inline void Hex :: set_size(int board_size)	{ size=board_size; }
	inline int Hex ::  get_size() { return size; }
	inline void Hex :: set_player(int user)  { player=user; }
	inline int Hex:: get_player() { return player;}


	
	void Hex:: set_board(){
		hexCells.resize(size, vector<Cell>(size));
		for(int i=0; i<size; i++){ 
			for(int j = 0; j < size; j++)
				hexCells[i][j].data = '.';
		}	
		print_board();
	}

	void Hex:: set_board(string board_data){
		hexCells.resize(size, vector<Cell>(size));
		int k=0;
		for(int i=0; i<size; i++){ 
			for(int j = 0; j < size; j++){
				hexCells[i][j].data = board_data[k];
				k++;
		}}
		print_board();
	}
	

	void Hex:: print_board(){
		int i,j,k; char ch = 'a'; 
		cout << endl << "  "; 
		for(i=0; i<size; i++){	//to print upper frame of the board (a b c d e....)
			cout << ch << " ";
			ch++;
		}cout<<endl;
		for(i=0; i<size; i++){		//prints the board
			cout << i+1;	// prints side frame of the board (1 2 3 4 5 ... )
			for(k=0; k<i+1; k++)
				cout << " ";
			for(j=0; j<size; j++){
				cout << hexCells[i][j].data << " "; 
			}cout<< endl;}
		playGame();
	}



	void Hex:: print_board(string finish){
		int i,j,k; 	//to use in loops
		char ch = 'a'; 
		cout << endl << "  "; 
		for(i=0; i<size; i++){	//to print upper frame of the board (a b c d e....)
			cout << ch << " ";
			ch++;
		}cout<<endl;
		for(i=0; i<size; i++){		//prints the board
			cout << i+1;	// prints side frame of the board (1 2 3 4 5 ... )
			for(k=0; k<i+1; k++)
				cout << " ";
			for(j=0; j<size; j++){
				cout << hexCells[i][j].data << " "; 
			}cout<< endl;}
	}


	void Hex:: playGame(){
		int ret_data=0;
		if(player == 1){
			if(turn%2==0 ){
				cout << "It's your turn. Enter a coordinate to move..." << endl;
				getline(cin>>ws,command);
				analyze_command(); //move yapıp döndü
				check_finish_x();
			}else{
				int c_first=1;
				computer_move(c_first);	
				check_finish_o();
			}		
		}else{
			if(turn%2 ==0){	
				cout << "It's user1's turn. Enter a coordinate to move..." << endl;
				getline(cin>>ws, command);
				analyze_command(); 
				ret_data = check_finish_x();
			}else if(ret_data!=1){
				cout << "It's user2's turn. Enter a coordinate to move..." << endl;
				getline(cin>>ws, command);
				analyze_command(); 
				check_finish_o();
			}}
	}


	void Hex:: analyze_command(){
		auto save = "SAVE", load = "LOAD", compare="COMPARE";
		string firstWord, secondWord;	int a=0;
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
			save_game(secondWord);
			cout<< "\nTHE GAME HAS BEEN SAVED SUCCESSFULLY!\nYou can access this game whenever you want with the LOAD command." << endl;	
		}
		else if(load == firstWord ){	//if first word is load, do load file operations
			load_game(secondWord);
			cout << "\nTHE FILE HAS BEEN LOADED SUCCESSFULLY!\nYou can continue playing the game where you left off." << endl<<endl;
		}
		else if(command.size() == 2){	//if user entered a coordinate like a2
			coord1 = command.at(0);	
			coord2 = command.at(1)-48;	//convert char to int
			coordinates_valid_or_not();
		}
		else if(command.size() == 3){	//if user entered a coordinate like a12
			string n1, n2, letter;
			int number;
			coord1 = command[0];
			n1= command[1];
			n2= command[2];
			n1.append(n2);
			coord2 = stoi(n1);
			coordinates_valid_or_not();
		}
		else if(compare == firstWord){	// if user wants to COMPARE games
			char t1 = secondWord[0];
			int otherObj = (int)t1-48;
			cout<< otherObj <<endl;
			if(compare_objects(otherObj)==1){
				cout<<endl<<"Current game (game"<<object<<") has more marked cells than game"<<otherObj<<" !!!"<< endl<<endl;
			}
			else
				cout<<endl<<"Game"<<otherObj<<" has more marked cells than the current game (game"<<object<<") !!!"<<endl<<endl;
			exit(1);
		}else{	//invalid input
			cerr << "Coordinates are invalid!" << endl;
			playGame();
		}
	}

/*	It's an utility function to check the coordinates valid or not. Include uppercase and lowercase conditions. Returns 0 if invalid, returns 1 or 2 if valid */
	void Hex:: coordinates_valid_or_not(){		
		int flag; // to return an integer if it is valid or not and lowercase or uppercase
		int uppercase='A', lowercase = 'a';		//to use ASCII values of these letters
	//	cout << "testAa -> "<< uppercase<< " " <<lowercase<<endl;
		if( coord1 >= lowercase && coord1 <= lowercase+size && coord2>0 && coord2<=size) 
			flag=0;	//lowercase, valid
		else if( coord1 >= uppercase && coord1 <= uppercase+size && coord2>0 && coord2<=size)
			flag=1;	//uppercase, valid
		else{
			flag=2;
			cerr << "Coordinates you entered is invalid, please enter new coordinates..."<< endl;
     	 	playGame();	//invalid
		}
		make_move(flag);
	} 


	void Hex:: make_move(int flag){
		int x_move=0, o_move=0;
		if(flag == 0)// 1 means it is lowercase
			coord1 = coord1-'a';	//converts to int
		else	//uppercase
			coord1 = coord1-'A';	// converts to int

		if(hexCells[coord2-1][coord1].data == cell_states::empty){ 	//if the coordinate is empty
			switch(player){
			case 1:	hexCells[coord2-1][coord1].data = cell_states::firstPlayer; //user1's move	
					x_move=1;	break;
			
			case 2: if(turn%2 !=1){
						hexCells[coord2-1][coord1].data = cell_states::firstPlayer; //user1's move	
						x_move=1;		
					}else{
					hexCells[coord2-1][coord1].data = cell_states::secondPlayer; //user2's move
						o_move=1;
					}break;
			}
			if(x_move==1){
				if(check_finish_x() ==1){
					game_end('x');
				}else if(filled() ==1){ //doldu
					print_board("filled");
					cerr << "\n!!! GAME OVER!!! \nAll cells are filled, nobody won..."<< endl;
					exit(1);
				}else{
					turn++;
					markedCells();
					print_board();
			}}
			else if(o_move==1){
				if( check_finish_o()==1){	
					game_end('o');

				}else if(filled() ==1){ //doldu
					print_board("filled");
					cerr << "\n!!! GAME OVER!!! \nAll cells are filled, nobody won..."<< endl;
					exit(1);
				}else{
					turn++;
					print_board();
				}}
		}else{	//coordinate has already been moved
			cerr << "The coordinate you choose is filled!! Please enter new coordinates..."<< endl;
			playGame();
		}

	}

	void Hex::game_end(int won){
		if(won=='x'){
			print_board("finish");
			cout << "\n!!! GAME OVER!!! \nX WON THIS GAME"<< endl;
			exit(1);
		}else{
			print_board("finish");
			cout << "\n!!! GAME OVER!!! \nO WON THIS GAME"<< endl;	
			exit(1);
		}
	}


/*This function checks all cells are filled or not*/
	int Hex:: filled(){
		int ret, i, j;
		for(i=0; i<size-1; i++){
			for(j=0; j<size-1; j++){
				if(hexCells[i][j].data == '.'){	//if the cell is '.' it means its empty, so board is not filled
					ret = 0;	//return 0 - board is not filled
					break;
				}
				else
					ret=1;	// there is no cells with '.' all cells are filled, return 1
		}} 	
		return ret;
	}


	/* This is an utility function to check the game is end or not for USER1 */
	int Hex:: check_finish_x(){
		board_won.resize(size, vector<int>(size));
		int counter=1, x=0, y=0,i, j;
		int x_before=0, y_before=0, ctr=0;		// to keep previous values of the x and y
		int up=0, down=0;		// to prevent infinite loop, (up-down up-down)
		for(i=0; i<size; i++){
			for(j=0; j<size; j++)
				board_won[i][j] = 0;	//to fill the board with 0's
		}
		for(i=0; i<size; i++){
			x=i;
			if(hexCells[x][y].data == cell_states::firstPlayer){	//checks the coordinate's value is 'x' or not
				board_won[x][y] = 1;	//fill the cell with 1
check:			
			if(y != size-1 ){	
				if(x-1>=0 && down==0 && hexCells[x-1][y].data == cell_states::firstPlayer){	//A move -> northwest					
					x_before = x, y_before = y;
					x = x-1;							
					up=1;
					board_won[x][y] = 1;		//fill the cell with 1
					goto check;
				}
				if(y+1<=size-1 &&x-1>=0 &&hexCells[x-1][y+1].data == cell_states::firstPlayer){
					counter++;
					x_before = x, y_before = y;
					x=x-1,
					y=y+1;
					board_won[x][y] = 1;
					goto check;
				}
				if(hexCells[x][y+1].data== cell_states::firstPlayer){		//C move -> east
					counter++;
					x_before = x, y_before = y;
					y=y+1;
					board_won[x][y] = 1;
					goto check;
				}

				if( x+1<=size-1  && hexCells[x+1][y].data== cell_states::firstPlayer && up ==0){		//D move -> southeast
					x_before = x, y_before = y;
					x=x+1;
					down=1;
					board_won[x][y] = 1;
					goto check;
				}
			}
			if(y==size-1)
				break;
			counter--;	//to not count moves which is not finish
			x = x_before;		//to go back the coordinates before did the last move
			y= y_before;
			board_won[x][y] = 0;	//to undo the move	
			}x++;
		}
		if(y == size-1){
			char letter_won = 	cell_states::firstPlayer;// if x is winner
			make_uppercase( letter_won);	//to make uppercase the winning path
			return 1;
		}else
			return 0; 
	}		



int Hex:: check_finish_o(){
		board_won.resize(size, vector<int>(size));
		int counter=1, x=0, y=0,i,j;
		int x_before=0, y_before=0, ctr=0;		// to keep previous values of the x and y
		int up=0, down=0;
		for(i=0; i<size; i++){
			for(j=0; j<size; j++)
				board_won[i][j] = 0;	//to fill the board with 0's
		}
		for(i=0; i<size; i++){
			y=i;
			if(hexCells[x][y].data == cell_states::secondPlayer){	//checks the coordinate's value is 'o' or not
				board_won[x][y] = 1;		//fill the cell with 1
check:					
				if(x !=size-1){
					if( y-1>=0 && hexCells[x][y-1].data == cell_states::secondPlayer && down==0){	//A move -> northwest
						x_before = x, y_before = y;
						y = y-1;	up=1;
						board_won[x][y] = 1;		//fill the cell with 1
						goto check;
					}
					if(y-1>=0 && x+1<=size-1 && hexCells[x+1][y-1].data == cell_states :: secondPlayer){	//B moved -> northeast					
						counter++;
						x_before = x, y_before = y;
						x=x+1;	y=y-1;
						board_won[x][y] = 1;
						goto check;
					}
					if(x+1<=size-1 && hexCells[x+1][y].data== cell_states::secondPlayer){		//C move -> east
						counter++;
						x_before = x, y_before = y;
						x=x+1;
						board_won[x][y] = 1;
						goto check;
					}
					if(y+1<=size-1 && hexCells[x][y+1].data == cell_states::secondPlayer ){		//D move -> southeast
						x_before = x, y_before = y;
						y=y+1;	down=1;
						board_won[x][y] = 1;
						goto check;
					}
				}
				if(x==size-1)
					break;
				
				counter--;	//to not count moves which is not finish
				x = x_before;		//to go back the coordinates before did the last move
				y= y_before;
				board_won[x][y] = 0;
		}y++;}
		if(x == size-1){	// if o is winner
			char letter_won = 	cell_states::secondPlayer;// if x is winner
			make_uppercase(letter_won);		//to make uppercase the winning path
			return 1;
		}else
			return 0;	
	}		



/* This function generates random number to choose a move in computer_move function*/
/* I got this part from the internet */
	int Hex:: generate_random(){	// 
		int number;
		random_device rd;  
    	mt19937 gen(rd()); 
    	uniform_int_distribution<> distrib(1, 15);
		number =  distrib(gen);
		return number;
	}

/* This function generates random coordinates for computer's move*/
	void Hex:: choose_different_rand(int &last_x, int &last_y){
		int rand_numb, i, rand_move[2];	
		random_device rd;  
    	mt19937 gen(rd()); 
    	uniform_int_distribution<> distrib(0, size-1);
randomly_move:		
			for(i=0; i<2; i++)
				rand_move[i] = distrib(gen);	
			if(hexCells[rand_move[0]][rand_move[1]].data =='.'){ //if the coordinate is empty
				hexCells[rand_move[0]][rand_move[1]].data = 'o'; //fill the cell with 'o'
				last_x = rand_move[0];	// to keep last coordinates to use in next coordinate choosing
				last_y = rand_move[1];	
			}
			else
				goto randomly_move;
	}


/* This function makes users move on the board*/
	int Hex:: computer_move( int first ){ 
		int last_x, last_y, rand_numb, i, first_move[2], moved;
		if(first == 1){		
			random_device rd;  //Will be used to obtain a seed for the random number engine
    		mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    		uniform_int_distribution<> distrib(0, size-1);
first_again:		
			for(i=0; i<2; i++)
				first_move[i] = distrib(gen);
			if(hexCells[first_move[0]][first_move[1]].data =='.'){
				hexCells[first_move[0]][first_move[1]].data = 'o';
				last_x = first_move[0];
				last_y = first_move[1];	
			}
			else
				goto first_again;
			moved=1;
		}else{
rand_again:
			rand_numb = generate_random();
			//cout<<"rand-> "<< rand_numb<< endl;
			//  1. MOVE
			if(rand_numb == 1 || rand_numb == 11 ){		// there is 2 random number to increase the chances of making moves up and down								
				if(hexCells[last_x+1][last_y-1].data== '.' && (last_x+1)<=size-1 && (last_y-1)<=size-1 && 0<=(last_x+1) && 0<=(last_y-1) ){					
					hexCells[last_x+1][last_y-1].data = 'o';			// 	  o
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
				if(hexCells[last_x+1][last_y].data  == '.' && last_x+1<=size-1 && last_y<=size-1 && 0<=(last_x+1) && 0<=(last_y)){					
					hexCells[last_x+1][last_y].data = 'o';			 	// 	  o
					last_x = last_x+1;							//	   \      	//
					moved=1;									//      o(new)
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 3  ){							// 3. MOVE
				if(hexCells[last_x][last_y-1].data == '.' && last_x<=size-1 && last_y-1<=size-1 && 0<=(last_x) && 0<=(last_y-1)){				
					hexCells[last_x][last_y-1].data = 'o';			 		  	// 	 o(new) <-- o
 					last_y = last_y-1; 
					moved=1;
				}
				else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 4){							// 4. MOVE
				if(hexCells[last_x][last_y+1].data == '.'&& last_x<=size-1 && last_y+1<=size-1 && 0<=(last_x) && 0<=(last_y+1) ){					
					hexCells[last_x][last_y+1].data = 'o';			 	// 	 o --> o(new)	  
 					last_y = last_y+1; 
					moved=1;
				}else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 5){							// 5. MOVE
				if(hexCells[last_x+1][last_y-2].data == '.' && last_x+1<=size-1 && last_y-2<=size-1 && 0<=(last_x+1) && 0<=(last_y-2) ){					
					hexCells[last_x+1][last_y-2].data = 'o';			
 					last_x = last_x+1;							// 	. o .
 					last_y = last_y-2; 							// 	o . .  
					moved=1;									// (new)
				}else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 6){							// 6.MOVE
				if(hexCells[last_x+1][last_y+1].data== '.' && last_x+1<=size-1 && last_y+1<=size-1 && 0<=(last_x+1) && 0<=(last_y+1) ){					// 	. o .
					hexCells[last_x+1][last_y+1].data = 'o';			// 	. . o  
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
				if(hexCells[last_x-1][last_y].data == '.' && last_x-1<=size-1 && last_y<=size-1 && 0<=(last_x-1) && 0<=(last_y) ){					
					hexCells[last_x-1][last_y].data = 'o';				//  (new)
 					last_x = last_x-1;							//    o . .
					moved=1; 									//   . o .
				}else{
					moved=0;
					goto rand_again;
				}
			}

			// 8.MOVE
			else if(rand_numb == 8 || rand_numb == 14){			// there is 2 random number to increase the chances of making moves up and down	
				if(hexCells[last_x-1][last_y+1].data== '.' && last_x-1<=size-1 && last_y+1<=size-1 && 0<=(last_x-1) && 0<=(last_y+1) ){					
					hexCells[last_x-1][last_y+1].data = 'o';			//     (new)
 					last_x = last_x-1;							//  . . o
					last_y = last_y+1;							//   . o .
					moved=1; 									
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 9){							// 9.MOVE
				if(hexCells[last_x-1][last_y-1].data == '.' && last_x-1<=size-1 && last_y-1<=size-1 && 0<=(last_x-1) && 0<=(last_y-1) ){					
					hexCells[last_x-1][last_y-1].data = 'o';			// (new)
 					last_x = last_x-1;							//   o . . .
					last_y = last_y-1;							//    . o .
					moved=1; 									
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 10){							// 10.MOVE
				if(hexCells[last_x-1][last_y+2].data== '.' && last_x-1<=size-1 && last_y+2<=size-1 && 0<=(last_x-1) && 0<=(last_y+2) ){					
					hexCells[last_x-1][last_y+2].data = 'o';				//       (new)
 					last_x = last_x-1;								//  . . . o
					last_y = last_y+2;								//   . o .
					moved=1; 
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 15){
				choose_different_rand(last_x, last_y); // to choose independet coordinates from last move
				moved=1;
			}
	}
		if(moved == 1){ 	//if the coordinate is empty
			char y;
			switch(last_y){		// to print which move computer did
				case 0: y='a';break;		case 1: y='b';break; 	case 2: y='c';break; 		case 3: y='d';break; 
				case 4: y='e';break; 		case 5: y='f';break; 	case 6: y='g';break; 		case 7: y='h';break; 
				case 8: y='i';break; 		case 9: y='j';break; 	case 10: y='k';break; 		case 11: y='l';break;
			}
			cout << endl << "Computer's Move -> " << y << last_x+1<< endl;
			turn++;									
			print_board();
			return 0;
		}else{	//coordinate has already been moved
			cerr << "The coordinate you choose is filled!! Please enter new coordinates..."<< endl;
			return 1;	//tells to main function that the move was not made.
		}	
	}	



	void Hex:: make_uppercase( char letter_won){
		int i, j;
		if(letter_won == 'x'){	//if the winner is 'x'
			for(i=0; i<size; i++){
				for(j=0; j<size; j++){
					if(board_won[i][j] == 1)
						hexCells[i][j].data='X';	
		}}}
		else if(letter_won == 'o'){		//if the winner is 'o'
			for(i=0; i<size; i++){
				for(j=0; j<size; j++){
					if(board_won[i][j] == 1)
						hexCells[i][j].data='O';
		}}}
}


	void Hex:: save_game(string fileName){
			ofstream saveFile;	//open a file
			saveFile.open(fileName.c_str());
	 		for (int x = 0; x < size; x++){
  	  			for (int y = 0; y < size; y++)
   					saveFile << hexCells[x][y].data;	//saves board
  		 	}
  		 	saveFile<< " " << size << " " << player;	//saves size and player information
	}


	void Hex:: load_game(string fileName){
			string previous_data;	
			ifstream readDataFile(fileName);
			while (getline (readDataFile, previous_data)) {}
			readDataFile.close();
		
			string board_data, size_data_ch;
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
					}word = "";
				}else 
					word = word + iter;
			}
			player = stoi(word);
			size = stoi(size_data_ch);
			
			int x=0, y=0;
			int user_turn;
			if(player==1)
				Hex(size,player,board_data);			

			else if(player==2){	//to find who's turn
				for(int i=0;i<size*size; i++){
					if(board_data[i] == 'x')
						x++;
					else if(board_data[i]=='o')
						y++;
				}
				if(x<=y)	user_turn=0;
				else	user_turn=1;
				Hex(size, player, board_data, user_turn);			
			}
	}



	void Hex:: markedCells(){		
		int counter=0;	// to keep number of marked cells
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				if(hexCells[i][j].data!='.'){
					counter++;
		}}}
		counter++;		
		if(object==1)		ob1=counter;	// to assign marked cells datas to static variables
		else if(object==2)	ob2=counter;	
		else if(object==3)	ob3=counter;
		else if(object==4)	ob4=counter;
		else if(object==5)	ob5=counter;
	}



	bool Hex:: compare_objects(int another_obj){	//compares current game and another game datas
		int numbMarkedCells1 = get_markedCells(object);
		int numbMarkedCells2 = get_markedCells(another_obj);
		if(numbMarkedCells1>numbMarkedCells2)
			return true;
		else
			return false;
	}
