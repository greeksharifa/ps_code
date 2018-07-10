#pragma once

#include "sharifa_header.h"

vector<int> string_to_vi(string& s) {
    vector<int> ret(s.size());
    for (int i = 0; i < s.size(); i++)
        ret[i] = s[i] - '0';
    return ret;
}

