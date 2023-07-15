#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

void solve() {
    ll n, lis = 1;
    cin >> n;
    vector<ll> nums(n), dp(n + 1, 0), cnt(n + 1, 0);
    for (int i = 0; i < n; i++)cin >> nums[i];
    for (int i = 0; i < n; i++) {
        cnt[i] = 1;
        auto &ans = dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (ans < dp[j] + 1)ans = dp[j] + 1, cnt[i] = cnt[j];
                else if (ans == dp[j] + 1)cnt[i] += cnt[j];
            }
        }
        lis = max(lis, dp[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)if (lis == dp[i])ans += cnt[i];
    cout << ans << endl;
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
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
