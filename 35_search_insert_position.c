//
//  main.c
//  35_search_insert_position
//
//  Created by Shih-Ling Shen on 2022-12-11.
//

#include <stdio.h>

#define NONE -1

//no main function. See LeetCode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Locates the position the insert the number
 * Params:  nums -      the array to search in
 *          numsSize -  size of the array, numsSize
 *          target -    target number to be inserted
 * Return:  the index to insert the number target
 */
int searchInsert(int* nums, int numsSize, int target){
    //defaults the insert position to non-exisiting index
    int insert_position = NONE;

    //if target is smaller than smallest element of the array position is the front
    if(target < nums[0]) {
        insert_position = 0;
    }

    //search until EOF or the location is found
    for(int index = 0; index < numsSize && insert_position == NONE; ++index) {
        //if exact match, save the current position
        if(nums[index] == target) {
            insert_position = index;
        }
        //if next number is not EOF, and
        //next number is greater than target number, assign index to insert position
        else if (index + 1 < numsSize && nums[index + 1] > target) {
            insert_position = index + 1;
        }
    }

    //if EOF, and no position is found, insert at the end
    if(insert_position == NONE) {
        insert_position = numsSize;
    }

    return insert_position;
}
