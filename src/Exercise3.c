/*
3. Receive a string, find the shortest and longest word in that string.
Ex:
 __________________________________________________________
| Input: "This is a string with shortest and longest word" |
| Output: Shortest word: a                                 |
|         Longest word: shortest                           |
|__________________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void Ex3(char *str)
{
	//Your codes here
    int i;
    int j;
    int len = strlen(str);
    int Shortest = 99;
    int Longest = 1;
    int a, b;
    int sum = 0;
    for (i = 0; i <= len; ++i)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
            if(sum < Shortest)
            {
                b = i;
                Shortest = sum;
            }
            else if (sum > Longest)
            {
                Longest = sum;
                a = i;
            }
            sum = 0;
        }
        else sum ++;
    }
    printf("Shortest word: ");
    for (i = b - Shortest; i <= b -1; ++i) 
    {
        printf("%c",str[i]);
    }  
    printf("\nLongest word: ");
    for (i = a -Longest; i <= a -1; ++i) 
    {
        printf("%c",str[i]);
    }    
}	

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	char *testcase = argv[1];
	
	Ex3(testcase);
	
	return 0;
}
