#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

const int mx = 1e6 + 10, mod = 1e9 + 7;
ll dp[mx][2];
ll rec(int i, bool f) {
    if (i == 1) return 1;
    auto &ans = dp[i][f];
    if (ans != -1)return ans;
    ans = 0;
    if (f)(ans += 4 * rec(i - 1, 1) + rec(i - 1, 0)) %= mod;
    else (ans += 2 * rec(i - 1, 0) + rec(i - 1, 1)) %= mod;
    return ans;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (rec(n, 0) + rec(n, 1)) % mod << endl;
    }

}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
