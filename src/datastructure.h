//
// Created by traceback on 2/16/20.
//

#ifndef CHESSBOARD_COVER_DATASTRUCTURE_H
#define CHESSBOARD_COVER_DATASTRUCTURE_H

/*
 * TYPE1:  #
 *        ##
 *
 * TYPE2: #
 *        ##
 *
 * TYPE3: ##
 *         #
 *
 * TYPE4: ##
 *        #
 */
typedef enum
{
	EMPTY = 0,
	TYPE1,
	TYPE2,
	TYPE3,
	TYPE4,
	SPECIAL
} POINT_STATE;

typedef struct node
{
	char *chess_board; // char [1 << (2 * k)]
	struct node *next;
	unsigned int first_empty_pos;
} node_t;

typedef struct list
{
	node_t *head;
} list_t;

list_t *initList(unsigned int k, unsigned int pos);
void freeList(list_t *list);
void freeNode(node_t *node);

// get the pointer of the list head, and delete the head from the list
node_t *pop(list_t *list);

// insert node_list to the front of the list's head
int insert(list_t *list, node_t *node);

#endif // CHESSBOARD_COVER_DATASTRUCTURE_H
