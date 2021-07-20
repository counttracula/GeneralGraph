//
// Created by Radmilo Racic on 20/07/2021.
//

#ifndef GENERALGRAPH_GRAPH_H
#define GENERALGRAPH_GRAPH_H


class Node {
public:
    int node;
    int weight;
    Node *next;
    Node() {
        node = 0;
        weight = 0;
        next = nullptr;
    }
    void print();
};

class Edge {
public:
    int startNode;
    int endNode;
    int weight;
    Edge(int sn, int en, int w): startNode(sn), endNode(en), weight(w) {};
    void print();
};

class Graph {
public:
    int nVertices;
    int nEdges;
    Node** head;        // adjacency info
    // default ctor
    Graph();

    // ctor
    Graph(Edge edges[], int nv, int ne);

    // copy ctor
    Graph(const Graph& source);

    // move ctor
    Graph(Graph&& source);

    // copy assignment
    Graph& operator=(const Graph& source);

    // move assignment
    Graph& operator=(Graph&& source);

    // dtor
    ~Graph();

    Node* insertNode(int value, int weight, Node* head);
    void print();
};


#endif //GENERALGRAPH_GRAPH_H
