/*
Description

You are given an array A of n non-negative integers.

Define function F = Summation of |Ai-X|2 for all i from 1 to n.

Find the minimum value of the function F by choosing an appropriate integer X.

 


Input Format

First line of input contains T, number of test cases.

First line of each test case contains n .

Second line contains n integers, Ai , the array A.


Output Format

For each test case print the minimum value of F.


Constraints

T ≤ 10

1 ≤ n ≤ 105

0 ≤ Ai ≤ 106
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
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    int c,f;
    if(sum%n==0){
        f=sum/n;
        c=sum/n;
    }else{
        f=sum/n;
        c=(sum/n)+1;
    }

    int a=0, b=0;
    for(int i=0;i<n;i++){
        a+=(v[i]-f)*(v[i]-f);
        b+=(v[i]-c)*(v[i]-c);
    }
    cout<<min(a,b)<<"\n";

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
