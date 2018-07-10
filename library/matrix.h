#include "sharifa_header.h"
#include "bit_library.h"

vector<vector<int> > mat_mul(vector<vector<int> > matrix_A, vector<vector<int> > matrix_B, int mod) {
    int m = matrix_A.size();
    vector<vector<int> > ret(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
              ret[i][j] += ((ll)matrix_A[i][k] * matrix_B[k][j]) % mod;
              ret[i][j] %= mod;
            }
        }
    }
    return ret;

}

vector<vector<int> > matrix_power_N(vector<vector<int> > matrix, int N, int mod, bool print) {
    int m = matrix.size(), len = binary_len(N);
    vector<vector<int> > original = matrix;
    vector<vector<int> > ret = vector<vector<int> >(m, vector<int>(m));
    for (int i = 0; i < m; i++)
        ret[i][i] = 1;
    
	N = bit_reverse(N);
    while (len--) {
        ret = mat_mul(ret, ret, mod);
        if (N & 1) {
            ret = mat_mul(ret, original, mod);
        }
        N >>= 1;
    }
    if (print) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                printf("%d ", ret[i][j]);
            puts("");
        }
    }
    return ret;
}
