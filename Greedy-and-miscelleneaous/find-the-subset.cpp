/*
Description

You are given a multiset of N integers. Check whether there exists a nonempty subset of it such that the sum of the subset's elements is divisible by N. Otherwise, state that this subset doesn't exist.


Input Format

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test consists of a single integer N - the size of the multiset.
The second line of each test contains N single space-separated integers - the multiset's elements.


Output Format

For each test case, print 'YES' if such a subset exists, otherwise print 'NO'.


Constraints

1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Ai ≤ 109
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

vector<int>pref_sum;

void solve()
{
    int n;
    cin>>n;
    vector<int>v(n);
    pref_sum.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    pref_sum[0]=v[0];
    map<int,int> mp;
    mp[pref_sum[0] %n]++;
    for(int i=1;i<n;i++){
        pref_sum[i]=pref_sum[i-1]+v[i];
        int temp = pref_sum[i]%n;
        if(mp.find(temp)!=mp.end()){
            cout<<"YES\n";
            return;
        }
        mp[temp]++;
    }
    cout<<"NO\n";


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
