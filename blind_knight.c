#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include "config.h"

struct Chess_piece {
	int xpos;
	int ypos;
};


int letter_to_number(char letter) {
	int number;
	switch(letter) {
	case 'A':
		number = 1;
		break;
	case 'B':
		number = 2;
		break;
	case 'C':
		number = 3;
		break;
	case 'D':
		number = 4;
		break;

	case 'E':
		number = 5;
		break;
	case 'F':
		number = 6;
		break;
	case 'G':
		number = 7;
		break;
	case 'H':
		number = 8;
		break;
	default:
		number = 0;
		;;
	}
	return number;
}

char number_to_letter(int number) {
	char letter;
	switch(number) {
	case 1:
		letter = 'A';
		break;
	case 2:
		letter = 'B';
		break;
	case 3:
		letter = 'C';
		break;
	case 4:
		letter = 'D';
		break;

	case 5:
		letter = 'E';
		break;
	case 6:
		letter = 'F';
		break;
	case 7:
		letter = 'G';
		break;
	case 8:
		letter = 'H';
		break;
	default:
		letter = '0';
		;;
	}
	return letter;
}


int validate_square_is_on_board(int xpos,int ypos) {

	return !(xpos < 1 || xpos > 8 || ypos < 1 || ypos > 8 );
}

int validate_knight_move(struct Chess_piece knight,struct Chess_piece queen,int xpos_new,int ypos_new) {
	/* Go through each knight jump and see if xpos_new and ypos_new are possible */
	int Xmoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
   	int Ymoves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int valid_knight_jump = 0;
        for (int i = 1; i < 9; i++) {
	      int x = knight.xpos + Xmoves[i];
	      int y = knight.ypos + Ymoves[i];
	      if (x>=1 && y>=1 && x<9 && y<9){
		  if (x == xpos_new && y == ypos_new) {
			  valid_knight_jump = 1;
		  }
		}
	}
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

void human_to_machine(int* buffer,char* human_move) {
	char letter = letter_to_number(toupper(human_move[0]));
	int number = human_move[1] - '0';
	buffer[0] = letter;
	buffer[1] = number;
}

void print_chess_positon(struct Chess_piece * piece, char* name) {
	int letter_i = piece->xpos;
	int number = piece->ypos;
	char letter = number_to_letter(letter_i);
	printf("\n%s is at %c%d\n",name,letter,number);
}

void move_knight(struct Chess_piece * knight,int xpos_new,int ypos_new) {
	knight->xpos = xpos_new;
	knight->ypos = ypos_new;
	printf("\nPosition of knight updated\n");
	print_chess_positon(knight,"Knight");
}

/* TO DO - code solver and use it to check there is a possible solution */


void blindknight_game() {
	char move[8];
	int move_array[2];
	struct Chess_piece knight;
	struct Chess_piece queen;
	position_selection:
	int xposition_knight = (rand() % 8) + 1;
	int yposition_knight = (rand() % 8) + 1;
	int xposition_queen = (rand() % 8) + 1;
	int yposition_queen = (rand() % 8) + 1;

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
	if (!validate_knight_move(knight,queen,move_array[0],move_array[1])) {
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

