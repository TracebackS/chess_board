//
// Created by traceback on 2/16/20.
//

#include "datastructure.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

list_t *initList(unsigned int k, unsigned int pos)
{
	list_t *list = (list_t *)malloc(sizeof(list_t));
	assert(list);

	list->head = (node_t *)malloc(sizeof(node_t));
	assert(list->head);

	list->head->chess_board = (char *)malloc(1u << (2 * k));
	assert(list->head->chess_board);

	memset(list->head->chess_board, EMPTY, 1u << (2 * k));
	list->head->chess_board[pos] = SPECIAL;
	list->head->next = NULL;
	list->head->first_empty_pos = pos ? 0 : 1;
	return list;
}

void freeList(list_t *list)
{
	node_t *p = list->head;
	while (p)
	{
		p = p->next;
		freeNode(list->head);
		list->head = p;
	}
	free(list);
}

void freeNode(node_t *node)
{
	free(node->chess_board);
	free(node);
}

node_t *pop(list_t *list)
{
	if (list->head == NULL)
	{
		return NULL;
	}
	node_t *node = list->head;
	list->head = list->head->next;
	return node;
}

int insert(list_t *list, node_t *node)
{
	if (!node)
	{
		return -1;
	}
	node_t *p = node;
	while (p->next)
	{
		p = p->next;
	}
	p->next = list->head;
	list->head = node;
	return 0;
}
