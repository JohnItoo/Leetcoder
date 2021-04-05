#include <bits/stdc++.h>
using namespace std;

int main() {
    // The general concept of topological sort is ordering a Directed Acyclic
    // graph.
    int edges;
    cin >> edges;
    int vertices;
    cin >> vertices;
    vector<vector<int> > graph(vertices + 5, vector<int>());
    vector<int> indegree(vertices + 5);
    for (int i = 0; i < edges; i++) {
        // The edges are directed so going from U to V.
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    int origin = -1;
    for (int i = 1; i <= vertices; i++) {
        if (!indegree[i]) {
            origin = i;
            break;
        }
    }
    // Origin or patient zero is the originth vertex;
    queue<int> q;
    q.push(origin);  // This queue houses every vertex with indegree zero at all
                     // times
    vector<int> topologicalSort;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int i = 0; i < graph[front].size(); i++) {
            int edge = graph[front][i];
            indegree[edge]--;
            if (indegree[edge] == 0) {
                q.push(edge);
            }
        }
        topologicalSort.push_back(front);
    }
    if (topologicalSort.size() == vertices) {
        reverse(topologicalSort.begin(), topologicalSort.end());
    } else {
        // there is no topological sort of the graph because it is not a DAG. It
        // is just a Directed Graph.
    }

    return 0;
}