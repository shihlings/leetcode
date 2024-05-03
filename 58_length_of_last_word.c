//
//  main.c
//  58_length_of_last_word
//
//  Created by Shih-Ling Shen on 2022-12-14.
//

#include <stdio.h>

int lengthOfLastWord(char * s);

//no main function. Test in leetcode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Determine the length of the last word in a string
 * Params:  *s - the string to examine
 * Return:  the length of the last word
 */
int lengthOfLastWord(char * s) {
    int length = 0;
    int index = 0;

    //examine first character in the string
    if (s[index] != ' ') {
        ++index;
        ++length;
    }

    while (s[index] != '\0') {
        if (s[index] != ' ') {
            //reset the counter if a space was typed before a character
            if (s[index - 1] == ' ') {
                length = 0;
            }
            //increase the length for every character found
            ++length;
        }

        ++index;
    }

    return length;
}
