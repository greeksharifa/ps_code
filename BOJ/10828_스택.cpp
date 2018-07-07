#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main_10828() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);    cin.tie(NULL);

    int n;
    stack<int> st;

    cin >> n;

    while (n--) {
        string order;
        cin >> order;
        if (order == "push") {
            int e;
            cin >> e;
            st.push(e);
        }
        else if (order == "pop") {
            if (st.empty())
                cout << -1 << '\n';
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (order == "size") {
            cout << st.size() << '\n';
        }
        else if (order == "empty") {
            cout << int(st.empty()) << '\n';
        }
        else {
            if (st.empty())
                cout << -1 << '\n';
            else
                cout << st.top() << '\n';
        }
    }
    return 0;
}