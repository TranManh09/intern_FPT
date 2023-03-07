#ifndef _linked_H_
#define _linked_H_

/*******************************************************************************
 * Type defination
 ******************************************************************************/

typedef struct sinh_vien {
    uint8_t name[20];
    uint8_t id;
    uint8_t math;
    struct sinh_vien *next;
}node;

/*******************************************************************************
*                                   API
******************************************************************************/

/**
* @brief create element of node
* @param[in]    none
* @param[out]   none
* @returns temp: nodes
*/
node * Create_Node();
/**
* @brief add students
* @param[in]    none
* @param[out]   none
* @returns head: nodes
*/
node* addstudent();
/**
* @brief find a student with id
* @param[in]    none
* @param[out]   none
* @returns      none
*/
uint32_t Search();

/**
* @brief delete student with id
* @param[in]    none
* @param[out]   none
* @returns 0
*/
void del_element();

/**
* @brief Dynamically allocate 10 bytes for a pointer
* @param[in]    none
* @param[out]   none
* @returns      none
*/
void output();

/**
* @brief opions to change node
* @param[in]    none
* @param[out]   none
* @returns      none
*/
void options(char *b);
#endif/*_linked_H_*/
