#ifndef _chess_
#define _chess_
#include "chess.c"
/* Chess declarations */
struct Chess_piece;

int letter_to_number(char letter);

int validate_square_is_on_board(int xpos,int ypos);

void human_to_machine(int* buffer,char* human_move);

void print_chess_positon(struct Chess_piece * piece, char* name);

int generate_all_possible_knight_moves(struct Chess_piece knight, int moves_array[8][2]);

int check_valid_knight_jump(struct Chess_piece knight, int xpos_new, int ypos_new);

void move_knight(struct Chess_piece * knight,int xpos_new,int ypos_new);

#endif

