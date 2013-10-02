/*
 *  palin.c
 *  
 *
 *  Created by Jorge Conde on 13-09-24.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int letter_index_array[27];
char** words;
char** reversed_array;
char** result_array;


int returnIndex(char* word);
void storeLetterIndex(char* words, int index);
char * reverseWord(char* words);
int lookUpReversedWords( int num_words);
int compare (const void * a, const void * b );
char ** reverseArray(int num_words);

int main(int argc, char* argv[]) {
    
    int i = 0;

    int count;
    int word_size = 25;
    int num_words = 235886;
    
    words = malloc((num_words+1) * sizeof(char *));
    
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
        count = i;
    }
    letter_index_array[26] = num_words;

    
    //char** reversed_array = lookUpReversedWords(words, num_words);
    
    reversed_array = reverseArray(num_words);
    
    qsort(reversed_array, num_words, sizeof(char *), compare);
    
    int total = lookUpReversedWords(num_words);
    
    for (i=0; i<total; i++) {
        printf("%s\n",result_array[i]);
    }

}

int compare (const void * a, const void * b ) {
    return strcmp(*(const char **)a, *(const char **)b);
}


int lookUpReversedWords(int num_words){
    int i, j, z;
    int k = 0;
    char *previous_word = "";
    result_array = malloc((1500)*sizeof(char *));

    for (i=0; i<num_words; i++) {
        
        
        char *word_reversed = reversed_array[i];
    
        
        if (strcmp(word_reversed, words[i]) == 0) {
            
            //printf("%s\n",word_reversed);
            result_array[k] = word_reversed;
            previous_word = word_reversed;
            k++;
        }
        else{
            
            z = returnIndex(word_reversed);

            for (j=letter_index_array[z]; j<=letter_index_array[z+1]; j++) {
                if (strcmp(word_reversed,words[j]) == 0) {
                    //printf("%s\n",word_reversed);
                    
                    letter_index_array[z] = j;
                    result_array[k] = word_reversed;
                    previous_word = word_reversed;
                    k++;
                    break;
                }
            }
        }
    }
   
    return k;
}

char ** reverseArray(int num_words){
    int i;
    char *reversed;
    char** local_reversed_array = malloc((num_words+1)*sizeof(char *));
    
    for (i=0; i<num_words; i++) {
        reversed = reverseWord(words[i]);
        local_reversed_array[i] = reversed;
    }
    
    return local_reversed_array;
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
