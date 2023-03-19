#define _XOPEN_SOURCE 700
#include "numbers.c"
#include "cards.c"
#include "constants.c"
#include "calculation.c"
#include "powers.c"
#include "day_of_any_date.c"
#include "blind_knight.c"
#include "knights_tour.c"
#include "squares.c"
#include "countries.c"
#include "elements.c"
#include "flashcards.c"

/* memory games */
void numbers_game(int amount_of_number, int length_of_time);
void cards_game(int amount_of_cards, int length_of_time);
void constants_game(char* constant, int amount_of_digits);
void constants_game(char* constant, int amount_of_digits);
void country_game();
void elements_game();

/* Calculation games */
void doad_game(int explainer);
void calculations_game(int amount_of_digits, char operation, int length_of_time);
void powers_game(int amount_of_digits, int power, int length_of_time);


/* Blindfold Visualtion games */
void blindknight_game();
void knighttour_game();
void knighttour_game_solved();
void chessquares_game();

/* Studying  */
void flashcards_game();

