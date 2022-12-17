//
//  main.c
//  66_pius_one
//
//  Created by Shih-Ling Shen on 2022-12-16.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//no main function. Test in leetcode
int main(int argc, const char * argv[]) {
    return 0;
}

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* Purpose: Add one to the number represented in an array
 * Params:  *digits     - the array containing the number
 *          digitsSize  - the size of the array, digits
 *          *returnSize - the size of the return array
 * Return:  A malloced array that is incremented by one compared to digits
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int need_extra = TRUE;
    *returnSize = digitsSize;

    //determining if the returnSize needs to be increased
    for (int index = digitsSize - 1; index >= 0 && need_extra == TRUE; --index){
        //Only if the whole array consists of 9, the array will increase in size
        if (digits[index] != 9) {
            need_extra = FALSE;
        }
    }
    
    //increment size if required
    if (need_extra == TRUE) {
        ++*returnSize;
    }

    //malloc the array with returnSize
    int *incremented = malloc(*returnSize * sizeof(int));

    for (int index = *returnSize - 1, not_complete = TRUE; index >= 0; --index) {
        //if at the end and extra digit is required, make it 1
        if (need_extra == TRUE && index == 0) {
            incremented[index] = 1;
        }
        //if not complete and encounters a nine, change it to 0 and increment the next digit
        else if (digits[index - need_extra] == 9 && not_complete == TRUE) {
            incremented[index] = 0;
        }
        else {
            //increments digit if the array is not complete, copies if it is complete
            incremented[index] = digits[index - need_extra] + not_complete;
            not_complete = FALSE;
        }
    }

    return incremented;
}
