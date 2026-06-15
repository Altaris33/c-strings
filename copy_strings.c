#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>

int main() {

    // Copy strings to other strings
    // strcpy & strncpy
    // both method return the address of the destination string (a pointer)
    char source[] = "I program";
    char dest[] = "Programming is fun";
    printf("Before copy: \"%s\"\n", source);
    printf("After copy: \"%s\"\n", strcpy(dest, source));

    //strncpy() is safer  
    //          It runs a check on the maximum number of element that will be copied to 
    //          the dest string
    char long_str[] = "I would program if I had the chance to get some good sleep";
    printf("Before copy: \"%s\"\n", source);
    // the null character will be missing and should be added manually after the copy
    printf("After copy: \"%s\"\n", strncpy(dest, "hello", 3));

    printf("Before copy: \"%s\"\n", source);
    printf("After copy: \"%s\"\n", strncpy(dest, "hello", sizeof(dest)));

    // the null character will be missing because the source string is greater > dest
    // and will get entirely copied without addind the \0
    // we have to add it manually to have a proper string
    // that way we are sure that after the copy operation
    // the string can be manipulated correctly
    printf("Before copy: \"%s\"\n", dest);
    strncpy(dest, long_str, sizeof(dest));
    dest[sizeof(dest) - 1] = '\0';
    printf("After copy: \"%s\"\n", dest);

    return 0;
}