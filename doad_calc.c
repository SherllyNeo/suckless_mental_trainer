#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>



int find_days_in_month(int month,int year) {
	int days_in_month;
	switch (month)
	{
    case 1:
      days_in_month = 31;
      break;
    case 2:
      if ((year%4==0) && ((year%400==0) || (year%100!=0))) {days_in_month = 29; }
      else {
	      days_in_month = 28;
      }
      break;
    case 3:
      days_in_month = 31;
      break;
    case 4:
      days_in_month = 30;
      break;
    case 5:
      days_in_month = 31;
      break;
    case 6:
      days_in_month = 30;
      break;
    case 7:
      days_in_month = 31;
      break;
    case 8:
      days_in_month = 31;
      break;
    case 9:
      days_in_month = 30;
      break;
    case 10:
      days_in_month = 31;
      break;
    case 11:
      days_in_month = 30;
      break;
    case 12:
      days_in_month = 31;
      break;
    default:
      days_in_month = 30;
	}
	return days_in_month;

}
char* month_name(int month) {
	char* name;
	switch (month)
	{
    case 1:
	name = "Jan";
      break;
    case 2:
	name = "Feb";
      break;
    case 3:
      name = "Mar";
      break;
    case 4:
      name = "Apr";
      break;
    case 5:
      name = "May";
      break;
    case 6:
      name = "Jun";
      break;
    case 7:
      name = "Jul";
      break;
    case 8:
      name = "Aug";
      break;
    case 9:
      name = "Sep";
      break;
    case 10:
      name = "Oct";
      break;
    case 11:
      name = "Nov";
      break;
    case 12:
      name = "Dec";
      break;
    default:
      name = "Cannot find Month Name";
	}
	return name;
}

char* day_name(int day) {
	char* name;
	switch (day)
	{
    case 0:
	name = "Sun";
      break;
    case 1:
	name = "Mon";
      break;
    case 2:
	name = "Tue";
      break;
    case 3:
      name = "Wed";
      break;
    case 4:
      name = "Thu";
      break;
    case 5:
      name = "Fri";
      break;
    case 6:
      name = "Sat";
      break;
    default:
      name = "Cannot find Day name";
	}
	return name;
}


int get_month_code(int month) {
	int month_code;
	switch (month)
	{
    case 1:
	month_code = 0;
      break;
    case 2:
      month_code = 3;
      break;
    case 3:
      month_code = 3;
      break;
    case 4:
      month_code = 6;
      break;
    case 5:
      month_code = 1;
      break;
    case 6:
      month_code = 4;
      break;
    case 7:
      month_code = 6;
      break;
    case 8:
      month_code = 2;
      break;
    case 9:
      month_code = 5;
      break;
    case 10:
      month_code = 0;
      break;
    case 11:
      month_code = 3;
      break;
    case 12:
      month_code = 5;
      break;
    default:
      printf("Invalid month");
      month_code = -1;
      exit(0);
	}
	return month_code;

}

int get_century_code(int century) {
	int century_code;
	switch (century)
	{
    case 17:
	    century_code = 4;
      break;
    case 18:
	    century_code = 2;
      break;
    case 19:
	    century_code = 0;
      break;
    case 20:
	    century_code = 6;
      break;
    case 21:
	    century_code = 4;
      break;
    case 22:
	    century_code = 2;
      break;
    case 23:
      century_code = 0;
    break;
    default:
      printf("Invalid century");
      century_code = -1;
      exit(0);
	}
	return century_code;

}
int get_year_code(int year) {
	return (year + (year / 4)) % 7;
}

int calculate_day(int year, int month, int day, int explain) {
      int is_leap_year = 0;
      if ((year%4==0) && ((year%400==0) || (year%100!=0))) {is_leap_year = 1; }
      if (explain) {
	      if (is_leap_year) {
	      printf("\n%d is a leap year because leap Years are any year that can be exactly divided by 4 unless they can be divided by 100 expect in the case where it is divided by 400.\n",year);
		if (month == 1 || month == 2) {
			printf("\nThis matters to our calculation as the month is in %s\n",month_name(month));
		}
	      }

	      else {
		      printf("\nNot a leap year\n");
	      }

      }
      int day_code = day % 7;
      int month_code = get_month_code(month);
      if (explain) {
      printf("\nday_code is %d\nand month_code is %d\n\n",day_code,month_code);
      }
      int century_part = floor(year/100);
      int year_part = year % 100;

      int century_code = get_century_code(century_part);
      int year_code = get_year_code(year_part);
      if (explain) {
      printf("\ncentury_code is %d \nyear_code is %d\n",century_code,year_code);
      }

      int result = (year_code + century_code + month_code + day_code) % 7;
      return result;



}

