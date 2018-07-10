#pragma once

#include "sharifa_header.h"

template <typename T>
int binary_len(T n) {
    ll power_of_2 = 1;
    int ret = 0;
    while (power_of_2 <= n)power_of_2 <<= 1, ++ret;
    return ret;
}

template <typename T>
T bit_reverse(T n) {
    T ret = 0;
    while (n) {
        ret <<= 1;
        ret |= n & 1;
        n >>= 1;
    }
    return ret;
}

template <typename T>
T power_of_2_eg_than(T n) {
    T ret = 1;
    while (n > ret) ret <<= 1;
    return ret;
}