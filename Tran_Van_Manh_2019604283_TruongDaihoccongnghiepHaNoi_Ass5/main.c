#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "linked.h"

/*******************************************************************************
*                           Code
******************************************************************************/

int main()
{
    int32_t n;
    int32_t i;
    int32_t j;
    char b[2];
    printf("nhap so hoc sinh n: ");
    scanf("%d",&n);
    for(i=0; i<n;i++)
    {
        printf("\n\tenter number is %d", i+1);
        addstudent();
    }
    /*print element to screen*/
    output();
    /*options to choice*/
    for(j=0; ;j++)
    {
        printf("\n option:");
        printf("\n 'i' to add students");
        printf("\n 'd' to delete students");
        printf("\n 't' to find students with id");
        printf("\n 'p' to print students");
        printf("\n enter option:");
        scanf("%s",&b);
        options(b);
        /*loop options*/
        j =-1;
    }
    return 0;
}
