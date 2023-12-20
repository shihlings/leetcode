//
//  main.c
//  70_climbing_stairs
//
//  Created by Shih-Ling Shen on 2022-12-12.
//

#include <stdio.h>

//no main function. Test in LeetCode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Calculate the ways to climb a number of stairs
 * Params:  n - number of stairs
 * Return:  The number of ways
 */
int climbStairs(int n) {
    //there is only one possibility if there is one stair
    if (n == 1) {
        return 1;
    }
    //there is only two possibilities if there is two stairs
    if (n == 2) {
        return 2;
    }

    //setting up intial contions for n > 3
    //starting at n = 3, n = 2 => 2, n = 1 => 1
    int ways = 0;
    int prev1 = climbStairs(2);
    int prev2 = climbStairs(1);

    for(int iteration = 3; iteration <= n; ++iteration) {
        //the current ways is the two previous added together
        ways = prev1 + prev2;

        //reset the previous terms to new ones
        prev2 = prev1;
        prev1 = ways;
    }

    return ways;
}
