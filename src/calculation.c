#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "config.h"


double calculate(int number1, int number2, char operation_func) {
	double result;
	printf("\n%d %c %d\n",number1,operation_func,number2);
 	switch(operation_func) {
	case '+':
		result = number1 + number2;
		break;
	case '*':
		result = number1 * number2;
		break;
	case '-':
		result = number1 - number2;
		break;
	case '/':
		result = (double)number1 / (double)number2;
		break;
	case '^':
		result = pow((double)number1,(double)number2);
		break;
	default:
		printf("\nunknown operation, resulting to default addition\n");
		result = number1 + number2;
		;;

	}
	return result;
}

void calculations_game(int amount_of_digits, char operation, int length_of_time) {
int max_number = pow(10,(double)amount_of_digits) - 1;
for (;;) {
int random_number_1 = (rand() % max_number) + 1;
int random_number_2 = (rand() % max_number) + 1;
double result = calculate(random_number_1,random_number_2,operation);
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

