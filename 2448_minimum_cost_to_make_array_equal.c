//
//  main.c
//  2448_minimum_cost_to_make_array_equal
//
//  Created by Shih-Ling Shen on 2022-11-02.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void sortArray (int* nums, int numsSize, int* cost);
long long sumArray(int* cost, int costSize);
int searchIndex(int* cost, int costSize, long double target);
long long minCost(int* nums, int numsSize, int* cost, int costSize);

//no main function. Test in LeetCode.
int main(void) {
    return 0;
}

/* Purpose: sorts array in acending order (alters array directly), cost array is altered with nums as associated costs
 * Params:  nums     - address to the array
 *          numsSize - Size of the array, nums
 *          cost     - address to the cost array
 * Return:  void (nothing)
 */
void sortArray (int* nums, int numsSize, int* cost) {
    int target;
    int target_cost;
    
    //sort array using insertion sort
    //starts from second element as there must be at least one element to compare with
    for (int index = 1; index < numsSize; ++index){
        //targets number at index
        target = nums[index];
        target_cost = cost[index];
        
        //set first compared number to the one right before target
        int compare_index = index - 1;
        
        //compare if numbers before target are larger
        while (compare_index >= 0 && nums[compare_index] > target) {
            //push back elements by one space if they are larger
            nums[compare_index + 1] = nums[compare_index];
            cost[compare_index + 1] = cost[compare_index];
            --compare_index;
        }
        
        //inserts target back to array, in front of the larger numbers
        nums[compare_index + 1] = target;
        cost[compare_index + 1] = target_cost;
    }
}

/* Purpose: finds the sum of an array
 * Params:  nums     - target array to sum
 *          numsSize - the size of array, rums
 * Return:  sum of all elements in array
 */
long long sumArray(int* nums, int numsSize){
    //sets total to 0
    long long sum = 0;
    
    //add each element to sum to get total
    for(int index = 0; index < numsSize; ++index){
        sum += nums[index];
    }
    
    return sum;
}

/* Purpose: Finds the element in the array which the sum of the array before (inclusive) that element is equal to target
 * Params:  cost     - array containing the cost to alter each element in nums
 *          costSize - size of the array, cost
 *          target   - the target amount
 * Return:  the index of elemnt which the sum of the array before (inclusive) that element is equal to target
 */
int searchIndex(int* cost, int costSize, long double target){
    //set the current index to 0
    int index = 0;

    //found indicator is not found
    int found = FALSE;
    
    //continue iterating until the index of the element is found
    for (;index < costSize && found == FALSE; ++index) {
        //deduct the cost at index from target until it reaches below (or equal) 0
        target -= cost[index];
        if (target <= 0) {
            found = TRUE;
        }
    }
    
    //returns the index reduced by one (compensate for the extra added from the for loop)
    return index - 1;
}

/* Purpose: Finds the minimum cost to make the array equal
 * Params:  nums     - the array to make equal
 *          numsSize - size of the array, nums
 *          cost     - array containing the cost to alter each element in nums
 *          costSize - size of the array, cost
 * Return:  the minimum cost to make array equal
 */
long long minCost(int* nums, int numsSize, int* cost, int costSize){
    //sorts the array from in ascending order, cost is altered to associate costs to nums
    sortArray (nums, numsSize, cost);
    
    //the target_cost is half of the total cost
    long double target_cost = sumArray(cost, costSize) / 2.0;
    
    //uses the target_cost to find the index of the number that should be targeted
    int target_index = searchIndex(cost, costSize, target_cost);
    
    //sets the minimum cost to 0
    long long minicost = 0;
    
    //finds the total cost
    for (int index = 0; index < numsSize; ++index){
        //adds the cost to alter each element to the value of nums[target_index]
        minicost += (long long) cost[index] * (long long) abs(nums[target_index] - nums[index]);
    }
    
    return minicost;
}
