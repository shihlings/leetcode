//
//  main.c
//  1720_decode_xored_array
//
//  Created by Shih-Ling Shen on 2022-12-18.
//

#include <stdio.h>
#include <stdlib.h>

int* decode(int* encoded, int encodedSize, int first, int* returnSize);

//no main function. Test in leetcode.
int main(int argc, const char * argv[]) {
    return 0;
}

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* Purpose: Decodes an array using XOR
 * Params:  encoded -       array containing the encoded values
 *          encodedSize -   the size of the encoded array
 *          first -         the first value of the decoded array
 *          *returnSize -   pointer to the size of the return array
 * Return:  An array containing the decoded values
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize){
    //the decoded array is larger by one
    *returnSize = encodedSize + 1;
    int *decoded = malloc(*returnSize * sizeof(int));

    //store the inital value into the array
    decoded[0] = first;
    //calculate each element decoded using XOR
    for (int index = 0; index < encodedSize; ++index) {
        decoded[index + 1] = decoded[index] ^ encoded[index];
    }

    return decoded;
}
