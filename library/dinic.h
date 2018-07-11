#pragma once

#include "sharifa_header.h"

#define MAX_V 52
#define S 0     // source
#define T 25    // sink
#define INF 1000000009

struct Edge {   // u -> v
    int v, cap, ref;
    Edge(int v, int cap, int ref) :v(v), cap(cap), ref(ref) {}
};

class Dinic {
    vector<vector<Edge> > edges;    // graph
    // level: 레벨 그래프, next_v: DFS에서 flow 계산 시 역추적에 사용
    vector<int> level, next_v;

public:
    void init() {
        edges.resize(MAX_V);
        level.resize(MAX_V);
        next_v.resize(MAX_V);
    }

    void addEdge(int u, int v, int cap) {
        edges[u].emplace_back(v, cap, (int)edges[v].size());
        edges[v].emplace_back(u, 0, (int)edges[u].size() - 1);
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        //level = vector<int>(MAX_V, -1);

        queue<int> q;
        level[S] = 0;
        q.push(S);

        while (!q.empty()) {
            int u = q.front();   q.pop();
            for (auto edge : edges[u]) {
                int v = edge.v, cap = edge.cap;

                if (level[v] == -1 && cap > 0) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        return level[T] != -1;
    }

    void reset_next_v() {
        fill(next_v.begin(), next_v.end(), 0);
        //next_v = vector<int>(MAX_V, 0);
    }

    int dfs(int u, int max_flow) {
        if (u == T)
            return max_flow;

        for (int &i = next_v[u]; i < edges[u].size(); i++) {
            int v = edges[u][i].v, cap = edges[u][i].cap;

            if (level[u] + 1 == level[v] && cap > 0) {
                int flow = dfs(v, min(max_flow, cap));

                if (flow > 0) {
                    edges[u][i].cap -= flow;
                    edges[v][edges[u][i].ref].cap += flow;
                    return flow;
                }
            }
        }
        return 0;
    }
};
