//
//  main.c
//  344_reverse_string
//
//  Created by Shih-Ling Shen on 2022-12-11.
//

#include <stdio.h>

void reverseString(char* string, int string_size);

//Test code only. No main function. Test in LeetCode.
int main(int argc, const char * argv[]) {
    //only alter the string and size
    char string[] = "HELLO";
    int string_size = 5;
    
    //do not alter anything below
    reverseString(string, string_size);
    
    printf("%s", string);
    
    return 0;
}

/* Purpose: Reverses the string
 * Params:  string      -   the string
 *          string_size - the size of the string, string
 * Return:  nothing (Void)
 */
void reverseString(char* string, int string_size){
    //starting from the start of the string to halfway point
    for (int index = 0; index < string_size / 2; ++index) {
        //stores the character on the oppsite end of index to temp
        char temp = string[string_size - 1 - index];
        //move character at index to the opposite end
        string[string_size - 1 - index] = string[index];
        //assign the character at the opposite end back to index
        string[index] = temp;
    }
}
