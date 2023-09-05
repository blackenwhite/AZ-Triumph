/*
Description

Given the value of integer N how many solutions does the following equation have?

1/x + 1/y = 1/N

If x and y are integers there is only a finite number of solutions but if x and y are real numbers then there can be an infinite number of solutions. What if x and y are floating-point numbers with limited size, e.g. x and y are floating point numbers with d digits after the decimal points, how many different solutions will be there?


Input Format

Input file contains at most 2000 lines of input. Each line contains two integers N (0 < N ≤ 10000000000) and d (0 ≤ d ≤ 1000), here d means that there can be maximum d digits after the decimal point. Input is terminated by a line containing two zeros. This line should not be processed.


Output Format

For each line of input, produce one line of output which contains an integer T. This line contains the number of different solutions the equation has for the given value of N and d. As the value of T can be very large so output T modulo 1000007.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        ll n, d;
        cin >> n >> d;

        if (!n && !d)
            break;

        map<ll, ll> M;

        for (ll i = 2; i * i <= n; i++)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            if (cnt)
                M[i] += 2 * cnt;
        }

        if (n > 1)
            M[n] += 2;

        M[2] += 2 * d;
        M[5] += 2 * d;

        ll ans = 1;
        bool sqr = true;

        ll mod = 1000007;

        for (auto it : M)
        {
            ans *= (it.second + 1);
            ans %= mod;
            if (ans < 0)
                ans += mod;
            if (it.second % 2)
                sqr = false;
        }

        ans *= 2;
        ans %= mod;
        if (ans < 0)
            ans += mod;

        if (sqr)
            ans = (ans - 1 + mod) % mod;

        cout << ans << "\n";
    }
}
