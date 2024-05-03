//
//  main.c
//  71_simplify_path
//
//  Created by Shih-Ling Shen on 2022-12-12.
//

#include <stdio.h>

#define FALSE 0
#define TRUE 1

void pushforwardArray(char *array, int index, int target_index);
int searchIndex(char* array, char target, int index);
char * simplifyPath(char * path);

//Test code only. See LeetCode.
int main(int argc, const char * argv[]) {
    
    char path[] = "/ewaf........////////f/dsa.f/e.w/f.e.wa/./e.w/ag.e/w.....e/wa/.f/ewafe/e/wa//.f../././....//feafewa..././../ffe";
    
    simplifyPath(path);
    
    printf("%s\n", path);
    
    return 0;
}

/* Purpose: Push forward array to right after the target index
 * Params:  *array -        array to be modified
 *          index -         the start point to be pushed forward
 *          target_index -  the target location to be pushed to
 * Return:  nothing (void)
 */
void pushforwardArray(char *array, int index, int target_index) {
    //if the only element to move is null character, abort.
    if(array[index] != '\0') {
        do {
            array[target_index] = array[index];
            ++index;
            ++target_index;
        } while(array[index] != '\0');
    }

    array[target_index] = '\0';
}

/* Purpose: Finds the element in the array going back from the given index
 * Params:  *array   - the array to search in
 *          target   - the target character
 *          index    - the index to start from
 * Return:  the index of element where the target element is found first in the array
 */
int searchIndex(char* array, char target, int index){
    //found indicator is not found
    int found = FALSE;
    
    //continue iterating until the index of the element is found
    for (;index >= 0 && found == FALSE; --index) {
        //deduct the cost at index from target until it reaches below (or equal) 0
        if (array[index] == target) {
            found = TRUE;
        }
    }
    
    //returns the index reduced by one (compensate for the extra added from the for loop)
    return index + 1;
}

/* Purpose: Simplifies path given in the string
 * Params:  *path - string containing the given path
 * Return:  address to the optimized string
 */
char * simplifyPath(char * path){
    //optimize the path by removing extraneous '/' first
    for(int index = 0; path[index] != '\0'; ++index) {
        //if a '/' is detected, initialize the check
        if(path[index] == '/') {
            //if more than one '/' are found in a row, remove until no more than one is left
            while (path[index + 1] == '/') {
                pushforwardArray(path, index + 1, index);
            }
        }
    }
    
    //initialize string pointer
    int index = 0;
    //optimize until NULL is detected
    while(path[index] != '\0') {
        //if '/.' is detected, take action
        while(path[index] == '/' && path[index + 1] == '.') {
            //check for current directory
            int last_dir = searchIndex(path, '/', index);
            
            //if '/./' or '/.\0', remove './' or '.'
            if(path[index + 2] == '\0' || path[index + 2] == '/') {
                //don't remove leading '/' if there is trailing '\0' in the sequence
                if(path[index + 2] == '\0') {
                    ++last_dir;
                }
                //remove extraneous characters
                pushforwardArray(path, index + 2, last_dir);
                
                //prevent out of bound addresses, do not -1 recalibrate if at 0
                if (last_dir == 0) {
                    index = last_dir;
                }
                else {
                    index = last_dir - 1;
                }
            }
            //if '/../' or '/..\0' remove the '/..'
            else if (path[index + 2] == '.' && (path[index + 3] == '/' || path[index + 3] == '\0')) {
                //locate parent directory
                if (last_dir != 0) {
                    last_dir = searchIndex(path, '/', last_dir - 1);
                }
                
                //don't remove leading '/' if there is trailing '\0' in the sequence
                if (path[index + 3] == '\0') {
                    ++last_dir;
                }
                //remove extraneous characters until parent directory
                pushforwardArray(path, index + 3, last_dir);
                
                //prevent out of bound addresses, do not -1 recalibrate if at 0
                if (last_dir == 0) {
                    index = last_dir;
                }
                else {
                    index = last_dir - 1;
                }
            }
            //if no action performed, break
            else {
                break;
            }
        }
        
        ++index;
    }
    
    //remove trailing '/' and replace with '\0'
    if (index - 1 != 0 && path[index - 1] == '/') {
        path[index - 1] = '\0';
    }
    
    return path;
}
