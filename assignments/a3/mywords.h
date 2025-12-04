#ifndef MYWORDS_H
#define MYWORDS_H

#include <stdio.h>

// Define BOOLEAN type
typedef enum boolean {
    FALSE = 0,
    TRUE = 1
} BOOLEAN;

// Define WORD structure
typedef struct word {
    char word[20];  // to store a word
    int count;      // frequency of the word
} WORD;

// Define WORDSTATS structure
typedef struct wordstats {
    int line_count;     // number of lines
    int word_count;     // total words
    int keyword_count;  // number of non-common keywords
} WORDSTATS;

// Function prototypes

/**
 * Load word data from file and insert into a dictionary.
 *
 * @param fp - file pointer to opened text file
 * @param dictionary - char array where dictionary words are stored
 * @return number of words added into the dictionary
 */
int create_dictionary(FILE *fp, char *dictionary);

#endif
 
