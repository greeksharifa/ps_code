#pragma once

#include "sharifa_header.h"

using namespace std;

int n, a[500002];

void LIS(vector<int>&a, vector<int>&b) {
    vector<int>p(a.size());
    int u, v, c, i;
    for (i = 1; i < a.size(); i++) {
        if (a[b.back()] < a[i]) {
            p[i] = b.back();
            b.push_back(i);
            continue;
        }
        for (u = 0, v = b.size() - 1; u < v;) {
            c = (u + v) >> 1;
            if (a[b[c]] < a[i])u = c + 1;
            else v = c;
        }
        if (a[i] < a[b[u]]) {
            if (u)p[i] = b[u - 1];
            b[u] = i;
        }
    }
    for (u = b.size(), v = b.back(); u--; v = p[v])b[u] = v;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int i;
    for (int i = 0; i < n; i++)scanf("%d", a + i);
    vector<int>A(a, a + n), B(1, 0);
    LIS(A, B);
    for (i = 0; i < B.size(); i++)printf("%d ", A[B[i]]);
    return 0;
}