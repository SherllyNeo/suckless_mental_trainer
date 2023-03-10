#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "config.h"
#include "games.h"






int main(int argc, char* argv[]) {
	printf("\nWelcome to Sherlly's Mental Trainer. A one of a kind feature rich and suckless tool for all of your mental athletic needs\n");
	sleep(1);
	if (argc < 2 ) {
		printf("\nPlease use the format: mental_trainer --mode number_of_digits amount_of_time\n\n");
		exit(0);
	}
	srand(time(NULL));
	char* mode = argv[1];

	if (strcmp(mode,"--day_of_week") == 0) {
		int explain = 0;
		if (argc > 2) {
			if (strcmp(argv[2],"-e") == 0) {
			explain = 1;
			}
		 }
		doad_game(explain);
	}

	else if (strcmp(mode,"--numbers") == 0) {
		if (argc < 2) {
			exit(0);
		}
		int amount_of_digits = atoi(argv[2]);
		int length_of_time = atoi(argv[3]);
		numbers_game(amount_of_digits,length_of_time);
	}
	else if ((strcmp(mode,"-h") == 0) || (strcmp(mode,"--h") == 0)) {
	}
	else {
		printf("\nI do not know that commnad, please type in --help or -h for a full menu\n");
	}







	return 0;
}

