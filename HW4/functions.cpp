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
			}else
				set_size(board_size); 

			if(user!=1 && user!=2){
				cerr << "!! Please enter a valid number of players !!" << endl << endl; 
				cout << "Press 1 for single player game, 2 for two player game..."<< endl;
				cin>>player;
				Hex(board_size,user);	
			}else
				set_player(user);
			move_counter=0;
			object++;

			board_won = new int*[size]; // allocate array of int pointers
			for( int i = 0; i < size; i++)
			    board_won[i] = new int[size]; // allocate each array of ints

			allMoves = new int*[size]; // allocate array of int pointers
			for( int i = 0; i < size; i++)
		    	allMoves[i] = new int[size]; // allocate each array of ints
			set_board();
		}

		Hex::Hex(int board_size, int user, string board_data){
			set_size(board_size);
			set_player(user);
			
			allMoves = new int*[size]; // allocate array of int pointers
			for( int i = 0; i < size; i++)
			  	allMoves[i] = new int[size]; // allocate each array of ints
			set_all_moves();

			set_board(board_data);

		}

		Hex::Hex(int board_size, int user, string board_data, int user_turn) : turn(user_turn){
			set_size(board_size);
			allMoves = new int*[size]; // allocate array of int pointers
			for( int i = 0; i < size; i++)
			 	allMoves[i] = new int[size]; // allocate each array of ints
			
			set_all_moves();
			set_player(user);
			set_board(board_data);
		}

		Hex::Hex(const Hex& temp){
		cout<<endl<<"Copy Constructor"<<endl;
		marked=temp.marked;
		turn=temp.turn;	//determines who is in turn in the game
		size=temp.size;
		player=temp.player;
		board_data = temp.board_data;
		move_counter = temp.move_counter;
		
		allMoves = new int*[size]; // allocate array of int pointers
		for( int i = 0; i < size; i++)
			allMoves[i] = new int[size]; // allocate each array of ints		
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++)
				allMoves[i][j]=temp.allMoves[i][j];
			
		}

		board_won = new int*[size]; // allocate array of int pointers
		for( int i = 0; i < size; i++)
			board_won[i] = new int[size]; // allocate each array of ints	
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++)
				board_won[i][j]=temp.board_won[i][j];
		}

		hexCells = new Cell*[size]; // allocate array of int pointers
		for( int i = 0; i < size; i++)
			hexCells[i] = new Cell[size]; // allocate each array of ints	
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++)
				hexCells[i][j].data=temp.hexCells[i][j].data;
		}

		cout<<endl<<"a board showing the moves made in sequence...(in copy constructor)"<<endl;
		for(int i=0; i<size; i++){
			for(int k=0; k<i+1; k++)
			cout << " ";
			for(int j=0; j<size; j++)
				cout << allMoves[i][j]<< " "; 
			cout<< endl;
		}}





		Hex& Hex::operator=(const Hex& temp){
					cout<<"copy assignment operator"<<endl;
			if (this != &temp){
				marked=temp.marked;
				turn=temp.turn;	//determines who is in turn in the game
				size=temp.size;
				player=temp.player;
				board_data = temp.board_data;
				move_counter = temp.move_counter;
				
				allMoves = new int*[size]; // allocate array of int pointers
				for( int i = 0; i < size; i++)				
					allMoves[i] = new int[size]; // allocate each array of ints
				for(int i=0; i<size; i++){
					for(int j=0; j<size; j++)
						allMoves[i][j]=temp.allMoves[i][j];
				}
				
				board_won = new int*[size]; // allocate array of int pointers
				for( int i = 0; i < size; i++)
					board_won[i] = new int[size]; // allocate each array of ints	
				for(int i=0; i<size; i++){
					for(int j=0; j<size; j++)
						board_won[i][j]=temp.board_won[i][j];
				}
				
				hexCells = new Cell*[size]; // allocate array of int pointers
				for( int i = 0; i < size; i++)
					hexCells[i] = new Cell[size]; // allocate each array of ints
				for(int i=0; i<size; i++){
					for(int j=0; j<size; j++)
						hexCells[i][j].data=temp.hexCells[i][j].data;
				}
		}
			return *this;
		}


		Hex::~Hex(){
			cout<<"destructor"<<endl;
			for(int i = 0; i < size; ++i) 
		        delete[] board_won[i];   
		    delete[] board_won;

			for(int i = 0; i < size; ++i)
		        delete[] allMoves[i];    
		    delete[] allMoves;

			for(int i = 0; i < size; ++i) 
		        delete[] hexCells[i];   
		    delete[] hexCells;
		    
		}


	inline void Hex:: set_move_counter(int m_counter){ move_counter=m_counter; }
	inline void Hex :: set_size(int board_size)	{ size=board_size; }
	inline int Hex ::  get_size() { return size; }
	inline void Hex :: set_player(int user)  { player=user; }
	inline int Hex:: get_player() { return player;}

	void Hex :: set_all_moves(){
		cout<<"set_all_moves "<<endl;
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				allMoves[i][j];
		}}
	}

	
	void Hex:: set_board(){
		hexCells = new Cell*[size]; // allocate array of int pointers
		for( int i = 0; i < size; i++)
			hexCells[i] = new Cell[size]; // allocate each array of ints
			
		for(int i=0; i<size; i++){ 
			for(int j = 0; j < size; j++)
				hexCells[i][j].data = '.';
		}	
		cout<<*this;
	}

	void Hex:: set_board(string board_data){
		hexCells = new Cell*[size]; // allocate array of int pointers
		for( int i = 0; i < size; i++)
			hexCells[i] = new Cell[size]; // allocate each array of ints
			
		int k=0;
		for(int i=0; i<size; i++){ 
			for(int j = 0; j < size; j++){
				hexCells[i][j].data = board_data[k];
				k++;
		}}
		cout<<*this;

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


	void Hex :: play(){
		int c_first=1;
		computer_move(c_first);	
	}

	void Hex :: play(string command){ 		
		analyze_command(command);
	}



	void Hex:: playGame(){
		string command;
		int ret_data=0;
		if(player == 1){
			if(turn%2==0 ){
				cout << "It's your turn. Enter a coordinate to move..." << endl;
				getline(cin>>ws,command);
				play(command); //move yapıp döndü
			//	cout<<"game"<<endl;
				check_finish_x();
			}else{
				int c_first=1;
				play();
				check_finish_o();
			}		
		}else{
			if(turn%2 ==0){	
				cout << "It's user1's turn. Enter a coordinate to move..." << endl;
				getline(cin>>ws, command);
				play(command); 
				ret_data = check_finish_x();
			}else{
				cout << "It's user2's turn. Enter a coordinate to move..." << endl;
				getline(cin>>ws, command);
				play(command); 
				check_finish_o();
			}}

	}


	void Hex:: analyze_command(string command){
		auto save = "SAVE", load = "LOAD", compare="COMPARE", undo="UNDO";
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
    		insertion=1;
			ofstream saveFile;	//open a file
			saveFile.open(secondWord.c_str());
    		saveFile<<*this;
			cout<< "\nTHE GAME HAS BEEN SAVED SUCCESSFULLY!\nYou can access this game whenever you want with the LOAD command." << endl;	
		}
		else if(load == firstWord ){	//if first word is load, do load file operations
    		fileName=secondWord;
			ifstream File(fileName);
    		File>>*this;
			cout << "\nTHE FILE HAS BEEN LOADED SUCCESSFULLY!\nYou can continue playing the game where you left off." << endl<<endl;
		}
		else if(command.size() == 4){
			cout<<"unmov  "<<move_counter<<endl;
			if(move_counter == 0){
				cout<<"you are already in the initial state, you cannot perform any more 'undo' command."<<endl;
				goto inv;

			}else{
				if(undo == secondWord){
					if(player == 1){
						--*this;	
						cout<<*this;
					}
					else{
						 (*this)--;
						cout<<*this;
		}}}}
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
			(*this).cmp=1;	
			char t1 = secondWord[0];
			otherObj = (int)t1-48;
		}else{	//invalid input
			cerr << "Coordinates are invalid!" << endl;
inv:
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
					x_move=1;
						allMoves[coord2-1][coord1] = ++move_counter;

					break;
			
			case 2: if(turn%2 !=1){
						hexCells[coord2-1][coord1].data = cell_states::firstPlayer; //user1's move	
						allMoves[coord2-1][coord1] = ++move_counter;
						x_move=1;		
					}else{
					hexCells[coord2-1][coord1].data = cell_states::secondPlayer; //user2's move
						allMoves[coord2-1][coord1] = ++move_counter;
						o_move=1;
					}break;
			}

			cout<<endl<<"a board showing the moves made in sequence..."<<endl;
			for(int i=0; i<size; i++){
				for(int k=0; k<i+1; k++)
				cout << " ";
				for(int j=0; j<size; j++){
					cout << allMoves[i][j]<< " "; 
				}cout<< endl;
			}

			find_score();
			if(x_move==1){
				if(check_finish_x() ==1){
					game_end('x');
				}else{
					turn++;
					markedCells();
					cout<<*this;
			}}
			else if(o_move==1){
				if( check_finish_o()==1){	
					game_end('o');

				}else if(filled() ==1){ //doldu
					print_board("filled");
					cerr << "\n!!! GAME OVER!!! \nAll cells are filled, nobody won..."<< endl;
				}else{
					turn++;
					cout<<*this;
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
		//	exit(1);
		}else{
			print_board("finish");
			cout << "\n!!! GAME OVER!!! \nO WON THIS GAME"<< endl;	
		//	exit(1);
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
		int counter=1, x=0, y=0,i, j;
		int x_before=0, y_before=0;		// to keep previous values of the x and y
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
		//board_won.resize(size, vector<int>(size));
	board_won = new int*[size]; // allocate array of int pointers
			for( int i = 0; i < size; i++)
			{
			    board_won[i] = new int[size]; // allocate each array of ints
			}

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
		}else{
				return 0;	
		}
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
			allMoves[last_x][last_y] = ++move_counter;
			switch(last_y){		// to print which move computer did
				case 0: y='a';break;		case 1: y='b';break; 	case 2: y='c';break; 		case 3: y='d';break; 
				case 4: y='e';break; 		case 5: y='f';break; 	case 6: y='g';break; 		case 7: y='h';break; 
				case 8: y='i';break; 		case 9: y='j';break; 	case 10: y='k';break; 		case 11: y='l';break;
			}
			cout << endl << "Computer's Move -> " << y << last_x+1<< endl;
			turn++;		
			cout<<endl<<"a board showing the moves made in sequence..."<<endl;
			for(int i=0; i<size; i++){
				for(int k=0; k<i+1; k++)
				cout << " ";
				for(int j=0; j<size; j++){
					cout << allMoves[i][j]<< " "; 
				}cout<< endl;
			}
							
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


//SAVE FILE
	ofstream& operator<<(ofstream& file, Hex& H){
			for (int x = 0; x < H.size; x++){
  	  			for (int y = 0; y < H.get_size(); y++)
  					file << H.hexCells[x][y].data;	//saves board
  		 	}
	 		 	file<< " " << H.get_size() << " " << H.player;	//saves size and player information
  		 	return file;
		}


//PRINT BOARD
	ostream& operator<<(ostream& outS, Hex& H){
			H.print_board();
  		 	return outS;
		}



//LOAD FILE
  	ifstream& operator>>(ifstream& file, Hex& H){
		string previous_data;	
			while (getline (file, previous_data)) {}
			file.close();		
			string  size_data_ch;
			int a=0, b=0 ;
			string word = "";
			for (auto iter : previous_data){
				if (iter == ' '){
					if(a==0){
						H.board_data=word;
						a++;//to sp
					}else if(a!=0 && b==0){
						size_data_ch=word;
						b++;
					}word = "";
				}else 
					word = word + iter;
			}
			H.player = stoi(word);
			H.size = stoi(size_data_ch);
			int x=0, y=0, user_turn;
			int **temp = new int*[H.size]; // allocate array of int pointers
			for( int i = 0; i < H.size; i++)
			{
			    temp[i] = new int[H.size]; // allocate each array of ints
			}
			for(int i=0; i<H.size; i++){
				for(int j=0; j<H.size; j++){
					temp[i][j]=0;
			}}
			if(H.player==1)
				Hex(H.size, H.player, H.board_data);			//DONNN

			else if(H.player==2){	//to find who's turn
				for(int i=0;i<H.size*H.size; i++){
					if(H.board_data[i] == 'x')
						x++;
					else if(H.board_data[i]=='o')
						y++;
				}
				if(x<=y)	user_turn=0;
				else	user_turn=1;
				Hex(H.size, H.player, H.board_data, user_turn);			//DONN			
			}
  		return file;
  	}



	void Hex:: markedCells(){		
		int counter=0;	// to keep number of marked cells
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				if(hexCells[i][j].data!='.'){
					counter++;
		}}}
		counter++;	
		marked=counter;
	}

//UNDO - for computer-usr play
	Hex Hex :: operator--(){
		board_data.clear();
		int k=0, i,j ;
		int flag=0;
		while(k!=2){
			flag=0;
		for( i=0; i<size; i++){
			for( j=0; j<size; j++){
				if(allMoves[i][j] == move_counter){
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
			hexCells[i][j].data = '.';
			allMoves[i][j] = 0;
			move_counter--;
			k++;
		}

		k=0;
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				 board_data += hexCells[i][j].data;	
			k++;

		}}
		return *this;
	}



//UNDO - for user1-user2 play
	Hex Hex :: operator--(int ignoreMe){
		 board_data.clear();
		int k=0, i,j ;
		int flag=0;
			
		for( i=0; i<size; i++){
			for( j=0; j<size; j++){
				if(allMoves[i][j] == move_counter){
					flag=1;
					break;
			}}
			if(flag==1)
				break;
		}
			cout<<"i "<<i<<"j "<<j<<endl;
			cout<<move_counter<<endl;
			hexCells[i][j].data = '.';
			allMoves[i][j] = 0;
			move_counter--;
		k=0;
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				 board_data += hexCells[i][j].data;	
			k++;

			}
		}
	int x=0, o=0;
	for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				if(hexCells[i][j].data == 'x')
					x++;
				else if(hexCells[i][j].data == 'o')
					o++;
		}}
		if(x<=o)	turn=0;
		else	turn=1;

		return *this;		//copy constructor'a gidip nesneyi kopyalar
	}


//to compare objects
	bool operator== (const Hex &otherObj, const Hex &currentObj){
		if(otherObj.marked > currentObj.marked){
			return false;
		}
		else{
			return true;
		}
	}




/*not working porperly*/
	void Hex:: find_score(){
		/*
		int temp[size][size];
		int test=0, score[size];
		int counter=1, x=0, y=0,i, j,k=0;
		int x_before=0, y_before=0;		// to keep previous values of the x and y
		int up=0, down=0;		// to prevent infinite loop, (up-down up-down)
		for(i=0; i<size; i++){
			for(j=0; j<size; j++)
				temp[i][j] = 0;	//to fill the board with 0's
		}
			k=0;

		for(i=0; i<size; i++){
			test=0;
			if(hexCells[x][y].data == cell_states::firstPlayer){	//checks the coordinate's value is 'x' or not
				temp[x][y] = 1;	//fill the cell with 1
check:			
			if(y != size-1 ){	
				if(x-1>=0 && down==0 && hexCells[x-1][y].data == cell_states::firstPlayer){	//A move -> northwest					
					x_before = x, y_before = y;
					x = x-1;							
					up=1;
					temp[x][y] = 1;		//fill the cell with 1
					
					goto check;
				}
				if(y+1<=size-1 &&x-1>=0 &&hexCells[x-1][y+1].data == cell_states::firstPlayer){
					counter++;
					x_before = x, y_before = y;
					x=x-1,
					y=y+1;
					temp[x][y] = 1;
					test++;

					goto check;
				}
				if(hexCells[x][y+1].data== cell_states::firstPlayer){		//C move -> east
					counter++;
					x_before = x, y_before = y;
					y=y+1;
					temp[x][y] = 1;
					test++;
					goto check;
				}

				if( x+1<=size-1  && hexCells[x+1][y].data== cell_states::firstPlayer && up ==0){		//D move -> southeast
					x_before = x, y_before = y;
					x=x+1;
					down=1;
					temp[x][y] = 1;
					
					goto check;
				}
			}else
				y++;
			if(y==size-1)
				break;
			counter--;	//to not count moves which is not finish
			x = x_before;		//to go back the coordinates before did the last move
			y= y_before;
			cout<<"test "<<test<<endl;
			score[k]=test*10;
			cout<<"k "<<k<<" sco  "<<score[k]<<endl;
			k++;
			//temp[x][y] = 0;	//to undo the move	
			}x++;
		}






	for(j=0; j<size; j++)
		cout<<score[j];
cout<<endl;
*/

	}

