#include "../library/conversion_library.h"
#include "../library/fft.h"

int main_13277() {
    ios::sync_with_stdio(false);    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    vector<int> A = string_to_vi(a);
    vector<int> B = string_to_vi(b);
    reverse(A.begin(), A.end());	reverse(B.begin(), B.end());

    vector<int> ret = multiply(A, B);

    int i = 0;
    while (i < ret.size()) {
        if (ret[i] >= 10) {
            if (i == ret.size() - 1)
                ret.push_back(ret[i] / 10);
            else
                ret[i + 1] += ret[i] / 10;
            ret[i] %= 10;
        }
        ++i;
    }

    reverse(ret.begin(), ret.end());

    bool start = false;
    for (auto elem : ret) {
        if (elem)start = true;
        if (start)cout << elem;
    }
    if (!start)cout << '0';

    return 0;
}