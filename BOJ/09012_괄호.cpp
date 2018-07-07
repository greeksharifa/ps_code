#include <string>
#include <iostream>

using namespace std;

int main_09012() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);    cin.tie(NULL);

    int TC;

    cin >> TC;
    while (TC--) {
        int n = 0;
        string str;
        cin >> str;
        for (auto s : str) {
            if (s == '(')
                ++n;
            else 
                --n;
            if (n < 0)break;
        }
        cout << (n ? "NO" : "YES") << '\n';
    }
    return 0;
}