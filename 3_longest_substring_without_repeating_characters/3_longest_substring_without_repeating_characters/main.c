//
//  main.c
//  3_longest_substring_without_repeating_characters
//
//  Created by Shih-Ling Shen on 2022-12-16.
//

#include <stdio.h>

#define NONE -1

int max(int num1, int num2);
int search(char *array, char target, int start_index);
int lastNonRepeat(char *array, int index);
int lengthOfLongestSubstring(char * s);

//No main function. Test in Leetcode.
int main(int argc, const char * argv[]) {
    return 0;
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

/* Purpose: Search for an element in an array before the starting index
 * Params:  array -       the array to search in
 *          target -      the target character to search for in array
 *          start_index - the starting index to search from
 * Return:  Index of the element that is equal to target
 */
int search(char *array, char target, int start_index){
    //sets default value of found_index to NONE
    int found_index = NONE;

    //compare elements one by one until found
    for (int index = start_index - 1; start_index >= 0 && found_index == NONE; --index) {
        //if element at index is equal to target, save the location
        if (array[index] == target) {
            found_index = index;
        }
    }

    return found_index;
}

int lastNonRepeat(char *array, int index) {
    if (index == 0) {
        return 0;
    }
    
    for (;index >= 0 && search(array, array[index], index) == NONE; --index);

    return index;
}

int lengthOfLongestSubstring(char * s){
    int length = 0;

    for (int index = 0; s[index] != '\0'; ++index) {
        int temp_length = 0;

        temp_length = index - lastNonRepeat(*s, index) + 1;

        length = max(length, temp_length);
    }

    return length;
}
