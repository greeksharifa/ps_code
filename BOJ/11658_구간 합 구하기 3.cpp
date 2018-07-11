#include "../library/sharifa_header.h"
#include "../library/Fenwick_tree_2D_BIT.h"

int N, m;

int main_11658() {
	ios::sync_with_stdio(false);    cin.tie(NULL);

	cin >> N >> m;

    FenwickTree2D BIT(N);

    int w, x1, y1, x2, y2, val;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> val;
			BIT.update(i, j, val);
		}
	}
	while(m--){
        cin >> w >> x1 >> y1;
		if (w){
            cin >> x2 >> y2;
			cout << BIT.sum(x1, y1, x2, y2) << '\n';
        } else {
            cin >> val;
			BIT.update(x1, y1, val);
		}
	}
	return 0;
}
