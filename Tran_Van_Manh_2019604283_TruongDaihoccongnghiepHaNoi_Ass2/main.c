#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "lib.h"
uint8_t c[100] = {0,1,2,3,4,5,6};
uint8_t main()
{
	uint8_t i,j,*a,n,pt;
	/*a or(a+i) is address and *(a) or *(a+i) is value of a, a = c <=> a = &c[0]  */
	a =c;
	uint8_t b[2];
	printf("mang hien tai la:\n");
	
	/*clear old array*/
	
	for(j=0;j<15;j++)
	{
		printf("\t%d",a[j]);
	}
	
	/*clear data of before array*/
	
	do
	{
		printf("\nnhap c de xoa mang: ");
		scanf("%s",&b);
	}
	while(strcmp(b,"c")!=0);
	{
		clear(a,100);
	}
	
	printf("\nnhap kich thuoc cua mang tu 0 den 100:");
	scanf("%d",&n);
	a=(uint8_t*)malloc(n*sizeof(uint8_t));
	
	
	if(a!= NULL)
	{
	nhapmang(a,n);
	/*use program without don't run program again*/
	for (i=0;;i++)
	{
		
		printf("\nnhap nua chon\n");
		scanf("%s",&b);
		options(a,b,n);
		if(strcmp(b,"c")==0)
		{
			printf("\nnhap kich thuoc cua mang:");
			scanf("%d",&n);
			nhapmang(a,n);
		}
		if(strcmp(b,"i")==0)
		{
			n= n+1;
		}
		else if(strcmp(b,"d")==0)
		{
			n =n-1;
		}
		
		i=0;
	}
	}
	else
	{
		printf(" Cap phat khong thanh cong !!!");
	}
	return 0;
}
