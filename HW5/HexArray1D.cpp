#include "HexArray1D.h"
using namespace sevraHexGame;


	HexArray1D :: HexArray1D (int boardSize, int user){
		cout<<"HexArray1D CLASS CONST2"<<endl;
			if(boardSize<=5){		//checks validity of entered board size
				cerr << "!! Please enter a valid board size !!" << endl << endl;
				cout << "Please enter the board size between (like 6x6, 7x7)" << endl;
				cin>>boardSize;
				HexArray1D(boardSize,user);	//enter new board size
			}else
				setSize(boardSize); 

			if(user!=1 && user!=2){
				cerr << "!! Please enter a valid number of players !!" << endl << endl; 
				cout << "Press 1 for single player game, 2 for two player game..."<< endl;
				cin>>user;
				HexArray1D(boardSize,user);	
			}else
				setPlayer(user);
		
			allMoves = (int *)malloc(size * sizeof(int)); // allocate array of int pointers
			setBoard();
	}


		HexArray1D::HexArray1D(int board_size, int user, string board_data){
			setSize(board_size);
			setPlayer(user);
			setBoard(board_data);
		}


		HexArray1D::HexArray1D(int board_size, int user, string board_data, int user_turn){
			turn = user_turn;
			setSize(board_size);
			setPlayer(user);
			setBoard(board_data);
		}

		/*	Copy constructor	*/
		HexArray1D::HexArray1D(const HexArray1D& copy){
			cout<<endl<<"Copy Constructor"<<endl;
			turn=copy.turn;	//determines who is in turn in the game
			size=copy.size;
			edge=copy.edge;
			player=copy.player;

			allMoves = (int *)malloc(size * sizeof(int)); // allocate array of int pointers	
			for(int i=0; i<size; i++)
					allMoves[i]=copy.allMoves[i];	
			
			hexCells = (Cell *)malloc(size * sizeof(Cell)); // allocate array of int pointers	
			for(int i=0; i<size; i++)
					hexCells[i].setData(copy.hexCells[i].getData());

			board_won.resize(edge, vector<int>(edge));
			for(int i=0; i<edge; i++){
				for(int j=0; j<edge; j++)
					board_won[i][j]=copy.board_won[i][j];
			}

		}

		/*	Destructor	*/
		HexArray1D::~HexArray1D(){
			cout<<"DESTRUCTOR"<<endl;
			free(allMoves);
			free(hexCells);	
		}

		/*	Copy Assignment Operator	*/
		HexArray1D& HexArray1D:: operator=(const HexArray1D& assign){
			cout<<"Copy Assignment Operator"<<endl;
			if (this != &assign){
				turn=assign.turn;	//determines who is in turn in the game
				size=assign.size;
				player=assign.player;
				
			allMoves = (int *)malloc(size * sizeof(int)); // allocate array of int pointers	
			for(int i=0; i<size; i++)
					allMoves[i]=assign.allMoves[i];	
				
			board_won.resize(edge, vector<int>(edge));
			for(int i=0; i<edge; i++){
				for(int j=0; j<edge; j++)
					board_won[i][j]=assign.board_won[i][j];
			}
			
			hexCells = (Cell *)malloc(size * sizeof(Cell)); // allocate array of int pointers	
			for(int i=0; i<size; i++)
					hexCells[i].setData(assign.hexCells[i].getData());
		
			}
			return *this;

		}




		void HexArray1D:: setSize(int boardSize){
			size= boardSize*boardSize;
			reset();
			allMoves = (int *)malloc(size * sizeof(int)); // allocate array of int pointers
		}

		void HexArray1D::reset(){
			free(allMoves);
			free(hexCells);
			hexCells = (Cell *)malloc(size * sizeof(Cell)); // allocate array of int pointers
			for(int i=0; i<getSize(); i++)
				hexCells[i].setData('.');
		}


	void HexArray1D::setBoard(){
		hexCells = (Cell *)malloc(size * sizeof(Cell)); // allocate array of int pointers
		for(int i=0; i<getSize(); i++)
				hexCells[i].setData('.');
		print();
	}


	void HexArray1D:: setBoard(string board_data){
		hexCells = (Cell *)malloc(size * sizeof(Cell)); // allocate array of int pointers
		int k=0;
		char temp;
		cout<<board_data<<endl;
		for(int i=0; i<getSize(); i++)
				hexCells[i].setData(board_data[i]);
		cout << "\nTHE FILE HAS BEEN LOADED SUCCESSFULLY!\nYou can continue playing the game where you left off." << endl<<endl;
		print();
	}


	void HexArray1D::print(){
		cout<<endl<<"Number of Moves -> "<<numberOfMoves()<<endl;
		edge = sqrt(size);
		int *ptr= lastMove();
		cout<<"lastMove() function test->  "<< *(ptr+1)<<*ptr+1 <<" --- equivalence in board format-> ";
		switch(*(ptr+1)){		// to print which move computer did
			case 0: cout<<'a';break;		case 1: cout<<'b';break; 	case 2: cout<<'c';break; 		case 3: cout<<'d';break; 
			case 4: cout<<'e';break; 		case 5: cout<<'f';break; 	case 6: cout<<'g';break; 		case 7: cout<<'h';break; 
			case 8: cout<<'i';break; 		case 9: cout<<'j';break; 	case 10: cout<<'k';break; 		case 11: cout<<'l';break;
		}cout<<*ptr+1<<endl;

		char ch = 'a'; 
		cout << endl << "  "; 
		for(int i=0; i<edge; i++){	//to print upper frame of the board (a b c d e....)
			cout << ch << " ";
			ch++;
		}cout<<endl;
		cout<<"1  ";
		for(int i=0; i<getSize(); i++){		//prints the board
			cout << hexCells[i].getData() << " "; 
			if( (i+1)%edge == 0 ){
				cout<< endl;
				if ((((i+1)/edge)+1)<=edge){
				cout<<((i+1)/edge)+1<<" ";
				for(int k=0; k<(i+1)/edge; k++)
					cout << " ";
		}}}
		enterCommand();		
	}



	void HexArray1D:: print(string finish){
		edge = sqrt(size); //edge is one side of the board
		char ch = 'a'; 
		cout << endl << "  "; 
		for(int i=0; i<edge; i++){	//to print upper frame of the board (a b c d e....)
			cout << ch << " ";
			ch++;
		}cout<<endl;
		cout<<"1 ";
		for(int i=0; i<getSize(); i++){		//prints the board
			cout << hexCells[i].getData() << " "; 
			if( (i+1)%edge == 0 ){
				cout<< endl;
				if ((((i+1)/edge)+1)<=edge){
					cout<<((i+1)/edge)+1<<" ";
					for(int k=0; k<(i+1)/edge; k++)
						cout << " ";
		}}}
	}


	void HexArray1D:: enterCommand(){
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



	void HexArray1D:: analyze_command(string command){
		auto save = "SAVE", load = "LOAD", compare="COMPARE", exit = "EXIT";
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
		else{	//invalid input
			cerr << "Coordinates are invalid!" << endl;
inv:
			enterCommand();
		}
	}


/*	It's an utility function to check the coordinates valid or not. Include uppercase and lowercase conditions. Returns 0 if invalid, returns 1 or 2 if valid */
	void HexArray1D:: coordinates_valid_or_not(){
		cout<<"corval"<<endl;
		edge = sqrt(size);
		int flag; // to return an integer if it is valid or not and lowercase or uppercase
		int uppercase='A', lowercase = 'a';		//to use ASCII values of these letters
		if( coord1 >= lowercase && coord1 <= lowercase+edge && coord2>0 && coord2<=edge) 
			flag=0;	//lowercase, valid
		else if( coord1 >= uppercase && coord1 <= uppercase+edge && coord2>0 && coord2<=edge)
			flag=1;	//uppercase, valid
		else{
			flag=2;
			cerr << "Coordinates you entered is invalid, please enter new coordinates..."<< endl;
     	 	enterCommand();	//invalid
		}
		make_move(flag);
	} 



	void HexArray1D:: make_move(int flag){
		int x_move=0, o_move=0;
		if(flag == 0)// 1 means it is lowercase
			coord1 = coord1-'a';	//converts to int
		else	//uppercase
			coord1 = coord1-'A';	// converts to int
		edge = sqrt(size);
		int coord_1D = edge*(coord2-1)+coord1;
		if(hexCells[coord_1D].getData() == '.'){ 	//if the coordinate is empty
			switch(player){
			case 1:	hexCells[coord_1D].setData('x'); //user1's move				
					x_move=1;
					cout<<"kelebek"<<endl; 		
					setNumberOfMoves();
					allMoves[coord_1D] = numberOfMoves();
					break;
			
			case 2: if(turn%2 !=1){
						hexCells[coord_1D].setData('x') ; //user1's move	
						setNumberOfMoves();
						allMoves[coord_1D] = numberOfMoves();
						x_move=1;		
					}else{
						hexCells[coord_1D].setData('o')  ; //user2's move
						setNumberOfMoves();
						allMoves[coord_1D] = numberOfMoves();
						o_move=1;
					}break;
			}
/*
			cout<<endl<<"a board showing the moves made in sequence..."<<endl;
			for(int i=0; i<getSize(); i++){		//prints the board
				cout << allMoves[i] << " "; 
				if( (i+1)%edge == 0 ){
					cout<< endl;
					for(int k=0; k<(i+1)/edge; k++)
						cout << " ";
			}}
*/
			if(x_move==1){				
				if(isEnd(1)){
					game_end('x');
				}else{
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
	void HexArray1D:: choose_different_rand(int &last_x, int &last_y){
		edge = sqrt(size);
		int rand_numb, i, rand_move[2];	
		random_device rd;  
    	mt19937 gen(rd()); 
    	uniform_int_distribution<> distrib(0, edge-1);
randomly_move:		
			for(i=0; i<2; i++)
				rand_move[i] = distrib(gen);	
			
			int coord_1D = edge*rand_move[0]+rand_move[1];

			if(hexCells[coord_1D].getData() =='.'){ //if the coordinate is empty
				hexCells[coord_1D].setData('o') ; //fill the cell with 'o'
				last_x = rand_move[0];	// to keep last coordinates to use in next coordinate choosing
				last_y = rand_move[1];	
			}
			else
				goto randomly_move;
	}



/* This function makes computer's move on the board*/
	int HexArray1D :: computerMove ( int first ){ 
		edge = sqrt(size);
		int coord_1D ;
		vector<vector<char> > tempBoard;	//to find winner path
		tempBoard.resize(edge, vector<char>(edge));
		int k=0;
    	for(int i=0; i<edge; i++){
    		for(int j=0; j<edge; j++)
    			tempBoard[i][j] = hexCells[k++].getData();
    	}
		int last_x, last_y, rand_numb, i, first_move[2], moved;
		if(first == 1){		
			random_device rd;  //Will be used to obtain a seed for the random number engine
    		mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    		uniform_int_distribution<> distrib(0, edge-1);
first_again:		
			for(i=0; i<2; i++)
				first_move[i] = distrib(gen);

			if(tempBoard[first_move[0]][first_move[1]] =='.'){
				last_x = first_move[0];
				last_y = first_move[1];	
				coord_1D = edge*first_move[0]+first_move[1];
				hexCells[coord_1D].setData('o');	
			}
			else
				goto first_again;
			moved=1;
		}else{

rand_again:
			rand_numb = generate_random();
			//  1. MOVE
			if(rand_numb == 1 || rand_numb == 11 ){		// there is 2 random number to increase the chances of making moves up and down								
				if(tempBoard[last_x+1][last_y-1]== '.' && (last_x+1)<=edge-1 && (last_y-1)<=edge-1 && 0<=(last_x+1) && 0<=(last_y-1) ){					
					last_x = last_x+1;							
 					last_y = last_y-1;
					coord_1D = edge*last_x+last_y;
					hexCells[coord_1D].setData('o');
					moved=1;
				}else{
					moved=0;
					goto rand_again;
				}
			}
			// 2. MOVE
			else if(rand_numb == 2 || rand_numb == 12  ){	// there is 2 random number to increase the chances of making moves up and down						 
				if(tempBoard[last_x+1][last_y]  == '.' && last_x+1<=edge-1 && last_y<=edge-1 && 0<=(last_x+1) && 0<=(last_y)){					
					last_x = last_x+1;		
					coord_1D = edge*last_x+last_y;
					hexCells[coord_1D].setData('o');
					moved=1;									//      o(new)
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 3  ){							// 3. MOVE
				if(tempBoard[last_x][last_y-1] == '.' && last_x<=edge-1 && last_y-1<=edge-1 && 0<=(last_x) && 0<=(last_y-1)){				
 					last_y = last_y-1; 	
					coord_1D = edge*last_x+last_y;
					hexCells[coord_1D].setData('o');
					moved=1;
				}
				else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 4){							// 4. MOVE
				if(tempBoard[last_x][last_y+1] == '.' && last_x<=edge-1 && last_y+1<=edge-1 && 0<=(last_x) && 0<=(last_y+1) ){					
 					last_y = last_y+1; 
					coord_1D = edge*last_x+last_y;
					hexCells[coord_1D].setData('o');
					moved=1;
				}else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 5){							// 5. MOVE
				if(tempBoard[last_x+1][last_y-2] == '.' && last_x+1<=edge-1 && last_y-2<=edge-1 && 0<=(last_x+1) && 0<=(last_y-2) ){					
 					last_x = last_x+1;							
 					last_y = last_y-2; 							
					coord_1D = edge*last_x+last_y;
					hexCells[coord_1D].setData('o');
					moved=1;									
				}else{
					moved=0;
					goto rand_again;
				}
			}

			else if(rand_numb == 6){							// 6.MOVE
				if(tempBoard[last_x+1][last_y+1] == '.' && last_x+1<=edge-1 && last_y+1<=edge-1 && 0<=(last_x+1) && 0<=(last_y+1) ){					// 	. o .
 					last_x = last_x+1;							
 					last_y = last_y+1; 
					coord_1D = edge*last_x+last_y;
					hexCells[coord_1D].setData('o');
					moved=1;
				}else{
					moved=0;
					goto rand_again;
				}
			}
			// 7.MOVE
			else if(rand_numb == 7 || rand_numb == 13){			// there is 2 random number to increase the chances of making moves up and down			
				if(tempBoard[last_x-1][last_y] == '.' && last_x-1<=edge-1 && last_y<=edge-1 && 0<=(last_x-1) && 0<=(last_y) ){					
 					last_x = last_x-1;							
					coord_1D = edge*last_x+last_y;
					hexCells[coord_1D].setData('o');
					moved=1; 									
				}else{
					moved=0;
					goto rand_again;
				}
			}

			// 8.MOVE
			else if(rand_numb == 8 || rand_numb == 14){			// there is 2 random number to increase the chances of making moves up and down	
				if(tempBoard[last_x-1][last_y+1] == '.' && last_x-1<=edge-1 && last_y+1<=edge-1 && 0<=(last_x-1) && 0<=(last_y+1) ){					
 					last_x = last_x-1;						
					last_y = last_y+1;							
					coord_1D = edge*last_x+last_y;
					hexCells[coord_1D].setData('o');
					moved=1; 									
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 9){							// 9.MOVE
				if(tempBoard[last_x-1][last_y-1] == '.' && last_x-1<=edge-1 && last_y-1<=edge-1 && 0<=(last_x-1) && 0<=(last_y-1) ){					
 					last_x = last_x-1;							
					last_y = last_y-1;							
					coord_1D = edge*last_x+last_y;
					hexCells[coord_1D].setData('o');
					moved=1; 									
				}else{
					moved=0;
					goto rand_again;
				}
			}
			else if(rand_numb == 10){							// 10.MOVE
				if(tempBoard[last_x-1][last_y+2] == '.' && last_x-1<=edge-1 && last_y+2<=edge-1 && 0<=(last_x-1) && 0<=(last_y+2) ){					
 					last_x = last_x-1;								
					last_y = last_y+2;								
					coord_1D = edge*last_x+last_y;
					hexCells[coord_1D].setData('o');
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
			allMoves[coord_1D] = numberOfMoves();
			switch(last_y){		// to print which move computer did
				case 0: y='a';break;		case 1: y='b';break; 	case 2: y='c';break; 		case 3: y='d';break; 
				case 4: y='e';break; 		case 5: y='f';break; 	case 6: y='g';break; 		case 7: y='h';break; 
				case 8: y='i';break; 		case 9: y='j';break; 	case 10: y='k';break; 		case 11: y='l';break;
			}
			cout << endl << "Computer's Move -> " << y << last_x+1<< endl;
			turn++;				
			print();
			return 0;
		}else{	//coordinate has already been moved
			cerr << "The coordinate you choose is filled!! Please enter new coordinates..."<< endl;
			return 1;	//tells to main function that the move was not made.
		}	
	}	


	bool HexArray1D:: isEnd(int player){
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


	void HexArray1D::game_end(int won){
		if(won=='x'){
			print("finish");
			cout << "\n!!! GAME OVER!!! \nX WON THIS GAME"<< endl;
		}else{
			print("finish");
			cout << "\n!!! GAME OVER!!! \nO WON THIS GAME"<< endl;	
		}
	}


/*This function checks all cells are filled or not*/
	int HexArray1D:: filled(){
		int ret;
		for(int i=0; i<size-1; i++){
			if(hexCells[i].getData() == '.'){	//if the cell is '.' it means its empty, so board is not filled
				ret = 0;	//return 0 - board is not filled
				break;
			}
			else
				ret=1;	// there is no cells with '.' all cells are filled, return 1
		} 	
		return ret;
	}




	/* This is an utility function to check the game is end or not for USER1 */
	int HexArray1D:: check_finish_x(){
		edge = sqrt(size);
		board_won.resize(edge, vector<int>(edge));
		vector<vector<char> > tempBoard;	//to find winner path
		tempBoard.resize(edge, vector<char>(edge));
		int k=0;
    	for(int i=0; i<edge; i++){
    		for(int j=0; j<edge; j++)
    			tempBoard[i][j] = hexCells[k++].getData();
    	}
		int counter=1, x=0, y=0,i, j;
		int x_before=0, y_before=0;		// to keep previous values of the x and y
		int up=0, down=0;		// to prevent infinite loop, (up-down up-down)
		for(i=0; i<edge; i++){
			for(j=0; j<edge; j++)
				board_won[i][j] = 0;	//to fill the board with 0's
		}
		for(i=0; i<edge; i++){
			x=i;
			if(tempBoard[x][y] == 'x'){	//checks the coordinate's value is 'x' or not
				board_won[x][y] = 1;	//fill the cell with 1
check:			
			if(y != size-1 ){	
				if(x-1>=0 && down==0 && tempBoard[x-1][y] == 'x'){	//A move -> northwest					
					x_before = x, y_before = y;
					x = x-1;							
					up=1;
					board_won[x][y] = 1;		//fill the cell with 1
					goto check;
				}
				if(y+1<=size-1 &&x-1>=0 && tempBoard[x-1][y+1] == 'x'){
					counter++;
					x_before = x, y_before = y;
					x=x-1,
					y=y+1;
					board_won[x][y] = 1;
					goto check;
				}
				if(tempBoard[x][y+1] == 'x'){		//C move -> east
					counter++;
					x_before = x, y_before = y;
					y=y+1;
					board_won[x][y] = 1;
					goto check;
				}
				if( x+1<=size-1  && tempBoard[x+1][y] == 'x' && up ==0){		//D move -> southeast
					x_before = x, y_before = y;
					x=x+1;
					down=1;
					board_won[x][y] = 1;
					goto check;
				}
			}

			if(y==edge-1)
				break;

			counter--;	//to not count moves which is not finish
			x = x_before;		//to go back the coordinates before did the last move
			y= y_before;
			board_won[x][y] = 0;	//to undo the move	
			}
			x++;
		}
		if(y == edge-1){
			char letter_won = 	'x';// if x is winner			
			make_uppercase( letter_won);	//to make uppercase the winning path
			return 1;
		}else
			return 0; 
	}		


	int HexArray1D:: check_finish_o(){
		edge = sqrt(size);
		board_won.resize(edge, vector<int>(edge));
		vector<vector<char> > tempBoard;	//to find winner path
		tempBoard.resize(edge, vector<char>(edge));
		int k=0;
    	for(int i=0; i<edge; i++){
    		for(int j=0; j<edge; j++)
    			tempBoard[i][j] = hexCells[k++].getData();
    	}
		int counter=1, x=0, y=0,i,j;
		int x_before=0, y_before=0, ctr=0;		// to keep previous values of the x and y
		int up=0, down=0;
		for(i=0; i<edge; i++){
			for(j=0; j<edge; j++)
				board_won[i][j] = 0;	//to fill the board with 0's
		}
		for(i=0; i<edge; i++){
			y=i;
			if(tempBoard[x][y] == 'o'){	//checks the coordinate's value is 'o' or not
				board_won[x][y] = 1;		//fill the cell with 1
check:					
				if(x !=edge-1){
					if( y-1>=0 && tempBoard[x][y-1] == 'o' && down==0){	//A move -> northwest
						x_before = x, y_before = y;
						y = y-1;	up=1;
						board_won[x][y] = 1;		//fill the cell with 1
						goto check;
					}
					if(y-1>=0 && x+1<=edge-1 && tempBoard[x+1][y-1] == 'o'){	//B moved -> northeast					
						counter++;
						x_before = x, y_before = y;
						x=x+1;	y=y-1;
						board_won[x][y] = 1;
						goto check;
					}
					if(x+1<=size-1 && tempBoard[x+1][y] == 'o'){		//C move -> east
						counter++;
						x_before = x, y_before = y;
						x=x+1;
						board_won[x][y] = 1;
						goto check;
					}
					if(y+1<=size-1 && tempBoard[x][y+1] == 'o' ){		//D move -> southeast
						x_before = x, y_before = y;
						y=y+1;	down=1;
						board_won[x][y] = 1;
						goto check;
					}
				}
				if(x==edge-1)
					break;
				
				counter--;	//to not count moves which is not finish
				x = x_before;		//to go back the coordinates before did the last move
				y= y_before;
				board_won[x][y] = 0;
		}y++;}
		if(x == edge-1){	// if o is winner
			char letter_won = '0';// if x is winner
			make_uppercase(letter_won);		//to make uppercase the winning path
			return 1;
		}else{
				return 0;	
		}
	}		


	void HexArray1D :: make_uppercase( char letter_won){
		edge = sqrt(size);
		int coord_1D ;
		int i, j;
		/*
		if(letter_won == 'x'){	//if the winner is 'x'
			for(i=0; i<edge; i++){
				for(j=0; j<edge; j++){
					if(board_won[i][j] == 1){
						coord_1D = edge*(j-1)+i-1;
						hexCells[coord_1D].setData('X');	
					}
		}}}
		else if(letter_won == 'o'){		//if the winner is 'o'
			for(i=0; i<edge; i++){
				for(j=0; j<edge; j++){
					if(board_won[i][j] == 1){
						coord_1D = edge*(j-1)+i-1;
						hexCells[coord_1D].setData('O');
					}
		}}}*/

}


	void HexArray1D:: writeToFile(string fileName){
		ofstream saveFile;	//open a file
		saveFile.open(fileName.c_str());
		for (int x = 0; x < getSize(); x++)
   			saveFile << hexCells[x].getData();	//saves board
  	 	saveFile<< " " << sqrt(size) << " " << getPlayer();	//saves size and player information
	}

	void HexArray1D:: readFromFile(string fileName){
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
			HexArray1D(size,player,board_data);			
			else if(player==2){	//to find who's turn
			for(int i=0;i<size; i++){
				if(board_data[i] == 'x')
					x++;
				else if(board_data[i]=='o')
					y++;
			}
			if(x<=y)	user_turn=0;
			else	user_turn=1;
			HexArray1D(size, player, board_data, user_turn);			
		}
	}


		int* HexArray1D::lastMove(){
			edge = sqrt(size);
			int flag, last=0, k=0;
			static int ret[2];
			int temp[size][size];
	    	for(int i=0; i<edge; i++){
	    		for(int j=0; j<edge; j++)
	    			temp[i][j] = allMoves[k++];
	    	}

		try{
			for(int i=0; i<edge; i++){
				for(int j=0; j<edge; j++){
					if(temp[i][j] == 0)
						flag=0;
					else{
						flag=1;
						break;
					}
				}
				if(flag==1)
					break;
			}	
			
			if(flag==0)
				throw "No moves were made, there is no 'last move' !";
			else{
				for(int i=0; i<edge; i++){
					for(int j=0; j<edge; j++){
						if(temp[i][j]>last){
							last = temp[i][j];
							ret[0]=i;
							ret[1]=j;
		}}}}}

		catch(const char* error){
			cerr<<error<<endl;
		}		
		return ret;
	}



	char HexArray1D::operator() (int i1, int i2){
		try{
			edge = sqrt(size);
			int coord_1D = edge*(i2)+i1;
			if(i1<edge && i2<edge && i1>=0 && i2>=0)
				return hexCells[coord_1D].getData();
			throw "There is no cell with index you entered !!";
		}

		catch (const char* error){
			cerr<<error<<endl;
		}
		return 'e';
	}



	bool HexArray1D:: operator==( AbstractHex& other){
		edge = sqrt(size);
		const HexArray1D* cast_other = dynamic_cast<const HexArray1D*> (&other);

		if(this->getSize() != cast_other->getSize())
			return false;
		else{
			for(int i=0; i<edge; i++){
					if(this->hexCells[i].getData() != cast_other->hexCells[i].getData())
						return false;
		}}
		return true;
	}