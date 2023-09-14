#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include <strings.h>

int font_size(int scale) {
    return (GetScreenWidth() / 103) * scale;
}

void display_text(char *text_untouched,int size,Color color, int *row) {
    char text[6000];
    strcpy(text,text_untouched);
    printf("\ndisplying text: %s\n",text);
    printf("\nFirst char: %c\n",text[1]);

    BeginDrawing();
    ClearBackground(BEIGE);
    int text_size = MeasureText(text, font_size(size));
    int text_difference = 0;
    char first_character[2];
    char text_chunk[10000];

    first_character[0] = text[1];
    first_character[1] = '\0';
    int first_character_width = MeasureText(first_character, font_size(size));

    /* 
      We want overflowing to wrap around 
      To achieve this we modify text
      |------------|----

      -->

      |------------|
      |    ----    |

      while text size is over screenwidth, we will display up until the difference
      Then display the rest on the next row, ad infinitum

     */
    while (text_size > GetScreenWidth()) {
        printf("Text \"%s\" is over screenwidth, chunking\n",text);
        
        int diff = text_size - GetScreenWidth();
        int character_overflow_estimate = (diff / first_character_width);
        int last_character_on_screen_est = strlen(text) - character_overflow_estimate;
        if (character_overflow_estimate == 0)  {
            text_size = MeasureText(text, font_size(size));
            DrawText(text, (GetScreenWidth() - text_size) / 2, GetScreenHeight() / 20 * (*row), font_size(size), color);
            *row += 1;
            break;
        }
        printf("\n\ndiff: %d\ncharacter_overflow_estimate: %d\nlast_character_on_screen_est: %d\n\n",diff,character_overflow_estimate,last_character_on_screen_est);;

        /* split into two stings on overflow */
        text_size = MeasureText(text, font_size(size));
        char first_chunk[5000];
        char last_chunk[5000];
        char tmp[5000];
        memset(first_chunk,'\0',sizeof(first_chunk)); 
        memset(last_chunk,'\0',sizeof(last_chunk)); 
        memset(tmp,'\0',sizeof(tmp)); 

        /* 
         find what space to split on, the last space that is on screen 
         assume we are at the right place, go backwards until we hit a space
         and if we don't find one, set it back to character on screen est
        */
        int index_to_split = last_character_on_screen_est;
        while ((text[index_to_split] != ' ') && (index_to_split > 0)) {
            index_to_split--;
        }
        if (!index_to_split) {
            index_to_split = last_character_on_screen_est;
        }


        strncpy(first_chunk,text,strlen(text)-index_to_split - 1);
        strcpy(last_chunk,&text[strlen(text)-index_to_split - 1]);

        first_chunk[strlen(first_chunk)+1] = '\0';
        last_chunk[strlen(last_chunk)+1] = '\0';

        printf("split into \"%s\" \nand \"%s\" on space at index %d which is \"%c\"\n",first_chunk,last_chunk,index_to_split,text[index_to_split]);

        int display_text_size = MeasureText(first_chunk, font_size(size));
        DrawText(first_chunk, (GetScreenWidth() - display_text_size) / 2, GetScreenHeight() / 20 * (*row), font_size(size), color);

        strcpy(text,last_chunk);
        *row += 1;
        printf("EOL: text size of \"%s\" is %d\n\n\n",text,text_size);
    }
    if (text_size < GetScreenWidth()) {
        text_size = MeasureText(text, font_size(size));
        DrawText(text, (GetScreenWidth() - text_size) / 2, GetScreenHeight() / 20 * (*row), font_size(size), color);
        *row += 1;
    }

    EndDrawing();
};

void get_user_input_text(char text[],int size,Color color,char output[], int* output_len,int* row) {
    BeginDrawing();
    ClearBackground(BEIGE);
        
    char cur_char = GetCharPressed();

    output[*output_len - 1] = cur_char;
    output[*output_len] = '\0';
    *output_len += 1;
 
    if (IsKeyPressed(KEY_DELETE) || IsKeyPressed(KEY_BACKSPACE)) {
        *output_len -= 1;
        output[*output_len - 1] = '\0';
    };

    EndDrawing();
};

