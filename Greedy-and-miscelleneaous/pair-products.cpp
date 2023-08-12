/*
Description

You have given an array of n numbers and a positive integer m. Lets define c(i, j) = |ai - aj|.
Your task is to find the product of c(i, j) for all 1 ≤ i < j ≤ n. Since this product can be very large, print it with modulo m.


Input Format

The first line contains two integers n, m (2 ≤ n ≤ 2 x 105, 1 ≤ m ≤ 1000) — number of numbers and modulo.
The second line contains n integers a1, a2, …, an (0 ≤ ai ≤ 109).


Output Format

Output a single integer.
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
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    if(n>m){
        cout<<"0\n";
        return;
    }
    int prod=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            // cout<<"hi\n";
            prod = (prod*abs(v[i]-v[j]))%m;
        }
    }
    cout<<prod<<"\n";
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
