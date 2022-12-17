//
//  main.c
//  1221-split-a-string-in-balanced-strings
//
//  Created by Shih-Ling Shen on 2022-12-17.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

int balancedStringSplit(char * s){
    int total = 0;
    int numl = 0;
    int numr = 0;
    
    for (int index = 0; s[index] != '\0'; ++index) {
        if (index == 'L') {
            ++numl;
        }
        else {
            ++numr;
        }

        if (numr > 0 && numr == numl) {
            ++total;
            numr = 0;
            numl = 0;
        }
    }

    return total;
}
