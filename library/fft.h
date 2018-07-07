/*
fft 함수는 http://topology-blog.tistory.com/6 블로그를 참조한 것입니다.
*/

#pragma once

#include "re_define.h"
#include "bit_library.h"

typedef complex<double> base;

void fft(vector<base> &a, bool inv) {
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }
    for (int i = 1; i < n; i <<= 1) {
        double x = (inv ? 1 : -1) * M_PI / i;
        base w = { cos(x), sin(x) };
        for (int j = 0; j < n; j += i << 1) {
            base th(1);
            for (int k = 0; k < i; k++) {
                base tmp = a[i + j + k] * th;
                a[i + j + k] = a[j + k] - tmp;
                a[j + k] += tmp;
                th *= w;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}

vi multiply(vi &A, vi &B) {
    vector<base> a(all(A));
    vector<base> b(all(B));
    int n = power_of_2_eg_than(max(a.size(), b.size())) * 2;

    a.resize(n);	b.resize(n);
    fft(a, false);	fft(b, false);

    for (int i = 0; i < n; i++)
        a[i] *= b[i];
    fft(a, true);

    vi ret(n);
    for (int i = 0; i < n; i++)
        ret[i] = (int)round(a[i].real());
    return ret;
}

void decimal_print(vi &A) {
    int i = 0;
    while (i < A.size()) {
        if (A[i] >= 10) {
            if (i == A.size() - 1)
                A.push_back(A[i] / 10);
            else
                A[i + 1] += A[i] / 10;
            A[i] %= 10;
        }
        ++i;
    }

    reverse(all(A));

    bool start = false;
    for (auto elem : A) {
        if (elem)start = true;
        if (start)cout << elem;
    }
    if (!start)cout << '0';
}