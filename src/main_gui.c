#include <ctype.h>
#include <endian.h>
#include <raylib.h>
#include "gui_parser.h"
#include <unistd.h>
#define _XOPEN_SOURCE  700
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "config.h"
#include "games.h"

#define INIT_WIDTH 900
#define INIT_HEIGHT 900


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

typedef enum {
    START,
    GAME_SELECT,
    GAME_INTRO,
    PLAY,
    CHECK_WIN,
    END_GAME
} Game_Phase;

typedef struct {
    Game_Phase game_phase;
    bool chosen_flag;
} Game_State;


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

    InitWindow(INIT_WIDTH, INIT_HEIGHT, "Sherlly's Mental Trainer");
    /* INIT GAME */
    Game_State Game;
    Game.game_phase = START;
    Game.chosen_flag = false;
    char output[100];
    output[0] = '\0';
    int output_len = 1;



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

    char chosen[110];

    /* DRAW */
    while (!WindowShouldClose()) {
        ClearBackground(BEIGE);

        if (Game.game_phase ==  START) {
            BeginDrawing();
            char* welcome_text = "\nWelcome to Sherlly's Mental Trainer. A one of a kind feature rich and efficient tool for all of your mental athletic needs\n";
            int welcome_row = 8;
            int font_size = 3;
            display_text(welcome_text,font_size,BLACK, &welcome_row);
            display_text("Press enter to begin!",font_size,GRAY,&welcome_row);
            if (IsKeyPressed(KEY_ENTER)) {
                Game.game_phase = GAME_SELECT;
            }
            EndDrawing();

        }
        if (Game.game_phase == GAME_SELECT) {
            int row = 0;
            if (Game.chosen_flag) {
                sprintf(chosen,"You chose %s\n",output);
                row = 10;
                BeginDrawing();
                display_text(chosen, 3, BLUE, &row);
                EndDrawing();
                Game.game_phase = PLAY;
            }
            else {
                BeginDrawing();
                get_user_input_text("Please select a game", 3, BLACK, output, &output_len, &row);
                EndDrawing();
                if (IsKeyPressed(KEY_ENTER)) {
                    Game.chosen_flag = true;
                }
            }

        }
        if (Game.game_phase == PLAY) {
            mode = &output[0];
            printf("mode: %s\n",mode);
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

        }
    }


    return 0;
}

