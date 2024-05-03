//
//  main.c
//  1221_split_a_string_in_balanced_strings
//
//  Created by Shih-Ling Shen on 2022-12-18.
//

#include <stdio.h>

int balancedStringSplit(char * s);

//Test code only. See leetcode
int main(int argc, const char * argv[]) {
    char *string = "RLRRLLRLRL";
    
    printf("%d\n", balancedStringSplit(string));
    
    return 0;
}

/* Purpose: Find the maximum number of balanced strings that can be obtained from the string
 * Params:  s - the string (contains only R and L)
 * Return:  the total number of balanced strings that can be obtained
 */
int balancedStringSplit(char * s){
    int total = 0;
    int numl = 0;
    int numr = 0;
    
    for (int index = 0; s[index] != '\0'; ++index) {
        //count number of Ls and Rs
        if (s[index] == 'L') {
            ++numl;
        }
        else {
            ++numr;
        }

        //once Ls and Rs are equal and both are not 0, it counts as one string, resets counters
        if (numr > 0 && numr == numl) {
            ++total;
            numr = 0;
            numl = 0;
        }
    }

    return total;
}
