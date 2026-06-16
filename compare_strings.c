#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>

int main() {

    char str_1[] = "abcd";
    char str_2[] = "abcz";

    // COMPARING STRINGS
    // functions: strcmp() and strncmp()
    // it compares each char item from the strings based on their ASCII value
    // ex: 'a' < 'b' < 'c' ...
    // strcmp stops after a first difference in char item is found
    printf("strcmp [%s vs %s] : %d\n", str_1, str_2, strcmp(str_1, str_2));

    // the null character gets encountered at the end of "abc" 
    // its value is 0 so it is always < any character
    char str_3[] = "abc";
    char str_4[] = "abcaaa";
    printf("strcmp [%s vs %s] : %d\n", str_3, str_4, strcmp(str_3, str_4));

    printf("strncmp [%s vs %s] : %d\n", str_3, str_4, strncmp(str_3, str_4, 3));

    return 0;
}