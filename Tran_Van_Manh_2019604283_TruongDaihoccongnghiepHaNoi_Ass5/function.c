/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "linked.h"
/*******************************************************************************
* global Variables
******************************************************************************/
node *head = NULL;
node *tail = NULL;

/*******************************************************************************
* Function
******************************************************************************/

/*create new node*/
node * Create_Node()
{
    int32_t a1;
    int32_t a2;
    node *temp = NULL;
    temp = (node*)malloc(sizeof(node));
    temp->next = NULL;

    if (temp != NULL)
    {
        /* Enter name */
        do
        {
            printf("\nPress name: ");
            fflush(stdin);
            gets(temp->name);
        }
        /*enter name again if name is capacity*/
        while(strcmp(temp->name,"")==0);
        
        /*enter id*/
        
        printf("\nPress ID: ");
        fflush(stdin);
        scanf("%d", &a1);
        temp->id = a1;
        
        /*enter math score form 0 to 10*/
        do
        {
        printf("\nPress math score: ");
        fflush(stdin);
        scanf("%d", &a2);
        temp->math = a2;
        if(a2<0 || a2 >10)
        {
            printf("\nenter math score form 0 to 10");
        }
        }
        /*enter math score if a2 don't form 0 to 10*/
        while(a2<0 || a2 >10);
        
        return temp;

    }
    else {
        printf("Cann't allocate memory !!!");
    }
}
/*add student*/
node* addstudent()
{
    int32_t a=0;
    node *temp = NULL;
    node *current = NULL;
    temp = Create_Node();
    
    if(head == NULL){
        head =tail= temp;
    }
    else{
            for(a=0 ;a <2 ;a++)
            {
            /*check duplicate numbers id*/
            for (current = head; current != NULL; current = current->next)
            {
                if(temp->id == current->id)
                {
                    free(temp);
                    printf("\nenter again because duplicate id: %d",temp->id);
                    temp =Create_Node();
                    /*to repeat the loop*/
                    a=-1;
                    break;
                }
                else
                {
                    /*break if don't duplicate*/
                    a=2;
                }

            }
            if(a ==2)
            {
                break;
            }
            else
            {
                a=-1;
            }
            }
            /*add to the end of the list*/
            tail->next = temp;
            tail = temp;
            a=0;
            }

    return head;
}
/*find elment when enter id*/
uint32_t Search(){
    node *temp = NULL;
    int32_t ID;
    int32_t i =0;
    int8_t position = 0;
    
    printf("\nnhap id muon tim: ");
    scanf("%d",&ID);
    
    /*print an element*/
    for(temp = head; temp != NULL; temp = temp->next){
        if(temp->id == ID){
            printf("\nName");
            printf("\tID");
            printf("\tmath");
            printf("\n%s", temp->name);
            printf("\t%d", temp->id);
            printf("\t%d", temp->math);
            i=0;
            break;
        }
        else
            {
                i=1;

            }
        //++position;
    }
    if(i==1)
        {
            printf("\ndon't find id");
        }
    return 0;
}
/*delete*/
void del_element()
{
    int32_t i =0;
    int32_t ID;
    node * temp = NULL;
    node * p = NULL;
    node *k = NULL;
    
    printf("\nenter id you want to delete: ");
    scanf("%d",&ID);

    /*remove head element*/
    if(head->id == ID)
    {

        temp = head;
        head = head->next;
        temp->next = NULL;
    }
    /*remove tail element*/
    else if(tail->id == ID){
        for(k = head; k != NULL; k = k ->next)
        {
        /*if browsing to the last tail element in the list*/
            if(k->next == tail)
            {
                /*remove the last element*/
                free(tail);
                /*the element before the last element to NULL*/
                k->next = NULL;
                /*change back the last element pTail of the list*/
                tail = k;
            }
        }
    }
    else
    {
    /*iterate over the elements in the list*/
        for (temp = head; temp != NULL; temp = temp->next)
        {
            /*if find duplicate id */
            if(temp->id == ID)
            {
                /*assign node p next pointer to node temp next pointer*/
                p -> next = temp->next;
                free(temp);
                i=0;
                break;

            }
            else
            {
                i=1;

            }
            /*asaign node p with node temp*/
            p = temp;
        }
        if(i==1)
        {
            printf("\ndon't find id");
        }
    }

}

/*print element to screen*/
void output()
{
    int32_t index = 0;
    node *temp = NULL;
    system("cls");
    //    temp = head;
    printf("\n Information of some students: \n");
            printf("\nName");
            printf("\t\t\tID");
            printf("\t\t\tmath");
    for (temp = head; temp != NULL; temp = temp->next)
    {
            printf("\n%s", temp->name);
            printf("\t\t\t%d", temp->id);
            printf("\t\t\t%d", temp->math);
        /*
        printf("\nName: %s", temp->name);
        printf("\nID: %d", temp->id);
        printf("\nmath: %d", temp->math);
        */
    }
}
/*options to choice*/
void options(char *b)
{
    int32_t m;
    int32_t j;
    
    /*if b is equal to i*/
    if(strcmp(b,"i")==0)
    {
        printf("\nenter numbers student need add:");
            scanf("%d",&m);
            for(j=0; j<m;j++)
            {
                printf("\n\tenter number is %d", j+1);
                /*add students*/
                addstudent();
            }
            /*print element to screen*/
            output();
    }
    /*if b is equal to d*/
    else if(strcmp(b,"d")==0)
    {
        /*remove element*/
        del_element();
        /*print element to screen*/
        output();

    }
    /*if b is equal to t*/
    else if(strcmp(b,"t")==0)
    {
        
        system("cls");
        output();
        Search();/*find element*/
        
    }
    /*print element*/
    else if(strcmp(b,"p")==0)
    {

        output();/*find element*/

    }
    /*if b is equal to e*/
    else if (strcmp(b,"e")==0)
    {
        /*exit program*/
        exit(0);
    }
}
/*******************************************************************************
 * End of file
 ******************************************************************************/
