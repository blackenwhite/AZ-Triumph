/*
Description

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.

For example, when removing "ab" from "cabxbae" it becomes "cxbae".

Remove substring "ba" and gain y points.

For example, when removing "ba" from "cabxbae" it becomes "cabxe".

Return the maximum points you can gain after applying the above operations on s.


Input Format

The first line contains an integer T (number of test cases), 1 ≤ T ≤ 10^5.

The next T lines contain a string S and 2 space-separated integers S, X, Y where 1 ≤ X,Y ≤ 10^9, 1 ≤ |S| ≤ 10^6.

Sum of |S| across all test cases ≤ 10^7.


Output Format

For each test case print the maximum point possible in a new line.
*/ 

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define pii pair<int, int>
#define N 100005
int inf = 1e18;
struct less_than_key
{
    bool operator()(const pii &a, const pii &b)
    {
        return (a.first - a.second) > (b.first - b.second);
    }
};

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(a % b, b);
}

int mult(int a, int b) // O(1)
{
    return ((a % mod) * (b % mod)) % mod;
}

int exponent(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

int inverse(int a)
{
    return exponent(a, mod - 2);
}

int fact[N];
int invFact[N];

void init()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = mult(i, fact[i - 1]);
    }

    invFact[N - 1] = inverse(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        invFact[i] = mult(invFact[i + 1], i + 1);
    }
}

int nCr(int n, int r)
{
    return mult(fact[n], mult(invFact[n - r], invFact[r]));
}

int add(int a, int b)
{ // O(1)
    int ans = (a + b);
    if (ans >= mod)
        ans -= mod;
    if (ans < 0)
        ans += mod;
    return ans;
}

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void pr(vector<int> &v)
{
    cout << "Printing vector---\n";
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << "\n";
}

void solve()
{
    stack<char> st;
    int x, y;
    string s;
    cin >> s >> x >> y;
    string A = "ab";
    string B = "ba";

    if (y > x)
    {
        swap(x, y);
        swap(A, B);
    }

    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (!st.empty() && st.top() == A[0] && s[i] == A[1])
        {
            st.pop();
            ans += x;
        }
        else
        {
            st.push(s[i]);
        }
    }

    string m;
    while (!st.empty())
    {
        m += st.top();
        st.pop();
    }

    reverse(m.begin(), m.end());

    for (int i = 0; i < m.length(); i++)
    {
        if (!st.empty() && st.top() == B[0] && m[i] == B[1])
        {
            st.pop();
            ans += y;
        }
        else
        {
            st.push(m[i]);
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    // init();
    while (t--)
    {
        solve();
    }
    // for(tt=1;tt<=t;tt++){
    //     cin>>s;
    //     cout<<rec(0,1,1)<<"\n";
    // }
    return 0;
}
