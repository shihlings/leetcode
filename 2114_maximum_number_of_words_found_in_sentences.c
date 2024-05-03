//
//  main.c
//  2114_maximum_number_of_words_found_in_sentences
//
//  Created by Shih-Ling Shen on 2022-12-18.
//

#include <stdio.h>

#define NONE -1

//no main function. Test in leetcode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Find the maximum of the two numbers
 * Params:  num1 -  First number to compare
 *          num2 -  Second number to compare
 * Return:  the maximum of the two numbers
 */
int max(int num1, int num2) {
    //if num1 is larger, early return num1
    if (num1 > num2) {
        return num1;
    }
    //return num2 if num1 is not larger
    return num2;
}

/* Purpose: Search for an element in a string
 * Params:  string -    the string to search in
 *          target -    the target value to search for in the string
 *          index -     the index to start the search
 * Return:  Index of the element that is equal to target
 */
int search(char* string, int target, int index){
    //sets default value of found_index to NONE
    int found_index = NONE;

    //compare elements one by one until found
    for (; string[index] != '\0' && found_index == NONE; ++index) {
        //if element at index is equal to target, save the location
        if (string[index] == target) {
            found_index = index;
        }
    }

    return found_index;
}

/* Purpose: Calculate the maximum words in the array of sentences
 * Params:  **sentences -       array containing addresses to the strings containing the sentences
 *          sentencesSize -     size of the array containing the addresses
 * Return:  the maximum amounts of words
 */
int mostWordsFound(char ** sentences, int sentencesSize){
    int max_words = 0;

    for (int index = 0; index < sentencesSize; ++index) {
        int count = 0;
        int space_index = 0;

        //continue to detect white space in the string, each white space indicates 1 additonal word
        while (space_index != NONE) {
            space_index = search(sentences[index], ' ', space_index + 1);
            ++count;
        }

        //compare the maximum and the current and store the larger in max_words
        max_words = max(max_words, count);
    }

    return max_words;
}
