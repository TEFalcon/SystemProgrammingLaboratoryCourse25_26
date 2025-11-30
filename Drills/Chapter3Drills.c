/**
 * @file Chapter3Drills.c
 * @author Eyal K.
 * @date Nov30th 2025
 *
 * @brief Drills from lecture 2 of reccorded lecturer Eran from 2021B and from Chapter 3 of "The C Programming Language"
 *
 * @warning these were run on the ubuntu system but writen in VScode - they were copied from start of drill to the next individually
 * do not try to run the entire doc as is!
 */

/**
 * @name Exercise 3-1
 * @brief change binsearch from pg 58 to only having one test inside the loop
 */
int binsearch(int x, int v[], int len);

/**
 * @brief searching an initger in an array of intigers
 * 
 * @param x - the intiger to search
 * @param v -the array
 * @param len -length
 * @return int of the location found
 */
int binsearch(int x, int v[], int len)
{
    int low = 0, high, mid;

    high = len - 1;
    while (low <= high)
    {
        mid= (low+high)/2;
        if(x < v[mid])
            high =mid ;
        else{
            low = mid +1;
        }
    }
    if (low < len && v[low] == x) {
        return low;
    }
    return -1;
}

/**
 * @name Exercise 3-3
 * @brief expanding shorhand notations
 */
#include <stdio.h>
#include <ctype.h>

#define isEXP(PREV,NEXT) ((islower(PREV)&&islower(NEXT))||(isupper(PREV)&&isupper(NEXT))||(isdigit(PREV)&&isdigit(NEXT)))

#define MAX_SIZE 1024

void expand(char s1[],char s2[]);

int main(){
    char s[MAX_SIZE], ret[MAX_SIZE];
    fgets(s,MAX_SIZE,stdin);
    expand(s,ret);
    printf("before: %s \nand after: %s\n",s,ret);
    
    return 0;
}

/**
 * @brief expanding shorthand notations from s1 into s2
 * 
 * @param s1 the origins of the notations
 * @param s2 the result
 */
void expand(char s1[],char s2[]){
    int i,j;
    for ( i = 0; s1[i]!='\0'; i++)
    {
        for (int i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == '-' && i && isExp(s1[i - 1], s1[i + 1]))
		{
			j--;
			if (s1[i - 1] <= s1[i + 1])
				for (char c = s1[i - 1]; c <= s1[i + 1]; c++)
					s2[j++] = c;
			else
				for (char c = s1[i - 1]; c >= s1[i + 1]; c--)
					s2[j++] = c;
			i++;
		}
		else
			s2[j++] = s1[i];
	}
	s2[j] = '\0';
    }
    
}

/**
 * @name Exercise 3-5
 * @brief converts the integer n into base b charecter in the string s.
 * @pre base has to be between 2 to 36(digits+AtoZ)
 */
#include <stdio.h>

void itob(int n,char s[],int b);

void itob(int n, char s[],int b){
    static char digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    int indx,sign =n;
    if(sign<0)
        n*=-1;

    
    while(n>0){
        s[indx++] = digits[n%b];
        n /=b;
    }
    if(sign<0){
        s[indx++]='-';
    }
    s[indx] = '\0';

    int i,chr;
    for ( i = 0; i < indx; i++,indx--)
    {
        chr = s[i];
        s[i] = s[indx];
        s[indx] = chr;
    }
    
}
