#include <stdio.h>
#include <stdint.h>
#include "macro.h"



int main()
{
	uint32_t a = 0;
	REG_BIT_SET32(&a,2);/* set bit 2 in register a*/
	printf("%x", a);
	
	uint32_t b = 0x12;
	REG_BIT_CLEAR32(&b,1);/* set bit 2 in register b*/
	printf("\n%x", b);
	
	uint32_t c = 0x12345678;
	SWAP_BYTE32(&c);/* convert big endian-litte endian  with 32 byte*/
	printf("\n%x", c);
	
	uint16_t d = 0x1234;
	SWAP_BYTE16(&d);/* convert big endian-litte endian  with 16 byte*/
	printf("\n%x", d);
	return 0;
}
