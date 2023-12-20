//
//  main.c
//  13_roman_to_integer
//
//  Created by Shih-Ling Shen on 2022-12-13.
//

#include <stdio.h>

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

//no main function. Test in leetcode.
int main(int argc, const char * argv[]) {
    return 0;
}

/* Purpose: Convert Roman Numeral to integer
 * Params:  s - string conaining the roman numeral
 * Return:  the equvailent integer for the roman numeral
 */
int romanToInt(char * s){
    //initialize storage at 0
    int number = 0;

    //check through each element and add the value to the variable
    for(int index = 0; s[index] != '\0'; ++index) {
        if(s[index] == 'M') {
            number += M;
            
            //if there are preceeding characters that have a smaller value, deduct twice the value
            if(index != 0){
                if(s[index - 1] == 'C'){
                    number -= 2 * C;
                }
                else if(s[index - 1] == 'D') {
                    number -= 2 * D;
                }
            }
        }
        else if(s[index] == 'D') {
            number += D;

            //if there are preceeding characters that have a smaller value, deduct twice the value
            if(index != 0 && s[index - 1] == 'C'){
                number -= 2 * C;
            }
        }
        else if(s[index] == 'C') {
            number += C;

            //if there are preceeding characters that have a smaller value, deduct twice the value
            if(index != 0){
                if(s[index - 1] == 'X'){
                    number -= 2 * X;
                }
                else if(s[index - 1] == 'L') {
                    number -= 2 * L;
                }
            }
        }
        else if(s[index] == 'L') {
            number += L;

            //if there are preceeding characters that have a smaller value, deduct twice the value
            if(index != 0 && s[index - 1] == 'X'){
                number -= 2 * X;
            }
        }
        else if(s[index] == 'X') {
            number += X;

            //if there are preceeding characters that have a smaller value, deduct twice the value
            if(index != 0){
                if(s[index - 1] == 'V'){
                    number -= 2 * V;
                }
                else if(s[index - 1] == 'I') {
                    number -= 2 * I;
                }
            }
        }
        else if(s[index] == 'V') {
            number += V;

            //if there are preceeding characters that have a smaller value, deduct twice the value
            if(index != 0 && s[index - 1] == 'I'){
                number -= 2 * I;
            }
        }
        else if(s[index] == 'I') {
            number += I;
        }
    }
    
    return number;
}
