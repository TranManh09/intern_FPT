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
extern int dem;
extern int max;
extern int next;

int32_t list[255];

/*******************************************************************************
* Function
******************************************************************************/
/*parse file*/
void parse_file(uint8_t * filename)
{
    int32_t checkS ;
    int32_t checkHexa;
    int32_t checkByteCount;
    int32_t checkSum;
    int32_t checkDataRecord;
    int32_t checkLineCounts;
    int32_t checkEnd =0;
    uint8_t line[255];
    int32_t a=0;/*to loop error*/
    int32_t temp;
    int32_t address=0;
    int32_t data;
    int32_t i;
    int32_t i1;
    int32_t i2;
    int32_t j;
    FILE *fin = fopen(filename, "r");
    if (fin == NULL) { // Kiem tra loi khi mo file
        printf("don't open file file %s\n", filename);
        return;
    }
    
   FILE *fout = fopen("Output.txt", "w");
    /*error checking when pen file*/
    if (fout == NULL) {
        printf("don't create file output.txt\n");
        fclose(fin);
        return;
    }
    max = Check_Data_Record(filename);
    while (fgets(line, sizeof(line), fin) != NULL)
    {
        dem++;
        /*check S*/
        checkS = check_S(line);
        /*check hexa*/
        checkHexa = check_hexa(line);
        /*check byte count*/
        checkByteCount = check_byte_count(line);
        /*checkSum*/
        checkSum = check_sum(line);
        /*check data record*/
        checkDataRecord = check_line_count_Type(line);
        /*compare checkDataRecord with each line*/
        if(checkDataRecord ==1 || checkDataRecord ==2 || checkDataRecord ==3)
        {
            /*check checkDataRecord = max of s1 or s2 or s3*/
            if(checkDataRecord !=max)
            {
                printf("\nwrong line %d 1st character\n",dem);
                /*loop when error*/
                a=1;
            }
        }
        /*check line count*/
        checkLineCounts = check_Line_Counts(line);
        /*check line the end*/
        if(next ==dem)
        {
            checkEnd = check_end(line);
        }
        /*export to file Output.txt*/
        /*check total errors*/
        if(checkS != 1 && checkHexa != 1 &&checkByteCount !=1 && checkSum !=1 &&
        a!=1 && checkLineCounts !=1 && checkEnd !=1)
        {
            
            int32_t check_line = strlen(line);
            /*count number of bytes*/
            for(j =0 ; j <strlen(line);j++)
            {
                if(line[j] == '\n')
                {
                    check_line = j;
                }
            }
            /*max is total s1 or s2 or s3 if s1 or s2 or s3 max, then compare
             it*/
            if(max ==1)
            {
                /*address caculation*/
                for(i1 =4 ; i1 <8;i1++)
                {
                    /*count sum of byte address*/
                  address=  address+convert_string_to_hex(line[i1], line[i1+1]);
                  i1++;
                }
                /* don't have data is type = S5*/
                if(line[1] =='5')
                {
                    /*convert hex to string*/
                    sprintf(list,"%d %04x ", dem,address);
                    /*export output.txt*/
                    fprintf(fout,"%s\n",list);
                }
                else
                {
                    /*convert hex to string*/
                    sprintf(list,"%d %04x ", dem,address);
                    /*export output.txt*/
                    fprintf(fout,"%s",list);
                }
                /*calculate data*/
                for(i2 =8 ; i2 <check_line-2;i2++)
                {
                    /*calulate data*/
                    data=  convert_string_to_hex(line[i2], line[i2+1]);
                    /*compare i2 with ordinal numbers of a line*/
                    if(i2 == check_line-4)
                    {
                        /*convert hex to string*/
                        sprintf(list,"%02x\n",data);
                        /*export output.txt*/
                        fprintf(fout,"%s",list);
                    }
                    else
                    {
                    sprintf(list,"%02x",data);
                    fprintf(fout,"%s",list);
                    }

                    i2++;
                }
            /*address and data  = 0 to loop line*/
            address=0;
            data =0;
            }
            /*max is total s1 or s2 or s3 if s1 or s2 or s3 max, then compare
             it*/
            else if(max ==3)
            {
                /*convert hex to string*/
                sprintf(list,"%d ",dem);
                /*export output.txt*/
                fprintf(fout,"%s",list);
                for(i1 =4 ; i1 <12;i1++)
                {
                /*count sum of byte address*/
                    address= convert_string_to_hex(line[i1], line[i1+1]);
                    /* don't have data is type = S5*/
                    if(line[1] =='5')
                    {
                        sprintf(list,"%02x",address);
                        fprintf(fout,"%s",list);
                        /*because S5 don't have data,
                        so check ordinal number last of data*/
                        if(i1 == 6)
                        {
                            fprintf(fout,"%s","\n");
                        }
                    }
                    /*check S0 to space*/
                    if(line[1] =='0')
                    {
                        sprintf(list,"%02x",address);
                        fprintf(fout,"%s",list);
                        /*because S5 don't have data,
                        so check ordinal number last of data*/
                        if(i1 == 6)
                        {
                            fprintf(fout,"%s"," ");
                            /*check S0 to space*/
                            temp=1;
                        }
                    }
                    else
                    {
                        sprintf(list,"%02x",address);
                        fprintf(fout,"%s",list);
                        /*check S0 to space*/
                        temp=0;
                    }
                    i1++;
                    }
                    /*check S0 to space*/
                    if(temp!=1)
                    {
                        /*export space*/
                        fprintf(fout,"%s"," ");
                    }
                /*check data form ordinal number head data*/
                for(i2 =12 ; i2 <check_line-2;i2++)
                {
                    /*count sum of byte address*/
                    data=  convert_string_to_hex(line[i2], line[i2+1]);
                    /*check the ordinal number of last data*/
                    if(i2 == check_line-4)
                    {
                        sprintf(list,"%02x",data);
                        fprintf(fout,"%s\n",list);
                    }
                    else
                    {
                        sprintf(list,"%02x",data);
                        fprintf(fout,"%s",list);
                    }
                
                    i2++;
                }
                /*address and data  = 0 to loop line*/
                address=0;
                data =0;
            }
        }
        a=0;
    }
    
    fclose(fin);
    fclose(fout);
}
