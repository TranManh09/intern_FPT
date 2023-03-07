#ifndef _LIB_H_
#define _LIB_H_

/*******************************************************************************
*                                   API
******************************************************************************/

/**
* @brief convert string to hex
* @param[in]    High byte, Low byte
* @param[out]   heaxa value
* @returns : hexavalue
*/
uint8_t convert_string_to_hex(uint8_t varHigh, uint8_t varLow);

/**
* @brief check 'S'
* @param[in]    line
* @param[out]   none
* @returns : none
*/
uint8_t check_S(uint8_t * line);

/**
* @brief check byte Count
* @param[in]    line
* @param[out]   none
* @returns : none
*/
void check_S5(uint8_t * line);
uint8_t check_byte_count(uint8_t * line);

/**
* @brief check hexadecimal
* @param[in]    line
* @param[out]   none
* @returns : none
*/
uint8_t check_hexa(uint8_t *line);

/**
* @brief compare CheckSum
* @param[in]    sum byte of byteCoun + address + data, checkSum
* @param[out]   none
* @returns : none
*/
uint8_t compare_checkSum(int32_t n1, int32_t n2);

/**
* @brief check CheckSum
* @param[in]    line
* @param[out]   none
* @returns : none
*/
uint8_t check_sum(uint8_t * line);

/**
* @brief check type to compare record
* @param[in]    line
* @param[out]   none
* @returns : Type
*/
uint8_t check_line_count_Type(uint8_t * line);

/**
* @brief Check Data Record
* @param[in]    file name
* @param[out]   none
* @returns : max of type
*/
uint8_t Check_Data_Record(uint8_t * fileName);

/**
* @brief check line Count
* @param[in]    line
* @param[out]   none
* @returns : none
*/
uint8_t check_Line_Counts(uint8_t * line);

/**
* @brief check end of line
* @param[in]    line
* @param[out]   none
* @returns : none
*/
uint8_t check_end(uint8_t *line);

/**
* @brief parse file
* @param[in]    line
* @param[out]   none
* @returns : none
*/
void parse_file(uint8_t * filename);
void print_space(char * filename);
#endif/*_LIB_H_*/
