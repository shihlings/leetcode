//
//  main.c
//  12_int_to_roman
//
//  Created by Shih-Ling Shen on 2022-12-11.
//

#include <stdio.h>
#include <stdlib.h>

//define the value and size of each roman numeral character
#define M_VAL 1000
#define M_SIZE 1

#define CM_VAL 900
#define CM_SIZE 2

#define D_VAL 500
#define D_SIZE 1

#define CD_VAL 400
#define CD_SIZE 2

#define C_VAL 100
#define C_SIZE 1

#define XC_VAL 90
#define XC_SIZE 2

#define L_VAL 50
#define L_SIZE 1

#define XL_VAL 40
#define XL_SIZE 2

#define X_VAL 10
#define X_SIZE 1

#define IX_VAL 9
#define IX_SIZE 2

#define V_VAL 5
#define V_SIZE 1

#define IV_VAL 4
#define IV_SIZE 2

#define I_VAL 1
#define I_SIZE 1

//logest Roman Numeral under 4000 is 15 characters, 16 including '\0'
#define LONGEST_SIZE 16

char* intToRoman(int num);
void calcNumOfChar(int *num, int roman_val, int *times);
void addCharToStr(char *add_string, int add_string_size, char *string, int *string_index, int *times);

int main(int argc, const char * argv[]) {
    int num = 2121;
    
    char *roman = intToRoman(num);
    
    printf("%s\n", roman);
    
    free(roman);
    return 0;
}

/* Purpose: Calculates the roman numeral of a number
 * Params:  *num          - the number given to calculate the roman numeral of
 * Return:  address to the string, *roman, which contains the roman numeral that represents the particular integer
 */
char* intToRoman(int num){
    char *roman = malloc(LONGEST_SIZE * sizeof(char));
    int times = 0;
    roman[0] = '\0';
    int index = 0;
    char add_string[2] = {};
    
    add_string[0] = 'M';
    add_string[1] = '\0';
    calcNumOfChar(&num, M_VAL, &times);
    addCharToStr(add_string, M_SIZE, roman, &index, &times);
    roman[index] = '\0';
    
    add_string[0] = 'C';
    add_string[1] = 'M';
    calcNumOfChar(&num, CM_VAL, &times);
    addCharToStr(add_string, CM_SIZE, roman, &index, &times);
    roman[index] = '\0';
    
    add_string[0] = 'D';
    add_string[1] = '\0';
    calcNumOfChar(&num, D_VAL, &times);
    addCharToStr(add_string, D_SIZE, roman, &index, &times);
    roman[index] = '\0';
    
    add_string[0] = 'C';
    add_string[1] = 'D';
    calcNumOfChar(&num, CD_VAL, &times);
    addCharToStr(add_string, CD_SIZE, roman, &index, &times);
    roman[index] = '\0';

    add_string[0] = 'C';
    add_string[1] = '\0';
    calcNumOfChar(&num, C_VAL, &times);
    addCharToStr(add_string, C_SIZE, roman, &index, &times);
    roman[index] = '\0';
    
    add_string[0] = 'X';
    add_string[1] = 'C';
    calcNumOfChar(&num, XC_VAL, &times);
    addCharToStr(add_string, XC_SIZE, roman, &index, &times);
    roman[index] = '\0';
    
    add_string[0] = 'L';
    add_string[1] = '\0';
    calcNumOfChar(&num, L_VAL, &times);
    addCharToStr(add_string, L_SIZE, roman, &index, &times);
    roman[index] = '\0';
    
    add_string[0] = 'X';
    add_string[1] = 'L';
    calcNumOfChar(&num, XL_VAL, &times);
    addCharToStr(add_string, XL_SIZE, roman, &index, &times);
    roman[index] = '\0';
    
    add_string[0] = 'X';
    add_string[1] = '\0';
    calcNumOfChar(&num, X_VAL, &times);
    addCharToStr(add_string, X_SIZE, roman, &index, &times);
    roman[index] = '\0';
    
    add_string[0] = 'I';
    add_string[1] = 'X';
    calcNumOfChar(&num, IX_VAL, &times);
    addCharToStr(add_string, IX_SIZE, roman, &index, &times);
    roman[index] = '\0';
    
    add_string[0] = 'V';
    add_string[1] = '\0';
    calcNumOfChar(&num, V_VAL, &times);
    addCharToStr(add_string, V_SIZE, roman, &index, &times);
    roman[index] = '\0';
    
    add_string[0] = 'I';
    add_string[1] = 'V';
    calcNumOfChar(&num, IV_VAL, &times);
    addCharToStr(add_string, IV_SIZE, roman, &index, &times);
    roman[index] = '\0';
    
    add_string[0] = 'I';
    add_string[1] = '\0';
    calcNumOfChar(&num, I_VAL, &times);
    addCharToStr(add_string, I_SIZE, roman, &index, &times);
    roman[index] = '\0';
        
    return roman;
}

/* Purpose: Calculate the number of times the roman numeral character needs to be printed
 * Params:  *num          - the number given to calculate the roman numeral of
 *          roman_val     - the value of the given roman numeral in decimal numbers
 *          *times        - number of times the roman numberal character should be printed
 * Return:  nothing (void)
 */
void calcNumOfChar(int *num, int roman_val, int *times) {
    //calculates how many times the character should be printed
    *times = *num / roman_val;
    
    //deduct the total value represented by the characters from *num
    *num -= *times * roman_val;
}

/* Purpose: Add a string to the end of an existing string
 * Params:  *add_string         - the string to be added to the end
 *          add_string_size     - the size of add_string
 *          *string             - the exsiting string that is being modified
 *          *string_index       - the location of the NULL character in the string, string
 *          *times              - number of times the string, add_string, will be added to the string, string
 * Return:  nothing (void)
 */
void addCharToStr(char *add_string, int add_string_size, char *string, int *string_index, int *times) {
    //repeats the printing process *times times
    for (int repeat = 0; repeat < *times; ++repeat) {
        //prints each character in *add_string into *string
        for (int currentchar = 0; currentchar < add_string_size; ++currentchar, ++*string_index){
            string[*string_index] = add_string[currentchar];
        }
    }
}
