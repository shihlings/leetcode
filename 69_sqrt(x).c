//
//  main.c
//  69_sqrt(x)
//
//  Created by Shih-Ling Shen on 2022-12-15.
//

#include <stdio.h>

//no main function. Test in leetcode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Find the square root of an integer
 * Params:  x - the integer to find the sqaure root of
 * Return:  the integer square root of x
 */
int mySqrt(int x){
    unsigned int root = 0;

    //continue increasing the value of root until it is larger than x
    do {
        ++root;
    } while (root * root <= x);

    //compensate for the extra that causes it to be larger than x
    return root - 1;
}
