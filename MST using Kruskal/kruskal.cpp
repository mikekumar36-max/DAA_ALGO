#include <bits/stdc++.h>
using namespace std;

class DSU {
public:

    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {

        if(parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionSet(int u, int v) {

        u = findParent(u);
        v = findParent(v);

        if(u == v)
            return;

        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[u] > rank[v]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
};

void kruskalMST(int n, vector<vector<int>>& edges) {

    // Sort according to weight
    sort(edges.begin(), edges.end(),
         [](vector<int>& a, vector<int>& b) {
             return a[2] < b[2];
         });

    DSU dsu(n);

    int totalWeight = 0;
    int edgesTaken = 0;

    cout << "Edges in MST:\n";

    for(auto edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // Check whether adding edge creates a cycle
        if(dsu.findParent(u) != dsu.findParent(v)) {

            cout << u << " - " << v
                 << " : " << weight << endl;

            totalWeight += weight;
            edgesTaken++;

            dsu.unionSet(u, v);

            if(edgesTaken == n - 1)
                break;
        }
    }

    cout << "Total MST weight = "
         << totalWeight << endl;
}

int main() {

    int n = 5;

    vector<vector<int>> edges = {

        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}

    };

    kruskalMST(n, edges);

    return 0;
}