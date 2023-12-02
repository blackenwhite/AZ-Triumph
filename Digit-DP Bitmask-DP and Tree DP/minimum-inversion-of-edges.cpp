/*
Description

You are given a graph of N nodes having N-1 directed edges. If we don't take the direction of edges into consideration then the graph is a tree.

You have to find all the nodes u, such that it is possible to move from node u to all the other nodes by changing the direction of minimum number of edges.

Print the minimum number of inversions required such that it is possible to reach all the nodes from a node u. After that print all the possible node u in ascending order in the next line.


Input Format

The first line contains an integer T ( 1 ≤ T ≤ 10^5) - the number of test cases.

The first line of each test case contains an integer N( 1 ≤ N≤ 10^5).

The next N-1 lines contain a description of an edge → ui, vi (1 ≤ ui, vi ≤ N, ui≠vi,). Vertices ui and vi are connected by a directed edge from ui to vi.

It is guaranteed that sum of all N over all test cases does not exceed 10^6.


Output Format

Print the minimum number of inversions required such that it is possible to reach all the nodes from a node u. After that print all the possible node u in ascending order in the next line.

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
map<pair<int,int>,int> mp;
int n;
vector<vector<int>> g;
vector<int> indp,outdp;
void indfs(int node,int par){
    for(auto v:g[node]){
        if(v==par) continue;
        indfs(v,node);
        indp[node]+=mp[{node,v}]+indp[v]; 
    }
}
void outdfs(int node,int par,int outval){
    outdp[node]=outval;
    for(auto v:g[node]){
        if(v==par) continue;
        int temp=indp[node]+outdp[node]-(indp[v]+mp[{node,v}])+mp[{v,node}];
        outdfs(v,node,temp);
    }
}
void solve(){
    cin>>n;
    g.clear();
    g.resize(n+1);
    indp.assign(n+1,0);
    outdp.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        mp[{u,v}]=0;
        mp[{v,u}]=1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    indfs(1,0);
    outdfs(1,0,0);
    int mn=1e9;
    vector<int> arr;
    for(int i=1;i<=n;i++){
        int val=indp[i]+outdp[i];
        if(mn>val){
            mn=val;
            arr.clear();
            arr.push_back(i);
        }
        else if(mn==val){
            arr.push_back(i);
        }
    }
    sort(arr.begin(),arr.end());
    cout<<mn<<"\n";
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";
}
signed main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
