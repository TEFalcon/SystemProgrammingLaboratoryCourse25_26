/**
 * @file Lecture1Drills.c
 * @author Eyal K.
 * @date Nov24th 2025
 * 
 * @brief Drills from lecture 1 of reccorded lecturer Eran from 2021B
 * 
 * @warning these were run on the ubuntu system but writen in VScode - they were copied from start of drill to the next individually
 * do not try to run the entire doc as is!
 */


/**1.8p20 from lecture 1 -
 *  counting spcaces,tabs and lines from user input (can also be used on a file with <)
 * */
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


/**Exercise 1-13 from lecture 1 -
 *  printing a histogram of 
 * */
#define MAX_LENGTH 20


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
