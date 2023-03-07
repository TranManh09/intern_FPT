#ifndef _macro_H_
#define _macro_H_

/** @defgroup set nth in register add
  * @{
  */
# define REG_BIT_SET32(add,n) 	(*((uint32_t*)(add)) |= 1 <<n)
/**
  * @}
  */
  
  
/** @defgroup reset nth in register add
  * @{
  */
# define REG_BIT_CLEAR32(add,n) (*((uint32_t*)(add)) &= ~(1 <<n ))
/**
  * @}
  */
  
  
/** @defgroup swap nth in register add
  * @{
  */
# define SWAP_BYTE32(add) 		(*((uint32_t*)(add))= ((*((uint32_t*)(add)) >> 24) & 0x000000FF) \
								| ((*((uint32_t*)(add)) >> 8) & 0x0000FF00  ) \
								| ((*((uint32_t*)(add)) << 8) & 0x00FF0000  ) \
								| ((*((uint32_t*)(add)) << 24) & 0xFF000000 ))

# define SWAP_BYTE16(add) 		(*((uint16_t*)(add)) =  ((*((uint16_t*)(add)) >> 8) & 0x00FF ) | ((*((uint16_t*)(add)) << 8)& 0xFF00 ))
/**
  * @}
  */
  
#endif /*_macro_H_*/
