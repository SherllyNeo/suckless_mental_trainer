#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include "config.h"
#include "chess.h"


char colour_of_square(int xpos, int ypos) {
	/* 1 is white, 0 is black */
	int xpos_mod2 = xpos % 2;
	int ypos_mod2 = ypos % 2;
	char colour = 'W';
	if (xpos_mod2 == ypos_mod2) {
		colour = 'B';
	}
	return colour;
}

void chesssquares_game() {
	char colour_get[8];
	struct Chess_piece knight;
	get_pos:
	;
	int xposition = (rand() % BOARD_WIDTH) + 1;
	int yposition = (rand() % BOARD_LENGTH) + 1;
	char xposition_char = number_to_letter(xposition);
	printf("\nWhat colour is the square: %c%d\n",xposition_char,yposition);

	get_move:
	;
	printf("\nPlease input a colour as W or B:\n");
	memset(colour_get,'\0',sizeof(colour_get));
	fgets(colour_get,sizeof(colour_get),stdin);
	char real_colour = colour_of_square(xposition,yposition);
	char colour = colour_get[0];

	if (real_colour == toupper(colour)) {
		printf( "\nYou got it right!\n" );
	}
	else {
		printf( "\nYou got it wrong\n" );
	}
	goto get_pos;

}

