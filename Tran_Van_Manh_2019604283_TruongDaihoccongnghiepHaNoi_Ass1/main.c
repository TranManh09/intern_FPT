#include<stdio.h>
#include<stdint.h>
#include"fibonacci.h"


int main()
{	/*declare array*/
	int s,n,i;
	unsigned long long int a[2]={0,1};
	unsigned long long int b[2]={0,1};
	unsigned long long int c[2]={0,0};
	unsigned long long int d[2]={0,0};
	
	do /*while n<1 or n>=100 then input again n from 1 to 100 then prunsigned long int fibonacci number */
	{	
		printf("nhap n tu 1 den 100:");
		scanf("%lld",&n);
	
	}
	while(n<1 || n>101);
		
	if (n>=1 && n<=93)
	{
		
		printf("gia tri cua Fibonacci la: %llu",fibonacci(n));
	}
	else if(n >93)
	{   /*Use arrays to avoid overflow, remove the last 2 numbers and assign number to the array*/
	     a[0] = fibonacci(93)/100;/*take the whole part*/
	     a[1] = fibonacci(93)%100;/*take the remainder*/
	     b[0] = fibonacci(92)/100;/*take the whole part*/
	     b[1] = fibonacci(92)%100;/*take the remainder*/
	     
	     /*declare to caculate 94th because a[0] = b[0], b[0] = c[0], c[0] = a[0] + b[0] + (a[1] + b[1])/100; */
	     c[0] = a[0];
	     c[1] = a[1];
	     
	     /*use to caculate number input*/
	     for(i = 93; i< n;i++)
        {
                a[0] = b[0];
                a[1] = b[1];
                b[0] = c[0];
                b[1] = c[1];
                c[1] = a[1] + b[1];
                d[0] = c[1];/*assign variable to compare d[0] */
                /*take the remainder and the whole part  of sum a[1] and b[1] then add c[0] to caulate value of ordinal numbers */
                if(c[1]>99)
                {
                    c[1] = (a[1] + b[1])%100;
                    //d[1] =(a[1] + b[1])/10;
                    c[0] = a[0] + b[0] + (a[1] + b[1])/100;
                    
                }
                else
                {
                    c[0] = a[0] + b[0] + (a[1] + b[1])/100;
                    c[1] = (a[1] + b[1])%100;
                }
               
        }
        if(d[0]>99)
	    {
	        if(d[0]>110)
	        {
	            printf("gia tri cua Fibonacci la:%llu%llu\n",c[0],c[1]);
	        }
	        else
	        {
	        printf("gia tri cua Fibonacci la:%llu%llu%llu\n",c[0],d[1],c[1]);
	        }
	    }
	    else
	    {
	        printf("gia tri cua Fibonacci la: %llu%llu\n",c[0],c[1]);
	    }
	     
	}
	
		
	return 0;
}
