#include <stdio.h>
#include <string.h>

int main(){
    char s1[10] = "Hello";
    char s2[10];

    strcpy(s1, s2);

    printf("%s\n", s2);

    return 0;
}