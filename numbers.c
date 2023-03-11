#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "config.h"

int get_random_index(int max_length) {
	int index = rand() % max_length;
	return index;
}

void print_string(char* string, int chunk_size) {
	/* Display random string with breaks ergomonic to loci chunks */
	for (int i = 0; i<strlen(string);++i) {
		char current_char = string[i];

		 if ( (i + 1) % (chunk_size) == 0 ) {
		  	printf("%c ",current_char);
 		 }
		 else {
			printf("%c",current_char);
		 }
		if (i+1 == strlen(string)) {
		  	printf("\n");
 		 }
	}
}

void numbers_game(int amount_of_numbers, int length_of_time) {
		char character_pool[] = "1234567890";
	int length_of_character_pool = strlen(character_pool);
	char random_string[amount_of_numbers+1];
	int length_of_random_string = strlen(random_string);

	memset(random_string, '\0', length_of_random_string);



	for (int i = 0; i<amount_of_numbers;++i) {

		 int random_index = get_random_index(length_of_character_pool);
		 char character_to_append_to_random_string = character_pool[random_index];

		 strncat(random_string, &character_to_append_to_random_string, 1);
	}


	print_string(random_string,LOCI_SIZE_NUMBERS);


	/* Clear screen */
	printf("\nWill show for %d seconds before clearing \n",length_of_time);
	sleep(length_of_time);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" );

	/* Get and see user input */

	 char user_input[amount_of_numbers+1];
	 memset(user_input, '\0', strlen(user_input));

	 printf("Enter the number: \n");
    	 fgets(user_input, sizeof(user_input), stdin);

	 int compare_value = strncmp(user_input,random_string,amount_of_numbers);
	 if ( compare_value == 0){
		 printf(ANSI_COLOR_GREEN "\nWell done, you memorised it correctly!\n" ANSI_COLOR_RESET);
	 }
	 else {
	printf(ANSI_COLOR_RED "\nI'm afraid you made an error \n" ANSI_COLOR_RESET);
	/* Display random string with breaks ergomonic to image chunks */
	for (int i = 0; i<amount_of_numbers;++i) {
		char character_in_random_string = random_string[i];
		char character_in_user_string = user_input[i];

		if ( (i + 1) % (IMAGE_SIZE_NUMBERS) == 0 ) {

			if (character_in_random_string == character_in_user_string) {
				printf(ANSI_COLOR_GREEN "%c " ANSI_COLOR_RESET,character_in_random_string);
			}
			else {
					printf(ANSI_COLOR_RED "%c " ANSI_COLOR_RESET,character_in_random_string);
			}
 		 }
		 else {
			if (character_in_random_string == character_in_user_string) {
				printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET,character_in_random_string);
			}
			else {
				printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,character_in_random_string);
			}


		 }
		if (i+1 == amount_of_numbers) {
		  	printf("\n");
 		 }
	}


	printf("\nHowever you wrote \n");
	print_string(user_input,IMAGE_SIZE_NUMBERS);
	 }


}

