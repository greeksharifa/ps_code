#include "sharifa_header.h"
#include "bit_library.h"

template <typename T>
class FenwickTree {
public:
    int size;
    vector<T> arr;
    vector<ll> data;

    FenwickTree<T>(int _N) {
        size = _N;
        arr.resize(_N + 1);
        size = power_of_2_eg_than(_N);
        data.resize(size + 1);
    }

    void update(int x, T val) {
        T delta_val = val - arr[x];
        arr[x] = val;

        while (x <= size) {
            data[x] += delta_val;
            x += (x&-x);
        }
    }
    ll sum(int x) {
        ll ret = 0;
        while (x) {
            ret += data[x];
            x -= (x&-x);
        }
        return ret;
    }
    ll sum(int x, int y) {
        return sum(y) - sum(x - 1);
    }
};