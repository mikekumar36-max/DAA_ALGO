#include <bits/stdc++.h>
using namespace std;

void primMST(int n, vector<vector<pair<int,int>>>& adj) {

    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    // Start from vertex 0
    key[0] = 0;

    for(int count = 0; count < n; count++) {

        int u = -1;

        // Find unvisited vertex with minimum key
        for(int i = 0; i < n; i++) {
            if(!visited[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        visited[u] = true;

        // Update neighbouring vertices
        for(auto edge : adj[u]) {

            int v = edge.first;
            int weight = edge.second;

            if(!visited[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;

    cout << "Edges in MST:\n";

    for(int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i
             << " : " << key[i] << endl;

        totalWeight += key[i];
    }

    cout << "Total MST weight = " << totalWeight << endl;
}

int main() {

    int n = 5;

    vector<vector<pair<int,int>>> adj(n);

    // u, v, weight
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    adj[3].push_back({4, 9});
    adj[4].push_back({3, 9});

    primMST(n, adj);

    return 0;
}