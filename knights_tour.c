#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include "config.h"
#include "chess.h"




int check_if_values_in_2D_array(int array[BOARD_AREA][2],int x, int y) {
	for (int i; i<=BOARD_AREA;++i) {
		if (array[i][0] == x && array[i][1] == y) {
			return 1;
		}
	}
	return 0;
}


int validate_knight_move_with_previous_moves(struct Chess_piece knight,int previous_moves[BOARD_AREA][2],int xpos_new,int ypos_new) {
	int valid_knight_jump = check_valid_knight_jump(knight,xpos_new,ypos_new);
	if (valid_knight_jump == 0) {
		printf(ANSI_COLOR_RED "\nNot a valid knight move\n" ANSI_COLOR_RESET);
		return 0;
	}
	if (check_if_values_in_2D_array(previous_moves,xpos_new,ypos_new)) {
		printf(ANSI_COLOR_RED "\nYou've been to that square before\n" ANSI_COLOR_RESET);
		return 0;
	}
	else {
		return 1;
	}

	return -1;
}


void block_out_visited_square(int visited_squares[BOARD_AREA][2],int move_counter,int xpos,int ypos) {
	visited_squares[move_counter][0] = xpos;
	visited_squares[move_counter][1] = ypos;
}

/* TO DO - code solver and use it to check there is a possible solution */


void knighttour_game() {
	char move[8];
	int move_array[2];
	struct Chess_piece knight;
	int visited_squares[BOARD_AREA][2];
	memset(visited_squares,0,sizeof(visited_squares));

	position_selection:
	int xposition_knight = (rand() % BOARD_WIDTH) + 1;
	int yposition_knight = (rand() % BOARD_LENGTH) + 1;

	knight.xpos = xposition_knight;
	knight.ypos = yposition_knight;

	print_chess_positon(&knight,"Knight");
	int move_counter = 0;
	get_move:
	printf("\nPlease input a knight move:\n");
	memset(move,'\0',sizeof(move));
	fgets(move,sizeof(move),stdin);
	human_to_machine(move_array,move);
	if (!validate_square_is_on_board(move_array[0],move_array[1])) {
		printf(ANSI_COLOR_RED "\nNot a chess square\n" ANSI_COLOR_RESET);
		goto get_move;
	}
	if (!validate_knight_move_with_previous_moves(knight,visited_squares,move_array[0],move_array[1])) {
		goto get_move;
	}
	block_out_visited_square(visited_squares,move_counter,knight.xpos,knight.ypos);
	move_knight(&knight,move_array[0],move_array[1]);
	++move_counter;
	if (visited_squares[BOARD_AREA-1][1] == 0) {
		goto get_move;
	}
	else {
		printf(ANSI_COLOR_GREEN "\nYou completed the tour!\n" ANSI_COLOR_RESET,move_counter);

	}

}

void knighttour_game_solved() {
	char move[8];
	int move_array[2];
	get_move:
	printf("\nPlease input a starting square for the knights tour:\n");
	memset(move,'\0',sizeof(move));
	fgets(move,sizeof(move),stdin);
	human_to_machine(move_array,move);
	if (!validate_square_is_on_board(move_array[0],move_array[1])) {
		printf(ANSI_COLOR_RED "\nNot a chess square\n" ANSI_COLOR_RESET);
		goto get_move;
	}
	char* chess_moves[64] = { "A1","C2","E3","D1","B2","A4","C5","B7","D8","E6","G5","E4","D2","F1","H2","G4","E5","D3","B4","D5","F4","E2","D4","F5","E7","C6","A5","C4","D6","E8","G7","H5","G3","H1","F2","H3","G1","F3","E1","G2","H4","G6","H8","F7","H6","G8","F6","H7","F8","D7","B8","A6","C7","A8","B6","C8","A7","B5","A3","B1","C3","A2","C1","B3"};
	char starting_square[2];
	for (int i=0; i<64;++i) {
		if (strncmp(move,chess_moves[i],2) == 0) {
			/* Found starting square */
			strncpy(starting_square,move,2);
			for (int j=i; j<(64+i);++j) {
				printf("\nKnight moved from %s to %s\n",chess_moves[j % 64],chess_moves[(j+1) % 64]);
				sleep(1);
				}

			}

			}
		}

