//
//  main.c
//  1528_shuffle_string
//
//  Created by Shih-Ling Shen on 2022-12-18.
//

#include <stdio.h>

void sortArray (int *array, char *tagging_array, int array_size);
char *restoreString(char * s, int* indices, int indicesSize);

//no main function. Test in leetcode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: sorts array in acending order (alters array directly)
 * Params:  array         - address to the array to be sorted
 *          tagging_array -  array to be sorted along with the 'array'
 *          array_size  - Size of the array, 'array'
 * Return:  void (nothing)
 */
void sortArray (int *array, char *tagging_array, int array_size) {
    int target;
    char target_tagged;

    //sort array using insertion sort
    //starts from second element as there must be at least one element to compare with
    for (int index = 1; index < array_size; ++index){
        //targets number at index
        target = array[index];
        target_tagged = tagging_array[index];
        
        //set first compared number to the one right before target
        int compare_index = index - 1;
        
        //compare if numbers before target are larger
        while (compare_index >= 0 && array[compare_index] > target) {
            //push back elements by one space if they are larger
            array[compare_index + 1] = array[compare_index];
            tagging_array[compare_index + 1] = tagging_array[compare_index];
            --compare_index;
        }
        
        //inserts target back to array, in front of the larger numbers
        array[compare_index + 1] = target;
        tagging_array[compare_index + 1] = target_tagged;
    }
}

/* Purpose: Restores the string according to the indices provided
 * Params:  s -           the string to be restored
 *          indices -     array containing the indices
 *          inicesSize -  Size of the indices array
 * Return:  array to the restored string
 */
char *restoreString (char * s, int* indices, int indicesSize) {
    //sorts the string according to the indices in accending order
    sortArray(indices, s, indicesSize);
    return s;
}
