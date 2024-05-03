//
//  main.c
//  34_find_first_and_last_position_of_element_in_sorted_array
//
//  Created by Shih-Ling Shen on 2022-12-11.
//

#include <stdio.h>
#include <stdlib.h>

#define NONE -1

int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main(int argc, const char * argv[]) {
    int nums[] = {1,2,7,7,7,7,7,8};
    int numsSize = 8;
    int target = 7;
    
    int *returnSize = malloc(sizeof(int));
    int *position = searchRange(nums, numsSize, target, returnSize);
    
    printf("[%d,%d]\n", position[0], position[1]);
    
    free(position);
    free(returnSize);
    
    return 0;
}

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* Purpose: Search an array for elements and return the range that it is found
 * Params:  *nums -      the array to search in
 *          *numsSize -  the size of the array, nums
 *          target -     the target number to search for
 *          returnSize - the size of the return array
 * Return:  The index of the start and end the element is found in the array, if none [-1,-1]
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    //sets returnSize to 2
    *returnSize = 2;
    
    //initialize return array to default [-1,-1]
    int *position = malloc(*returnSize * sizeof(int));
    position[0] = NONE;
    position[1] = NONE;

    //search until EOF or start and end determined
    for(int index = 0; index < numsSize && nums[index] <= target; ++index) {
        //save start position if found matches
        if(position[0] == NONE && nums[index] == target) {
            position[0] = index;
        }
        
        //save end position if next array element is no longer matching
        if(position[0] != NONE && index + 1 < numsSize && nums[index + 1] != target) {
            position[1] = index;
        }
    }

    //save the last element of the array as end position
    //if the array seach is complete and no end position was saved
    if(position[0] != NONE && position[1] == NONE) {
        position[1] = numsSize - 1;
    }

    return position;
}
