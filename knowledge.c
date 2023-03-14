#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include "config.h"


struct Country {
	char name[30];
	char capital[30];
	int phone_prefix;
};
void print_country(struct Country country) {
	printf("\nname: %s\ncapital: %s\nphone prefix: %d\n",country.name,country.capital,country.phone_prefix);
}
int filter_countries(char* user_guess,struct Country list[3],int length) {
	for (int i =0;i<length;++i) {
		char* country_name = list[i].name;
		if (strncmp(user_guess,country_name,strlen(country_name)) == 0) {
			/* replace element we need to delete with the last element of the array and decriment the length */
			printf("\nWell done, removing %s from list\n",country_name);
			print_country(list[i]);
			list[i] = list[length-1];
			--length;
		}
}
return length;
}

struct Element {
	char name[30];
	double atomic_number;
	double atomic_mass;
	double boiling_point;
};
void print_element(struct Element element) {
	printf("\nname: %s\natomic number::%f\natomic mass: %f\nboiling point: %f\n",element.name,element.atomic_number,element.atomic_mass,element.boiling_point);
}

struct Uk_City {
	char name[30];
	char cathedral[30];
	char fact[100];
};
void print_uk_city(struct Uk_City city) {
	printf("\nname: %s\ncapital: %s\nphone prefix: %d\n",city.name,city.cathedral,city.fact);
}



void knowledge_game() {
struct Country countries[3] = { { "England", "london",44 }, { "Juvan","benki",45 }, { "beep","benki",45 }};
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

