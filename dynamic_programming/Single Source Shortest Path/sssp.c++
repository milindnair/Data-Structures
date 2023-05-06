#include <iostream>
#include <vector>

using namespace std;

// define a structure to represent a weighted edge in the graph
struct Edge {
    int from;
    int to;
    int weight;
};

// function to compute the shortest path using the Bellman-Ford algorithm
void bellmanFord(vector<Edge> &edges, int numVertices, int source) {
    // initialize distances from source to all vertices to be infinity except for the source vertex itself
    vector<int> dist(numVertices, INT_MAX);
    dist[source] = 0;

    // relax all edges (numVertices - 1) times
    for (int i = 1; i < numVertices; i++) {
        for (Edge edge : edges) {
            int u = edge.from;
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // check for negative-weight cycles
    for (Edge edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int w = edge.weight;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
        }
    }

    // print the shortest distances from the source vertex to all other vertices
    for (int i = 0; i < numVertices; i++) {
        cout << "Shortest distance from " << source << " to " << i << " is " << dist[i] << endl;
    }
}

int main() {
    // create a graph with 5 vertices and 8 edges
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, -1},
        {1, 3, 1},
        {2, 3, 3},
        {2, 4, 2},
        {3, 4, -4},
        {4, 0, 1}
    };
    int numVertices = 5;
    int source = 0;

    // run the Bellman-Ford algorithm
    bellmanFord(edges, numVertices, source);

    return 0;
}
