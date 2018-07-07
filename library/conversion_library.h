#pragma once

#include "re_define.h"

vi string_to_vi(string& s) {
    vi ret(s.size());
    for (int i = 0; i < s.size(); i++)
        ret[i] = s[i] - '0';
    return ret;
}

