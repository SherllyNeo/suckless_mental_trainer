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
int validate_knight_move_with_queen_silent(struct Chess_piece knight,struct Chess_piece queen,int xpos_new,int ypos_new) {
    int valid_knight_jump = check_valid_knight_jump(knight,xpos_new,ypos_new);
    if (valid_knight_jump == 0) {
        return 0;
    }
    /* If the knight is going to land on the queen, it is valid */
    if ((xpos_new == queen.xpos) && (ypos_new == queen.ypos)) {
        return 1;
    }
    /* Check the new position does not hit the queens sight */
    if (xpos_new == queen.xpos || ypos_new == queen.ypos || abs(xpos_new-queen.xpos) == abs(queen.ypos-ypos_new)) {
        return 0;
    }
    return -1;
}

int generate_all_possible_knight_moves_with_queen(struct Chess_piece knight,struct Chess_piece queen,int moves_array[8][2]) {
    /* Go through each knight jump and append to array */
    int array_size = 0;
    int Xmoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int Ymoves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int valid_knight_jump = 0;
    for (int i = 0; i < 9; i++) {
        int x = knight.xpos + Xmoves[i];
        int y = knight.ypos + Ymoves[i];
        if (x>=1 && y>=1 && x<(BOARD_WIDTH+1) && y<(BOARD_LENGTH+1) ){
            if (validate_square_is_on_board(x,y)) {

                if (validate_knight_move_with_queen_silent(knight,queen,x,y)) {
                    moves_array[array_size][0] = x;
                    moves_array[array_size][1] = y;
                    ++array_size;
                }
            }

        }
    }
    return array_size;
}


int blindknight_game_solved(struct Chess_piece knight, struct Chess_piece queen) {
    char move[8];
position_selection:
    ;
    int moves_array[8][2];
    int distance[8];
    float minimum_distance = 1000;
    int moves = 0;

    /* Generate all possible moves into an array */
    int amount_of_moves = generate_all_possible_knight_moves_with_queen(knight,queen,moves_array);
    if (amount_of_moves == 0) {
        return -1;
    }
    int xnew = 0;
    int ynew = 0;
    int visited_array[30][2];
    /* Repeat until we win */
    while (!( (queen.xpos == knight.xpos) && (queen.ypos == knight.ypos) )) {
        amount_of_moves = generate_all_possible_knight_moves_with_queen(knight,queen,moves_array);
        for (int i = 0; i<amount_of_moves; ++i) {
            xnew = moves_array[i][0];
            ynew = moves_array[i][1];

        }
        int xmin;
        int ymin;
        for (int i = 0; i<amount_of_moves; ++i) {
            xnew = moves_array[i][0];
            ynew = moves_array[i][1];

            /* Check if shorter distance than current global */
            float distance = sqrt(pow(queen.xpos - xnew,2) + pow(queen.ypos - ynew,2));
            if (distance<minimum_distance) {
                minimum_distance = distance;
                xmin = xnew;
                ymin = ynew;
            }

        }
        moves++;
        knight.xpos = xmin;
        knight.ypos = ymin;
        /* Reset minimum distance */
        minimum_distance = 1000;
    }

    return moves;


}

void blindknight_game() {
    char move[8];
    int move_array[2];
    struct Chess_piece knight;
    struct Chess_piece queen;
position_selection:
    ;
    int xposition_knight = (rand() % BOARD_WIDTH) + 1;
    int yposition_knight = (rand() % BOARD_LENGTH) + 1;
    int xposition_queen = (rand() % BOARD_WIDTH) + 1;
    int yposition_queen = (rand() % BOARD_LENGTH) + 1;

    knight.xpos = xposition_knight;
    knight.ypos = yposition_knight;
    queen.xpos = xposition_queen;
    queen.ypos = yposition_queen;

    if ((knight.xpos == queen.xpos) && (knight.ypos == queen.ypos)) {
        goto position_selection;
    }
    int move_counter = 0;
    int amount_of_moves_to_solve = blindknight_game_solved(knight,queen);
    printf("\nThis can be done in %d moves\n",amount_of_moves_to_solve);
    if (amount_of_moves_to_solve == -1) {
        goto position_selection;
    }
    print_chess_positon(&queen,"Queen");
    print_chess_positon(&knight,"Knight");
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
        if (move_counter<=amount_of_moves_to_solve) {
            printf(ANSI_COLOR_GREEN "\nYou killed the queen in %d moves! The optimal amount of moves\n" ANSI_COLOR_RESET,move_counter);
        }
        else {
            printf(ANSI_COLOR_GREEN "\nYou killed the queen in %d moves! The optimal amount of moves was %d\n" ANSI_COLOR_RESET,move_counter,amount_of_moves_to_solve);
        }

    }

}

