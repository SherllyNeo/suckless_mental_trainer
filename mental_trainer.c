#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "config.h"
#include "games.h"






int main(int argc, char* argv[]) {
	if (argc < 2 ) {
		printf("\nPlease use the format: mental_trainer --mode number_of_digits amount_of_time\n");
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








	return 0;
}

