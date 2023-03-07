/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"

/*******************************************************************************
* global Variables
******************************************************************************/
int dem =0;
int max =0;
/*sum of lines*/
int next  =0;

/*******************************************************************************
* Function
******************************************************************************/
/*convert string to hex*/
uint8_t convert_string_to_hex(uint8_t varHigh, uint8_t varLow)
{
    uint8_t value = 0;
    uint8_t tmpLow = 0;
    uint8_t tmpHigh = 0;
    /*change value low bit*/
    if(varLow <= 'F' && varLow >= 'A')
    {/**/
        tmpLow = varLow - 55;
    }
    else
    {
        tmpLow = varLow - 48;
    }
    /*change value low bit*/
    if(varHigh <= 'F' && varHigh >= 'A')
    {
        tmpHigh = varHigh - 55;
    }
    else
    {
        tmpHigh = varHigh - 48;
    }
    /*change bit*/
    value = (tmpHigh << 4 | tmpLow);
    return value;
}

/*check 'S'*/
uint8_t check_S(uint8_t * line)
{
    uint8_t type;
    int32_t checkToPrint=0;

    /*check S*/
    if(line[0] != 'S')
    {
        printf("\nwrong line %d 1st character is %c change to S\n",dem,line[0]);
        checkToPrint =1;
    }
    type = line[1] - '0';
    /*check 2nd of each line */
    if(type <0 || type >9)
    {
        printf("\nwrong line %d 1st character is %c\n", dem, line[1]);
        checkToPrint =1;
    }
    return checkToPrint;
}

/*check byte count*/
uint8_t check_byte_count(uint8_t * line)
{
    int32_t convert;
    int32_t i;
    uint8_t check_line = strlen(line);
    int32_t checkToPrint=0;

    /*convert bytecount to compare*/
    convert=  convert_string_to_hex(line[2], line[3]);
    /*count the number of bytes*/
    for(i=0;i<strlen(line);i++)
    {
        if(line[i] == '\n')
        {
            check_line = i;
        }
    }
    /*check byte count*/
    if((check_line - 4) != (convert*2))
    {
    printf("\nwrong line is %d", dem);
    printf("\nbyte count don't sum of address,data end checkSum\n");
    checkToPrint =1;
    }
    return checkToPrint;
}

/*check hexadecimal*/
uint8_t check_hexa(uint8_t *line)
{
    int32_t i;
    int32_t num =0;
    int32_t checkToPrint=0;

    /*check hexadecimal*/
    for(i=1; i< strlen(line) -1 ;i++)
    {
        if(line[i] < '0' || line[i] > 'F')
        {
            printf("\nwrong line %d number character %d is: %c\n", dem, i,line[i]);
            checkToPrint =1;
        }
    }
    return checkToPrint;
}

/*compare checkSum with sum of byte count, address and data*/
uint8_t compare_checkSum(int32_t n1, int32_t n2)
{
    // array to store binary number
    uint8_t binaryNum1[32];
    // counter for binary array
    int32_t i1 = 0;
    int32_t j1;
    int32_t j2;
    int32_t k=7;
    int32_t sum=0;
    int32_t checkToPrint=0;

    while (n1 > 0) {

        // storing remainder in binary array
        binaryNum1[i1] = n1 % 2;
        n1 = n1 / 2;
        i1++;
    }
    /*if i1 <8, add '0' into head to calculate the complement*/
    if(i1<8)
    {

    for (j2= i1; j2<8; j2++)
    {
        /*add '0' at the end*/
        binaryNum1[i1] = 0;
        /*add value to array binaryNum1[i1] for enough 8 bit*/
        i1++;
    }
    }
    /*printing array's complement  in reverse order*/
    for (j1 = 7; j1 >= 0; j1--)
    {

        if(binaryNum1[j1] == 0)
        {
            /*convert 0 to 1*/
            binaryNum1[j1] =1;
            /*calculate decimal*/
            sum = sum + binaryNum1[j1] *pow(2,k);
            k--;
        }
        else
        {
            binaryNum1[j1] =0;
            sum = sum + binaryNum1[j1] *pow(2,k);
            k--;
        }
    }
    /*compare two decimal n1 and n2*/
    if(sum !=n2)
    {
        printf("\nwrong line %d",dem);
        printf("\ncheckSum not equal to byte count + address + data");
        printf("\ncheck again byte count, address, data\n");
        checkToPrint =1;
    }
    return checkToPrint;

}
/*check Checksum*/
uint8_t check_sum( uint8_t * line)
{
    int32_t check_line = strlen(line);
    int32_t type;
    int32_t sum = 0;
    int32_t convertCheckSum=0;
    int32_t  i;
    int32_t j;
    int32_t compareCheckSum;
    /*count the number of bytes*/
    for(j =0 ; j <strlen(line);j++)
    {
        if(line[j] == '\n')
        {
            check_line = j;
        }
    }
    /*kiem tra checkSum*/
    for(i =2 ; i <=(check_line -4);i++)
    {
        sum=  sum+convert_string_to_hex(line[i], line[i+1]);
        i++;
    }
    convertCheckSum=convert_string_to_hex(line[check_line-2],
    line[check_line-1]);

    compareCheckSum = compare_checkSum(sum, convertCheckSum);

     return compareCheckSum;
}

/*check type to compare record*/
uint8_t check_line_count_Type( uint8_t * line)
{
    //int check_line = strlen(line);
    int32_t i;
    int32_t num=0;

        if(line[1] =='1')
        {
            num = 1;
        }
        else if(line[1] =='2')
        {
            num = 2;
        }
        else if(line[1] =='3')
        {
            num = 3;
        }
    return num;
}
/*check record*/
uint8_t Check_Data_Record(uint8_t * fileName)
{
    int32_t checkLineCountType;
    uint8_t line[255];
    uint8_t num[3]= {0,0,0};
    int32_t temp =0;
    int32_t i;
    int32_t max_value;

    /*open file name*/
    FILE *Fin = fopen(fileName, "r");
    /*check each line*/
    while (fgets(line, sizeof(line), Fin) != NULL)
    {
        next++;
        checkLineCountType = check_line_count_Type(line);
        /*count number s1, s2 s3*/
        if(checkLineCountType ==1)
        {
            num[0]++;
        }
        else if(checkLineCountType ==2)
        {
            num[1]++;
        }
        else if(checkLineCountType ==3)
        {
            num[2]++;
        }
    }
    /*close file name*/
    fclose(Fin);
    max_value = num[0];
    /*compare number end return max is s1 or s2 ors3*/
    for(i=1; i< 3;i++)
    {
        if(max_value<num[i])
        {
            max_value = num[i];
            max =i+1;
        }
        else
        {
            max_value = max_value;
            max =1;
        }
    }
    return max;
}

uint8_t check_Line_Counts(uint8_t * line)
{
    int32_t check_line = strlen(line);
    int32_t sum=0;
    int32_t list1[7]= {0,0,0,0,0,0,0};
    int32_t i;
    int32_t j;
    int32_t checkToPrint=0;

    /*count the number of bytes*/
    for(j =0 ; j <strlen(line);j++)
    {
        if(line[j] == '\n')
        {
            check_line = j;
        }
    }
    /*check line s5*/
    if(line[1] =='5')
    {
        for(i =4 ; i <=(check_line -3);i++)
        {
            /*count sum of byte address*/
            if(line[i]=='0'){ line[i] =0;}
            else if(line[i]=='1')
            {
                line[i] =1;
            }
            else if(line[i]=='2'){
                list1[i] =2;
            }
            else if(line[i]=='3'){
                list1[i] =3;
            }
            else if(line[i]=='4'){
                list1[i] =4;
                }
            else if(line[i]=='5'){
            list1[i] =5;
            }
            else if(line[i]=='6'){
            list1[i] =6;
            }
            else if(line[i]=='7'){
            list1[i] =7;
            }
            else if(line[i]=='8'){
            list1[i] =8;
            }
            else if(line[i]=='9'){
            list1[i] =9;
            }
        }
        /*calculate number of address of S5*/
           sum = list1[4]*1000 + list1[5]*100+ list1[6]*10 + list1[7];

        /*compare address and number of line*/
        if(sum != (next -3))
        {
            printf("\nwrong address line %d",dem);
            checkToPrint =1;
        }
    }
    return checkToPrint;
}

/*check the end of file*/
uint8_t check_end(uint8_t *line)
{
    int32_t check;
    int32_t checkToPrint=0;
    //uint8_t line[255];
    /*check type of the end of file*/
    if(max ==1)
    {   /*check type of the end of line*/
        if(line[1]!= '9')
        {
            printf("\nwrong line %d 1st character need change to 9",dem);
            checkToPrint =1;
        }
    }
    else if(max ==2)
    {
        if(line[1]!= '8')
        {
            printf("\nwrong line %d 1st character need change to 8",dem);
            checkToPrint =1;
        }
    }
    else if(max ==3)
    {
        if(line[1]!= '7')
        {
            printf("\nwrong line %d 1st character need change to 7",dem);
            checkToPrint =1;
        }
    }
    return checkToPrint;
}

/*******************************************************************************
 * End of file
 ******************************************************************************/
