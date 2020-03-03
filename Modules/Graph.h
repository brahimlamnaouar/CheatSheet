//
// Created by brahim on 07/02/2020.
//

#ifndef CHEATSHEET_GRAPH_H
#define CHEATSHEET_GRAPH_H

#include <iostream>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

template <class Type>

class Graph {
private:
    static const int MAXIMUM = 20;
    bool    adjacencyMatrix[MAXIMUM][MAXIMUM]{};
    Type    graphData[MAXIMUM];
    int     vertexCount{};
    void    depthFirstTraversal(Graph<Type> graph, int vertex, bool markedVertices[]);

public:
    Graph();
    ~Graph();

    //Graph Operations
    void    addVertex(const Type& value);
    void    addEdge(int source, int target);
    void    removeEdge(int source, int target);
    void    addUndirectedEdge(int source, int target);
    void    removeUndirectedEdge(int source, int target);

    //Accessors
    Type& operator [] (int vertex);
    Type operator [] (int vertex) const;
    int size() const;
    //Check Connection
    bool    hasUndirectedConnection(int source, int target) const;
    bool    areConnected(int source, int target) const;
    std::set<int> neighbors(int vertex) const;

    //Traversals
    void    depthFirstTraversal(Graph<Type> graph, int vertex);
    void    breadthFirstTraversal(Graph<Type> graph, int vertex);
};

template<class Type>
Graph<Type>::Graph() {
    this->vertexCount = 0;
}

template<class Type>
int Graph<Type>::size() const {
    return vertexCount;
}

template<class Type>
Type &Graph<Type>::operator[](int vertex) {
    assert(vertex < size());
    return graphData[vertex];
}

//Left hand side
template<class Type>
Type Graph<Type>::operator[](int vertex) const {
    assert(vertex < size());
}

//Left hand side
template<class Type>
Graph<Type>::~Graph() {
    //delete [] this->adjacencyMatrix;
    //delete [] this->graphData;
}

template<class Type>
void Graph<Type>::addVertex(const Type &value) {
    assert(size() < MAXIMUM);
    int newVertexNumber = vertexCount;
    vertexCount++;

    for (int i = 0; i < vertexCount; ++i) {
        adjacencyMatrix[i][newVertexNumber] = false;
        adjacencyMatrix[newVertexNumber][i] = false;
    }

    graphData[newVertexNumber] = value;

}

template<class Type>
void Graph<Type>::removeEdge(int source, int target) {
    assert(source < size() && target < size());
    adjacencyMatrix[source][target] = false;
}

template<class Type>
void Graph<Type>::addEdge(int source, int target) {
    assert(source < size() && target < size());
    adjacencyMatrix[source][target] = true;
}


template<class Type>
void Graph<Type>::removeUndirectedEdge(int source, int target) {
    this->removeEdge(source, target);
    this->removeEdge(target, source);
}


template<class Type>
void Graph<Type>::addUndirectedEdge(int source, int target) {
    this->addEdge(source, target);
    this->addEdge(target, source);
}

template<class Type>
bool Graph<Type>::hasUndirectedConnection(int source, int target) const {
    assert(source < size() && target < size());
    return adjacencyMatrix[source][target] || adjacencyMatrix[target][source];
}

template<class Type>
bool Graph<Type>::areConnected(int source, int target) const {
    assert(source < size() && target < size());
    return adjacencyMatrix[source][target];
}

template<class Type>
std::set<int> Graph<Type>::neighbors(int vertex) const {
    assert(vertex < size());
    std::set<int> neighbors;

    for (int i = 0; i < size(); ++i) {
        if (adjacencyMatrix[vertex][i]) {
            neighbors.insert(i);
        }
    }
    return neighbors;
}

template<class Type>
void Graph<Type>::depthFirstTraversal(Graph<Type> graph, int vertex) {
    bool visitedVertices[MAXIMUM];
    assert(vertex < graph.size());
    std::fill_n(visitedVertices, graph.size(), false);
    depthFirstTraversal(graph, vertex, visitedVertices);
}

template<class Type>
void Graph<Type>::depthFirstTraversal(Graph<Type> graph, int vertex, bool *markedVertices) {
    std::set<int> connections = graph.neighbors(vertex);
    std::set<int>::iterator setIterator;

    markedVertices[vertex] = true;
    cout << graphData[vertex] << ", " << endl;

    for (setIterator = connections.begin(); setIterator != connections.end(); ++setIterator) {
        if (!markedVertices[*setIterator]) {
            depthFirstTraversal(graph, *setIterator, markedVertices);
        }
    }
}

template<class Type>
void Graph<Type>::breadthFirstTraversal(Graph<Type> graph, int vertex) {
    assert(vertex < graph.size());
    bool visited[MAXIMUM];
    std::set<int> connections;
    std::set<int>::iterator setIterator;
    std::queue<int> vertexQueue;

    std::fill_n(visited, graph.size(), false);
    visited[vertex] = true;
    vertexQueue.push(vertex);
    while(!vertexQueue.empty()) {
        connections = graph.neighbors(vertexQueue.front());
        vertexQueue.pop();

        for (setIterator = connections.begin(); setIterator != connections.end(); setIterator++) {
            if (!visited[*setIterator]) {
                visited[*setIterator] = true;
                cout << graphData[*setIterator] << endl;
                vertexQueue.push(*setIterator);
            }
        }
    }
}

#endif //CHEATSHEET_GRAPH_H
