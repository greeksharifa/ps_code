#include "../library/sharifa_header.h"
#include "../library/bipartite_matching.h"

int n, m;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);    cin.tie(NULL);
    cin >> n >> m;
    BMatch bipartite(n, m);
    for (int a = 1; a <= n; a++) {
        int cnt, b;
        cin >> cnt;
        while (cnt--) {
            cin >> b;
            bipartite.addEdge(a, b);
        }
    }
    cout << bipartite.max_match();
}