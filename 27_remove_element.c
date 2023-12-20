//
//  main.c
//  27_remove_element
//
//  Created by Shih-Ling Shen on 2022-12-13.
//

#include <stdio.h>

void pushforwardArray(int *array, int *array_size, int index, int target_index);
int removeElement(int* nums, int numsSize, int val);

//no main function. Test in LeetCode
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
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

/* Purpose: Remove a target element from the array
 * Params:  *nums -         array to be modified
 *          numsSize -      the size of the array passed
 *          val -           the target element to remove
 * Return:  the final size of the array
 */
int removeElement(int* nums, int numsSize, int val) {
    //go through each element and check
    for (int index = 0; index < numsSize; ++index) {
        if (nums[index] == val) {
            //if last element, remove from scope of the array
            if (index + 1 == numsSize) {
                --numsSize;
            }
            //if matched, remove
            else {
                pushforwardArray(nums, &numsSize, index + 1, index);
                --index;
            }
            
        }
    }

    return numsSize;
}
