#define _XOPEN_SOURCE 700
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
#include <stdbool.h>
#include "config.h"

#define MAX_SIZE 10000


struct flashcard {
  char prompt[MAX_SIZE];
  char answer[MAX_SIZE];
  time_t lastseen;
  int delay;
  int id;
};

struct flashcard* csv_to_flashcard_array(char* flashcard_deck,int* p_amount_of_cards) {
    struct flashcard* flashcard_array = malloc(5*sizeof(flashcard_array));
    char buffer[MAX_SIZE];
    FILE *deck = NULL;
    int flag = 0;
    int lines = 0;
    deck = fopen(flashcard_deck,"r");
    while (fgets(buffer, MAX_SIZE, deck)) {
        char *token = strtok(buffer, ",");
	/* Make a struct flashcard to add to flashcard_array */
	struct flashcard tmp_flashcard = {};
        while (token) {
	    /* this will be 4 each time. The promt, answer, date and delay */
	    int parse_helper = flag % 4;
	    switch(parse_helper) {
	    	case 0:
			/* parse prompt */

			strcpy(tmp_flashcard.prompt,token);
			break;
	    	case 1:
			/* parse answer */
			strcpy(tmp_flashcard.answer,token);
			break;
	    	case 2:
			/* parse date */
			struct tm date = {};
			strptime(token, "%Y-%m-%d", &date);
			time_t t = mktime(&date);
			tmp_flashcard.lastseen = t;
			break;
	    	case 3:
			/* parse delay */
			tmp_flashcard.delay = atoi(token);
			break;
		default:
			continue;
			;;
	    }
	    ++flag;
            token = strtok(NULL, ",");
        }
	/* append to flashcard array  */
	flashcard_array = realloc(flashcard_array,(lines+1)*sizeof(struct flashcard));
	tmp_flashcard.id = (lines+1);
	flashcard_array[lines] = tmp_flashcard;
	++lines;
    }
    	*p_amount_of_cards = lines;
	return flashcard_array;
}

void print_flashcard(struct flashcard flash_card) {
	time_t time = flash_card.lastseen;
	struct tm *tm = localtime(&time);
	static char time_string[50];
	strftime(time_string, 50, "%Y-%m-%d", tm);
	printf("%s,%s,%s,%d,%d\n",flash_card.prompt,flash_card.answer,time_string,flash_card.delay,flash_card.id);
}
char* flashcard_to_string(struct flashcard flash_card) {
	char *buf;
	size_t sz;
	//time to string
	time_t time = flash_card.lastseen;
	struct tm *tm = localtime(&time);
	static char time_string[50];
	strftime(time_string, 50, "%Y-%m-%d", tm);

	sz = snprintf(NULL, 0,"%s,%s,%s,%d\n",flash_card.prompt,flash_card.answer,time_string,flash_card.delay);


	buf = (char *)malloc(sz + 3);
	snprintf(buf, sz+1, "%s,%s,%s,%d\n",flash_card.prompt,flash_card.answer,time_string,flash_card.delay);

	return buf;



 }

void setup_directory() {
    /* awful flashcard directory maker */

    char * home = getenv("HOME");
    int check;
    char path[1024];
    sprintf(path,"%s/.local",home);
    char * settings_path = path;
    check = mkdir(settings_path,0777);


    sprintf(path,"%s/.local/share",home);
    settings_path = path;
    check = mkdir(settings_path,0777);

    sprintf(path,"%s/.local/share/flashcards",home);
    settings_path = path;
    check = mkdir(settings_path,0777);
}

int choose_random(int min, int max) {
	int number = (rand() % (max - min)) + min;
	return number;

}

int count_dir(char *filepath) {
	int n=0, i=0;
	DIR *d;
	struct dirent *dir;
	d = opendir(filepath);

	/* Determine the number of files*/
	while((dir = readdir(d)) != NULL) {
	    if ( !strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..") )
	    {

	    } else {
		n++;
	    }
	}
	if ( n == 0 ) {
	  printf("there are no flashcard decks!\n");
	  sleep(1);
	  exit(0);

	}
	rewinddir(d);
	return n;
}

int count_lines(char* filename) {
	FILE *fp = fopen(filename,"r");
	  int ch=0;
	  int lines=0;

	  if (fp == NULL);
	  return 0;

	  lines++;
	  while ((ch = fgetc(fp)) != EOF)
	    {
	      if (ch == '\n')
	    lines++;
	    }
	  fclose(fp);
	  if ( lines == 0 ) {
	  printf("No cards in flashcard deck!!\n");
	  exit(0);

	}
	  return lines;
}

char** DirectoryArray(char* filepath,int n) {


    int i = 0;
    DIR *d;
    struct dirent *dir;
    d = opendir(filepath);


	static char *filesList[MAX_SIZE];

	//Put file names into the array
	while((dir = readdir(d)) != NULL) {
	    if ( !strcmp(dir->d_name, ".") || !strcmp(dir->d_name, "..") )
	    {}
	    else {
		filesList[i] = (char*) malloc (strlen(dir->d_name)+1);
		strncpy (filesList[i],dir->d_name, strlen(dir->d_name) );
		i++;
	    }
	}
	rewinddir(d);
	return filesList;
}


int change_line_of_csv(char *filepath, char* line_to_replace, int replace_line) {
	  /* Open original file for reading and a temp file for writing*/
	  FILE *file, *temp;
	  char buffer[MAX_SIZE];
	  char* temp_filename = "tmp_file,csv";
	  file = fopen(filepath, "r");
	  temp = fopen(temp_filename, "w");

	  if (file == NULL || temp == NULL)
	  {
	    printf("Error opening files(s).\n");
	    return 1;
	  }

	  bool keep_reading = true;

	  int current_line = 1;

	  do
	  {
	    fgets(buffer, MAX_SIZE, file);

	    /* Check for end of file */
	    if (feof(file)) {
		    keep_reading = false;
	    }
	    /* Replace current line */
	    else if (current_line == replace_line) {
	      fputs(line_to_replace, temp);
	      current_line++;
	    }
	    else  {
	    fputs(buffer, temp);
	    current_line++;
	    }

	  } while (keep_reading);

	  fclose(file);
	  fclose(temp);

	  remove(filepath);
	  rename(temp_filename, filepath);
	  return 1;
}

 int check_if_forbidden(time_t lastseen,int delay_code) {
	 int forbidden = 0;
	 int days_to_add = 0;

	  //parse time
	 struct tm * time_last_seen_tm_p = localtime(&lastseen);
	 struct tm time_last_seen_tm = *time_last_seen_tm_p;

	 if (delay_code > 4) {
		 days_to_add = 30;
	 }
	 else if (delay_code > 3) {
		 days_to_add = 14;
	 }
	 else if (delay_code > 2) {
		 days_to_add = 7;
	 }
	 else if (delay_code > 1) {
		 days_to_add = 1;
	 }
	else {
		days_to_add = 0;
	}

	 time_last_seen_tm.tm_mday += days_to_add;
	 time_t date_allowed =  mktime(&time_last_seen_tm);
	 time_t date_tday = time(NULL);

	 if (date_allowed > date_tday) {
		 forbidden = 1;
	 }
	 return forbidden;
}

void flashcards_game() {
	/* Inital set up */
	srand(time(NULL));
	start:
	setup_directory();


	char * home = getenv("HOME");
	char flashpath[1024];
	/* Set up flashpath so it points to the flashcards folder */
	sprintf(flashpath,"%s/%s",home,FLASHCARD_FOLDER);

	/* Count the amount of files in the path and use to make an array of the files inside */
	int amount_of_files = count_dir(flashpath);
    	char** filesList = DirectoryArray(flashpath,amount_of_files);

	/* Let user choose a file */
	for(int i=0; i<amount_of_files; i++)
	    printf("please press %d for deck %s\n",i,filesList[i]);

	int user_choice;


	/* Validate user choice */
	const int result = scanf("%d",&user_choice);
	if (1 != result) {
		printf("please type in a valid option \n");
		goto start;
		}
	if (user_choice < 0 || user_choice > amount_of_files-1) {
		printf("please type in a valid option \n");
		goto start;
	}


	/* Set path to deck csv file */
	char deck_path[1024];
    	sprintf(deck_path,"%s/%s/%s",home,FLASHCARD_FOLDER,filesList[user_choice]);


	char* choice;
	struct flashcard chosen_card;
	int random_index;
	struct flashcard* flashcard_array;
	int amount_of_cards;
	int forbidden;


	/* Choose random card */
	choice:

	/* Load in all lines of csv as an array of structs, discard all of the invalid structs, then check length of array */
	flashcard_array = csv_to_flashcard_array(deck_path,&amount_of_cards);
	int original_amount = amount_of_cards;
	for (int i = 0; i<original_amount;++i) {
		time_t lastseen_for_card = flashcard_array[i].lastseen;
		int delay_code =  flashcard_array[i].delay;
		forbidden = check_if_forbidden(lastseen_for_card,delay_code);
		if (forbidden) {
			/* Remove from array if forbidden*/
			flashcard_array[i] = flashcard_array[amount_of_cards-1];
			--amount_of_cards;
		}
	}
	if (amount_of_cards == 0) {
		printf("\nYou've completed all cards in deck for now\n");
		exit(0);
	}


	printf("amount of flashcards in deck are: %d \n",amount_of_cards);
	sleep(1);


	printf("\n \n grabbing flashcard from deck ....\n \n");
	sleep(1);
	random_index = choose_random(0, amount_of_cards);
	chosen_card = flashcard_array[random_index];

	//ask prompt
	prompt:
	printf("Prompt: %s \n \n \nplease press r to reveal answer \n \n",chosen_card.prompt);
	char show_answer[30];

	// use user choice
	scanf("%s",&show_answer);
	if (show_answer[0] == 'r') {
	 printf("Answer is: %s \n",chosen_card.answer);

	}
	else {
		printf("\nthat isn't an r, showing promt again \n");
		goto prompt;
	}


	//ask if they got the flashcard correct
	printf("\ndid you get this one correct? (y/n) \n \n ");
	char correct_question[1];
	int delay_value = chosen_card.delay;

	 //use user choice
	scanf("%s",&correct_question);
 	if (correct_question[0] == 'y') {
 	 printf(ANSI_COLOR_GREEN "Well done getting it right, it will be hidden for longer \n" ANSI_COLOR_RESET);
	  ++delay_value;
 	}
 	else {
 		printf("Don't worry about getting it wrong \n");
		delay_value = 0;
 	}
	sleep(1);
      //write to file
        time_t today = time(NULL);
  	chosen_card.lastseen = today;
  	chosen_card.delay = delay_value;
	char* string_of_new_card = flashcard_to_string(chosen_card);
	if (change_line_of_csv(deck_path,string_of_new_card,chosen_card.id)) {
	/* clean up */
	free(string_of_new_card);

	goto choice;
	}
	else {
		printf("\ncould not update your file with current date and info\n");
		free(string_of_new_card);
	        goto choice;
	}

};

