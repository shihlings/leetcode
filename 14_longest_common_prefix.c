//
//  main.c
//  14_longest_common_prefix
//
//  Created by Shih-Ling Shen on 2022-12-13.
//

#include <stdio.h>

//no main function. Test in leetcode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Check for the longest common prefix of a series of string
 * Params:  strs        - array containing addresses to strings
 *          strsSize    - number of strings to check
 * Return:  The longest common prefix in a string
 */
char * longestCommonPrefix(char ** strs, int strsSize){
    //read the each one and compare to the first string
    for (int current_string = 1; current_string < strsSize; ++current_string) {
        char *string = strs[current_string];
        char *compare = strs[0];

        //if the first string is empty, force quit the loop
        if (compare[0] == '\0') {
            current_string = strsSize;
        }
        else {
            //if the string to be compared is empty, empty the first string and force quit the loop
            if (string[0] == '\0') {
                compare[0] = '\0';
                current_string = strsSize;
            }
            else {
                //check each element and compare if is the same
                for (int index = 0; string[index] != '\0' && compare[index] != '\0'; ++index) {
                    //if difference is found, terminate the first string at current index
                    if (compare[index] != string[index]) {
                        compare[index] = '\0';
                    }
                    //if the string to be compared terminates earlier, terminate the first string at the same index
                    else if (string[index + 1] == '\0') {
                        compare[index + 1] = '\0';
                    }
                }
            }
        }
    }

    return strs[0];
}
