/**
 * @file Chapter2Drills.c
 * @author Eyal K.
 * @date Nov29th 2025
 * 
 * @brief Drills from lecture 2 of reccorded lecturer Eran from 2021B and from Chapter 2 of "The C Programming Language"
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
        else if((chr >= LOW_RANGE_NUM && chr <=HIGH_RANGE_NUM)||(chr >= LOW_RANGE_LOWERCHR && chr <=HIGH_RANGE_LOWERCHR)
        ||(chr >= LOW_RANGE_CAPCHR && chr <=HIGH_RANGE_CAPCHR)){
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
 * @brief the program will remove any char in s1 that excists in s2 using the function squeeze
  */
#include <stdio.h>
#define MAX_LENGTH 100
void squeeze(char s1[],char s2[]);

enum BOOL{
    FALSE,TRUE
};

int main(){
    int chr,indx=0;
    char s1[MAX_LENGTH], s2[MAX_LENGTH];
    printf("\nEnter s1:\n");
    while ((chr = getchar())!='\n' || indx==MAX_LENGTH)
    {
        s1[indx++] = chr;
    }
    indx =0;
    printf("Enter s2:\n");
    while ((chr = getchar())!='\n' || indx==MAX_LENGTH)
    {
        s2[indx++] = chr;
    }

    squeeze(s1,s2);
    printf("%s\n",s1);
    
    return 0;
}

/**
 * @brief the function removes any charecters in s1 that also apears in s2
 * 
 * @param s1 - char[]
 * @param s2 -char[]
 */
void squeeze(char s1[], char s2[])
{
    int i,j,k;
    enum BOOL flag;

    for ( i=j = 0; s1[i]!='\0'; i++)
    {
        flag = TRUE;
        for ( k = 0; s2[k]!='\0'; k++)
        {
            if(s1[i] == s2[k]){
                flag = FALSE;
                break;
            }
        }
        if(flag==TRUE)
            s1[j++] = s1[i];
        
    }
    s1[j] = '\0';
    
}



  /**
 * @name Exercise 2-5
  * @brief the program will search the first occurence in s1 of a charecter in common between s1 and s2
  */
#include <stdio.h>
#define MAX_LENGTH 100
int any(char s1[],char s2[]);

int main(){
    int chr,indx=0;
    char s1[MAX_LENGTH], s2[MAX_LENGTH];
    printf("\nEnter s1:\n");
    while ((chr = getchar())!='\n' || indx==MAX_LENGTH)
    {
        s1[indx++] = chr;
    }
    indx =0;
    printf("Enter s2:\n");
    while ((chr = getchar())!='\n' || indx==MAX_LENGTH)
    {
        s2[indx++] = chr;
    }

    printf("%d\n",any(s1,s2));
    
    return 0;
}

/**
 * @brief the function searches the index of the first char in common.
 * @details will return the first location in s1 of the charecter that is in s1 and also in s2, if will not find will return -1
 * 
 * @param s1 - char[]
 * @param s2 -char[]
 * @return int 
 */
int any(char s1[], char s2[])
{
    int i,j;

    for ( i= 0; s1[i]!='\0'; i++)
    {
        for ( j = 0; s2[j]!='\0'; j++)
        {
            if(s1[i] == s2[j]){
                return i;
            }
        }
        
    }
    return -1;
    
}


/**
* @name Exercise 2-7
* @brief returns x with the n bits that begin at position p inverted, leaving the others unchanged
*/
#include <stdio.h>
unsigned invert(unsigned x, int p, int n);

/**
 * @pre the check was done with scanf, i know there are other options such as fgets.
 */
int main(){
    unsigned int x = -1;
    int p,n;
    printf("enter a number\n");
    scanf("%u",&x);
    printf("enter p\n");
    scanf("%d",&p);
    printf("enter n\n");
    scanf("%d",&n);

    printf("%u\n",invert(x,p,n));
    
    return 0;
}
/**
 * @brief returns x with the n bits that begin at position p inverted, leaving the others unchanged
 * 
 * @param x - the binaric number
 * @param p - location
 * @param n -amount of bits
 * @return unsigned 
 */
unsigned invert(unsigned x, int p, int n){
    return(x ^ (~(~0<<n))<<(p-n+1));
}

/**
* @name Exercise 2-8
* @brief returns the value of the integer x rotated to the right by n bit positions
*/
#include <stdio.h>
unsigned rightrot(unsigned x, int n);
/**
 * @pre the check was done with scanf, i know there are other options such as fgets.
 */
int main(){

    unsigned int x = -1;
    printf("enter a number\n");
    scanf("%u",&x);
    printf("before: %u after:%u\n",x,rightrot(x,3));
    
    return 0;
}

/**
 * @brief returns the value of the integer x rotated to the right by n bit positions
 * 
 * @param x - the binaric number
 * @param n - amount of bits
 * @return unsigned 
 */
unsigned rightrot(unsigned x, int n){
    return (x>>n);
}


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
int lower(int chr)
{
    return chr +'a'-'A';
}
