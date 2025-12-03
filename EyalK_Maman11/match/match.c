/**
 * @file match.c
 * @author Eyal K.
 * @date Dec3st 2025
 * @version 0.5
 * 
 * @brief checking for partial matching between a patern and string and finding the location of the best partial match.
 * 
 * @details the program will get a text and a pattern from the user, it will then go over the text and for every charecter in the text will check how many mistakes
 * the substring has with the pattern- will return and print the lowest amount of mistakes which is the best Partial match.
 *
 * @pre the pattern or text can include tabs,spaces,digits and charecters but '\0' or '\n' will indicate end of input and wont be included in the given strings 
 * or in the matching process.
 * @pre empty textArr will not be sent but an empty pattern will give location 0 sinse there are no mistakes.
 * 
 * @example for the given input:pattern "viva" and text "vviaaa", the output will be 1(due to the pattern being 3 out of 4 matching)
 * 
 * @note My C course repository and version history available at: "https://github.com/TEFalcon/SystemProgrammingLaboratoryCourse25_26"
 */

 #include <stdio.h>
 #include <string.h>

int match(char pattern[],char text[]);

#define MAX_BUFFER 101 /* max charecters*/

#define STR_END_CHECK(arr,indx) (arr[indx] != '\0' && arr[indx] !='\n') /* macro check for ending the string - including new line as end of string*/

/**
 * @brief getting input from user and 
 *
 * @return int
 */
int main()
{
    char textArr[MAX_BUFFER + 3]; /* the text input from the user, has extra space for newline or '\0' */
    char patternArr[MAX_BUFFER + 3]; /* the pattern input from the user, has extra space for newline or '\0' */

    
    printf("Enter up to %d charecters for the text press enter to continue,To stop - Ctrl +D or EOF \n", (MAX_BUFFER - 1));
    
    while (fgets(textArr,MAX_BUFFER +2,stdin) != NULL )
    {
        if(STR_END_CHECK(textArr,0) ){
            printf("*the text input is: %snow enter the pattern: ",textArr);
            fgets(patternArr,MAX_BUFFER +2,stdin);/*not checking- will accept empty pattern*/
            printf("\n*the pattern input is: %s\n",patternArr);
            
            printf("*the index of the substring that matches the most is: %d\n", match(patternArr,textArr));
            
            printf("\nEnter up to %d charecters for the text press enter to continue,To stop - Ctrl +D or EOF \n", (MAX_BUFFER - 1));

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
    int i,j,currCount,currMin = patLen,savedIndx =0;
    /* currCount is the current amount of mistakes, 
    דcurrMin is the minimum of mistakes found so far,savedIndx is the returned value of the match with least mistakes*/
    
    for ( i=j = 0;STR_END_CHECK(text,i); i++)
    {
        currCount =patLen;
        for (j = 0; STR_END_CHECK(pattern,j) && STR_END_CHECK(text,i+j); j++)
        {
            if(pattern[j] == text[i+j]){/*found a match*/
                currCount--;
            }

        }
        if(currCount < currMin){/*found a new lowest mistake index*/
            currMin = currCount;
            savedIndx =i;
        }

    }

    return savedIndx;
}