#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int foo(int x,int y){
    if(x>=y){
        return x-y;
    }

    int ans=0;
    int temp=y;
    while(temp>x){
        if(temp%2){
            temp++;
        }
        else {
            temp/=2;
        }
        ans++;
    }
    ans+=x-temp;
    return ans;
}

void solve()
{
    int x,y;
    cin>>x>>y;
    cout<<foo(x,y)<<endl;
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
