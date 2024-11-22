#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TERM '\0'
#define SIZE 10
#include "header.h"



int main()
{
    char str1 [] = "MaHmOuD";
    char str2 [] = " mOhAmEd";
    char dest []= "aBcDeFgH";
    strToUpper(str1);
    strToLower(str2);

    printf("%s", str1);
    printf("%s", str2);

     printf("%d\n", strCompare("zm", "mmm"));      //  am vs mmm --> -1    mm vs mmm --> -1    zm vs mmm --> 1     mm vs mm --> 0    mm vs zmm -->-1
    printf("%d", strcmp("zm", "mmm"));
    strCopy(str1, dest, 3);
    printf("main string is: %s\n", str1);
    printf("copied string is: %s", dest);
    int size;
    printf("Enter size of the destination string: ");
    scanf("%d", &size);

    strcat(str1,str2, size);
    printf("%s", str1);
    printf("Length of string is: %d", strlen(str));*/
    return 0;
}
