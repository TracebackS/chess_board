//
// Created by traceback on 2/16/20.
//

#include "algorithm.h"
#include <stdlib.h>
#include <string.h>

int findNeighbour(node_t *node, node_t **neighbour, unsigned int k)
{
	node_t *p = NULL;
	/*
	 * TYPE1
	 * @a
	 * aa
	 */
	if (node->first_empty_pos % (1u << k) != 0
		&& node->first_empty_pos / (1u << k) < (1u << k) - 1
		&& node->chess_board[node->first_empty_pos + (1u << k) - 1] == EMPTY
		&& node->chess_board[node->first_empty_pos + (1u << k)] == EMPTY)
	{
		p = (node_t *)malloc(sizeof(node_t));
		*neighbour = p;
		p->chess_board = (char *)malloc(1u << (2 * k));
		memcpy(p->chess_board, node->chess_board, 1u << (2 * k));
		p->chess_board[node->first_empty_pos] = TYPE1;
		p->chess_board[node->first_empty_pos + (1u << k) - 1] = TYPE1;
		p->chess_board[node->first_empty_pos + (1u << k)] = TYPE1;
		p->first_empty_pos = node->first_empty_pos;
		p->next = NULL;
		while (p->first_empty_pos < 1u << (2 * k) && p->chess_board[p->first_empty_pos])
		{
			p->first_empty_pos++;
		}
		if (p->first_empty_pos == 1u << (2 * k))
		{
			return 1;
		}
	}
	/*
	 * TYPE2
	 * b.
	 * bb
	 */
	if (node->first_empty_pos % (1u << k) != (1u << k) - 1
		&& node->first_empty_pos / (1u << k) < (1u << k) - 1
		&& node->chess_board[node->first_empty_pos + (1u << k)] == EMPTY
		&& node->chess_board[node->first_empty_pos + (1u << k) + 1] == EMPTY)
	{
		if (!p)
		{
			p = (node_t *)malloc(sizeof(node_t));
			*neighbour = p;
		}
		else
		{
			p->next = (node_t *)malloc(sizeof(node_t));
			p = p->next;
		}
		p->chess_board = (char *)malloc(1u << (2 * k));
		memcpy(p->chess_board, node->chess_board, 1u << (2 * k));
		p->chess_board[node->first_empty_pos] = TYPE2;
		p->chess_board[node->first_empty_pos + (1u << k)] = TYPE2;
		p->chess_board[node->first_empty_pos + (1u << k) + 1] = TYPE2;
		p->first_empty_pos = node->first_empty_pos;
		p->next = NULL;
		while (p->first_empty_pos < 1u << (2 * k) && p->chess_board[p->first_empty_pos])
		{
			p->first_empty_pos++;
		}
		if (p->first_empty_pos == 1u << (2 * k))
		{
			while ((*neighbour)->next)
			{
				node_t *tmp = (*neighbour)->next;
				freeNode(*neighbour);
				*neighbour = tmp;
			}
			return 1;
		}
	}
	/*
	 * TYPE3
	 * cc
	 * .c
	 */
	if (node->first_empty_pos % (1u << k) != (1u << k) - 1
		&& node->first_empty_pos / (1u << k) < (1u << k) - 1
		&& node->chess_board[node->first_empty_pos + 1] == EMPTY
		&& node->chess_board[node->first_empty_pos + (1u << k) + 1] == EMPTY)
	{
		if (!p)
		{
			p = (node_t *)malloc(sizeof(node_t));
			*neighbour = p;
		}
		else
		{
			p->next = (node_t *)malloc(sizeof(node_t));
			p = p->next;
		}
		p->chess_board = (char *)malloc(1u << (2 * k));
		memcpy(p->chess_board, node->chess_board, 1u << (2 * k));
		p->chess_board[node->first_empty_pos] = TYPE3;
		p->chess_board[node->first_empty_pos + 1] = TYPE3;
		p->chess_board[node->first_empty_pos + (1u << k) + 1] = TYPE3;
		p->first_empty_pos = node->first_empty_pos;
		p->next = NULL;
		while (p->first_empty_pos < 1u << (2 * k) && p->chess_board[p->first_empty_pos])
		{
			p->first_empty_pos++;
		}
		if (p->first_empty_pos == 1u << (2 * k))
		{
			while ((*neighbour)->next)
			{
				node_t *tmp = (*neighbour)->next;
				freeNode(*neighbour);
				*neighbour = tmp;
			}
			return 1;
		}
	}
	/*
	 * TYPE4
	 * dd
	 * d.
	 */
	if (node->first_empty_pos % (1u << k) != (1u << k) - 1
		&& node->first_empty_pos / (1u << k) < (1u << k) - 1
		&& node->chess_board[node->first_empty_pos + 1] == EMPTY
		&& node->chess_board[node->first_empty_pos + (1u << k)] == EMPTY)
	{
		if (!p)
		{
			p = (node_t *)malloc(sizeof(node_t));
			*neighbour = p;
		}
		else
		{
			p->next = (node_t *)malloc(sizeof(node_t));
			p = p->next;
		}
		p->chess_board = (char *)malloc(1u << (2 * k));
		memcpy(p->chess_board, node->chess_board, 1u << (2 * k));
		p->chess_board[node->first_empty_pos] = TYPE4;
		p->chess_board[node->first_empty_pos + 1] = TYPE4;
		p->chess_board[node->first_empty_pos + (1u << k)] = TYPE4;
		p->first_empty_pos = node->first_empty_pos;
		p->next = NULL;
		while (p->first_empty_pos < 1u << (2 * k) && p->chess_board[p->first_empty_pos])
		{
			p->first_empty_pos++;
		}
		if (p->first_empty_pos == 1u << (2 * k))
		{
			while ((*neighbour)->next)
			{
				node_t *tmp = (*neighbour)->next;
				freeNode(*neighbour);
				*neighbour = tmp;
			}
			return 1;
		}
	}
	return 0;
}

void printNode(node_t *node, unsigned int k, FILE *outfile)
{
	unsigned int a = 1u << k;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			switch (node->chess_board[i * a + j])
			{
			case EMPTY:
				fputc('.', outfile);
				break;
			case TYPE1:
				fputc('a', outfile);
				break;
			case TYPE2:
				fputc('b', outfile);
				break;
			case TYPE3:
				fputc('c', outfile);
				break;
			case TYPE4:
				fputc('d', outfile);
				break;
			case SPECIAL:
				fputc('X', outfile);
				break;
			default:
				fprintf(outfile, "ERROR: wrong point state\n");
				return;
			}
		}
		fputc('\n', outfile);
	}
	fputc('\n', outfile);
}
