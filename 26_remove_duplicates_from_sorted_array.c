//
//  main.c
//  26_remove_duplicates_from_sorted_array
//
//  Created by Shih-Ling Shen on 2022-12-13.
//

#include <stdio.h>

void pushforwardArray(int *array, int *array_size, int index, int target_index);
int removeDuplicates(int* nums, int numsSize);

int main(int argc, const char * argv[]) {
    int numsSize = 20;
    int nums[] = {1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,3,3,3,4,4,4};
    
    int result_size = removeDuplicates(nums, numsSize);
    printf("%d\n[", result_size);
    for (int index = 0; index < result_size; ++index) {
        printf("%d", nums[index]);
        if (index != result_size - 1) {
            printf(",");
        }
    }
    printf("]\n");
    
    return 0;
}

/* Purpose: Push forward array to right after the target index
 * Params:  *array -        array to be modified
 *          *array_size -   the size of the array passed
 *          index -         the start point to be pushed forward
 *          target_index -  the target location to be pushed to
 * Return:  nothing (void)
 */
void pushforwardArray(int *array, int *array_size, int index, int target_index) {
    do {
        array[target_index] = array[index];
        ++index;
        ++target_index;
    } while(index < *array_size);
    
    //adjust the array to the new size
    *array_size = target_index;
}

/* Purpose: Remove duplicates from a sorted array (in ascending order)
 * Params:  *nums -         array to be modified
 *          numsSize -      the size of the array passed
 * Return:  the final size of the array
 */
int removeDuplicates(int *nums, int numsSize) {
    //go through each element and check
    for (int index = 1; index < numsSize; ++index) {
        //if duplicate, remove
        if (nums[index] == nums[index - 1]) {
            pushforwardArray(nums, &numsSize, index, index - 1);
            --index;
        }
    }

    return numsSize;
}
