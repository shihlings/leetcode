//
//  main.c
//  1_two_sum
//
//  Created by Shih-Ling Shen on 2022-12-11.
//

#include <stdio.h>
#include <stdlib.h>

//defaulting return [-2,-2] if no answer could be found
#define NONE -2

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

//test code in main, change only the declared variables
int main(int argc, const char * argv[]) {
    //declared variables, do not modify anything else other than these variables
    int numsSize = 10;
    int nums[] = {1,2,3,4,5,6,7,8,9,10};
    int target = 19;
    
    //do not modify anything below
    int *returnSize = malloc(sizeof(int));
    
    int *solution = twoSum(nums, numsSize, target, returnSize);
    
    printf("[%d,%d]\n", solution[0], solution[1]);
    
    free(solution);
    free(returnSize);
    
    return 0;
}

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* Purpose: Finds two elements in an array that add up to the target number
 * Params:  nums -          array containing numbers
 *          numsSize -      size of nums
 *          target -        the target number to be added to
 *          returnSize -    size of the returned array
 * Return:  address to an array that is malloced, contains the index of the
 *          two numbers in the array nums that can add up to target
 *          Default returns [-2,-2] if no solution is found.
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *solution = malloc(*returnSize * sizeof(int));
    
    solution[0] = NONE;
    solution[1] = NONE;

    for (int index = 0; index < numsSize && solution[0] != (index - 1); ++index) {
        int remain = target - nums[index];
        for (int index_find = index + 1; index_find < numsSize; ++index_find) {
            if (nums[index_find] == remain) {
                solution[0] = index;
                solution[1] = index_find;
            }
        }
    }

    return solution;
}
