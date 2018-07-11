#include "../library/dinic.h"

int E, cap, u, v;
Dinic network;

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    cin >> E;

    network.init();

    while (E--) {
        char x, y;
        cin >> x >> y >> cap;

        u = 'A' <= x && x <= 'Z' ? x - 'A' : x - 'a' + 26;
        v = 'A' <= y && y <= 'Z' ? y - 'A' : y - 'a' + 26;

        network.addEdge(u, v, cap);
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