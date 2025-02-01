/*
--------------------------------------------------
Project: assaignment 3
File:    myword.c
Author:  Ryan Tran
Version: 2025-01-09
--------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000

/*
 * Load word data from file, and insert words a directory represented by char array.
 * 
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored. 
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.   
 */
int create_dictionary(FILE *fp, char *dictionary) {
    char line[1000];
    char delimiters[] = " .,\n\t\r";
    char *token;
    int count = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        str_trim(line);  
        str_lower(line); 
        token =strtok(line, delimiters);
        while (token != NULL) {
            if (count >0) {
                strcat(dictionary, ",");
            }
            strcat(dictionary, token);            
            token = strtok(NULL, delimiters);
            count++;
        }
    }

    return count;
}
/*
 * Determine if a given word is contained in the given dictionary.  
 * 
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.  
 *                     
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.   
 */
BOOLEAN contain_word(char *dictionary, char *word) {
	 if (word == NULL || *word == '\0') {
	        return 0;

	    }
	    char temp[100] = "";
	    snprintf(temp, sizeof(temp), ",%s,", word);
	    if (strstr(dictionary, temp) != NULL) {
	        return TRUE;

	    } else {
	        return FALSE;

	    }
}

/*
 * Process text data from a file for word statistic information of line count, word count, keyword count, and frequency of keyword.   
 * 
 * @param *fp -  FILE pointer of input text data file. .
 * @param *words  -  WORD array for keywords and their frequencies.
 * @param *dictionary  -  stop-word/common-word dictionary.    
 *                     
 * @return - WORDSTATS value of processed word stats information.   
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
    	WORDSTATS ans = {0};
	    char line[MAX_LINE_LEN];
	    char *token;
	    char delimiters[] = " .,\n\t\r";
	    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
	        ans.line_count++;
	        str_lower(line);
	        token = strtok(line, delimiters);
	        while (token != NULL) {
	            ans.word_count++;
	            if (contain_word(dictionary, token) == FALSE) {
	                int j = 0;
	                while (j< ans.keyword_count && strcmp(token, words[j].word) != 0) {
	                    j++;
	                }

	                if (j < ans.keyword_count) {
	                    words[j].count++;
	                } else {
	                    strcpy(words[j].word, token);
	                    words[j].count =1;
	                    ans.keyword_count++;
	                }
	            }



	            token =strtok(NULL, delimiters);
	        }
	    }

	    return ans;
}
//gcc myword.c -o q2 