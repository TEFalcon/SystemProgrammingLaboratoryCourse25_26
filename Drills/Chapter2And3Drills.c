/**
 * @file Chapter2And3Drills.c
 * @author Eyal K.
 * @date Nov29th 2025
 * 
 * @brief Drills from lecture 2 of reccorded lecturer Eran from 2021B and from Chapter 2 and Chapter 3 of "The C Programming Language"
 * 
 * @warning these were run on the ubuntu system but writen in VScode - they were copied from start of drill to the next individually
 * do not try to run the entire doc as is!
 */

/**
 * @name Exercise 2-3
 * @brief the function htoi will convert input in hexadecimal basis to base of 10 and the program will test it
 * @pre will ignore any input that is not 0-9, a-f or A-F and just print it as is
  */
#include <stdio.h>
#include <math.h>
#define LOW_RANGE_NUM '0'
#define HIGH_RANGE_NUM '9'
#define LOW_RANGE_CAPCHR 'A'
#define HIGH_RANGE_CAPCHR 'F'
#define LOW_RANGE_LOWERCHR 'a'
#define HIGH_RANGE_LOWERCHR 'f'

#define MAX_LENGTH_HEX 10

long htoi(int chr[],int len);

int main(){
    int ret[MAX_LENGTH_HEX];
    int chr,indx =0,i;
    
  for(i = 0;i<MAX_LENGTH_HEX;i++){
    ret[i]=0;
  }

    while ((chr = getchar())!=EOF)
    {
        if(chr == '\n'){
            printf("\nnext: %ld \n",htoi(ret,indx));
            indx=0;
        }
        else if((chr >= LOW_RANGE_NUM && chr <=HIGH_RANGE_NUM)||(chr >= LOW_RANGE_LOWERCHR && chr <=HIGH_RANGE_LOWERCHR)||(chr >= LOW_RANGE_CAPCHR && chr <=HIGH_RANGE_CAPCHR)){
            ret[indx++] = chr;
        }
        else{
            printf("%c ",chr);
        }
    }
    return 0;
}
/**
 * @brief returns the intiger in base 10 of the Hexidecimal string
 * 
 * @param chr - int[]
 * @return int 
 */
long htoi(int chr[],int len){
    long ret=0;
    int i;
    for (i = 0; i < len; i++)
    {
        if((chr[i] >= LOW_RANGE_NUM && chr[i] <=HIGH_RANGE_NUM))
            ret = (chr[i] - LOW_RANGE_NUM) + (16 * ret);
        else if((chr[i] >= LOW_RANGE_LOWERCHR && chr[i] <=HIGH_RANGE_LOWERCHR))
            ret = (chr[i] - LOW_RANGE_LOWERCHR + 10) + (16 * ret);
        else{
            ret = (chr[i] - LOW_RANGE_CAPCHR + 10) + (16 * ret);
        }
    }
    return ret;
}

  /**
 * @name Exercise 2-4
 * @brief the program will 
  */






  /**
 * @name Exercise 2-5
 * @brief 
  */





  /**
 * @name Exercise 2-8
 * @brief 
  */




  /**
 * @name Exercise 2-10
 * @brief the function lower, will convert upper case letters to lower case letters with a conditional expression
 * @pre will ignore any input that is not an upper case letter and just print it as is 
  */
#include <stdio.h>
#include <ctype.h>
int lower(int chr);

int main(){
    int chr;

    while((chr = getchar())!= EOF){
        if(isupper(chr)){//with <ctype.h>
            printf("%c",lower(chr));
        }
        
        //without it
        /*
        if(chr >= 'A' && chr <= 'Z')
          printf("%c",lower(chr));
        */
        else{
            printf("%c",chr);
        }
    }
}
int lower(int chr){
    return chr +'a'-'A';
}

