/*
Given 
3
 strings 
s
1
, 
s
2
 and 
s
3
, the task is to find the length of the longest common sub-sequence in all three given strings.
*/ 

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int dp[102][102][102];
string s1,s2,s3;
int x,y,z;
int rec(int i,int j,int k)
{
    if(i>=x || j>=y || k>=z)return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    int ans = -1e9;
    ans = max(ans,rec(i+1,j,k));
    ans = max(ans,rec(i,j+1,k));
    ans = max(ans,rec(i,j,k+1));
    if(s1[i]==s2[j] && s2[j]==s3[k])
    {
        ans = max(ans,1+rec(i+1,j+1,k+1));
    }
    return dp[i][j][k] = ans;
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    cin>>s1>>s2>>s3;
    x=s1.length();
    y=s2.length();
    z=s3.length();
    cout<<rec(0,0,0)<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
   while(t--){
     solve();
   }
}
