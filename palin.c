/*
 *  palin.c
 *  
 *
 *  Created by Jorge Conde on 13-09-24.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char * reverse_word(char* words);

int main(int argc, char* argv[]) {
    
    int i = 0;
    int num_words = 235886;
    int word_size = 25;
    
    char** words = malloc( (num_words+1) * sizeof(char *));
    
    if (words == NULL) {
        printf("malloc returned NULL");
        return -1;
    }
    
    
    /* Allocate memory for each word and store them */
    for (i=0; i<num_words+1; i++) {
        words[i] = malloc( (word_size+1) * sizeof(char *));
        
        if (words[i] == NULL) {
            printf("malloc returned NULL");
            break;
        }
        
        // read word
        fgets(words[i], num_words, stdin);
    }
    
    /* reverse word */
    reverse_word(words[0]);
    
    
}


const char * reverse_word(char* words){
    int length = strlen(words);
    /* Reverse */
    return "";
}