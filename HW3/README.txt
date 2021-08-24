
	RULES
	- The user enters 'board size' and 'player' information.
	- User enters coordinate to move (like a1, b15, A7, B2...) 
	- All commands must be written when requesting coordinates.
	- If user wants to save the game, must enter 'SAVE FILENAME.TXT' command.
	  After save command program saves board, board size and player information into the file which name is determine by the user.
	- When the game is saved, the user is asked whether she/he wants to continue the game or not. 
	- If user enters 'y' or 'Y', next games starts(next object). If user enters 'n' or 'N', program ends.
	- If the user wants to continue a previously saved game, he/she must enter the 'LOAD FILENAME.TXT' command. 
	  Enter the file name correctly. More than one game can be saved.
	- When it is loaded in 2 player games, it is checked who played the game last. The game continues according to this.
	- If the player wants to compare the game they are playing with the non-empty cells in a previously played game, they must enter the command COMPARE GAMENUMBER.
	  like 'COMPARE 1' or 'COMPARE 2'
	- The program returns information on which game has won.
	- If a player complates his/her own path, the game is over. The winner is printed to the screen.
	- If all cells are full before anyone wins the game, the game is over.



	CODE DETAILS
	1 - There is a class named Hex in the program. Inside this class there is an inner class named Cell.
	2 - Hex has 3 constructors. 
	     *	Hex (int board_size, int user)   ->  This constructor used for starting the game.
	     *  Hex(int board_size, int user, string board_data)   ->  This constructor used for load the game after the LOAD command. (JUST PLAYER-COMPUTER GAME)
	     *  Hex(int board_size, int user, string board_data, int user_turn)   ->  This constructor used for load the game after the LOAD command. (JUST PLAYER1-PLAYER2)

	3 - There is static object variable that holds the number of objects.
	4 - The static getMarked Cells function returns the number of marked cells of the object that the user wants to compare.
	5 - There is a Cell type vector holds the game board. (hexCells)
	6 - Program read and write from files using save and load commands.
	7 - There is a playGame function that determines who will live in the program.
	8 - There is inline functions: getNumberOgObjects, get_heig_width, get_size...;
	
	
	