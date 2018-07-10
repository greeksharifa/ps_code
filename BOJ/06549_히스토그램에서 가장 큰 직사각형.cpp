#include "../library/sharifa_header.h"

int main_06549() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (!n)break;
        stack<pair<int,int> > st;
        ll ans = 0;
        for (int i_index = 0; i_index <= n; i_index++) {
            int i_height;
            if (i_index < n)
                scanf("%d", &i_height);
            else
                i_height = -1;
            int left = i_index;
            // top_index: st.top().first, top_height: st.top().second
            while (!st.empty() && st.top().second > i_height) {
                ans = max(ans, ((ll)i_index - st.top().first)*st.top().second);
                left = st.top().first;
                st.pop();
            }
            st.push(make_pair(left, i_height));
        }
        printf("%lld\n", ans);
    }
    return 0;
}