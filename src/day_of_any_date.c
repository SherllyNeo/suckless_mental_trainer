#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "config.h"
#include "doad_calc.h"

char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}

void doad_game(int explain) {
	int min_year = 1700;
	int min_month = 0;
	int min_day = 1;

	int max_year = 2399;
	int max_month = 12;
	int max_day = 32;

	for (;;) {
	int year = (min_year) + (rand() % (max_year - min_year) );
	int month = ( (min_month) + (rand() % (max_month - min_month) ) % 12 ) + 1;
	int days_in_month = find_days_in_month(month,year);
	int day = (( (min_day) + (rand() % (max_day - min_day) ) ) % days_in_month) + ( rand() % 2 );
	printf("\nRandom date: %d-%d-%d\n",year,month,day);
	int day_code = calculate_day(year,month,day,explain);
	char* day_of_week_p = day_name(day_code);

	char user_input[20];
	char day_of_week[20];

	memset(user_input,'\0',strlen(user_input));
	memset(day_of_week,'\0',strlen(day_of_week));

	strcpy(day_of_week,day_of_week_p);

	printf("\nPlease type in the day of the week for this date\n");
	fgets(user_input,sizeof(user_input),stdin);

	char* user_input_lower = strlwr(user_input);
	char* day_of_week_lower = strlwr(day_of_week);

	if (strncmp(user_input_lower,day_of_week_lower,strlen(day_of_week_lower)) == 0 ) {
		printf( "\nyou got it right!\n" );
	}
	else {
		printf( "\nyou got it wrong! The answer was %s\n" ,day_of_week);
		}
	sleep(1);
	}

}

