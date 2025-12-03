/**
 * @file translate.c
 * @author Eyal k
 * @date Dec1st 2025
 * @version 0.5
 *
 * @brief Converts decimal input to binary output
 *
 * @details the program will get a decimal numbers as a string input and will pass it to the function transale_dec which will translate it to an int
 * and will print the decimal number as a binary number
 *
 * @pre the input is meant for digits, any other char will not be taken into account but will take up space in the buffer
 * @pre the input is in the range unsigned int, and therefore has to be postive as well as have max input of 12 digits
 *
 * @note My C course repository and version history available at: "https://github.com/TEFalcon/SystemProgrammingLaboratoryCourse25_26"
 */
#include <stdio.h>
#include <ctype.h>

void translate_dec(char s[]);
void printBinFromDec(unsigned int deci_num);

#define MAX_BUFFER 10 /* max digits that the range of unsigned int can have*/
#define STR_END_CHECK(arr,indx) (arr[indx] != '\0' && arr[indx] != '\n')

/**
 * @brief uses a decimal number input from user or file to translate it to a binaric base
 *
 * @return int
 */
int main()
{
    char buffer[MAX_BUFFER + 3]; /* the input from the user, has extra space for newline or '\0' */
    printf("Enter up to %d digits, to stop - Ctrl +D or EOF \n", (MAX_BUFFER - 1));
    while (fgets(buffer, MAX_BUFFER + 2, stdin) != NULL)
    {
        if (STR_END_CHECK(buffer,0))
        {
            translate_dec(buffer);
            printf("Enter up to %d digits, to stop - Ctrl +D or EOF \n", (MAX_BUFFER - 1));
        }
    }
    printf("\nprogram ended.\n");

    return 0;
}

/**
 * @brief prints the binary value of the intiger given in string s
 *
 * @param s - the string containing the digits for the decimal numebr
 */
void translate_dec(char s[])
{
    unsigned int i = 0, deci_num = 0; /*i - runner, the decimal number - from the string input*/

    while (STR_END_CHECK(s,i)) /* implimenting atoi*/
    {
        if (isdigit(s[i]))
            deci_num = (s[i] - '0') + deci_num * 10;

        i++;
    }
    printf("your input is: %u\n The answer:\t", deci_num);

    /* printing in the right order*/
    printBinFromDec(deci_num);
    printf("\n");
}

/**
 * @brief converts a decimal number to binary and printing it from most significant digit to least
 * @details using recursion it will start printing only when getting to the most significant digit, when done converting then come back in the recursion and print
 *
 * @param deci_num - the given intial decimal number
 */
void printBinFromDec(unsigned int deci_num)
{
    if (deci_num > 0)
    {
        printBinFromDec(deci_num / 2);
        printf("%d", deci_num % 2);
    }
}
