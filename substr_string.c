#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>

/**
 * strchr() : locate first occurrence of character in strings
 * strstr() : locate substring within a string
 * strtok() : split a string into tokens
 * 
 * Task 1 : find all occurrences of a character inside a string 
 *          and format the result as in this example:
 *          "This is a simple string"
 *              ^  ^   ^      ^                     
 */

int find_all_occurrences(char str[], char c, int indexes[]) {
    int found = 0;
    char *pstr = str;
    do
    {
        pstr = strchr(pstr, c);
        // if we find a corresponding char (i.e strchr returns a pointer that is not null)
        // we can calculate the offset 
        //   between the char found and the base address of our string
        if (pstr)
        {
            indexes[found++] = pstr - str; 
            // we increment the pointer used for the search 
            // so the search resumes at the next character in the evaluated string 
            pstr++; 
        }
    } while (pstr); // same as pstr != NULL
    return found;
} 

void print_occurrences(char str[], int occurrences[], int found) {
    char pattern[strlen(str) + 1]; // +1 to save a slot for the null character
    memset(pattern , ' ' , sizeof(pattern));
    for (int i = 0; i < found; i++)
    {
        pattern[occurrences[i]] = '^';
    }
    pattern[sizeof(pattern) - 1] = '\0';
    printf("%s\n", str);
    printf("%s\n", pattern);
}

int main() {

    printf("====String Searching and Tokenizing===\n");
    char str[] = "this is a simple string";
    int occurrences[sizeof(str)];

    int found = find_all_occurrences(str, 's', occurrences);
    printf("found: %d in %s\n", found, str);
    print_occurrences(str, occurrences, found);

    printf("%s\n", strchr("test", 'e'));
    return 0;
}