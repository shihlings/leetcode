//
//  main.c
//  88_merge_sorted_array
//
//  Created by Shih-Ling Shen on 2022-12-16.
//

#include <stdio.h>

void sortArray (int* array, int array_size);
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

//no main function. Test in LeetCode
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: sorts array in acending order (alters array directly)
 * Params:  array       - address to the array
 *          array_size  - Size of the array, nums
 * Return:  void (nothing)
 */
void sortArray (int* array, int array_size) {
    int target;
    
    //sort array using insertion sort
    //starts from second element as there must be at least one element to compare with
    for (int index = 1; index < array_size; ++index){
        //targets number at index
        target = array[index];
        
        //set first compared number to the one right before target
        int compare_index = index - 1;
        
        //compare if numbers before target are larger
        while (compare_index >= 0 && array[compare_index] > target) {
            //push back elements by one space if they are larger
            array[compare_index + 1] = array[compare_index];
            --compare_index;
        }
        
        //inserts target back to array, in front of the larger numbers
        array[compare_index + 1] = target;
    }
}

/* Purpose: Merges 2 arrays into 1 and sorts them in ascending order
 * Params:  nums1       - the first array (must be of the size of the resulting array)
 *          nums1Size   - the total size of the resulting array
 *          m           - number of useable elements in nums1
 *          nums2       - the second array (to be merged into nums1)
 *          nums2Size   - the size of nums2
 *          n           - number of useable elements in nums 2 (should be equal to nus2Size)
 * Return:  nothing (void), the resulting array is directly stored in nums1
 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    //adds the elements of nums2 to the end of nums1
    for (int index = 0; index < nums2Size; ++index) {
        nums1[m + index] = nums2[index];
    }

    //sorts the array to increasing order
    sortArray(nums1, nums1Size);
}
