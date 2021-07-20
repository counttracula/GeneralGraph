//
// Created by Radmilo Racic on 20/07/2021.
//
#include <iostream>
#include "Graph.h"

using std::cout;
using std::endl;


void Node::print() {
    cout << node << ", " << weight << ") ";
}

void Edge::print() {
    cout << startNode << "->" << endNode << ": " << weight << endl;
}

Node* Graph::insertNode(int value, int weight, Node* head)   {
    Node* newNode = new Node;
    newNode->node = value;
    newNode->weight = weight;
    newNode->next = head;   // point new node to current head
    return newNode;
}
void Graph::print() {
    for (int i=0; i<nVertices; i++) {
        Node *ptr = head[i];
        while (ptr != nullptr) {
            cout << "(" << i << ", ";
            ptr->print();
            ptr = ptr->next;
        }
        cout << endl;
    }
}

Graph::Graph() {
    nVertices = 0;
    nEdges = 0;
    head = nullptr;
}

// ctor
Graph::Graph(Edge edges[], int nv, int ne) {
    cout << "Ctor for "<< this << endl;
    nVertices = nv;
    nEdges = ne;
    head = new Node*[nVertices]();
    for (int i = 0; i < nVertices; ++i)
        head[i] = nullptr;
    for (unsigned i = 0; i < nEdges; i++)  {
        int startVer = edges[i].startNode;
        int endVer = edges[i].endNode;
        int weight = edges[i].weight;
        // insert in the beginning
        Node* newNode = insertNode(endVer, weight, head[startVer]);

        // point head pointer to new node
        head[startVer] = newNode;
    }
}

// deep copy ctor
Graph::Graph(const Graph& source) {
    cout << "CopyCtor for " << this << endl;
    nVertices = source.nVertices;
    nEdges = source.nEdges;
    head = new Node*[nVertices]();
    for (int i = 0; i < nVertices; ++i) {
        Node* nodePtr = insertNode(source.head[i]->node, source.head[i]->weight, head[i]);
        head[i] = nodePtr;
    }
}

// move ctor
Graph::Graph(Graph&& source) {
    cout << "MoveCtor for " << this << endl;
    nVertices = source.nVertices;
    nEdges = source.nEdges;
    head = source.head;
    source.head = nullptr;
    source.nVertices = 0;
    source.nEdges = 0;
}

// copy assignment operator
Graph& Graph::operator=(const Graph& source) {
    cout << "Copy=Op for " << this << endl;
    nVertices = source.nVertices;
    nEdges = source.nEdges;
    head = new Node*[nVertices]();
    for (int i = 0; i < nVertices; ++i) {
        Node* nodePtr = insertNode(source.head[i]->node, source.head[i]->weight, head[i]);
        head[i] = nodePtr;
    }
    return *this;
}

// move assignment operator
Graph& Graph::operator=(Graph&& source) {
    cout << "Move=Op for " << this << endl;
    if (this == &source)
        return *this;
    for (int i = 0; i < nVertices; i++)
        delete[] head[i];
    delete [] head;

    nVertices = source.nVertices;
    nEdges = source.nEdges;
    head = new Node*[nVertices]();
    for (int i = 0; i < nVertices; ++i) {
        Node* nodePtr = insertNode(source.head[i]->node, source.head[i]->weight, head[i]);
        head[i] = nodePtr;
    }
    source.head = nullptr;
    source.nVertices = 0;
    source.nEdges = 0;
    return *this;
}

// dtor
Graph::~Graph() {
    cout << "Dtor for " << this << endl;
    for (int i = 0; i < nVertices; i++)
        delete[] head[i];
    delete[] head;
}
