//
//  main.c
//  1480_running_sum_of_1d_array
//
//  Created by Shih-Ling Shen on 2022-12-18.
//

#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize);

//No main function. Test in leetcode.
int main(int argc, const char * argv[]) {
    return 0;
}

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* Purpose: Calculate the running sum of an array
 * Params:  *nums -        array containing numbers to calculate the sum of
 *          numsSize -     the size of the array, nums
 *          *returnSize -  pointer to the location where the size of the return array is stored
 * Return:  the address to the array containing the running sum of the array, nums
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    //the size of the return array must be the same as the initial array, nums
    *returnSize = numsSize;
    int *running_sum = malloc(*returnSize * sizeof(int));

    //first element remains the same, left out of loop to reduce ifs in loop
    running_sum[0] = nums[0];
    for (int index = 1; index < numsSize; ++index) {
        //the running sum is new number added to the previous sum
        running_sum[index] = running_sum[index - 1] + nums[index];
    }

    return running_sum;
}
