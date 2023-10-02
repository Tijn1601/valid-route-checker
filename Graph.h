/**
* @author Valentijn van Overveld
*/

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class Graph
{
    public:
        Graph(int maxSize){matrix = new int*[maxSize + 1]; for(int i = 0; i < maxSize + 1; i++){matrix[i] = new int[maxSize + 1];}}
        int getSize(){return curSize;}
        void insertVertex();
        void insertEdge(int, int, int);
        void deleteVertex(int);
        void deleteEdge(int, int);

        //is public so its edges can be accessed
        int** matrix;

    private:
        int curSize = 0;
};

#endif // GRAPH_H
