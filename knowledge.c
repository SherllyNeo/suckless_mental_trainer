#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include "config.h"
#include "countries.c"
#include "elements.c"

#define STATE_AMOUNT 0
#define UKCITY_AMOUNT 0
#define ELEMENTS_AMOUNT 0

void print_element(struct Element element) {
	printf("\nname: %s\natomic number::%d\natomic mass: %f\nboiling point: %f\n",element.name,element.atomic_number,element.atomic_mass,element.boiling_point);
}

struct Uk_City {
	char name[30];
	int creation_year;
};
void print_uk_city(struct Uk_City city) {
	printf("\nname: %s\nreation year: %d\n",city.name,city.creation_year);
}


void knowledge_game() {
char user_input[100];
int length = sizeof(countries)/sizeof(countries[0]);
int length_after_filter;
while ( length != 0) {
	memset(user_input,'\0',sizeof(user_input));
	get_user_guess:
	printf("\nPlease type in a country name:\n");
	fgets(user_input,sizeof(user_input),stdin);
	length_after_filter = filter_countries(user_input,countries,length);
	if (length_after_filter == length) {
		printf(ANSI_COLOR_RED "\nNot a country\n" ANSI_COLOR_RESET);
		goto get_user_guess;
	}
	length = length_after_filter;
	for (int i =0;i<length;++i) {
	}
}
	printf(ANSI_COLOR_GREEN "\nWell done you got all the countries!\n" ANSI_COLOR_RESET);


}

