/*
There are N monsters in front of you. To defeat the i-th of them you need an army of Ai soldiers, Bi of which will be killed during the battle.
Now you want to know the minimal number of soldiers you need to recruit in order to kill all the monsters.
You don't care about the order of battles: the only thing that matters is that none of the monsters will be left alive.


Input Format

The first line contains a number T (1 ≤ T ≤ 105) - the number of test cases. Then T lines follow.
The first line of each test cases contains single integer N (1 ≤ N ≤ 105) - the number of monsters.
Each of the next N lines contains two space-separated integers: Ai and Bi (1 ≤ Bi ≤ Ai ≤ 109) - the number of soldiers you need to defeat the i-th monster,  and the number of soldiers that will be killed in the battle against him.
It is guaranteed that the sum of N over all test cases doesn't exceed 5 x 105.


Output Format

For each test case, output a single integer on a new line — the minimal number of soldiers that is sufficient to kill all the monsters.
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define pii pair<int,int>

struct less_than_key {
    bool operator()(const pii& a, const pii& b){
        return (a.first-a.second)>(b.first-b.second);
    }
};


void solve()
{
    int n;
    cin>>n;
    // vector<int>a(n), b(n), c(n);
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    
    sort(v.begin(), v.end(), less_than_key());
    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt<v[i].first){
            ans+=(v[i].first-cnt);
            cnt=v[i].first;
        }
        cnt-=v[i].second;
    }
    cout<<ans<<"\n";

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
