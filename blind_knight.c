#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include "config.h"
#include "chess.h"


int validate_knight_move_with_queen(struct Chess_piece knight,struct Chess_piece queen,int xpos_new,int ypos_new) {
	int valid_knight_jump = check_valid_knight_jump(knight,xpos_new,ypos_new);
	if (valid_knight_jump == 0) {
		printf(ANSI_COLOR_RED "\nNot a valid knight move\n" ANSI_COLOR_RESET);
		return 0;
	}
	/* If the knight is going to land on the queen, it is valid */
	if ((xpos_new == queen.xpos) && (ypos_new == queen.ypos)) {
		return 1;
	}
	/* Check the new position does not hit the queens sight */
	if (xpos_new == queen.xpos || ypos_new == queen.ypos || abs(xpos_new-queen.xpos) == abs(queen.ypos-ypos_new)) {
		printf(ANSI_COLOR_RED "\nThis move would hit the queen's line of sight\n" ANSI_COLOR_RESET);
		return 0;
	}
	return -1;
}


/* TO DO - code solver and use it to check there is a possible solution */


void blindknight_game() {
	char move[8];
	int move_array[2];
	struct Chess_piece knight;
	struct Chess_piece queen;
	position_selection:
	int xposition_knight = (rand() % BOARD_WIDTH) + 1;
	int yposition_knight = (rand() % BOARD_LENGTH) + 1;
	int xposition_queen = (rand() % BOARD_WIDTH) + 1;
	int yposition_queen = (rand() % BOARD_LENGTH) + 1;

	knight.xpos = xposition_knight;
	knight.ypos = yposition_knight;
	queen.xpos = xposition_queen;
	queen.ypos = yposition_queen;

	print_chess_positon(&queen,"Queen");
	print_chess_positon(&knight,"Knight");
	if ((knight.xpos == queen.xpos) && (knight.ypos == queen.ypos)) {
		goto position_selection;
	}
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
	if (!validate_knight_move_with_queen(knight,queen,move_array[0],move_array[1])) {
		goto get_move;
	}
	move_knight(&knight,move_array[0],move_array[1]);
	++move_counter;
	if (!((knight.xpos == queen.xpos) && (knight.ypos == queen.ypos))) {
		goto get_move;
	}
	else {
		printf(ANSI_COLOR_GREEN "\nYou killed the queen in %d moves!\n" ANSI_COLOR_RESET,move_counter);

	}

}

