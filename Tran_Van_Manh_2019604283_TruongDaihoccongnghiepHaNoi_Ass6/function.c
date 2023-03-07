/*******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lib.h"

/*******************************************************************************
* global Variables
******************************************************************************/

uint8_t assignment4[20] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

uint8_t next[20] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

uint8_t list[20];
uint8_t head = 0xFF;

/*******************************************************************************
* Function
******************************************************************************/

/*create node*/
void create_node()
{
    int32_t i;
    int32_t vt;
    int32_t value=0xFF;
    int32_t j;
    int32_t t;
    /*enter index from 0 to 19, enter again if index<0 or index>19*/
    do
    {
        printf("please enter index from 0 to 19: ");
        scanf("%d",&vt);
            /*compare vt with 0 and 19*/
            if(vt<0 || vt>19)
            {
                printf("index is not in the range 0 to 19, ");
            }
            /*compare value with 0xFF*/
            else if(assignment4[vt]!= 0xFF)
            {
                printf("index had value, ");
            }
    }
    /*enter again if index<0 or index>19*/
    while(vt<0 || vt>19 || assignment4[vt]!= 0xFF);
    
    /*enter value from 0 to 100*/
    do
    {
        printf("\nenter value from 0 to 100: ");
        scanf("%d",&value);
        for(i=0;i<20;i++)
        {
            /*re-enter the value if the value duplicate the value in the array*/
            if(assignment4[i] == value)
            {
                printf("value is duplicate, ");
                printf("enter again value from 0 to 100: ");
                scanf("%d",&value);
                i=-1;
            }
        }
    }
    /*enter again if value<0 or value>100*/
    while(value<0 ||value>100);
    {
        assignment4[vt] = value;
    }

}

/*delete node*/
void delete_node()
{
    int32_t i;
    int32_t value;
    int32_t dem;
    
    printf("\nenter value you want delete: ");
    scanf("%d",&value);
    if(value<0 || value>100)
    {
        printf("\n value doesn't range 0 and 100\n",value);
    }
    else
    {
        for(i=0;i<20;i++)
        {
            next[i] = 0xFF;
            if(assignment4[i] ==value)
            {
                assignment4[i] = 0xFF;
                dem=0;
                break;
            }
            else
            {
                dem=1;
            }

        }
    }

    if(dem==1)
    {
        printf("\n don't exist the value you want to delete");

    }
    
}
/*arrange nodes to create next*/
void arrange_nodes()
{
    int32_t i;
    int32_t j;
    int32_t t;
    int32_t min;
    int32_t temp;
    /*assign value of assignment4[] for list[]*/
    for(t=0;t<20;t++)
    {
        /*assign the value of assignment4 for a[] to creat next*/
        list[t] = assignment4[t];
    }
    for(i = 0; i < 19; i++){
        for(j = i + 1; j < 20; j++){
            if(list[i] > list[j]){
            /* permutation 2 numbers a and b*/
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
            }
        }
    }
}

/*create next*/
void cerate_pnext()
{
    int32_t i;
    int32_t j;
    int32_t index =0;
    int32_t min;
    
    arrange_nodes();
    /*list[0] is min because it's sorted*/
    min = list[0];
    
    for(i = 0; i < 19; i++){
        if(list[i]!= 0xFF)
        {
            for(j = 0; j < 20; j++){
                    if(list[i] == min && list[i] == assignment4[j])
                    {/*index is index of next*/
                        index= j;
                    }
                    else if(list[i] == assignment4[j]){
                    /*assign index of next equal to index of assignment4*/
                        next[index] = j;
                        index= j;
                    }
            }
        }
    }
}
/*print unsorted element*/
void print_unsorted_element()
{
    int32_t i1;
    int32_t i2;
    int32_t i3;
    
    cerate_pnext();
    
    printf("index\t   : ");
    for(i1=0;i1<20;i1++)
    {
        if(assignment4[i1]!=0xFF)
        {
            printf("%4d ",i1);
        }
    }
    
    printf("\nassignment4: ");
    for(i2=0;i2<20;i2++)
    {
        if(assignment4[i2]!=0xFF)
        {
            printf("%4d ", assignment4[i2]);
        }
    }
    
    printf("\nnext \t   : ");
    for(i3=0;i3<20;i3++)
    {
        if(assignment4[i3]!=0xFF)
        {
            printf("%4d ", next[i3]);
        }
    }
}
/*print sorted element*/
void print_sorted_element()
{
    int32_t t1;
    int32_t t2;
    int32_t t3;
    int32_t g;
    int32_t min;
    
    cerate_pnext();
    min = list[0];
    head = min;
    
    printf("index\t   : ");
    for(t1=0;t1<20;t1++)
    {
        if(assignment4[t1] == min)
        {
            printf("%4d ",t1);
            if(next[t1] ==0xFF)
            {
                break;
            }
            else
            {
                printf("%4d ",next[t1]);
                /*to to print the index of the next assignment4 with pnext*/
                t1= next[t1] -1;
                g=1;
            }
        }
        else if(g==1)
        {
            if(next[t1] ==0xFF)
            {
                break;
            }
            else
            {
                printf("%4d ",next[t1]);
                /*to to print the index of the next assignment4 with pnext*/
                t1= next[t1] -1;
            }
        }
        
    }
    g=0;
    
    printf("\nassignment4: ");
    for(t2=0;t2<20;t2++)
    {
        if(assignment4[t2] != 0xFF)
        {
            if(assignment4[t2] == min)
            {
                printf("%4d ",min);
                printf("%4d ",assignment4[next[t2]]);
                /*to to print the value of the next assignment4 with pnext*/
                t2= next[t2] -1;
                g=1;
            }
            else if(g==1)
            {
                if(next[t2] ==0x0FF)
                {
                    break;
                }
                else
                {
                    printf("%4d ",assignment4[next[t2]]);
                    /*to to print the value of the next assignment4 with pnext*/
                    t2= next[t2] -1;
                }
            }
        }
        
    }
    g=0;
    printf("\nnext  \t   : ");
    for(t3=0;t3<20;t3++)
    {
        if(assignment4[t3] == min)
        {
            printf("%4d ",next[t3]);
            /*to to print the index of the next assignment4 with pnext*/
            t3= next[t3] -1;
            g=1;
        }
        else if(g==1)
        {
                printf("%4d ",next[t3]);
                /*to to print the index of the next assignment4 with pnext*/
                t3= next[t3] -1;
        }

    }

}
/*options to choice*/
void options()
{
    int32_t options1;/*option to choice*/
    int32_t options2;/*option to choice*/
    int32_t add;
    int32_t i;
    
    printf("\nnhap options: ");
    scanf("%d",&options1);
    switch(options1)
    {
        case 1:
            system("cls");
            printf("enter number want add: ");
            scanf("%d",&add);
            for(i=0;i<add;i++)
            {
                printf("enter number %d",i+1);
                printf("\n");
                create_node();
                system("cls");

            }
        break;
        case 2:
            system("cls");
            delete_node();
            
        break;
        case 3:
            system("cls");
            printf("-----choice 1 into 2 options-----\n");
            printf("enter 1 to print unsorted array\n");
            printf("enter 2 to print sorted array\n");
            printf("enter option: ");
            scanf("%d",&options2);
            switch(options2)
            {
                case 1:
                    system("cls");
                    printf("\n-----value of assignment4-----\n");
                    print_unsorted_element();

                break;
                case 2:
                    system("cls");
                    printf("\n-----array after arrange-----\n");
                    print_sorted_element();
                break;
                default:
                break;
            }
        break;
        default:
        break;

    }
}
/*******************************************************************************
* End  of Function
******************************************************************************/
