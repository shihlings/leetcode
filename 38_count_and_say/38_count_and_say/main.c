//
//  main.c
//  38_count_and_say
//
//  Created by Shih-Ling Shen on 2022-12-11.
//

#include <stdio.h>
#include <stdlib.h>

//maximum number of characters of count and say at 30th iteration
#define MAX_SIZE 4500

char * countAndSay(int n);
void pushbackArray(char *array, int index);
void pushforwardArray(char *array, int index, int target_index);

int main(int argc, const char * argv[]) {
    int num = 30;
    
    char *say_array = countAndSay(num);
    
    printf("%s\n", say_array);
    
    free(say_array);
    
    return 0;
}

/* Purpose: Count and say until the target iteration
 * Params:  n - the nth iteration of count and say
 * Return:  the nth iteration of count and say in a string
 */
char * countAndSay(int n){
    //initialize the return array
    char *say_array = malloc(MAX_SIZE * sizeof(char));
    //set count and say 1st iteration to 1
    say_array[0] = '1';
    say_array[1] = '\0';
    
    //recursive until nth iteration
    for (int iteration = 1; iteration < n; ++iteration) {
        //go through the string until EOF
        for(int index = 0; say_array[index] != '\0'; ++index) {
            //set target character to the character the pointer is on, counter resets
            char current_char = say_array[index];
            int counter = 0;
            int found_index = index;
            
            //count how many times the target character appears in a row
            do{
                ++counter;
                ++index;
            } while (say_array[index] == current_char);
            
            //if it only occurs once, push back the whole array by one to make space for two characters
            if(counter == 1) {
                pushbackArray(say_array, index);
            }
            
            //replaces the first character found to the amount appeared, and second to the character found
            say_array[found_index] = counter + '0';
            say_array[found_index + 1] = current_char;
            
            //removes extraneous spaces if there are more than 2 characters of the same found
            if(counter > 2) {
                pushforwardArray(say_array, index, found_index + 2);
            }
            
            //resets the index pointer bact to the end of the replaced characters
            index = found_index + 1;
        }
    }
    
    return say_array;
}

/* Purpose: Pushback array by one space from index
 * Params:  *array -    array to be modified
 *          index -     the location to be pushed back
 * Return:  nothing (void)
 */
void pushbackArray(char *array, int index) {
    //stores the first to elemets to be pushed back in temp storage
    char temp1 = array[index];
    char temp2 = array[index + 1];

    //removes element at index
    array[index] = ' ';

    //increments index to next element (where the push back starts)
    ++index;

    //read until EOF
    while(array[index] != '\0') {
        array[index] = temp1;
        temp1 = temp2;
        temp2 = array[index + 1];
        ++index;
    }
    
    //restores remaining characters back into the array, temp2 should be '\0'
    array[index] = temp1;
    array[index + 1] = temp2;
}

/* Purpose: Push forward array to two spaces after target index
 * Params:  *array -        array to be modified
 *          index -         the start point to be pushed forward
 *          target_index -  the target location to be pushed to
 * Return:  nothing (void)
 */
void pushforwardArray(char *array, int index, int target_index) {
    do {
        array[target_index] = array[index];
        ++index;
        ++target_index;
    } while(array[index] != '\0');
    array[target_index] = '\0';
}
