//
// Created by traceback on 2/16/20.
//

#ifndef CHESSBOARD_COVER_ALGORITHM_H
#define CHESSBOARD_COVER_ALGORITHM_H

#include "datastructure.h"
#include <stdio.h>

/* neighbour is a null pointer, it will be allocated in this function
 * return 0 if no final answer was found
 * return 1 if found
 */
int findNeighbour(node_t *node, node_t **neighbour, unsigned int k);

void printNode(node_t *node, unsigned int k, FILE *outfile);

#endif // CHESSBOARD_COVER_ALGORITHM_H
