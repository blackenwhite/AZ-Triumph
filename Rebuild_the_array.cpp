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
    n = pow(2, n);
    multiset<ll> st;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        st.insert(x);
    }
    multiset<ll> sums;
    st.erase(st.begin());
    sums.insert(0);
    while (st.size() > 0)
    {
        auto it = st.begin();
        ll num = *it;
        cout << num << " ";
        multiset<ll> temp_st;
        for (auto it : sums)
        {
            ll temp = it + num;
            st.erase(st.find(temp));
            temp_st.insert(temp);
        }

        for (auto it : temp_st)
        {
            sums.insert(it);
        }
    }
    cout << "\n";
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
