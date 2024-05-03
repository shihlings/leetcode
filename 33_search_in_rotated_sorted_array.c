//
//  main.c
//  33_search_in_rotated_sorted_array
//
//  Created by Shih-Ling Shen on 2022-12-11.
//

#include <stdio.h>

#define NONE -1

int search(int* nums, int numsSize, int target);

//no main function. see LeetCode.
int main(void) {
    return 0;
}

/* Purpose: Search for an element in an array
 * Params:  nums -      array of number to search in
 *          numsSize -  size of the array, nums
 *          target -    the target value to search for in nums
 * Return:  Index of the element that is equal to target
 */
int search(int* nums, int numsSize, int target){
    //sets default value of found_index to NONE
    int found_index = NONE;

    //compare elements one by one until found
    for (int index = 0; index < numsSize && found_index == NONE; ++index) {
        //if element at index is equal to target, save the location
        if (nums[index] == target) {
            found_index = index;
        }
    }

    return found_index;
}
