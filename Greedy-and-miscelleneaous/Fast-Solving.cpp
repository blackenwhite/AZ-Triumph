/*
Description

There are N problems in a contest and the ith problem has a rating Ri. They are posted in an order top to bottom as given in input.

Each problem requires at least 1 minute to solve. You also know that if a problem P has a higher rating than a problem just above or just below it, then P must take strictly more time to solve than that problem. 

Find the minimum possible time required to solve all the problems.

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains N.

Second line contains N integers, Ri for i from 1 to N.

 


Output Format

For each test case output one integer: The minimum possible time in which all problems could be solved.


Constraints

T ≤ 10

1 ≤ n ≤ 105

1 ≤ Ri ≤ 109
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007


void solve()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>a1(n), a2(n);
    a1[0]=1;
    for(int i=1;i<n;i++){
        if(v[i-1]<v[i]) a1[i]=a1[i-1]+1;
        else a1[i]=1; 
    }

    a2[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(v[i]>v[i+1]) a2[i]=a2[i+1]+1;
        else a2[i]=1;
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=max(a1[i],a2[i]);
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
