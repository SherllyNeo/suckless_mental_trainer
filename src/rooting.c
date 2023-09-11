#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "config.h"


double result_calculate(int number1, int power) {

	double result;
	result = number1;
	if (power == 1) {
		printf("This is too easy, what is %lf?\n",result);
	}
	else if (power == 2) {
		int question = number1 * number1;
		printf("\nWhat is the square root of %d\n",question);
	}
	else if (power == 3) {
		int question = number1 * number1 * number1;
		printf("\nWhat is the cube root of %d\n",question);
	}
	else {
		int question = 1;
		int i;
		for (i=0;i<power;i++) {
			question *= number1;
		}
		printf("\nWhat is the %dth root of %d\n",power,question);
	}
	return result;
}

void rooting_game(int amount_of_digits, int power) {
int max_number = pow(10,(double)amount_of_digits) - 1;
for (;;) {
int random_number_1 = (rand() % max_number) + 1;
double result = result_calculate(random_number_1,power);
char user_input[50];
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

