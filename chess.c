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


int letter_to_number(char letter_) {
	int number;
	char letter = toupper(letter_);
	if (letter >= 'A' && letter <= 'Z')
	  number = letter - 'A';
	return (number + 1);
}

char number_to_letter(int number) {
	return (number + 'A' - 1);
}


int validate_square_is_on_board(int xpos,int ypos) {

	return !(xpos < 1 || xpos > 8 || ypos < 1 || ypos > 8 );
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


int generate_all_possible_knight_moves(struct Chess_piece knight,int moves_array[8][2]) {
	/* Go through each knight jump and append to array */
	int array_size = 0;
	int Xmoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
   	int Ymoves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int valid_knight_jump = 0;
        for (int i = 0; i < 9; i++) {
	      int x = knight.xpos + Xmoves[i];
	      int y = knight.ypos + Ymoves[i];
	      if (x>=1 && y>=1 && x<(BOARD_WIDTH+1) && y<(BOARD_LENGTH+1) ){
		      moves_array[array_size][0] = x;
		      moves_array[array_size][1] = y;
		      ++array_size;
		}
	}
	return array_size;
}


int check_valid_knight_jump(struct Chess_piece knight,int xpos_new,int ypos_new) {
	/* Go through each knight jump and see if xpos_new and ypos_new are possible */
	int Xmoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
   	int Ymoves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int valid_knight_jump = 0;
        for (int i = 0; i < 9; i++) {
	      int x = knight.xpos + Xmoves[i];
	      int y = knight.ypos + Ymoves[i];
	      if (x>=1 && y>=1 && x<(BOARD_WIDTH+1) && y<(BOARD_LENGTH+1) ){
		  if (x == xpos_new && y == ypos_new) {
			  valid_knight_jump = 1;
		  }
		}
	}
	return valid_knight_jump;

}



void move_knight(struct Chess_piece * knight,int xpos_new,int ypos_new) {
	knight->xpos = xpos_new;
	knight->ypos = ypos_new;
	printf("\nPosition of knight updated\n");
	print_chess_positon(knight,"Knight");
}

void move_knight_silent(struct Chess_piece * knight,int xpos_new,int ypos_new) {
	knight->xpos = xpos_new;
	knight->ypos = ypos_new;
}

