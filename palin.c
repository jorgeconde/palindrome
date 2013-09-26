/*
 *  palin.c
 *  
 *
 *  Created by Jorge Conde on 13-09-24.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int letter_index_array[26];


int returnIndex(char* word);
void storeLetterIndex(char* words, int index);
char * reverseWord(char* words);
char ** lookUpReversedWords(char** words, int num_words);

int main(int argc, char* argv[]) {
    
    int i = 0;
    int num_words = 235886;
    int word_size = 25;
    
    
    
    
    char** words = malloc((num_words+1) * sizeof(char *));
    
    if (words == NULL) {
        printf("malloc returned NULL");
        return -1;
    }
    
    
    /* Allocate memory for each word and store them */
    for (i=0; i<num_words+1; i++) {
        words[i] = malloc((word_size+1) * sizeof(char *));
        
        if (words[i] == NULL) {
            printf("malloc returned NULL");
            break;
        }
        
        // read word
        fgets(words[i], num_words, stdin);
        words[i][strlen(words[i])-1] = '\0';
        
        if (strlen(words[i]) == 1) {
            storeLetterIndex(words[i], i);
        }
    }
    
    
    char** reversed_array = lookUpReversedWords(words, num_words);

    
    
}

char ** lookUpReversedWords(char** words, int num_words){
    int i, j, z;
    int k = 0;
    char *previous_word = "";
    char** reversed_words = malloc((num_words+1) * sizeof(char *));

    for (i=0; i<num_words; i++) {
        char *word_reversed = reverseWord(words[i]);
        if (strcmp(word_reversed, words[i]) == 0) {
            reversed_words[k] = word_reversed;
            previous_word = word_reversed;
            k++;
        }
        else if(strcmp(word_reversed, previous_word) != 0){
            z = returnIndex(word_reversed);

            for (j=letter_index_array[z]; j<=letter_index_array[z+1]; j++) {
                if (strcmp(word_reversed,words[j]) == 0) {
                    //printf("found one, %s, %d\n",word_reversed, i);
                    reversed_words[k] = word_reversed;
                    previous_word = word_reversed;
                    k++;
                    break;
                }
            }
        }
    }
    return reversed_words;
}

char * reverseWord(char* words){
    int length = strlen(words);
    int i;
    int j = 0;
    char *reversed = malloc( (length+1) * sizeof(char *));
    
    for (i=length-1; i>=0; i--) {
        reversed[j] = words[i];
        j++;
    }
    //printf("This is the reversed of %s: %s\n", words, reversed);

    return reversed;
}

void storeLetterIndex(char* words, int index){
    char letter = words[0];
    
    letter_index_array[letter - 97] = index; 
}

int returnIndex(char* words){
    char letter = words[0];
    int index;
    
    index = letter - 97;
    
    return index;
}
