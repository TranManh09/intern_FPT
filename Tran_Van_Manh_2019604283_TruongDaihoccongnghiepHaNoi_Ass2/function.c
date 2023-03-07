#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "lib.h"
/**
  * @brief  create input array.
  * @param  uint8_t *a: element transmission to enter array a[i] with elemwnt n input
  * @param  uint8_t n: enter n input
  * @retval None
  */

void nhapmang(uint8_t *a,uint8_t n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\na[%d]=",i+1);
		scanf("%d",a+i);
		
	}
	
}
/**
  * @brief  export input array.
  * @param  uint8_t *a: element transmission to enter array a[i] with elemwnt n input
  * @param  uint8_t n: enter n input
  * @retval None
  */
  
void inmang(uint8_t *a,uint8_t n)
{
	uint8_t i;
	for(i=0;i<n;i++)
	printf("\t%d",*(a+i));
}
/**
  * @brief  clear data array.
  * @param  uint8_t *a: element transmission to enter array a[i] with elemwnt n input
  * @param  uint8_t n: enter n input
  * @retval None
  */
void clear(uint8_t *a, uint8_t n)//function clear array
{
    uint8_t i;
    printf("\nMang sau khi xoa la:\n");
    for(i=0; *(a+i)!= '\0'; i++)//move array
    {
        *(a+i) = '\0';  
        
		printf("a[%d]= %d ",i+1,*(a+i));
		       
    }
    printf("\nmang hien hai dang rong, nhap theo huong dan\n");
    printf("enter 'c' to clear data of array\n ");
    printf("enter 'p' to print array \n ");
    printf("enter 'i' to add an element to  the array\n");
    printf("enter 'd' to remove an element to the array\n");
    printf("Enter 's' to sort the array in ascending order:\n");
    printf("Enter 'x' to sort the array in decline order\n");
    printf("enter 't' to find an element print array\n");
    printf("enter 'a' to pruint8_t to the screen the max number\n");
    printf("enter 'w' to pruint8_t to the screen the min number\n");
    printf("enter 'e' to exit program");
     
	
}

/**
  * @brief  add x to any position
  * @param  uint8_t *a: element transmission to enter array a[i] with elemwnt n input
  * @param  uint8_t n: enter n input
  * @retval None
  */
void chenx(uint8_t *a, uint8_t n)//ham them phan tu
{
    int x,i,j,o;//khai bao vi tri muon them
    printf("\nNhap vi tri muon them:");
    scanf("%d", &x);
    int y;//khai bao gia tri muon them
    printf("\nNhap phan tu muon them:");
    scanf("%d", &y);
    do
    {
    	
    		for(j=0;j<n;j++)
    		{
    	
    			if(y==*(a+j))
    		{
    			printf("\nNhap lai phan tu muon them:");
    			scanf("%d", &y);
    			j=-1;
			}
			}
		
		
	}
	while(y==*(a+j));
    if(x<=0)//Them vao dau mang
    {
        x=0;
    }else if(x>=n)//Them vao cuoi mang
    {
        x=n;
    }
    for(i=n; i>x ; i--)//dich chuyen mang de tao o trong truoc khi them
    {
        *(a+i) = *(a+i-1);        
    }
    *(a+x)=y;// chen gia tri can them y tai x
    n++;// tang so phan tu cua mang
    
    printf("\nMang sau khi them la:\n");
    inmang(a,n);//goi ham xuat mang    
}

/**
  * @brief  remove k position to array
  * @param  uint8_t *a: element transmission to enter array a[i] with elemwnt n input
  * @param  uint8_t n: enter n input
  * @retval None
  */
void xoax(uint8_t *a, uint8_t n)
{
    uint8_t x,i;
    printf("\nNhap vi tri muon xoa:");
    scanf("%d", &x);
    if(x<=0)/*if array don't have element*/
    {
        printf("Khong the xoa mang rong!");
        
    }else if(x>=n)/*position want remove*/
    {
        printf("vi tri nam ngoai mang!");
        
    }
    for(i=x; i<n ; i++)//move array	
    {
        *(a+i) = *(a+i+1);        
    }
    n--;/* decline element to array*/
    printf("\nMang sau khi xoa la:\n");
    inmang(a,n);/*call function inmang*/  
}

/**
  * @brief  sort in ascending order
  * @param  uint8_t *a: element transmission to enter array a[i] with elemwnt n input
  * @param  uint8_t n: enter n input
  * @retval None
  */
void SapXepTang(uint8_t *a,uint8_t n)
{
	uint8_t i,j,tg;
	for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j ++){
            /*if find smaller element then exchange it for 2 parts*/
            if(*(a+i) > *(a+j)){
                //hoan vi 2 phan tu
                tg = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tg;
            }
        }
    }
    printf("mang sau khi sap xep la theo chieu tang dan: ");
		inmang(a,n);
}

/**
  * @brief  sort in decline order
  * @param  uint8_t *a: element transmission to enter array a[i] with elemwnt n input
  * @param  uint8_t n: enter n input
  * @retval None
  */
void SapXepGiam(uint8_t *a,uint8_t n)
{
	uint8_t i,j,tg;
	for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j ++){
            /*if find smaller element then exchange it for 2 parts*/
            if(*(a+i) < *(a+j)){
                /*displacement element*/
                tg = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = tg;
            }
        }
    }
    printf("mang sau khi sap xep tho chieu giam dan: ");
		inmang(a,n);
}

/**
  * @brief  find k element to array
  * @param  uint8_t *a: element transmission to enter array a[i] with elemwnt n input
  * @param  uint8_t n: enter n input
  * @retval None
  */
void timkiem(uint8_t *a,uint8_t n)
{
	uint8_t i,j,pt;
	printf("nhap phan tu can tim kiem: ");
		scanf("%d",&pt);
	for(i=0;i<n;i++)
	{
		if(pt == *(a+i))
		{
			j=i;
			break;
		}
	}
	if(pt == *(a+i)){
        printf("\nTIM THAY PHAN TU %d TAI VI TRI %d", pt, j);
    }else{
        printf("\nKHONG THAY PHAN TU %d", pt);
    }
}

/**
  * @brief  find max element to array
  * @param  uint8_t *a: element transmission to enter array a[i] with elemwnt n input
  * @param  uint8_t n: enter n input
  * @retval None
  */
uint8_t maxpt(uint8_t *a,uint8_t n)
{
	uint8_t i,max=*a;
	for(i=0;i<n;i++)
	{
		if(*(a+i)>max)
		{
		max=*(a+i);
		}
	}
	return max;	
	
}
/**
  * @brief  find min element to array
  * @param  uint8_t *a: element transmission to enter array a[i] with elemwnt n input
  * @param  uint8_t n: enter n input
  * @retval None
  */
uint8_t minpt(uint8_t *a,uint8_t n)
{
	uint8_t i,min=*a;
	for(i=0;i<n;i++)
	{
		if(*(a+i)<min)
		{
		min=*(a+i);
		}
	}
	return min;	
	
}

/**
  * @brief  options of program with array a[i], input b to choose and n is element array
  * @param  uint8_t *a: element transmission to enter array a[i] with elemwnt n input
  * @param  uint8_t n: enter n input
  * @retval None
  */
void options(uint8_t *a, uint8_t *b,uint8_t n)
{
	if(strcmp(b,"c")==0)/*compare input value and options*/
	{
		clear(a,n);/*clear data array*/
	}
	if( strcmp(b,"p")==0)
	{
		if(n==0)/*if don't have element of array, pruint8_t day trong*/
		{
			printf("day trong");
		}
		else
		{
			printf("\nmang vua nhap la:");
			inmang(a,n);
		}
	}
	else if(strcmp(b,"i")==0)
	{
		chenx(a,n);
	}
	else if(strcmp(b,"d")==0)
	{
		xoax(a,n);
		
	}
 	else if(strcmp(b,"s")==0)
	{
		SapXepTang(a,n);
		
	}
	else if(strcmp(b,"x")==0)
	{
		SapXepGiam(a,n);
		
	}
	else if(strcmp(b,"t")==0)
	{
		
		timkiem(a,n);
		
	}
	else if(strcmp(b,"a")==0)
	{
		printf("so lon nhat la: %d",maxpt(a,n));
		
	}
	else if(strcmp(b,"w")==0)
	{
		printf("so nho nhat la: %d",minpt(a,n));
		
	}
	
	else if (strcmp(b,"e")==0)
	{
		exit(0);
	}
}
