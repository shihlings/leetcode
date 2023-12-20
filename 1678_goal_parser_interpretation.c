//
//  main.c
//  1678_goal_parser_interpretation
//
//  Created by Shih-Ling Shen on 2022-12-18.
//

#include <stdio.h>

void pushforwardArray(char *array, int index, int target_index);
char * interpret(char * command);

//No main function. Test in LeetCode
int main(int argc, const char * argv[]) {
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

/* Purpose: Interpret the command, change '()' into 'o', and change '(al)' into 'al'
 * Params:  command - the string containing the command
 * Return:  The string that has be altered with the changes specified
 */
char * interpret(char * command) {
    for (int index = 0; command[index] != '\0'; ++index) {
        //start check if the character matches '('
        if (command[index] == '(') {
            //if 'al' is not found inbetween, replace with 'o' and push array forward
            if (command[index + 1] == ')') {
                command[index] = 'o';
                pushforwardArray(command, index + 2, index + 1);
            }
            //if 'al' is present, push 'al' forward, then push array forward
            else {
                command[index] = command[index + 1];
                command[index + 1] = command[index + 2];
                pushforwardArray(command, index + 4, index + 2);
            }
        }
    }

    return command;
}
