#include "sharifa_header.h"

class Union_Find {
    vector<int> parent, rank;

public:
    Union_Find(int V) {
        rank = vector<int>(V);
        parent = vector<int>(V);
        for (int i = 0; i < V; i++)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] == u)
            return u;
        else 
            return parent[u] = find(parent[u]);
    }

    void uni(int u, int v) {
        u = find(u), v = find(v);

        if (rank[u] < rank[v])
            parent[u] = v;
        else
            parent[v] = u;

        if (rank[u] == rank[v])
            ++rank[u];
    }
};