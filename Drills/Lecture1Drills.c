/**
 * @file Lecture1Drills.c
 * @author Eyal K.
 * @date Nov24th 2025
 * 
 * @brief Drills from lecture 1 of reccorded lecturer Eran from 2021B and from Chapter 1 of "The C Programming Language"
 * 
 * @warning these were run on the ubuntu system but writen in VScode - they were copied from start of drill to the next individually
 * do not try to run the entire doc as is!
 */

/**
 * @name Exercise 1-8
 * @brief 1.8p20 from lecture 1 -
 *  counting spcaces,tabs and lines from user input (can also be used on a file with <)
  */

# include <stdio.h>

int main(){
    int chr;
    int spaces,tabs,lines;

    spaces = lines = tabs =0;

    while ((chr = getchar())!= EOF){
        if(chr == ' ')
            spaces++;
        if(chr == '\t')
            tabs++;
        if(chr == '\n')
            lines++;
    }

    printf("------------------------------\n Total Spaces:\t%d\t Total Tabs:%d\t Total Lines:%d\n",spaces,tabs,lines);
}
/**
 * @name Exercise 1-10
 * @brief program copies the input to output and replaces every tab with \t, each backspace with \b, and every backslash by \\
 */

#include <stdio.h>


int main(){
    
    int chr ;

    while((chr = getchar())!=EOF){
        if (chr == '\t') 
            printf("\\t");  
        
        else if (chr == '\b') 
            printf("\\b");  
        
        else if (chr == '\\') 
            printf("\\\\"); 
         
        else {
            printf("%c",chr );
        }

    }

    
}



/**
 * @name Exercise 1-13
 * @brief
 * Exercise 1-13 from lecture 1 -
 *  printing a histogram of word lengths in the input or file 
 * with a max length words of 20
 * */

#include <stdio.h>
#define MAX_LENGTH 20


int main(){
    int i, count = 0 ,chr;
    int nchars[MAX_LENGTH];
    
    //reseting the arr
    for (i = 0; i < MAX_LENGTH; i++)
    {
        nchars[i]=0;
    }
    
    while ((chr = getchar())!=EOF)
    {
        if (chr != ' ' && chr != '\n' && chr!='\t')
            count++;
        else if(count > 0 && count < MAX_LENGTH)
        {
            nchars[count]++;
            count = 0;
        }
    }
    printf("number of charercters in words\n");
    for ( i = 1; i < MAX_LENGTH; i++)
    {
        printf("%2d %4d",i,nchars[i]);
        while (nchars[i]>0)
        {
            printf("|");
            nchars[i]--;
        }
        printf("\n");
    }
    
    
}


/**
* @name Exercise 1-14 
* @brief 
 * Exercise 1-14 from chapter 1 
 *  printing a histogram of charecter frequencies in the input or file 
 * two types of prints. once horizontal and once vertical
 */
#include <stdio.h>

#define LOWEST_VALUE ' '
#define HIGHEST_VALUE '~'

int main(){
    
    int i ,chr ,height =0;
    int nchars[HIGHEST_VALUE - LOWEST_VALUE+1];

    //reseting the arr
    for (i = 0; i <= (HIGHEST_VALUE - LOWEST_VALUE); i++)
    {
        nchars[i]=0;
    }
    
    while ((chr = getchar())!=EOF)
    {
        if ( chr >= LOWEST_VALUE && chr <= HIGHEST_VALUE){
            nchars[chr - LOWEST_VALUE]++;
            if ((nchars[chr - LOWEST_VALUE]) > height){
                height = nchars[chr - LOWEST_VALUE];
            }
        } 
    }


    //horizontal print
    int j;
     printf("number of charercters in words\n");
    for ( i = 0; i <= (HIGHEST_VALUE - LOWEST_VALUE); i++)
    {
        printf("%2c %4d \t",(i+LOWEST_VALUE),nchars[i]);
        j = nchars[i];
        while (j>0)
        {
            printf("|");
            j--;
        }
        printf("\n");
    }

    //vertical print
    //printing amount
     printf("number of charercters in words\n");
    for ( i = height; i >0; i--)
    {
        for ( j = 0; j < (HIGHEST_VALUE - LOWEST_VALUE); j++)
        {
            if(nchars[j] >= i){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    //printing end
    for ( i = 0; i < (HIGHEST_VALUE - LOWEST_VALUE); i++)
    {
        printf("_");
    }
    printf("\n");
    for ( i = 0; i < (HIGHEST_VALUE - LOWEST_VALUE); i++)
    {
        printf("%c",(i + LOWEST_VALUE));
    }
    printf("\n");
}