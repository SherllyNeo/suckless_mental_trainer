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

