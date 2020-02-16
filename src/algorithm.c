//
// Created by traceback on 2/16/20.
//

#include "algorithm.h"

int findNeighbour(node_t *node, node_t **neighbour)
{
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
