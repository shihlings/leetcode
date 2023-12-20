//
//  main.c
//  20_valid_parentheses
//
//  Created by Shih-Ling Shen on 2022-12-13.
//

#include <stdio.h>

#define PARA1_OPEN  '('
#define PARA1_CLOSE ')'
#define PARA2_OPEN  '['
#define PARA2_CLOSE ']'
#define PARA3_OPEN  '{'
#define PARA3_CLOSE '}'

#define TRUE 1
#define FALSE 0
#define NONE -1
//leetcode has bool in their version of C, modified to compile in Xcode.
#define bool int

void eraseArrayArray(char *s, int index);
void foundPara(char *s, int *index, int *valid, char target);
bool isValid(char * s);

int main(int argc, const char * argv[]) {
    char string[] = "([}}])";
    
    printf("%d\n", isValid(string));
    
    return 0;
}

/* Purpose: Erase the element at index of the array
 * Params:  *s      - the target string
 *          index   - target location to erase
 * Return:  nothing (void)
 */
void eraseArray (char *s, int index) {
    s[index] = ' ';
}

/* Purpose: Verify if there is a valid closing parenthesis for the found open parenthesis
 * Params:  *s      - target string to verify
 *          *index  - pointer to the index indicator
 *          *valid  - pointor to the validity indicator
 *          target  - the target closing parenthesis
 * Return:  void (nothing)
 */
void foundPara(char *s, int *index, int *valid, char target) {
    int complete = FALSE;
    
    //search for the target closing parenthesis
    //erase any element after it is read to prevent re-reading
    for (++*index; s[*index] != '\0' && complete == FALSE; ++*index) {
        //if found, quit loop and erase element
        if (s[*index] == target) {
            eraseArray(s, *index);
            complete = TRUE;
        }
        //if a new opening parenthesis is detected, find the closing parenthesis for that first
        if (s[*index] == PARA1_OPEN || s[*index] == PARA2_OPEN || s[*index] == PARA3_OPEN) {
            if (s[*index] == PARA1_OPEN) {
                eraseArray(s, *index);
                foundPara(s, index, valid, PARA1_CLOSE);
            }
            else if (s[*index] == PARA2_OPEN) {
                eraseArray(s, *index);
                foundPara(s, index, valid, PARA2_CLOSE);
            }
            else {
                eraseArray(s, *index);
                foundPara(s, index, valid, PARA3_CLOSE);
            }
        }
        //if any closing parenthesis is detected before a open parenthesis, string is not valid
        else if ((s[*index] == PARA1_CLOSE && target != PARA1_CLOSE) || (s[*index] == PARA2_CLOSE && target != PARA2_CLOSE) || (s[*index] == PARA3_CLOSE && target != PARA3_CLOSE)) {
            eraseArray(s, *index);
            *valid = FALSE;
            complete = TRUE;
        }
    }
    
    //if EOF and not found, parenthesis is not valid
    if (complete == FALSE) {
        *valid = FALSE;
    }
    
    //compensate for the extra ++*index done by the for loop
    --*index;
}

/* Purpose: Verifies if a string of parenthesis is valid
 * Params:  *s - the string containing the parenthesis
 * Return:  1 if valid, 0 if not valid
 */
bool isValid(char * s) {
    int valid = TRUE;
    
    //verify the the string from first element until not valid or EOF
    for (int index = 0; s[index] != '\0' && valid == TRUE; ++index) {
        //if any open parenthesis is detected, check for the corresponding closing parenthesis
        //erase any element after it is read to prevent re-reading
        if (s[index] == PARA1_OPEN) {
            eraseArray(s, index);
            foundPara(s, &index, &valid, PARA1_CLOSE);
        }
        else if (s[index] == PARA2_OPEN) {
            eraseArray(s, index);
            foundPara(s, &index, &valid, PARA2_CLOSE);
        }
        else if (s[index] == PARA3_OPEN) {
            eraseArray(s, index);
            foundPara(s, &index, &valid, PARA3_CLOSE);
        }
        //if any closing parenthesis is detected before a open parenthesis, string is not valid
        else if (s[index] == PARA1_CLOSE || s[index] == PARA2_CLOSE || s[index] == PARA3_CLOSE) {
            eraseArray(s, index);
            valid = FALSE;
        }
    }
    
    return valid;
}
