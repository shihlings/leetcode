//
//  main.c
//  4_median_of_two_sorted_arrays
//
//  Created by Shih-Ling Shen on 2022-12-11.
//

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);
void sortArray (int* nums, int numsSize);

//no function main. Test in leetcode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Finds the median of the two arrays
 * Params:  nums1     - address to the first number array
 *          nums1Size - Size of the array, nums2
 *          nums2     - address to the second number array
 *          nums2Size - Size of the array, nums2
 * Return:  median    - the median of the two arrays
 */
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    //create an array to include all numbers from nums1 and nums2
    int fullarraySize = nums1Size + nums2Size;
    int *fullarray = malloc(fullarraySize * sizeof (int));
    
    //set default median return to 0
    double median = 0;
    
    //adds nums1 into fullarray
    for (int index = 0; index < nums1Size; ++index) {
        fullarray[index] = nums1[index];
    }
    //adds nums2 into fullarray
    for (int index = 0; index < nums2Size; ++index) {
        fullarray[index + nums1Size] = nums2[index];
    }
    
    //sorts fullarray
    sortArray(fullarray, fullarraySize);
    
    //if there is odd number of elements, median is the center element
    if ((fullarraySize % 2) != 0) {
        median = (double) fullarray[fullarraySize / 2];
    }
    //if there is even number of elements, median is the two center elements averaged
    else {
        median = (double) (fullarray[fullarraySize / 2  - 1] + fullarray[fullarraySize / 2]) / 2.0;
    }
    
    //free address malloc to fullarray
    free(fullarray);
    
    return median;
}

/* Purpose: sorts array in acending order (alters array directly)
 * Params:  nums     - address to the array
 *          numsSize - Size of the array, nums
 * Return:  void (nothing)
 */
void sortArray (int* nums, int numsSize) {
    int target;
    
    //sort array using insertion sort
    //starts from second element as there must be at least one element to compare with
    for (int index = 1; index < numsSize; ++index){
        //targets number at index
        target = nums[index];
        
        //set first compared number to the one right before target
        int compare_index = index - 1;
        
        //compare if numbers before target are larger
        while (compare_index >= 0 && nums[compare_index] > target) {
            //push back elements by one space if they are larger
            nums[compare_index + 1] = nums[compare_index];
            --compare_index;
        }
        
        //inserts target back to array, in front of the larger numbers
        nums[compare_index + 1] = target;
    }
}
