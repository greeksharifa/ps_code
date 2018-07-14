#include "../library/dinic.h"

#define INF 1000000009

int TC, n, m;
int S, T;

int di[] = { 0,1,0,-1 }, dj[] = { 1,0,-1,0 };
int board[50][50];

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);

    cin >> TC;
    while (TC--) {
        int ans = 0;

        cin >> n >> m;
        S = n * m, T = n * m + 1;

        // S = n*m, T = n*m + 1
        Dinic network(n*m + 2, S, T);

        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                cin >> board[i][j], ans += board[i][j];

        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                if ((i + j) % 2) {
                    network.addEdge(i*m + j, T, board[i][j], false);
                } else {
                    network.addEdge(S, i*m + j, board[i][j], false);
                    for (int k = 0; k<4; k++) {
                        int ni = i + di[k], nj = j + dj[k];
                        if (ni<0 || nj<0 || ni >= n || nj >= m)continue;

                        network.addEdge(i*m + j, ni*m + nj, min(board[i][j], board[ni][nj]), false);
                    }
                }
            }
        }

        while (network.bfs()) {
            network.reset_next_v();
            while (true) {
                int flow = network.dfs(S, INF);
                if (!flow)
                    break;
                ans -= flow;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}