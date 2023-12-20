#include <stdio.h>

#define NONE -1
#define TRUE 1
#define FALSE 0

int strStr(char * haystack, char * needle);

int main() {
    char *haystack = "mississippi";
    char *needle = "i";
    
    printf("%d\n", strStr(haystack, needle));

    return 0;
}

/* Purpose: Find a string inside another string
 * Params:  haystack - the main string to search in
 *          needle   - the string to search for in haystack
 * Return:  the address of the first character where the needle is found in the haystack,
 *          returns -1 if not found
 */
int strStr(char * haystack, char * needle){
    //set the index that is found to an impossible location
    int found_index = NONE;
    //indicates if the search is complete
    int complete = FALSE;
    //sets current index in haystack to compare
    int index = 0;
    //sets current index in needle to compare
    int compare = 0;
    
    //compare until EOF or comparison is complete
    while (haystack[index] != '\0' && complete != TRUE){
        if (haystack[index] != needle[compare]) {
            //if previous matched, reset the indicators, since this one mismatched
            if (found_index != NONE) {
                //move haystack index to original found location and recompare for new matches
                index = found_index;
                found_index = NONE;
            }
            
            //reset the index of the needle to compare
            compare = 0;
        }
        else {
            //if the two matches, advance to next needle location to compare next element
            compare++;
            
            //if reached needle EOF, comparison is complete
            if (needle[compare] == '\0') {
                complete = TRUE;
            }
            
            //if previously not found, save the new found index to found_index
            if (found_index == NONE) {
                found_index = index;
            }
        }
        
        //increment index to compare next element in haystack
        index++;
    }
    
    //if haystack is EOF, and not found, change found_index to NONE
    if (complete != TRUE) {
        found_index = NONE;
    }
    
    return found_index;
}
