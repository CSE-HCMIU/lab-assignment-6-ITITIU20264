/*
1. Receive a maximum 4-digit integer n. Write a program to read the number n.
 ________________________________________________
| Input: 1234                                    |
| Output: one thousand two hundred thirty four   |
|________________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Ex1(char* number){
	//Your codes here
	int lenght = strlen(number); 
    char* singledigits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char* twodigits[] = {"", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char* tensmultiple[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char* tensower[] = {"hundred", "thousand"};
    if (lenght == 1) 
	{
        printf("%s\n", singledigits[*number - '0']);
        return;
    }
    while (*number != '\0') 
	{
        if (lenght >= 3) 
		{
            if (*number - '0' != 0) 
			{
                printf("%s ", singledigits[*number - '0']);
                printf("%s ", tensower[lenght - 3]); 
            }
            lenght--;
        }
 
        /* Code path for last 2 digits */
        else 
		{
            if (*number == '1') 
			{
                int sum = *number - '0' + *(number + 1) - '0';
                printf("%s\n", twodigits[sum]);
                return;
            }
            else if (*number == '2' && *(number + 1) == '0') 
			{
                printf("twenty\n");
                return;
            }
            else 
			{
                int i = *number - '0';
                printf("%s ", i ? tensmultiple[i] : "");
                ++number;
                if (*number != '0')
                    printf("%s ", singledigits[*number - '0']);
            }
        }
        number++;
    }
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	char *n = argv[1];
	
	Ex1(n);
	
	return 0;
}
