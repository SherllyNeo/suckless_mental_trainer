#include <ctype.h>
#include <unistd.h>
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

char useage[] = "\n \n \
               \nType in the game mode you want to play:\n\
               \nsome games have options like: -c/--constant_name for constant name, -op/--operation for operation, -a/--amount for amount of data, -l or --length_of_time for length of time (seconds), -e/--explain to explain and -p/--power for setting the powrr\
               \nFull documentation and tutorials can be found at: sherlly.org \
               \nUse config.h as settings\n \
               \navaliable modes are:  \
               \n\"numbers\" -a amount_of_digits -l length_of_time  \
               \n\"binary\" -a amount_of_digits -l length_of_time  \
               \n\"cards\" -a amount_of_cards -l length_of_time  \
               \n\"constants\" -c constant_name -a amount_of_digits -l length_of_time | (only supports pi, e, phi and c. c being a custom one you define in config.h \
                       \ncountries_quiz \
                       \nelements_quiz \
                       \nprimes_quiz \
                       \nday_of_week | -e to pre-calculate codes \
                       \ncalculator -a amount_of_digits -o 'operation' -l length_of_time | supports +, /, *, ^, -  \
                       \npowers -a amount_of_digits -p exponent -l length_of_time \
                       \nrooting -a amount_of_digits -p exponent | no time limit \
                       \nknight_tour | -e to pre-calculate codes \
                       \nblind_knight \
                       \nchess_squares \n";



void fill_str_data_fields(int *amount_of_data,int* length_of_time) {
            get_opt_integer:
            printf("Amount of data?\n");
            char amount_of_data_string[50];
            char length_of_time_string[50];
            char* _;
            memset(amount_of_data_string,'\0',strlen(amount_of_data_string));
            memset(length_of_time_string,'\0',strlen(length_of_time_string));

            fgets(amount_of_data_string,sizeof(amount_of_data_string),stdin);
            amount_of_data_string[strcspn(amount_of_data_string, "\n")] = 0;

            *amount_of_data = (int) strtol(amount_of_data_string,&_,10);

            if (*amount_of_data == 0) {
                printf("amount of data must be a positive integer\n");
                goto get_opt_integer;
            }
            get_opt_time:
            printf("How long would you like it to last before testing?\n");
            fgets(length_of_time_string,50,stdin);
            length_of_time_string[strcspn(length_of_time_string, "\n")] = 0;
            *length_of_time = (int) strtol(length_of_time_string,&_,10);

            if (*length_of_time == 0) {
                printf("length of time must be a positive integer\n");
                goto get_opt_time;
            }

}


int main(int argc, char* argv[]) {
	printf("\nWelcome to Sherlly's Mental Trainer. A one of a kind feature rich and efficient tool for all of your mental athletic needs\n");
	srand(time(NULL));
    int i;
    char* mode = "numbers";
    char tmp_buffer[50];
    memset(tmp_buffer,'\0',strlen(tmp_buffer));
    char* constant_name = "e";
    char operation = '+';
    int amount_of_data = 30;
    int length_of_time = 120;
    int explain = 0;
    int power = 1;
    
    if (argc > 1) {
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
    }
    else {
        /* get user input */
        get_user_input:

        printf("%s",useage);


        printf("Please type in a mode:\n");
        fgets(tmp_buffer,sizeof(tmp_buffer),stdin);
        tmp_buffer[strcspn(tmp_buffer, "\n")] = 0;
        mode = &tmp_buffer[0];

        if (strcmp(mode,"day_of_week") == 0) {
            printf("would you like to have explain mode on (y/n):\n");
            char response = fgetc(stdin);
            if (response == 'y' || response == 'Y') {
                explain = 1;
            }
        }

        else if (strcmp(mode,"numbers") == 0) {
            fill_str_data_fields(&amount_of_data, &length_of_time);
        }
        else if (strcmp(mode,"binary") == 0) {
            fill_str_data_fields(&amount_of_data, &length_of_time);
        }
        else if (strcmp(mode,"cards") == 0) {
            fill_str_data_fields(&amount_of_data, &length_of_time);
        }
        else if (strcmp(mode,"constants") == 0) {
            /* get constant name */
            char* _;
            get_opt_const:
            printf("What constant would you like to use? (pi, e, phi, c?\n");
            char constant_name_tmp[50];
            memset(constant_name_tmp,'\0',strlen(constant_name_tmp));

            fgets(constant_name_tmp,sizeof(constant_name_tmp),stdin);
            constant_name_tmp[strcspn(constant_name_tmp, "\n")] = 0;

            constant_name = &constant_name_tmp[0];
            if (!(!strcmp(constant_name,"e") || !strcmp(constant_name,"pi") || !strcmp(constant_name,"phi") || !strcmp(constant_name,"c") )) {
                printf("\nPlease select either pi, e, phi or the custom c\n");
                goto get_opt_const;
            }

            /* get amount of data for constant */
            get_opt_integer:
            printf("Amount of data?\n");
            char amount_of_data_string[50];
            memset(amount_of_data_string,'\0',strlen(amount_of_data_string));

            fgets(amount_of_data_string,sizeof(amount_of_data_string),stdin);
            amount_of_data_string[strcspn(amount_of_data_string, "\n")] = 0;

            amount_of_data = (int) strtol(amount_of_data_string,&_,10);

            if (amount_of_data == 0) {
                printf("amount of data must be a positive integer\n");
                goto get_opt_integer;
            }

        }
        else if (strcmp(mode,"calculator") == 0) {
            fill_str_data_fields(&amount_of_data, &length_of_time);
            /* get amount of data for constant */
            get_opt_operation:
            printf("What operation do you want to use? (upports +, /, *, ^, -)\n");
            char op_tmp[50];
            memset(op_tmp,'\0',strlen(op_tmp));

            fgets(op_tmp,sizeof(op_tmp),stdin);
            op_tmp[strcspn(op_tmp, "\n")] = 0;
            operation = op_tmp[0];

            if (!(operation == '+' || operation == '/' || operation == '*' || operation == '^' || operation == '-')) {
                printf("Please use +, /, *, ^ or -\n");
                goto get_opt_operation;
            }

            calculations_game(amount_of_data,operation,length_of_time);
        }
        else if (strcmp(mode,"powers") == 0) {
            fill_str_data_fields(&amount_of_data, &length_of_time);
            /* get power */
            get_opt_power:
            printf("What power would you like to raise to?\n");
            char* _;
            char power_string[50];
            memset(power_string,'\0',strlen(power_string));

            fgets(power_string,sizeof(power_string),stdin);
            power_string[strcspn(power_string, "\n")] = 0;

            power = (int) strtol(power_string,&_,10);

            if (power == 0) {
                printf("Power must be an integer\n");
                goto get_opt_power;
            }
        }
        else if (strcmp(mode,"rooting") == 0) {
            /* TODO */

            /* get power */
            get_opt_power_for_root:
            printf("What power would you like to raise to?\n");
            char* _;
            char power_string[50];
            memset(power_string,'\0',strlen(power_string));

            fgets(power_string,sizeof(power_string),stdin);
            power_string[strcspn(power_string, "\n")] = 0;

            power = (int) strtol(power_string,&_,10);

            if (power == 0) {
                printf("Power must be an integer\n");
                goto get_opt_power_for_root;
            }

            /* get amount of data */
            get_opt_data_for_root:

            printf("What amount of data?\n");
            char amount_of_data_string[50];
            memset(amount_of_data_string,'\0',strlen(amount_of_data_string));

            fgets(amount_of_data_string,sizeof(amount_of_data_string),stdin);
            amount_of_data_string[strcspn(amount_of_data_string, "\n")] = 0;

            amount_of_data = (int) strtol(amount_of_data_string,&_,10);

            if (amount_of_data == 0) {
                printf("Amount of data must be a positive integer");
                goto get_opt_data_for_root;
            }
        }
        else if (strcmp(mode,"knight_tour") == 0) {
            printf("would you like to have explain mode on (y/n):\n");
            char response = fgetc(stdin);
            if (response == 'y' || response == 'Y') {
                explain = 1;
            }
        }
        else {
            printf("Could not find specified mode\n");
            goto get_user_input;
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

