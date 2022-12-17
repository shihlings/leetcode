//
//  main.c
//  509_fibonacci_number
//
//  Created by Shih-Ling Shen on 2022-12-12.
//

#include <stdio.h>

//no main function. Test in LeetCode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Calculate the nth iteration fo fibonacci number
 * Params:  n - the iteration number
 * Return:  the nth iteration fo fibonacci number
 */
 int fib(int n){
    //initial conditions for the fibonacci number
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    //setting up intial contions for n >= 2
    //starting at n = 2, n = 1 => fib(1), n = 0 => fib(0)
    int fib_num = 0;
    int prev_num1 = fib(1);
    int prev_num2 = fib(0);

    for(int iterations = 2; iterations <= n; ++iterations) {
        //the fib_num is the two previous added together
        fib_num = prev_num1 + prev_num2;

        //reset the previous terms to new ones
        prev_num2 = prev_num1;
        prev_num1 = fib_num;
    }

    return fib_num;
}
