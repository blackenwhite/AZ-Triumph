// Enter your code below 
// Enter your code below 
//ANKAM SRIMAN
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define fi(i,a,b) for(long long  i = a; i<b; i++)
#define fd(i,a,b) for(long long  i = a; i>=b; i--)
#define scarr(a) for(long long  i=0;i<a.size();i++) cin>>a[i]
#define parr(a) for(long long  i=0;i<a.size();i++) cout<<a[i]<<" "
#define ll long long
#define ull unsigned long long int
//transform(s.begin(), s.end(), s.begin(), ::tolower);
// #define int long long int
#define spa " "
#define nl cout<<"\n"
#define pr(x) cout<<x<<"\n"
#define prvt(a) for(long long int i=0;i<a.size();i++) cout<<a[i]<<" "
#define star cout<<"*"
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define pr(x) cout<<x<<"\n"
#define f first
#define s second
#define ii pair<ll,ll>
// using state 
ll mod = 1000000007;



ll n,m,k,src,ed,cap;
vector<ll>dx = {1,0,-1,0};
vector<ll>dy = {0,1,0,-1};
ll board[105][15];
ll comp_size;
bool vis[105][15];

void dfs(ll r,ll c,ll colour){
    vis[r][c] = 1;
    comp_size++;
    for(ll i = 0;i<4;i++){
        ll xx = r+dx[i];
        ll yy = c+dy[i];
        if(xx>=0 && xx<n && yy>=0 && yy<10 && vis[xx][yy]== 0 && board[xx][yy]==colour){
            dfs(xx,yy,colour);
        }
    }
}

void dfs_delete(ll r,ll c,ll colour){
    board[r][c] = 0;
    for(ll i = 0;i<4;i++){
        ll xx = r+dx[i];
        ll yy = c+dy[i];
        if(xx>=0 && xx<n && yy>=0 && yy<10 && board[xx][yy]==colour){
            dfs_delete(xx,yy,colour);
        }
    }
}

void gravity(){
    for(ll j=0;j<10;j++){
        ll p = n-1;
        for(ll i =n-1;i>=0;i--){
            if(board[i][j]!=0){
                swap(board[i][j],board[p][j]);
                p--;
            }
        }
    }
}

void solve(){
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        for(ll j =0;j<10;j++) {
            char c;
            cin>>c;
            board[i][j] = c-'0';
        }
    }
    ll flag = 1;
    while(flag){
        flag = 0;
        memset(vis,0,sizeof(vis));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<10;j++){
                if(board[i][j]!=0 && vis[i][j]==0){
                    comp_size = 0;
                    dfs(i,j,board[i][j]);
                    if(comp_size>=k){
                        dfs_delete(i,j,board[i][j]);
                        flag = 1;
                    }
                }
                
            }
        }
        gravity();
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<10;j++) cout<<board[i][j];
        cout<<'\n';
    }
    
}

    
//string s;

signed main()
{
    //py;
    //fun 

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    //pow2();

    IOS;
    //cout<<"*";
    ll t=1;
    // cin >> t; 
    //getline(cin,s);

    while (t--)
    {
        // q++;

        solve();
    }
    return 0 ;
}
