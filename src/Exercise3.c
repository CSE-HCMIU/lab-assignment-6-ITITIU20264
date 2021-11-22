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

void Ex3(char *c){
	//Your codes here
	char input[1000] = "";
    char word[100] = "";
    char longestWord[100] = "";
    char shortestWord[100] = "";
    int wordIndex = 0;
    printf("Input a string: ");
    fgets(input, sizeof(input), stdin);
    for(int inputIndex = 0; inputIndex < strlen(input); inputIndex++)
    {
        while (inputIndex < strlen(input) && !isspace(input[inputIndex]) && isalnum(input[inputIndex]))
        {
            word[wordIndex++] = input[inputIndex++];
        }
        if(wordIndex != 0)
        {
            word[wordIndex] = '\0';
        }
        if(strlen(longestWord) == 0)
        {
            strcpy(longestWord, word);
        }
        if(strlen(shortestWord) == 0)
        {
            strcpy(shortestWord, word);
        }
        if(strlen(word) > strlen(longestWord))
        {
            strcpy(longestWord, word);
        }
        if(strlen(word) < strlen(shortestWord))
        {
            strcpy(shortestWord, word);
        }
        wordIndex = 0;
    }
    printf("Longest word: \'%s\'", longestWord);
    printf("\nShortest word: \'%s\'", shortestWord);
}

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	char *testcase = argv[1];
	
	Ex3(testcase);
	
	return 0;
}
