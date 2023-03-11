#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "config.h"

int get_random_index_for_cards(int max_length) {
	int index = rand() % max_length;
	return index;
}

void print_string_cards(char* string) {
	/* Display random string with breaks ergomonic to loci chunks */
	for (int i = 0; i<strlen(string);++i) {
		char current_char = string[i];
		char character_pool_suits_internal[] = "HDSC";
		if (strchr(character_pool_suits_internal,current_char) != NULL ) {
		   printf("%c ",current_char);
		}
		else {
		   printf("%c",current_char);
		}

	}
	printf("\n");
}

void cards_game(int amount_of_cards, int length_of_time) {
	char character_pool_values[] = "A23456789JKQ10"; /* 10 is a special case */
	char character_pool_suits[] = "HDSC";
	int length_of_character_pool_values = strlen(character_pool_values);
	int length_of_character_pool_suits = strlen(character_pool_suits);
	char random_string[amount_of_cards+1];
	int length_of_random_string = strlen(random_string);

	memset(random_string, '\0', length_of_random_string);



	for (int i = 0; i<amount_of_cards;++i) {

		 int random_index_suits = get_random_index_for_cards(length_of_character_pool_suits);
		 int random_index_values = get_random_index_for_cards(length_of_character_pool_values-1); /* We minus one so it'll never get the zero at the end */
		 char character_to_append_to_random_string_value;
		 char character_to_append_to_random_string_suit;
		 if (random_index_values == length_of_character_pool_values - 2){
		 /* if it is a ten then we append two values, the 1 and 0 */
		 char* ten = "10";
		 strncat(random_string, ten, 2);

		 /* Append suit  */
		 character_to_append_to_random_string_suit = character_pool_suits[random_index_suits];
		 strncat(random_string, &character_to_append_to_random_string_suit, 1);

		 }
		 else {

		 /* append value */
		 character_to_append_to_random_string_value = character_pool_values[random_index_values];
		 strncat(random_string, &character_to_append_to_random_string_value, 1);

		 /* Append suit  */
		 character_to_append_to_random_string_suit = character_pool_suits[random_index_suits];
		 strncat(random_string, &character_to_append_to_random_string_suit, 1);

		 }


	}


	print_string_cards(random_string);
	amount_of_cards = strlen(random_string);


	/* Clear screen */
	printf("\nWill show for %d seconds before clearing \n",length_of_time);
	sleep(length_of_time);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" );

	/* Get and see user input */

	 char user_input[amount_of_cards+1];
	 memset(user_input, '\0', strlen(user_input));

	 printf("Enter the cards as one long string: \n");
    	 fgets(user_input, sizeof(user_input), stdin);

	 int compare_value = strncmp(user_input,random_string,amount_of_cards);
	 if ( compare_value == 0){
		 printf(ANSI_COLOR_GREEN "\nWell done, you memorised it correctly!\n" ANSI_COLOR_RESET);
	 }
	 else {
	printf(ANSI_COLOR_RED "\nI'm afraid you made an error \n" ANSI_COLOR_RESET);
	/* Display random string with breaks ergomonic to image chunks */
	for (int i = 0; i<amount_of_cards;++i) {
		char character_in_random_string = random_string[i];
		char character_in_user_string = user_input[i];

		if ( strchr(character_pool_suits,character_in_random_string) != NULL  ) {

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
		if (i+1 == amount_of_cards) {
		  	printf("\n");
 		 }
	}


	printf("\nHowever you wrote \n");
	print_string_cards(user_input);
	 }


}

