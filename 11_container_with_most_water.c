//
//  main.c
//  11_container_with_most_water
//
//  Created by Shih-Ling Shen on 2022-12-12.
//

#include <stdio.h>

int maxArea(int* height, int heightSize);
int max(int num1, int num2);
int min(int num1, int num2);

//no main function. Test in LeetCode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Find the maximum area the array bars can contain
 * Params:  *height -    array containing the heights of each bar
 *          heightSize - size of the array, height
 * Return:  the maximum area contained in the array bars
 */
int maxArea(int* height, int heightSize){
    //initialize the variable storage for the maximum area to 0 (area cannot be negative)
    int max_area = 0;
    int right_bound = heightSize - 1;
    int left_bound = 0;

    //start from the wides rectangle
    while (left_bound < right_bound) {
        //calculate the area of the current configuration & store the maximum
        int area = min(height[left_bound], height[right_bound]) * (right_bound - left_bound);
        max_area = max(max_area, area);

        //try to maintain the tallest bar to allow maximum area, try a new bound if smaller
        if (height[left_bound] > height[right_bound]) {
            --right_bound;
        }
        else {
            ++left_bound;
        }
    }

    return max_area;
}

/* Purpose: Find the maximum of the two numbers
 * Params:  num1 -  First number to compare
 *          num2 -  Second number to compare
 * Return:  the maximum of the two numbers
 */
int max(int num1, int num2) {
    //if num1 is larger, early return num1
    if (num1 > num2) {
        return num1;
    }
    //return num2 if num1 is not larger
    return num2;
}

/* Purpose: Find the minimum of the two numbers
 * Params:  num1 -  First number to compare
 *          num2 -  Second number to compare
 * Return:  the minimum of the two numbers
 */
int min(int num1, int num2) {
    //if num1 is smaller, early return num1
    if(num1 < num2) {
        return num1;
    }
    //return num2 if num1 is not smaller
    return num2;
}
