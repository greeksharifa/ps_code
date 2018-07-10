#include "../library/sharifa_header.h"
#include "../library/Fenwick_tree_BIT.h"

int N, m, k;

int main_02042() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);    cin.tie(NULL);

    cin >> N >> m >> k;
    m += k;

    FenwickTree<int> BIT(N);

    int a, b, c;

    for (int i = 1; i <= N; i++) {
        cin >> c;
        BIT.update(i, c);
    }

    while (m--) {
        cin >> a >> b >> c;
        if (a == 1)
            BIT.update(b, c);
        else
            cout << BIT.sum(b, c) << '\n';
    }
    return 0;
}
