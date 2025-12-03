/**
 * @file match.c
 * @author Eyal K.
 * @date Dec2st 2025
 * @version 0.2
 * 
 * @brief checking for partial matching between a patern and string and finding the location of the best partial match.
 * 
 * @details the program will 
 *
 * @pre the pattern or text can include tabs,spaces,digits and charecters but '\0' or '\n' will indicate end of input and wont be included in the given strings 
 * or in the matching process.
 * 
 * @example for the given input:pattern "viva" and text "vviaaa", the output will be 1(due to the pattern being 3 out of 4 matching)
 * 
 * @note My C course repository and version history available at: "https://github.com/TEFalcon/SystemProgrammingLaboratoryCourse25_26"
 */

 #include <stdio.h>
 #include <string.h>

int match(char pattern[],char text[]);

#define MAX_BUFFER 101 /* max charecters*/

/**
 * @brief getting input from user and 
 *
 * @return int
 */
int main()
{
    char buffer[MAX_BUFFER + 3]; /* the input from the user, has extra space for newline or '\0' */
    printf("Enter up to %d charecters, to stop - Ctrl +D or EOF \n", (MAX_BUFFER - 1));
    while (fgets(buffer, MAX_BUFFER +2, stdin) != NULL )
    {
        if(buffer[0] != '\0' && buffer[0] != '\n'){
            printf("the input is:\t%s\n",buffer);


            printf("Enter up to %d charecters, to stop - Ctrl +D or EOF \n", (MAX_BUFFER - 1));

        }
    }
    printf("\nprogram ended.\n");

    return 0;
}


/**
 * @brief given two strings, the function will try and search for the most amount of matches of the pattern substring in the text, 
 * will return the location of where that substring starts.
 * 
 * @param pattern 
 * @param text 
 * @return int - location of 
 */
int match(char pattern[], char text[]){
    int patLen = strlen(pattern); /* the length of the pattern*/
    int txtLen = strlen(text); /* the length of the scanning text*/
    int i,j,currCount,currMin = patLen,savedIndx;
    /* currCount is the current amount of mistakes, 
    דcurrMin is the minimum of mistakes found so far,savedIndx is the returned value of the match with least mistakes*/
    
    for ( i=j = 0; text[i] != '\0'; i++)
    {
        currCount =patLen;
        for (j = 0; pattern[j] != '\0' && text[i+j]!='\0'; j++)
        {
            if(pattern[j] == text[i+j]){
                
            }

        }
        

    }
    
}