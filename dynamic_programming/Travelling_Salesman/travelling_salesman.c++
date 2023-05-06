#include<bits/stdc++.h>
using namespace std;
#define INF 999
 
// The function `tsp` is implementing the Traveling Salesman Problem (TSP) using recursive backtracking. 
// It takes in the following parameters:
// - `n`: the number of nodes in the graph
// - `graph`: a 2D array representing the graph with edge weights
// - `visited`: an array to keep track of which nodes have been visited
// - `curr_pos`: the current position in the graph
// - `count`: the number of nodes visited so far
// - `cost`: the cost of the path so far

int tsp(int n, int graph[][4], int visited[], int curr_pos, int count, int cost)
{
    // This code block is checking if all the nodes have been visited and if there is an edge 
    // from the current position to the starting position (0). If both conditions are true, 
    // it returns the cost of the path so far plus the cost of the edge from the current 
    // position to the starting position, which represents the complete path.
    if(count == n && graph[curr_pos][0])
    {
        return cost + graph[curr_pos][0];
    }
    int ans = INF;
    // The `for` loop is iterating through all the nodes in the graph. For each node, 
    // it checks if it has not been visited before (`!visited[i]`) and if there is an edge 
    // from the current position (`curr_pos`) to that node (`graph[curr_pos][i]`). If both 
    // conditions are true, it marks the node as visited (`visited[i] = 1`), calculates 
    // the cost of the path if that node is visited (`cost+graph[curr_pos][i]`), and 
    // recursively calls the `tsp` function with the new parameters. After the recursive call, 
    // it marks the node as unvisited (`visited[i] = 0`) to backtrack and try other paths. 
    // Finally, it takes the minimum cost of all the paths tried and returns it as the answer. 
    // This is essentially a depth-first search with backtracking to find the minimum cost Hamiltonian cycle in the graph.
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && graph[curr_pos][i])
        {
            visited[i] = 1;
            ans = min(ans, tsp(n, graph, visited, i, count+1, cost+graph[curr_pos][i]));
            visited[i] = 0;
        }
    }
    return ans;
}
 
int main()
{
    int n = 4;
    int graph[][4] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int visited[n];
    memset(visited, 0, sizeof(visited));
    visited[0] = 1;
    int ans = tsp(n, graph, visited, 0, 1, 0);
    cout << "Minimum cost to complete TSP: " << ans << endl;
    return 0;
}
