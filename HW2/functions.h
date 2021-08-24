#ifndef _FUNC_H
#define _FUNC_H


	#include <iostream>
	#include <random>
	#include <string>
	#include <fstream>
	using namespace std;

		enum  cells{empty='.', firstPlayer='x', secondPlayer ='o'};

		void print_board(char board[12][12], int size_of_board);
		int coordinates_valid_or_not(int coord1, char coord2_ch, int size);		
		int make_move(char board[12][12], char vertical, int horizontal, int upper_lower, int user);
		int check_finish_x(char board[12][12], const int& size, int& x_won);
		int check_finish_o(char board[12][12], const int& size, int& o_won);
		int generate_random();
		void choose_different_rand(char board[12][12], int size, int *last_x_ptr, int* last_y_ptr);
		int computer_move(char board[12][12], int first , int *last_x_ptr, int *last_y_ptr, int size);
		int filled(char board[12][12], int size);	
		void make_uppercase(char game_board[12][12], int board_won[12][12], int size, char letter_won);
		
		//HW2 FUNCTIONS		

		/*This function run, when user entered SAVE command. Opens a file with the name entered by the user. And open another file to copy the informations in the first file.*/		
		int file_operations(const string command ,char& coordinate1, int& coordinate2, char game_board[12][12], int& size, int& player, int& user_turn);
		
		/*This function run, when user entered SAVE command. Opens a file with the name entered by the user. And open another file to copy the informations in the first file.*/
		void save_game(string secondWord, const char game_board[12][12], const int size, const int player_number);
		
		/*This function load the previous data from the previous_game.txt file. Because this file contains the information saved after the SAVE command.
		  The function transfers this information to the game, allowing the user to continue the game from where she/he left off.*/
		void load_game(string secondWord, char game_board[12][12], int& size, int& player_number, int& user_turn);

		

#endif
