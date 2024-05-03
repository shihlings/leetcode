//
//  main.c
//  29_divide_two_integers
//
//  Created by Shih-Ling Shen on 2022-12-10.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE        1
#define FALSE       0
#define INT_MAX     2147483647
#define INT_MIN     -2147483648
#define INT_MIN_ABS 2147483648

int divide(long long dividend, long long divisor);
void changeToPositive(long long num1, long long num2, unsigned int *num1P, unsigned int *num2P, int *oppo_sign);
int shiftRightUntilZero(unsigned int num);

int main(int argc, const char * argv[]) {
    int dividend = -2147483648;
    int divisor = 1;
    
    printf("%i", divide(dividend, divisor));
    
    return 0;
}

/* Purpose: Divide two integers and return the resulting integer
 * Params:  dividend - the dividend of the equation
 *          divisor - the divisor of the equation
 * Return:  the solution the the equation, if it overflows int, return the max/min of int
 */
int divide(long long dividend, long long divisor){
    unsigned int solution = 0;
    unsigned int dividendP = 0;
    unsigned int divisorP = 0;
    int oppo_sign = FALSE;
    
    //change all numbers to positive
    changeToPositive(dividend, divisor, &dividendP, &divisorP, &oppo_sign);
    
    //determine if two numbers are equal
    if (divisorP == dividendP) {
        //if equal and opposite sign, answer is -1, return early
        if (oppo_sign == TRUE) {
            return -1;
        }
        //if equal and same sign, answer is 1, return early
        return 1;
    }
    
    //determine the number of bit shifts allowed without overflow
    int max_shift = shiftRightUntilZero(divisorP);
    
    for (int index = 32 - max_shift; index >= 0 && divisorP <= dividendP; --index) {
        //if the divisor shifted left by index, the dividend can be divided by divisor << index
        if ((divisorP << index) <= dividendP) {
            //subtract divisor << index from dividend
            dividendP -= (divisorP << index);
            //add 1 << index to solution
            solution += ((unsigned int) 1 << index);
        }
    }
    
    //if two numbers are opposite sign, solution should be negative
    if (oppo_sign == TRUE) {
        //if integer overflows, return the minimum
        if (solution > INT_MIN_ABS) {
            return INT_MIN;
        }
        
        //return the negative of solution if it doesn't overflow
        return solution * -1;
    }
    
    //if the number is postive and overflows, return the maximum
    if (solution > INT_MAX) {
        return INT_MAX;
    }
    
    //return the solution directly if not negative, and does not overflow
    return solution;
}

/* Purpose: Change numbers to positive, and determine if the two are same sign
 * Params:  num1 -         original num1
 *          num2 -         original num2
 *          *num1P -        num1 in positive form
 *          *num2P -        num2 in positive form
 *          *oppo_sign -    indicator if the two numbers are opposite sign
 */

void changeToPositive(long long num1, long long num2, unsigned int *num1P, unsigned int *num2P, int *oppo_sign){
    //if both negative, change both to positive
    if (num1 < 0 && num2 < 0) {
        *num1P = (int) (num1 * -1);
        *num2P = (int) (num2 * -1);
        //same sign
        *oppo_sign = FALSE;
    }
    //change to positive, and opposite sign is true
    else if (num1 < 0 && num2 > 0) {
        *num1P = (int) (num1 * -1);
        *num2P = (int) num2;
        *oppo_sign = TRUE;
    }
    else if (num2 < 0 && num1 > 0) {
        *num1P = (int) num1;
        *num2P = (int) (num2 * -1);
        *oppo_sign = TRUE;
    }
    //both positive, oppo_sign is false
    else {
        *num1P = (int) num1;
        *num2P = (int) num2;
        *oppo_sign = FALSE;
    }
}

/* Purpose: Determine the number of shifts required to make number zero
 * Params:  num - the number to be shifted
 * Return:  number of shifts required, if exceed 31, return 31
 */
int shiftRightUntilZero(unsigned int num) {
    int shifts = 0;
    
    //increase number of shifts until divisorP >> shifts will be zero
    //stop at 31 since int will overflow beyond 31
    while ((num >> shifts) != 0 && shifts < 31) {
        ++shifts;
    }
    
    return shifts;
}
