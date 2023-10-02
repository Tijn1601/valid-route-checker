/**
* @author Valentijn van Overveld
*/

#include "Graph.h"
#include <iostream>

/** Inserts a vertex into the graph
*/
void Graph::insertVertex(){
    curSize++;
    for(int i = 0; i < curSize; i++){
        matrix[i][curSize - 1] = 0;
        matrix[curSize - 1][i] = 0;
    }
}

/** Inserts an edge into the graph
* @param v1 the first vertex
* @param v2 the second vertex, that the first vertex is connected to
* @param weight the weight of the edge
*/
void Graph::insertEdge(int v1, int v2, int weight){
    matrix[v1][v2] = weight;
}

/** Deletes a vertex from the graph and reorganizes itself
* @param v the vertex to be deleted
*/
void Graph::deleteVertex(int v){
    if (v <= curSize) {
        while (v < curSize) {
            for (int i = 0; i < curSize; ++i) {
                matrix[i][v] = matrix[i][v + 1];
            }
            for (int i = 0; i < curSize; ++i) {
                matrix[v][i] = matrix[v + 1][i];
            }
            v++;
        }
        curSize--;
    }
}

/** Deletes an edge from the graph
* @param v1 the first vertex
* @param v2 the second vertex, that the first vertex is connected to
*/
void Graph::deleteEdge(int v1, int v2){
    matrix[v1][v2] = 0;
}
