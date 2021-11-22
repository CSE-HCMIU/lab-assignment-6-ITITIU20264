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
    char* single_digits[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    char* two_digits[] = { "", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    char* tens_multiple[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    char* tens_power[] = { "hundred", "thousand" };
    if (lenght == 1) 
	{
        printf("%s\n", single_digits[*number - '0']);
        return;
    }
    while (*number != '\0') 
	{
        if (lenght >= 3) 
		{
            if (*number - '0' != 0) 
			{
                printf("%s ", single_digits[*number - '0']);
                printf("%s ", tens_power[lenght - 3]); 
            }
            lenght--;
        }
 
        /* Code path for last 2 digits */
        else 
		{
            if (*number == '1') 
			{
                int sum = *number - '0' + *(number + 1) - '0';
                printf("%s\n", two_digits[sum]);
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
                printf("%s ", i ? tens_multiple[i] : "");
                ++number;
                if (*number != '0')
                    printf("%s ", single_digits[*number - '0']);
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
