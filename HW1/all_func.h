#ifndef _FUNC_H
#define _FUNC_H


#include <iostream>
#include <random>
using namespace std;


	void print_board(char board[12][12], int size_of_board);
	int coordinates_valid_or_not(int coord1, char coord2_ch, int size);		
	int make_move(char board[12][12], char vertical, int horizontal, int upper_lower, int user);
	int check_finish_x(char board[12][12], int size, int* x_won);
	int check_finish_o(char board[12][12], int size, int* o_won);
	int generate_random();
	void choose_different_rand(char board[12][12], int size, int *last_x_ptr, int* last_y_ptr);
	int computer_move(char board[12][12], int first , int *last_x_ptr, int *last_y_ptr, int size);
	int filled(char board[12][12], int size);
	void make_uppercase(char game_board[12][12], int board_won[12][12], int size, char letter_won);
	




#endif

