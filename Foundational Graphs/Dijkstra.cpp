
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<pair<int, int>>> g;
vector<bool> vis;
vector<int> dis;
int n, m;

class comp{
    public:
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second;
    }
};


void dijkstra(){
    dis[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    pq.push({1, 0});

    while(!pq.empty()){
        auto val = pq.top();
        int node = val.first;
        int curWeight = val.second;

        pq.pop();
        if(vis[node]) continue;
        vis[node] = true;

        for(auto neighNode : g[node]){
            int neigh = neighNode.first;
            int weight = neighNode.second;
            if(dis[neigh] > dis[node] + weight){
                dis[neigh] = dis[node] + weight;
                pq.push(make_pair(neigh, dis[neigh]));
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    g.assign(n+1, vector<pair<int, int>>());
    vis.assign(n+1, false);
    dis.assign(n+1, 1e18);
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    dijkstra();

    for(int i=1; i<=n; i++) cout << dis[i] << " ";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //int _t; cin >> _t; while(_t--)
    solve();

    return 0;
}
