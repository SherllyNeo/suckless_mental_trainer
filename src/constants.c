#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"


void constants_game(char* constant,int amount_of_constant_digits) {
	char constant_string[10000];
	if (strncmp(constant,"pi",2) == 0) {
		int length_of_pi = strlen(pi);
		if (amount_of_constant_digits > length_of_pi ){
			printf("\nYou can use at most %d digits for constant %s\n",length_of_pi,constant);
			exit(0);
		}
		strncpy(constant_string,pi,amount_of_constant_digits);

	}
	else if (strncmp(constant,"c",1) == 0) {
		int length_of_c = strlen(c);
		if (amount_of_constant_digits > length_of_c ){
			printf("\nYou can use at most %d digits for constant %s\n",length_of_c,constant);
			exit(0);
		}
		strncpy(constant_string,c,amount_of_constant_digits);

	}
	else if (strncmp(constant,"e",1) == 0) {
		int length_of_e = strlen(e);
		if (amount_of_constant_digits > length_of_e ){
			printf("\nYou can use at most %d digits for constant %s\n",length_of_e,constant);
			exit(0);
		}
		strncpy(constant_string,e,amount_of_constant_digits);

	}
	else if (strncmp(constant,"phi",3) == 0) {
		int length_of_phi = strlen(phi);
		if (amount_of_constant_digits > length_of_phi ){
			printf("\nYou can use at most %d digits for constant %s\n",length_of_phi,constant);
			exit(0);
		}
		strncpy(constant_string,phi,amount_of_constant_digits);

	}
	else {
		printf("\nNot a valid constant, please choose from pi, e, phi or c for a custom constant\n");
		 exit(0);
	}
	char user_input[amount_of_constant_digits+1];
	printf("\nPlease type in as many digits of %s as you can:\n",constant);
	fgets(user_input, sizeof(user_input), stdin);
	 int compare_value = strncmp(user_input,constant_string,amount_of_constant_digits);
	 if ( compare_value == 0){
		 printf( "\nWell done, you recalled %d digits of %s correctly!\n" ,amount_of_constant_digits,constant);
	 }
	 else {
	printf( "\nI'm afraid you made an error \n" );
	/* Display constant string with breaks ergomonic to image chunks */
	for (int i = 0; i<amount_of_constant_digits;++i) {
		char character_in_constant_string = constant_string[i];
		char character_in_user_string = user_input[i];

		if ( (i + 1) % (IMAGE_SIZE_NUMBERS) == 0 ) {

			if (character_in_constant_string == character_in_user_string) {
				printf( "%c " ,character_in_constant_string);
			}
			else {
					printf( "%c " ,character_in_constant_string);
			}
 		 }
		 else {
			if (character_in_constant_string == character_in_user_string) {
				printf( "%c" ,character_in_constant_string);
			}
			else {
				printf( "%c" ,character_in_constant_string);
			}


		 }
		if (i+1 == amount_of_constant_digits) {
		  	printf("\n");
 		 }
	}


	printf("\nHowever you wrote \n");
	print_string(user_input,IMAGE_SIZE_NUMBERS);
	 }



}

