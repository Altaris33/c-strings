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
 * 
 * Substring :
 * Given a string: 
 *          "This is a simple string"   
 * Find the occurrence of a substring "simple" and format the output as follow:
 *          "This is a simple string"
 *                     ------
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

/**
 * returns -1 if the substr wasn't found
 * otherwise returns the starting index of the substr within str 
 *  (i.e an offset in position between str and substr)
 * 
 * strstr() returns a NULL pointer if the substring wasn't found
 *  otherwise it will return a pointer to the base address of the found char 
 *  if it present in str
 */
int find_substr(char str[], char substr[]) {
    char *p_sub = strstr(str, substr);
    return p_sub ? p_sub - str : -1;
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

void print_substr(char str[], char substr[], int index) {
    printf("Finding substring \"%s\":\n", substr);
    printf("%s\n", str);
    if (index >= 0)
    {
        for (int i = 0; i < index + strlen(substr); i++)
        {
            printf("%c", (i < index) ? ' ' : '-');
        }    
    }
    printf("\n");
}

int main() {

    printf("====String Searching and Tokenizing===\n");
    char str[] = "this is a simple string";
    int occurrences[sizeof(str)];

    int found = find_all_occurrences(str, 's', occurrences);
    print_occurrences(str, occurrences, found);

    char str_2[] = "this is a simple string";
    char substr[] = "simple";
    int sub_found = find_substr(str_2, substr);
    print_substr(str_2, substr, sub_found);

    return 0;
}