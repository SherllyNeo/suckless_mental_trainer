#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "config.h"


void speed_counting_game(int amount_of_digits, int bpm) {
    int result = 0;
    int time_per_digit =  bpm/60;
    for (int i = 0; i<amount_of_digits;i++) {
        int number = (rand() % 20) - 10;
        result += number;
        printf("\r          ");
        printf("\r%d",number);
        fflush(stdout);
        sleep(time_per_digit);
    }
    char user_input[50];
    printf("\nPlease type in the answer:\n");
    fgets(user_input,sizeof(result),stdin);
    int user_answer = strtod(user_input,NULL);
    if (user_answer == result) {
        printf(ANSI_COLOR_GREEN "\nWell done, got it right!!\n" ANSI_COLOR_RESET);
    }
    else {
        printf(ANSI_COLOR_RED "\nAfraid you got it wrong :(\nThe answer was: \n%d\n" ANSI_COLOR_RESET,result);
    }
    sleep(1);
}   
