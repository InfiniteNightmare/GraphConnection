#include "Graph.h"
#include <iostream>

int main()
{
    freopen("E:\\C&C++\\in.txt", "r", stdin);
    freopen("E:\\C&C++\\out.txt", "w", stdout);
    // Graph graph(DG, 8, 60);
    Graph graph;
    graph.printGraph();
    graph.printAttr();
    return 0;
}