//
// Created by traceback on 2/16/20.
//

#ifndef CHESSBOARD_COVER_ALGORITHM_H
#define CHESSBOARD_COVER_ALGORITHM_H

#include "datastructure.h"
#include <stdio.h>

/* neighbour is a null pointer, it will be allocated in this function
 * return value is the num of neighbours, which are stored as a short list
 * return -1 if node is the final answer
 */
int findNeighbour(node_t *node, node_t **neighbour);

void printNode(node_t *node, unsigned int k, FILE *outfile);

#endif // CHESSBOARD_COVER_ALGORITHM_H
