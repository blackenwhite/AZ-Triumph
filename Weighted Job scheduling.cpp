#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string s;
// int dp[1001][1001];

class Job{
    public:
    int start;
    int end;
    int reward;

    Job(int start, int end, int reward){
        this->start=start;
        this->end=end;
        this->reward=reward;
    }

    Job(){
        start=0;
        end=0;
        reward=0;
    }
};

struct less_than_key{
    inline bool operator() (const Job& a, const Job& b){
        if(a.start==b.start) return a.end<b.end;
        return a.start<b.start;
    }
};

ll dp[200005];
vector<Job>v;

ll get_next_index(ll x){
    ll lo=0;
    ll hi = v.size()-1;
    ll ans=v.size();
    while(lo<=hi){
        ll mid=(lo+hi)/2;
        if(v[mid].start>x){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return ans;
}

ll rec(int ind,int n) {
    
    if(ind==n-1){
        return v[ind].reward;
    }

    if(dp[ind]!=-1){
        return dp[ind];
    }

    ll ans=0;
    ll take=v[ind].reward, not_take=0;
    // take
    ll next_ind = get_next_index(v[ind].end);
    if(next_ind<n){
        take+=rec(next_ind, n);
    }
    not_take = rec(ind+1,n);
    ans=max(take,not_take);
    return ans;
}

void solve()
{
    ll n;
    cin>>n;
    v.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[i].start = a;
        v[i].end=b;
        v[i].reward = c;
    }

    sort(v.begin(), v.end(), less_than_key());
    ll ans = rec(0,n);
    cout<<ans<<"\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

-------------------------- AZ code-------------------------------
  #include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int n;
vector<array<ll, 3>> v; // { b, a, p }
vector<ll> dp;
int binsearch(int i) {
    int l = 0, r = i - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid][0] < v[i][1])ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}
void solve() {
    cin >> n;
    v.resize(n, array<ll, 3>());
    for (int i = 0; i < n; i++)cin >> v[i][1] >> v[i][0] >> v[i][2];
    sort(v.begin(), v.end()); // sorting according to ending time.
    dp.resize(n);
    dp[0] = v[0][2];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1]; // not choosing current job ending at v[i][0].
        int idx = binsearch(i);
        if (idx != -1)dp[i] = max(dp[i], v[i][2] + dp[idx]); // choosing job ending at v[i][0].
        else dp[i] = max(dp[i], v[i][2]); // choosing only current Job.
    }
    cout << dp[n - 1] << endl;
    assert(dp[n-1]>=0);
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
