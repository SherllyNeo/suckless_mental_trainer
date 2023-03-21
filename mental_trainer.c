#define _XOPEN_SOURCE  700
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "config.h"
#include "games.h"






int main(int argc, char* argv[]) {
	printf("\nWelcome to Sherlly's Mental Trainer. A one of a kind feature rich and suckless tool for all of your mental athletic needs\n");
	sleep(1);
	if (argc < 2 ) {
		printf("\nPlease use the format: mental_trainer --mode number_of_digits amount_of_time\n\n");
		exit(0);
	}
	srand(time(NULL));
	char* mode = argv[1];

	if (strcmp(mode,"--day_of_week") == 0) {
		int explain = 0;
		if (argc > 2) {
			if (strcmp(argv[2],"-e") == 0) {
			explain = 1;
			}
		 }
		doad_game(explain);
	}

	else if (strcmp(mode,"--numbers") == 0) {
		if (argc < 2) {
			exit(0);
		}
		int amount_of_digits = atoi(argv[2]);
		int length_of_time = atoi(argv[3]);
		numbers_game(amount_of_digits,length_of_time);
	}
	else if (strcmp(mode,"--cards") == 0) {
		if (argc < 2) {
			exit(0);
		}
		int amount_of_digits = atoi(argv[2]);
		int length_of_time = atoi(argv[3]);
		cards_game(amount_of_digits,length_of_time);
	}
	else if (strcmp(mode,"--constants") == 0) {
		if (argc < 2) {
			exit(0);
		}
		char* constant_name = argv[2];
		int amount_of_digits = atoi(argv[3]);
		constants_game(constant_name,amount_of_digits);
	}
	else if (strcmp(mode,"--calculator") == 0) {
		if (argc < 3) {
			exit(0);
		}
		int amount_of_digits = atoi(argv[2]);
		char operation = *(argv[3]);
		int length_of_time = atoi(argv[4]);
		calculations_game(amount_of_digits,operation,length_of_time);
	}
	else if (strcmp(mode,"--powers") == 0) {
		if (argc < 3) {
			exit(0);
		}
		int amount_of_digits = atoi(argv[2]);
		int power = atoi(argv[3]);
		int length_of_time = atoi(argv[4]);
		powers_game(amount_of_digits,power,length_of_time);
	}
	else if (strcmp(mode,"--countries_quiz") == 0) {
		if (argc < 2) {
			exit(0);
		}
		char* list_name = argv[2];
		country_game();
	}
	else if (strcmp(mode,"--elements_quiz") == 0) {
		if (argc < 2) {
			exit(0);
		}
		char* list_name = argv[2];
		elements_game();
	}
	else if (strcmp(mode,"--primes_quiz") == 0) {
		if (argc < 2) {
			exit(0);
		}
		char* list_name = argv[2];
		primes_game();
	}
	else if (strcmp(mode,"--blind_knight") == 0) {
		blindknight_game();
	}
	else if (strcmp(mode,"--knight_tour") == 0) {
		if (argc > 2) {
		char* if_solve = argv[2];
		if (strcmp(if_solve,"-s") == 0) {
		knighttour_game_solved();
		}
		else {
		knighttour_game();
		}
		}
		knighttour_game();
	}
	else if (strcmp(mode,"--chess_squares") == 0) {
		chesssquares_game();
	}
	else if (strcmp(mode,"--flashcards") == 0) {
		flashcards_game();
	}
	else if ((strcmp(mode,"-h") == 0) || (strcmp(mode,"--help") == 0)) {
		printf("\nPlease use format:\n");
		printf("\nsmt --mode -options\n");
		printf("\nFull documentation and tutorials can be found at: sherlly.org\n");
		printf("\nUse config.h as settings\n\n");
		printf("\navaliable modes are: \n");
		printf("\n--numbers amount_of_digits length_of_time \n");
		printf("\n--cards amount_of_cards length_of_time \n");
		printf("\n--constants name_of_constant amount_of_digits (only supports pi, e, phi and c. c being a custom one you define in config.h\n");
		printf("\n--countries_quiz\n");
		printf("\n--elements_quiz\n");
		printf("\n--primes_quiz\n");
		printf("\n--day_of_week (an option -e to pre-calculate codes)\n");
		printf("\n--calculator amount_of_digits operation length_of_time (supports +, /, *, ^, - )\n");
		printf("\n--powers amount_of_digits exponent length_of_time\n");
		printf("\n--blind_knight\n");
		printf("\n--knight_tour\n");
		printf("\n--chess_squares\n");
		printf("\n--flashcards\n");
		printf("\n\nexamples!\n\n");
		printf("\n--numbers 30 60 \n");

	}
	else {
		printf("\nI do not know that commnad, please type in --help or -h for a full menu\n");
	}

	 return 0;
}

