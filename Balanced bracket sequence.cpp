#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
string s;
int dp[1001][1001];
int rec(int i, int j)
{
    if (j < 0)
        return 0;
    if (i == s.length())
    {
        if (j == 0)
            return 1;
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (s[i] == '(')
        ans = rec(i + 1, j + 1) % mod;
    else if (s[i] == ')')
        ans = rec(i + 1, j - 1) % mod;
    else
        ans = (rec(i + 1, j + 1) + rec(i + 1, j - 1)) % mod;
    return dp[i][j] = ans;
}
void solve()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < s.length(); j++)
            dp[i][j] = -1;
    }
    cout << rec(0, 0) << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
