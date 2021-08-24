

public interface HexGame {
	
	/*	Sets the board size	*/
	 boolean set_size(int board_size);	
	 
	 /*	Return size of the board	*/
	 int get_size();
	 
	 /*	Sets game type	*/
	 void set_player(int user);	
	 
	 /*	Returns game type	*/
	 int get_player(); 
	 
	 /* Sets board to play */
	 void set_board();		
 	 
	 /*	Sets board after the load command	*/
	 void set_board(String board_data);	
	 
	 /* To make move	*/
	 void play();
	 
	 /*	Prints equivalent of the game board to terminal	*/
	 void printBoard();		
	 
	 /*	Makes random computer move */
	 boolean computer_move();

	// int check_finish_x();	//checks x is won the game or not
	// int check_finish_o();	// checks o is won the game or not




}
