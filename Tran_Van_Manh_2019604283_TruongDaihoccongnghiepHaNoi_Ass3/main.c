#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "library.h"



int main()
{
    uint8_t *a;
	uint8_t b1 = 0;
	uint8_t b2 = 1;
    
	bool d = allocate10Bytes(&a);/*call function allocate10Bytes and pass to avariable a*/
	if(d == true)
	{
		
		free(a);
		return b1;
	}
	else
	{
		return b2;
	}
    
}
