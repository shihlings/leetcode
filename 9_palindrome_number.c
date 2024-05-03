//
//  main.c
//  9_palindrome_number
//
//  Created by Shih-Ling Shen on 2022-12-13.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
//leetcode has bool in their version of C, modified to compile in Xcode.
#define bool int

//no main function. Test in LeetCode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Check if a number is Palindrome
 * Params:  x   - integer to check
 * Return:  1 if true, 0 if false
 */
bool isPalindrome(int x){
    //impossible to have a negative number that is palindrome (the '-')
    if(x < 0) {
        return FALSE;
    }
    //only check if x is positive
    else {
        //initialize palindrome indicator as true
        int palindrome = TRUE;
        //minimum length leetcode requires
        int length = 11;
        //allocate array to store integer by characters
        char *x_array = malloc(length * sizeof(char));

        //stores integer as individual character and terminates with NULL
        for(int index = 0; index < length - 1; ++index) {
            x_array[index] = (x % 10 + '0');
            x /= 10;

            //if there are no more numbers, terminate with NULL and save index location
            if(x == 0) {
                x_array[index + 1] = '\0';
                length = index + 1;
            }
        }

        //check if number is palindrome
        for(int index = 0; index < length && palindrome == TRUE; ++index) {
            //if front is equal to opposite, number is palindrome
            if (x_array[index] != x_array[length - 1 - index]) {
                palindrome = FALSE;
            }
        }

        return palindrome;
    }
}
