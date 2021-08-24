#include "HexVector.h"
using namespace sevraHexGame;

	/*	Constructor with two parameter	*/
		HexVector :: HexVector (int boardSize, int user){
			if(boardSize<=5){		//checks validity of entered board size
				cerr << "!! Please enter a valid board size !!" << endl << endl;
				cout << "Please enter the board size between (like 6x6, 7x7)" << endl;
				cin>>boardSize;
				HexVector(boardSize,user);	//enter new board size
			}else
				setSize(boardSize); 

			if(user!=1 && user!=2){
				cerr << "!! Please enter a valid number of players !!" << endl << endl; 
				cout << "Press 1 for single player game, 2 for two player game..."<< endl;
				cin>>user;
				HexVector(boardSize,user);	
			}else
				setPlayer(user);

			allMoves.resize(getSize(), vector<int>(getSize()));
			for(int i=0; i<size; i++){
				for(int j=0; j<size; j++)
					allMoves[i][j] = 0;
			}
			setBoard();
		}

		/*Constructor after reading from file (computer-user)*/
		HexVector::HexVector(int board_size, int user, string board_data){

			setSize(board_size);
			setPlayer(user);
			setBoard(board_data);
		}

		/*Constructor after reading from file (player1-player2)*/
		HexVector::HexVector(int board_size, int user, string board_data, int user_turn) : turn(user_turn){
			setSize(board_size);
			setPlayer(user);
			setBoard(board_data);
		}


	void HexVector:: setSize(int boardSize){
		size= boardSize;
		reset();
		allMoves.resize(getSize(), vector<int>(getSize()));
		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++)
				allMoves[i][j] = 0;
			
	}


	void HexVector::setBoard(){
		hexCells.resize(getSize(), vector<Cell>(getSize()));
			for(int i=0; i<getSize(); i++)
				for(int j = 0; j < getSize(); j++)
					hexCells[i][j].setData('.');	
		print();
	}



	void HexVector:: setBoard(string board_data){
		reset();
		hexCells.resize(getSize(), vector<Cell>(size));
		int k=0;
		char temp;
		for(int i=0; i<getSize(); i++){ 
			for(int j = 0; j < getSize(); j++){
				hexCells[i][j].setData(board_data[k]);
				k++;
		}}
		cout << "\nTHE FILE HAS BEEN LOADED SUCCESSFULLY!\nYou can continue playing the game where you left off." << endl<<endl;
		print();
	}

	void HexVector::print(){
		cout<<"Number of Moves -> "<<numberOfMoves()<<endl;
		int *ptr= lastMove();
		cout<<"lastMove() function test->  "<< *(ptr+1)<<*ptr+1 <<" --- equivalence in board format-> ";
			switch(*(ptr+1)){		// to print which move computer did
				case 0: cout<<'a';break;		case 1: cout<<'b';break; 	case 2: cout<<'c';break; 		case 3: cout<<'d';break; 
				case 4: cout<<'e';break; 		case 5: cout<<'f';break; 	case 6: cout<<'g';break; 		case 7: cout<<'h';break; 
				case 8: cout<<'i';break; 		case 9: cout<<'j';break; 	case 10: cout<<'k';break; 		case 11: cout<<'l';break;
				}cout<<*ptr+1<<endl;

		char ch = 'a'; 
		cout << endl << "  "; 
		for(int i=0; i<getSize(); i++){	//to print upper frame of the board (a b c d e....)
			cout << ch << " ";
			ch++;
		}cout<<endl;
		for(int i=0; i<getSize(); i++){		//prints the board
			cout << i+1;	// prints side frame of the board (1 2 3 4 5 ... )
			for(int k=0; k<i+1; k++)
				cout << " ";
			for(int j=0; j<getSize(); j++){
				cout << hexCells[i][j].getData() << " "; 
			}cout<< endl;}
		enterCommand();		
	}


	void HexVector:: print(string finish){
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
			for(j=0; j<size; j++)
				cout << hexCells[i][j].getData() << " "; 
			cout<< endl;
		}
	}


	void HexVector:: enterCommand(){
		string command;   int ret_data=0;
		if(player == 1){
			if(turn%2==0 ){
				cout << "It's your turn. Enter a coordinate to move..." << endl;
				getline(cin>>ws,command);
				play(command); //move yapıp döndü
				isEnd(1);
			}else{
				int c_first=1;
				play();
				isEnd(2);
			}		
		}else{
			if(turn%2 ==0){	
				cout << "It's user1's turn. Enter a coordinate to move..." << endl;
				getline(cin>>ws, command);
				play(command); 
				ret_data = isEnd(1);
			}else{
				cout << "It's user2's turn. Enter a coordinate to move..." << endl;
				getline(cin>>ws, command);
				play(command); 
				isEnd(2);
			}}

	}




	void HexVector:: analyze_command(string command){
		auto save = "SAVE", load = "LOAD", compare="COMPARE", exit="EXIT";
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
    		fileName=secondWord;
    		writeToFile(fileName);
			cout<< "\nTHE GAME HAS BEEN SAVED SUCCESSFULLY!\nYou can access this game whenever you want with the LOAD command." << endl;	
		}
		else if(load == firstWord ){	//if first word is load, do load file operations
    		fileName=secondWord;
			readFromFile(fileName);
  		}
		else if(command.size() == 4){
			if(exit == secondWord)
				cerr<<"!! The game is interrupted by the user !!"<<endl;
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
		}
		else{	//invalid input
			cerr << "Coordinates are invalid!" << endl;
inv:
			enterCommand();
		}
	}




/*	It's an utility function to check the coordinates valid or not. Include uppercase and lowercase conditions. Returns 0 if invalid, returns 1 or 2 if valid */
	void HexVector:: coordinates_valid_or_not(){
		int flag; // to return an integer if it is valid or not and lowercase or uppercase
		int uppercase='A', lowercase = 'a';		//to use ASCII values of these letters
		if( coord1 >= lowercase && coord1 <= lowercase+size && coord2>0 && coord2<=size) 
			flag=0;	//lowercase, valid
		else if( coord1 >= uppercase && coord1 <= uppercase+size && coord2>0 && coord2<=size)
			flag=1;	//uppercase, valid
		else{
			flag=2;
			cerr << "Coordinates you entered is invalid, please enter new coordinates..."<< endl;
     	 	enterCommand();	//invalid
		}
		make_move(flag);
	} 


	void HexVector:: make_move(int flag){
		int x_move=0, o_move=0;
		if(flag == 0)// 1 means it is lowercase
			coord1 = coord1-'a';	//converts to int
		else	//uppercase
			coord1 = coord1-'A';	// converts to int

		if(hexCells[coord2-1][coord1].getData() == '.'){ 	//if the coordinate is empty
			switch(player){
			case 1:	hexCells[coord2-1][coord1].setData('x'); //user1's move				
					x_move=1;
					cout<<"kelebek"<<endl; 		
					setNumberOfMoves();
					allMoves[coord2-1][coord1] = numberOfMoves() ;
					break;
			
			case 2: if(turn%2 !=1){
						hexCells[coord2-1][coord1].setData('x') ; //user1's move
						setNumberOfMoves()	;
						allMoves[coord2-1][coord1] = numberOfMoves();
						x_move=1;		
					}else{
					hexCells[coord2-1][coord1].setData('o')  ; //user2's move
						setNumberOfMoves();
						allMoves[coord2-1][coord1] = numberOfMoves() ;
						o_move=1;
					}break;
			}
/*
			cout<<endl<<"a board showing the moves made in sequence..."<<endl;
			for(int i=0; i<size; i++){
				for(int k=0; k<i+1; k++)
				cout << " ";
				for(int j=0; j<size; j++){
					cout << allMoves[i][j]<< " "; 
				}cout<< endl;
			}
*/
			if(x_move==1){				

				if(isEnd(1))
					game_end('x');
				else{
					turn++;
					print();
			}}
			else if(o_move==1){
				if( isEnd(2)){	
					game_end('o');

				}else if(filled() ==1){ //doldu
					cerr << "\n!!! GAME OVER!!! \nAll cells are filled, nobody won..."<< endl;
				}else{
					turn++;
					print();
				}}
		}else{	//coordinate has already been moved
			cerr << "The coordinate you choose is filled!! Please enter new coordinates..."<< endl;
			enterCommand();
		}
	}


/* This function generates random coordinates for computer's move*/
	void HexVector:: choose_different_rand(int &last_x, int &last_y){
		int rand_numb, i, rand_move[2];	
		random_device rd;  
    	mt19937 gen(rd()); 
    	uniform_int_distribution<> distrib(0, size-1);
randomly_move:		
			for(i=0; i<2; i++)
				rand_move[i] = distrib(gen);	
			if(hexCells[rand_move[0]][rand_move[1]].getData() =='.'){ //if the coordinate is empty
				hexCells[rand_move[0]][rand_move[1]].setData('o') ; //fill the cell with 'o'
				last_x = rand_move[0];	// to keep last coordinates to use in next coordinate choosing
				last_y = rand_move[1];	
			}
			else
				goto randomly_move;
	}



/* This function makes computer's move on the board*/
	int HexVector :: computerMove ( int first ){ 
		int last_x, last_y, rand_numb, i, first_move[2], moved;
		if(first == 1){		
			random_device rd;  //Will be used to obtain a seed for the random number engine
    		mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    		uniform_int_distribution<> distrib(0, size-1);
first_again:		
			for(i=0; i<2; i++)
				first_move[i] = distrib(gen);
			if(hexCells[first_move[0]][first_move[1]].getData() =='.'){
				hexCells[first_move[0]][first_move[1]].setData('o') ;
				last_x = first_move[0];
				last_y = first_move[1];	
			}
			else
				goto first_again;
			moved=1;
		}else{
rand_again:
			rand_numb = generate_random();
			//  1. MOVE
			if(rand_numb == 1 || rand_numb == 11 ){		// there is 2 random number to increase the chances of making moves up and down								
				if(hexCells[last_x+1][last_y-1].getData()== '.' && (last_x+1)<=size-1 && (last_y-1)<=size-1 && 0<=(last_x+1) && 0<=(last_y-1) ){					
					hexCells[last_x+1][last_y-1].setData('o') ;			// 	  o
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
				if(hexCells[last_x+1][last_y].getData()  == '.' && last_x+1<=size-1 && last_y<=size-1 && 0<=(last_x+1) && 0<=(last_y)){					
					hexCells[last_x+1][last_y].setData('o') ;			 	// 	  o
					last_x = last_x+1;							//	   \      	//
					moved=1;									//      o(new)
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 3  ){							// 3. MOVE
				if(hexCells[last_x][last_y-1].getData() == '.' && last_x<=size-1 && last_y-1<=size-1 && 0<=(last_x) && 0<=(last_y-1)){				
					hexCells[last_x][last_y-1].setData('o') ;			 		  	// 	 o(new) <-- o
 					last_y = last_y-1; 
					moved=1;
				}
				else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 4){							// 4. MOVE
				if(hexCells[last_x][last_y+1].getData() == '.' && last_x<=size-1 && last_y+1<=size-1 && 0<=(last_x) && 0<=(last_y+1) ){					
					hexCells[last_x][last_y+1].setData('o');			 	// 	 o --> o(new)	  
 					last_y = last_y+1; 
					moved=1;
				}else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 5){							// 5. MOVE
				if(hexCells[last_x+1][last_y-2].getData() == '.' && last_x+1<=size-1 && last_y-2<=size-1 && 0<=(last_x+1) && 0<=(last_y-2) ){					
					hexCells[last_x+1][last_y-2].setData('o');			
 					last_x = last_x+1;							// 	. o .
 					last_y = last_y-2; 							// 	o . .  
					moved=1;									// (new)
				}else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 6){							// 6.MOVE
				if(hexCells[last_x+1][last_y+1].getData()== '.' && last_x+1<=size-1 && last_y+1<=size-1 && 0<=(last_x+1) && 0<=(last_y+1) ){					// 	. o .
					hexCells[last_x+1][last_y+1].setData('o') ;			// 	. . o  
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
				if(hexCells[last_x-1][last_y].getData() == '.' && last_x-1<=size-1 && last_y<=size-1 && 0<=(last_x-1) && 0<=(last_y) ){					
					hexCells[last_x-1][last_y].setData('o');				//  (new)
 					last_x = last_x-1;							//    o . .
					moved=1; 									//   . o .
				}else{
					moved=0;
					goto rand_again;
				}
			}

			// 8.MOVE
			else if(rand_numb == 8 || rand_numb == 14){			// there is 2 random number to increase the chances of making moves up and down	
				if(hexCells[last_x-1][last_y+1].getData()== '.' && last_x-1<=size-1 && last_y+1<=size-1 && 0<=(last_x-1) && 0<=(last_y+1) ){					
					hexCells[last_x-1][last_y+1].setData('o');			//     (new)
 					last_x = last_x-1;							//  . . o
					last_y = last_y+1;							//   . o .
					moved=1; 									
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 9){							// 9.MOVE
				if(hexCells[last_x-1][last_y-1].getData() == '.' && last_x-1<=size-1 && last_y-1<=size-1 && 0<=(last_x-1) && 0<=(last_y-1) ){					
					hexCells[last_x-1][last_y-1].setData('o');			// (new)
 					last_x = last_x-1;							//   o . . .
					last_y = last_y-1;							//    . o .
					moved=1; 									
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 10){							// 10.MOVE
				if(hexCells[last_x-1][last_y+2].getData()== '.' && last_x-1<=size-1 && last_y+2<=size-1 && 0<=(last_x-1) && 0<=(last_y+2) ){					
					hexCells[last_x-1][last_y+2].setData('o');				//       (new)
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
			setNumberOfMoves();
			allMoves[last_x][last_y] = numberOfMoves();
			switch(last_y){		// to print which move computer did
				case 0: y='a';break;		case 1: y='b';break; 	case 2: y='c';break; 		case 3: y='d';break; 
				case 4: y='e';break; 		case 5: y='f';break; 	case 6: y='g';break; 		case 7: y='h';break; 
				case 8: y='i';break; 		case 9: y='j';break; 	case 10: y='k';break; 		case 11: y='l';break;
			}
			cout << endl << "Computer's Move -> " << y << last_x+1<< endl;
			turn++;		
			/*
			cout<<endl<<"a board showing the moves made in sequence..."<<endl;
			for(int i=0; i<size; i++){
				for(int k=0; k<i+1; k++)
				cout << " ";
				for(int j=0; j<size; j++){
					cout << allMoves[i][j]<< " "; 
				}cout<< endl;
			}
				*/			
			print();
			return 0;
		}else{	//coordinate has already been moved
			cerr << "The coordinate you choose is filled!! Please enter new coordinates..."<< endl;
			return 1;	//tells to main function that the move was not made.
		}	
	}	



void HexVector::game_end(int won){
		if(won=='x'){
			print("finish");
			cout << "\n!!! GAME OVER!!! \nX WON THIS GAME"<< endl;
		//	exit(1);
		}else{
			print("finish");
			cout << "\n!!! GAME OVER!!! \nO WON THIS GAME"<< endl;	
		//	exit(1);
		}
	}


/*This function checks all cells are filled or not*/
	int HexVector:: filled(){
		int ret;
		for(int i=0; i<size-1; i++){
			for(int j=0; j<size-1; j++){
				if(hexCells[i][j].getData() == '.'){	//if the cell is '.' it means its empty, so board is not filled
					ret = 0;	//return 0 - board is not filled
					break;
				}
				else
					ret=1;	// there is no cells with '.' all cells are filled, return 1
		}} 	
		return ret;
	}


	/* This is an utility function to check the game is end or not for USER1 */
	int HexVector:: check_finish_x(){
		board_won.resize(size, vector<int>(size));
		int counter=1, x=0, y=0,i, j;
		int x_before=0, y_before=0;		// to keep previous values of the x and y
		int up=0, down=0;		// to prevent infinite loop, (up-down up-down)
		for(i=0; i<size; i++){
			for(j=0; j<size; j++)
				board_won[i][j] = 0;	//to fill the board with 0's
		}
		for(i=0; i<size; i++){
			x=i;
			if(hexCells[x][y].getData() == 'x'){	//checks the coordinate's value is 'x' or not
				board_won[x][y] = 1;	//fill the cell with 1
check:			
			if(y != size-1 ){	
				if(x-1>=0 && down==0 && hexCells[x-1][y].getData() == 'x'){	//A move -> northwest					
					x_before = x, y_before = y;
					x = x-1;							
					up=1;
					board_won[x][y] = 1;		//fill the cell with 1
					goto check;
				}
				if(y+1<=size-1 &&x-1>=0 &&hexCells[x-1][y+1].getData() == 'x'){
					counter++;
					x_before = x, y_before = y;
					x=x-1,
					y=y+1;
					board_won[x][y] = 1;
					goto check;
				}
				if(hexCells[x][y+1].getData() == 'x'){		//C move -> east
					counter++;
					x_before = x, y_before = y;
					y=y+1;
					board_won[x][y] = 1;
					goto check;
				}

				if( x+1<=size-1  && hexCells[x+1][y].getData() == 'x' && up ==0){		//D move -> southeast
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
			char letter_won = 	'x';// if x is winner
			make_uppercase( letter_won);	//to make uppercase the winning path
			return 1;
		}else
			return 0; 
	}		



int HexVector:: check_finish_o(){
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
			if(hexCells[x][y].getData() == 'o'){	//checks the coordinate's value is 'o' or not
				board_won[x][y] = 1;		//fill the cell with 1
check:					
				if(x !=size-1){
					if( y-1>=0 && hexCells[x][y-1].getData() == 'o' && down==0){	//A move -> northwest
						x_before = x, y_before = y;
						y = y-1;	up=1;
						board_won[x][y] = 1;		//fill the cell with 1
						goto check;
					}
					if(y-1>=0 && x+1<=size-1 && hexCells[x+1][y-1].getData() == 'o'){	//B moved -> northeast					
						counter++;
						x_before = x, y_before = y;
						x=x+1;	y=y-1;
						board_won[x][y] = 1;
						goto check;
					}
					if(x+1<=size-1 && hexCells[x+1][y].getData() == 'o'){		//C move -> east
						counter++;
						x_before = x, y_before = y;
						x=x+1;
						board_won[x][y] = 1;
						goto check;
					}
					if(y+1<=size-1 && hexCells[x][y+1].getData() == 'o' ){		//D move -> southeast
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
			char letter_won = 'O';// if x is winner
			make_uppercase(letter_won);		//to make uppercase the winning path
			return 1;
		}else
			return 0;	
		
	}		


/*This function checks if the game is end */
	bool HexVector:: isEnd(int player){
		if(player == 1){
			if(check_finish_x() == 1)
				return true;
			return false;
		}
		else{
			if(check_finish_o() == 1)
				return true;
			return false;
		}
	}


/*	This function makes uppercase the winning path	*/
	void HexVector:: make_uppercase( char letter_won){
		int i, j;
		if(letter_won == 'x'){	//if the winner is 'x'
			for(i=0; i<size; i++){
				for(j=0; j<size; j++){
					if(board_won[i][j] == 1)
						hexCells[i][j].setData('X');	
		}}}
		else if(letter_won == 'o'){		//if the winner is 'o'
			for(i=0; i<size; i++){
				for(j=0; j<size; j++){
					if(board_won[i][j] == 1)
						hexCells[i][j].setData('O');
		}}}
}


/*	This function resets datas in the vectors and resizes the board	*/
	void HexVector::reset(){
		hexCells.clear();
		board_won.clear();
		allMoves.clear();

		hexCells.resize(getSize(), vector<Cell>(getSize()));
			for(int i=0; i<getSize(); i++){ 
				for(int j = 0; j < getSize(); j++)
					hexCells[i][j].setData('.');
			}	
	}


	void HexVector:: writeToFile(string fileName){
		ofstream saveFile;	//open a file
		saveFile.open(fileName.c_str());
 		for (int x = 0; x < getSize(); x++){
  			for (int y = 0; y < getSize(); y++)
				saveFile << hexCells[x][y].getData();	//saves board
	 	}
	 	saveFile<< " " << getSize() << " " << getPlayer();	//saves size and player information
	}

	void HexVector:: readFromFile(string fileName){
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
		if(sevraHexGame::board_validity(board_data,size)){

			if(player==1)
				HexVector(size,player,board_data);			
			else if(player==2){	//to find who's turn
				for(int i=0;i<size*size; i++){
					if(board_data[i] == 'x')
						x++;
					else if(board_data[i]=='o')
						y++;
				}
				if(x<=y)	user_turn=0;
				else	user_turn=1;
				HexVector(size, player, board_data, user_turn);			
			}
		}
		else{
			cerr<<"File contains invalid characters !!"<<endl;
		}

	}



	int* HexVector::lastMove(){
		int flag, last=0;
		static int temp[2];
		try{
			for(int i=0; i<getSize(); i++){
				for(int j=0; j<getSize(); j++){
					if(allMoves[i][j] == 0)
						flag=0;
					else{
						flag=1;
						break;
				}}
			if(flag==1)
				break;
			}	
			if(flag==0)
				throw "No moves were made, there is no 'last move' !";
			else{
				for(int i=0; i<getSize(); i++){
					for(int j=0; j<getSize(); j++){
						if(allMoves[i][j]>last){
							last = allMoves[i][j];
							temp[0]=i;
							temp[1]=j;
			}}}}
		}

		catch(const char* error){
			cerr<<error<<endl;
		}		
		return temp;
	}

/*	Takes two indexes and return corresponding cell content	*/
	char HexVector::operator() (int i1, int i2) {
		try{
			if(i1<getSize() && i2<getSize() && i1>=0 && i2>=0)
				return hexCells[i2][i1].getData();
			throw "There is no cell with index you entered !!";
		}
		catch (const char* error){
			cerr<<error<<endl;
		}
		return 'e';
	}


/*	Compares two boards are equal or not	*/
	bool HexVector:: operator==(AbstractHex& other){
		const HexVector* cast_other = static_cast<const HexVector*> (&other);
		if(this->getSize() != cast_other->getSize())
			return false;
		else{
			for(int i=0; i<getSize(); i++){
				for(int j=0; j<getSize(); j++){
					if(this->hexCells[i][j].getData() != cast_other->hexCells[i][j].getData())
						return false;
		}}}
		return true;
	}
