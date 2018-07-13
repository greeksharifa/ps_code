#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MOD 1000000007
#define MAX_X 200001

class FenwickTree {
public:
    vector<ll> count, summ;

    FenwickTree() {
        count.resize(MAX_X + 1);
        summ.resize(MAX_X + 1);
    }

    void update(int x, int val) {
        while (x <= MAX_X) {
            ++count[x];
            summ[x] += val;
            x += (x&-x);
        }
    }

    ll sum(int x, bool cnt) {
        ll ret = 0;
        while (x) {
            ret += cnt? count[x] : summ[x];
            x &= x-1;
        }
        return ret;
    }
};

FenwickTree BIT;
int N, p_i;

int main_01280() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);    cin.tie(NULL);
    cin >> N >> p_i;    ++p_i;

    BIT.update(p_i, p_i);

    ll ans = 1;
    ll p_i_sum = p_i;

    for(int i=2;i<=N;i++){
        cin >> p_i; ++p_i;

        ll n_i = BIT.sum(p_i, true);
        ll smaller = BIT.sum(p_i, false);

        ll cost = (2 * n_i + 1 - i) * p_i;
        cost -= smaller;
        cost += p_i_sum - smaller;
        cost %= MOD;

        p_i_sum += p_i;
        ans = (ans*cost) % MOD;

        BIT.update(p_i, p_i);
    }

    cout << ans;

    return 0;
}
