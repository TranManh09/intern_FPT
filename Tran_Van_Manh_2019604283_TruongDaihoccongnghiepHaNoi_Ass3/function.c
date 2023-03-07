#include <stdbool.h>
#include <stdint.h>
#include "library.h"

bool allocate10Bytes(uint8_t *outPtr);
bool allocate10Bytes(uint8_t *outPtr)
{
	uint16_t *y = (uint16_t*)outPtr;
    y = (uint16_t *)malloc(10*sizeof(uint16_t));/*perform memory allocation for the outPtr variable and specify the number of bytes to allocate*/

    if(outPtr == NULL) /*if outPtr is NULL, function return false or  return true if outPtr difference NULL*/
    {
    	
	 	return false;
	}
	else
	 {
    	return true;
	  }
	  
}
