#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Edge edges[] = {
            // (x, y, w) -> edge from x to y with weight w
            {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    for (auto i: edges)
        i.print();
    int nVerts = 5;      // Number of vertices in the graph
    // calculate number of edges
    int nEdges = sizeof(edges)/sizeof(edges[0]);
    // construct graph
    Graph graph(edges, nVerts, nEdges);
    // print adjacency list representation of graph
    graph.print();

    Graph graph2(graph);
    graph2.print();

    Graph graph3(edges, nVerts, nEdges);
    graph3 = graph;
    graph3.print();

    Graph graph4 = Graph(std::move(graph));
    graph4.print();

    Graph graph5;
    graph5 = Graph(edges, nVerts, nEdges);
    graph5.print();

    return 0;
}
