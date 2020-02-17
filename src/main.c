#include <stdio.h>
#include <stdlib.h>
#include "algorithm.h"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		fprintf(stderr, "ERROR: too few or too many args\n");
		return -1;
	}
	unsigned int k = strtoul(argv[1], NULL, 10);
	unsigned int pos = strtoul(argv[2], NULL, 10);
	const char *outfile = argv[3];
	if (pos >= (1u << (2 * k)))
	{
		fprintf(stderr, "ERROR: special point's position run out of the chessboard\n       or 'k' is too large\n");
		return -1;
	}
	FILE *fout = fopen(outfile, "w");
	list_t *list = initList(k, pos);

	while (list->head)
	{
		node_t *node = pop(list);
		printNode(node, k, fout);
		node_t *neighbour = NULL;
		int find_answer = findNeighbour(node, &neighbour, k);
		freeNode(node);
		if (find_answer)
		{
			printNode(neighbour, k, fout);
			freeNode(neighbour);
			fprintf(fout, "SUCCESS\n");
			fclose(fout);
			freeList(list);
			return 0;
		}
		insert(list, neighbour);
	}
	fprintf(fout, "No solution\n");
	fclose(fout);
	freeList(list);
	return 0;
}
