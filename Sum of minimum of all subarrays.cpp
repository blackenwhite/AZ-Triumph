#include <bits/stdc++.h>
using namespace std;
#define N 100100
#define ll long long
#define ld long double
#define pii pair<ll, ll>
#define F first
#define S second

ll n, m, q, k;

ll mod = (ll)(1e9 + 7);
ll inf = (ll)(1e18);

ll dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class State
{
public:
    ll dest;
    ll wt;
    ll numf;

    State()
    {
        dest = 0;
        wt = 0;
        numf = 0;
    }
};

class prioritize
{
public:
    bool operator()(State &p1, State &p2)
    {
        return p1.wt > p2.wt;
    }
};

// vector<pii> g[N];

ll nC2(ll n)
{
    return (n * (n - 1)) / 2;
}

void solve()
{
    cin >> n;
    // original vector with extra head and tail
    vector<ll> v(n + 2);
    v[0] = -1;
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    v[n + 1] = -1;
    stack<ll> st;
    // vectors to store L and R of each ind
    vector<ll> L(n + 2), R(n + 2);
    L[0] = 34; // random
    st.push(0);
    // using stack get the nearest smaller integer to the left
    for (ll i = 1; i <= n; i++)
    {
        while (v[st.top()] > v[i])
        {
            st.pop();
        }
        L[i] = st.top();
        st.push(i);
    }

    while (st.size() > 0)
        st.pop();
    st.push(n + 1);
    R[n + 1] = 34; // random
    // using stack get the nearest smaller integer to the left
    for (ll i = n; i >= 1; i--)
    {
        while (v[st.top()] > v[i])
        {
            st.pop();
        }
        R[i] = st.top();
        st.push(i);
    }
    ll sum = 0;
    for (ll i = 1; i <= n; i++)
    {
        sum += (i - L[i]) * (R[i] - i) * v[i]; // contr. of each index: (i-L)*(R-i)*v[i]
    }
    cout << sum << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
