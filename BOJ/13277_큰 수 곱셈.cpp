#include "../library/bit_library.h"
#include "../library/conversion_library.h"
#include "../library/fft.h"

int main_13277() {
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    vi A = string_to_vi(a);
    vi B = string_to_vi(b);
    reverse(all(A));	reverse(all(B));

    vi ret = multiply(A, B);
    decimal_print(ret);

    return 0;
}