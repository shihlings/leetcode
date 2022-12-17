//
//  main.c
//  1137_n-th_tribonacci_number
//
//  Created by Shih-Ling Shen on 2022-12-12.
//

#include <stdio.h>

//test code only. Test in LeetCode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Calculate the nth iteration fo tribonacci number
 * Params:  n - the iteration number
 * Return:  the nth iteration fo tribonacci number
 */
 int tribonacci(int n){
    //initial conditions for the tribonacci number
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 1;
    }

    //setting up intial contions for n >= 3
    //starting at n = 3, n = 2 => tribonacci(2), n = 1 => tribonacci(1), n = 1 => tribonacci(0)
    int tribonacci_num = 0;
    int prev_num1 = tribonacci(2);
    int prev_num2 = tribonacci(1);
    int prev_num3 = tribonacci(0);

    for(int iterations = 3; iterations <= n; ++iterations) {
        //the fib_num is the three previous added together
        tribonacci_num = prev_num1 + prev_num2 + prev_num3;

        //reset the previous terms to new ones
        prev_num3 = prev_num2;
        prev_num2 = prev_num1;
        prev_num1 = tribonacci_num;
    }

    return tribonacci_num;
}
