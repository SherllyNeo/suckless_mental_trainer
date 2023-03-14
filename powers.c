#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "config.h"


void powers_game(int amount_of_digits, int power,int length_of_time) {
	int max_number = pow(10,(double)amount_of_digits) - 1;
	for (;;) {
		int random_number_1 = (rand() % max_number) + 1;
		double result = pow(random_number_1,power);
		printf("\n%d^%d\n",random_number_1,power);
		char user_input[50];
		printf("\nShowing for %d seconds\n",length_of_time);
		sleep(length_of_time);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\nPlease type in the answer:\n");
		fgets(user_input,sizeof(result),stdin);
		double user_answer = strtod(user_input,NULL);
		if (user_answer == result) {
				 printf(ANSI_COLOR_GREEN "\nWell done, got it right!!\n" ANSI_COLOR_RESET);
		}
		else {
				 printf(ANSI_COLOR_RED "\nAfraid you got it wrong :(\nThe answer was: \n%f\n" ANSI_COLOR_RESET,result);
		}
		sleep(1);
		}


}

