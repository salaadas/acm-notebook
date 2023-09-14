#include <stdio.h>

void main()
{
    char *temp = "Paras";

    int i;
    i=0;

    temp[3]='F'; // we cannot modify a string literal assigned to a char pointer

    for (i =0 ; i < 5 ; i++ )
        printf("%c\n", temp[i]);


}
