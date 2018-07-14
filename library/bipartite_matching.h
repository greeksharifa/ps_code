#include "sharifa_header.h"

class BMatch {
    int V_A, V_B;
    vector<int> bmatch;
    vector<bool> visited;

    vector<vector<int> > edges;

public:
    BMatch(int A, int B) : V_A(A), V_B(B) {
        bmatch = vector<int>(B + 1);
        visited = vector<bool>(B + 1);
        edges.resize(A + 1);
    }

    void addEdge(int u, int v) {  // u -> v
        edges[u].push_back(v);
    }

    bool dfs(int u) {
        if (visited[u]) return false;
        visited[u] = true;

        for (int v : edges[u]) {
            if (!bmatch[v] || dfs(bmatch[v])) {
                bmatch[v] = u;
                return true;
            }
        }
        return false;
    }

    int max_match() {
        int ret = 0;
        for (int a = 1; a <= V_A; a++) {
            fill(visited.begin(), visited.end(), 0);
            if (dfs(a))
                ++ret;
        }
        return ret;
    }
};

