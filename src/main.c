#define _XOPEN_SOURCE  700
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "config.h"
#include "games.h"


char help[] = "\n \n \
               \nsmt -m mode -options \
               \noptions are -m/--m for mode, -c/--constant_name for constant name, -op/--operation for operation, -a/--amount for amount of data, -l or --length_of_time for length of time (seconds), -e/--explain to explain and -p/--power for setting the powrr\
               \nFull documentation and tutorials can be found at: sherlly.org \
               \nUse config.h as settings\n \
               \navaliable modes are:  \
               \n-m \"numbers\" -a amount_of_digits -l length_of_time  \
               \n-m \"binary\" -a amount_of_digits -l length_of_time  \
               \n-m \"cards\" -a amount_of_cards -l length_of_time  \
               \n-m \"constants\" -c constant_name -a amount_of_digits -l length_of_time | (only supports pi, e, phi and c. c being a custom one you define in config.h \
                       \n-m countries_quiz \
                       \n-m elements_quiz \
                       \n-m primes_quiz \
                       \n-m day_of_week | -e to pre-calculate codes \
                       \n-m calculator -a amount_of_digits -o 'operation' -l length_of_time | supports +, /, *, ^, -  \
                       \n-m powers -a amount_of_digits -p exponent -l length_of_time \
                       \n-m rooting -a amount_of_digits -p exponent | no time limit \
                       \n-m knight_tour | -e to pre-calculate codes \
                       \n-m blind_knight \
                       \n-m chess_squares \n";




int main(int argc, char* argv[]) {
	printf("\nWelcome to Sherlly's Mental Trainer. A one of a kind feature rich and efficient tool for all of your mental athletic needs\n");
	srand(time(NULL));
    int i;
    char* mode = "numbers";
    char* constant_name = "e";
    char operation = '+';
    int amount_of_data = 30;
    int length_of_time = 120;
    int explain = 0;
    int power = 1;
    
    
    /* Parse command line arguments */
    for (i = 1;i<argc;i++) {
        char* current_arg = argv[i];
        if (!strcmp(current_arg,"-h") || !strcmp(current_arg,"--help") ) {
            printf("%s",help);
            return 1;
        }
        else if (!strcmp(current_arg,"-m") || !strcmp(current_arg,"--mode") ) {
            mode = argv[++i];
        }
        else if (!strcmp(current_arg,"-c") || !strcmp(current_arg,"--constant_name") ) {
            constant_name = argv[++i];
        }
        else if (!strcmp(current_arg,"-o") || !strcmp(current_arg,"--operation") ) {
            operation = *argv[++i];
        }
        else if (!strcmp(current_arg,"-a") || !strcmp(current_arg,"--amount") ) {
            amount_of_data = atoi(argv[++i]);
        }
        else if (!strcmp(current_arg,"-l") || !strcmp(current_arg,"--length_of_time") ) {
            length_of_time = atoi(argv[++i]);
        }
        else if (!strcmp(current_arg,"-e") || !strcmp(current_arg,"--explain") ) {
            explain = !explain;
        }
        else if (!strcmp(current_arg,"-p") || !strcmp(current_arg,"--power") ) {
            power = atoi(argv[++i]);
        }
    }

    
    /* use them to run */
    if (strcmp(mode,"day_of_week") == 0) {
        doad_game(explain);
    }

    else if (strcmp(mode,"numbers") == 0) {
        numbers_game(amount_of_data,length_of_time);
    }
    else if (strcmp(mode,"binary") == 0) {
        binnumbers_game(amount_of_data,length_of_time);
    }
    else if (strcmp(mode,"cards") == 0) {
        cards_game(amount_of_data,length_of_time);
    }
    else if (strcmp(mode,"constants") == 0) {
        constants_game(constant_name,amount_of_data);
    }
    else if (strcmp(mode,"calculator") == 0) {
        calculations_game(amount_of_data,operation,length_of_time);
    }
    else if (strcmp(mode,"powers") == 0) {
        powers_game(amount_of_data,power,length_of_time);
    }
    else if (strcmp(mode,"rooting") == 0) {
        rooting_game(amount_of_data,power);
    }
    else if (strcmp(mode,"countries_quiz") == 0) {
        country_game();
    }
    else if (strcmp(mode,"cities_quiz") == 0) {
        city_game();
    }
    else if (strcmp(mode,"states_quiz") == 0) {
        state_game();
    }
    else if (strcmp(mode,"elements_quiz") == 0) {
        elements_game();
    }
    else if (strcmp(mode,"primes_quiz") == 0) {
        primes_game();
    }
    else if (strcmp(mode,"blind_knight") == 0) {
        blindknight_game();
    }
    else if (strcmp(mode,"knight_tour") == 0) {
            if (explain) {
                knighttour_game_solved();
            }
            else {
                knighttour_game();
            }
    }
    else if (strcmp(mode,"chess_squares") == 0) {
        chesssquares_game();
    }

	 return 0;
}

