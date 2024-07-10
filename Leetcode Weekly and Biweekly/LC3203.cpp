/*
There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

You must connect one node from the first tree with another node from the second tree with an edge.

Return the minimum possible diameter of the resulting tree.

The diameter of a tree is the length of the longest path between any two nodes in the tree.
*/

class Solution {
public:
    vector<int>g1[100100];
    vector<int>g2[100100];

    int farn;
    int maxx;

    void dfs(int node, int par, int depth, vector<int>&dis, vector<int>* g) {
        // cout<<" hi at "<<node<<"\n";
        dis[node] = depth;
        if(dis[node]>maxx){
            maxx = dis[node];
            farn = node;
        }
        for(auto it:g[node]) {
            if(it!=par){
                dfs(it,node, depth+1, dis, g);
            }
        }
    }
    int findDiameter(vector<int> *g, int n){
        vector<int>dis(n+1,-1);
        farn = -1, maxx = -1;
        dfs(0,-1,0, dis, g);
        // cout<<"farn = "<<farn<<"\n";
        int start = farn;
        maxx = -1;
        farn = -1;
        dis = vector<int>(n+1, -1);
        dfs(start, -1, 0,dis, g);
        // cout<<"farn = "<<farn<<"\n";
        return maxx;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();

        for(auto it:edges1){
            g1[it[0]].push_back(it[1]);
            g1[it[1]].push_back(it[0]);
        }

        for(auto it:edges2) {
            g2[it[0]].push_back(it[1]);
            g2[it[1]].push_back(it[0]);
        }

        int d1 = findDiameter(g1, n+1);
        // cout<<"d1 = "<<d1<<"\n";

        int d2 = findDiameter(g2, m+1);
        // cout<<"d2 = "<<d2<<"\n";

        return max(max(d1, d2), (d1+1)/2 + (d2+1)/2 + 1);
    }
};
