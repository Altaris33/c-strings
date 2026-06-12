#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    
    printf("\n\n===Strings: Declare and Access===\n\n");

    char word[10] = {'h', 'e', 'l', 'l', 'o'};
    char another_word[] = "another world";

    // defining an array of strings i.e a 2D char array (conceptuually speaking)
    char days[][10] = {
        "monday",
        "tuesday",
        "wednesday",
        "thursday",
        "friday",
        "saturday",
        "sunday"
    };

    // defining a 1D array using an array of pointers, so an array made up of addresses. 
    // similar to a 2D array except 
    // the layout in memory will be different
    char *all_days[] = {
        "monday",
        "tuesday",
        "wednesday",
        "thursday",
        "friday",
        "saturday",
        "sunday"
    };
    
    
    // printing strings
    // 1. One way
    for (int i = 0; i < sizeof(word) / sizeof(char); i++)
    {
        printf("%c ", word[i]);
    }

    printf("\n");

    // 2. Another way
    printf("%s\n", word);
    printf("%s\n", another_word);

    printf("%s\n", &another_word[8]);
    printf("%4s\n", another_word);

    printf("\n");

    for (int i = 0; i < 7; i++)
    {
        printf("%s\n", days[i]);
    }
    printf("\n");

    for (int i = 0; i < 7; i++)
    {
        printf("%s\n", all_days[i]);
    }
    
    printf("\n");

    char input_str[20];
    // drawbacks of scanf() it only reads up to one word
    // internally, it stips any whitespace before the first encountered character 
    // and stops at the first whitespace found after the characters entered 
    printf("Enter something: ");
    scanf("%s", &input_str);
    printf("input entered: %s\n", input_str);

    return 0;
}