#include <iostream>
#include <vector>
using namespace std;

int safe_check(vector<vector<int>>& graph, vector<int>& color) {
    for (int i = 0; i < graph.size(); i++) {
        for (int j = i + 1; j < graph.size(); j++) {
            if (graph[i][j] && color[j] == color[i]) {
                return 0;
            }
        }
    }
    return 1;
}

void print_soln(vector<int>& color) {
    cout << "Solution Exists:";
    for (int i = 0; i < color.size(); i++) {
        cout << " " << color[i];
    }
    cout << endl;
}

int graphColoring(vector<vector<int>>& graph, int m, int i, vector<int>& color) {
    if (i == color.size()) {
        if (safe_check(graph, color)) {
            print_soln(color);
            return 1;
        }
        return 0;
    }
    for (int j = 1; j <= m; j++) {
        color[i] = j;
        if (graphColoring(graph, m, i + 1, color)) {
            return 1;
        }
        color[i] = 0;
    }
    return 0;
}

int main() {
    vector<vector<int>> graph = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 }
    };
    int m = 3;
    cout << "No. of colours: " << m << endl;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> color(graph.size(), 0);
    if (!graphColoring(graph, m, 0, color)) {
        cout << "Solution does not exist" << endl;
    }
    return 0;
}
