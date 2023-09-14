#include <ctype.h>
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
    int text_size = MeasureText(text, font_size(size));
    int text_difference = 0;
    char first_character[2];
    char text_chunk[10000];

    first_character[0] = 'W'; /*  Widest letter */
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
        
        int buffer = (GetScreenWidth() + size) / 4;
        int diff = text_size - GetScreenWidth() + buffer;
        int character_overflow_estimate = (diff / first_character_width);
        int last_character_on_screen_est = strlen(text) - character_overflow_estimate;
        if (character_overflow_estimate == 0)  {
            text_size = MeasureText(text, font_size(size));
            DrawText(text, (GetScreenWidth() - text_size) / 2, GetScreenHeight() / 20 * (*row), font_size(size), color);
            *row += 1;
            break;
        }

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
        while ((text[index_to_split] != ' ') && (index_to_split >= 0)) {
            index_to_split--;
        }
        if (text[index_to_split] != ' ') {
            index_to_split = last_character_on_screen_est;
        }


        strncpy(first_chunk,text,index_to_split);
        strcpy(last_chunk,&text[index_to_split]);

        first_chunk[strlen(first_chunk)+1] = '\0';
        last_chunk[strlen(last_chunk)+1] = '\0';


        int display_text_size = MeasureText(first_chunk, font_size(size));
        DrawText(first_chunk, (GetScreenWidth() - display_text_size) / 2, GetScreenHeight() / 20 * (*row), font_size(size), color);

        strcpy(text,last_chunk);
        *row += 1;
    }
    if (text_size < GetScreenWidth()) {
        text_size = MeasureText(text, font_size(size));
        DrawText(text, (GetScreenWidth() - text_size) / 2, GetScreenHeight() / 20 * (*row), font_size(size), color);
        *row += 1;
    }
};

void get_user_input_text(char text[],int size,Color color,char output[], int* output_len,int* row) {
    display_text(text, size, color, row);
        
    char cur_char = GetCharPressed();
    if (isalnum(cur_char) || cur_char == ' ' || cur_char == '-' || cur_char == '_' ) {
        output[*output_len - 1] = cur_char;
        output[*output_len] = '\0';
        *output_len += 1;
    }
 
    if (IsKeyPressed(KEY_DELETE) || IsKeyPressed(KEY_BACKSPACE)) {
        *output_len -= 1;
        output[*output_len - 1] = '\0';
    };
    display_text(output, size, color, row);

};

void get_user_input_number(char text[],int size,Color color,char output[], int* output_len,int* row) {
    display_text(text, size, color, row);
        
    char cur_char = GetCharPressed();
    if (isdigit(cur_char) || cur_char == '-' ) {
        output[*output_len - 1] = cur_char;
        output[*output_len] = '\0';
        *output_len += 1;
    }
 
    if (IsKeyPressed(KEY_DELETE) || IsKeyPressed(KEY_BACKSPACE)) {
        *output_len -= 1;
        output[*output_len - 1] = '\0';
    };
    display_text(output, size, color, row);

};
