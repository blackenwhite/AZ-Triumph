/*
There are two arrays of size n, A [a1, a2 … an] and B [b1, b2 … bn]. You can permute the elements in both the arrays any way you want.

Your goal is to minimize the sum of the absolute differences between corresponding elements of the arrays i.e. sum of |ai-bi| for i from 1 to n.

Find this minimum sum.


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n, size of the arrays.

Second line contains n integers a1, a2 … an .

Third line contians n integers b1, b2 … bn .

 

 


Output Format

For each test case print a single integer in a new line: Minimum sum of the absolute differences between corresponding elements of the arrays.


Constraints

T ≤ 10

1 ≤ n ≤ 105

0 ≤ |ai|,|bi| ≤ 106

  */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007


void solve()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-b[i]);
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
