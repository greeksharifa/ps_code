#include "../library/dinic.h"

#define MAX_V 52
#define S 0     // source
#define T 25    // sink
#define INF 1000000009

int E, cap, u, v;
Dinic network(MAX_V, S, T);

int main_06086() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    cin >> E;

    while (E--) {
        char x, y;
        cin >> x >> y >> cap;

        u = 'A' <= x && x <= 'Z' ? x - 'A' : x - 'a' + 26;
        v = 'A' <= y && y <= 'Z' ? y - 'A' : y - 'a' + 26;

        network.addEdge(u, v, cap, true);
    }

    int ans = 0;

    while (network.bfs()) {
        network.reset_next_v();
        while (true) {
            int flow = network.dfs(S, INF);
            if (!flow)
                break;
            ans += flow;
        }
    }

    cout << ans;

    return 0;
}