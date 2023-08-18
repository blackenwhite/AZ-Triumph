/*
BFS + Binary Search
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

*/

#define pii pair<int,int>
class Solution {
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
    vector<vector<int>> dist;
public:

    bool valid(int x, int y, int n, int m){
        return x>=0 && x<n && y>=0 && y<m;
    }

    bool check(vector<vector<int>>&grid, int x){
        int n=grid.size();
        int m=grid[0].size();

        if(x>dist[0][0] || x>dist[n-1][m-1]) return false;
        // cout<<"Checking for x= "<<x<<"\n";
        vector<vector<int>>vis(n, vector<int>(m));
        vis[0][0]=1;
        queue<pii> q;
        q.push({0,0});
        while(!q.empty()){
            int cur_x=q.front().first;
            int cur_y=q.front().second;
            q.pop();
            // cout<<"cur_x = "<<cur_x<<" cur_y= "<<cur_y<<"\n";

            for(int k=0;k<4;k++){
                int new_x=cur_x+dir[k][0];
                int new_y=cur_y+dir[k][1];
                if(new_x==n-1 && new_y==m-1) return true;
                if(valid(new_x, new_y, n, m) && !vis[new_x][new_y]) {
                    
                    if(x<=dist[new_x][new_y]) {
                        // cout<<"yo"<<"\n";
                        vis[new_x][new_y]=1;
                        q.push({new_x,new_y});
                    }
                }
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dist.resize(n, vector<int>(m,-1));

        // populate the dist grid
        queue<pii>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int new_x = cur_x+dir[k][0];
                int new_y = cur_y+dir[k][1];

                if(valid(new_x, new_y, n, m) && dist[new_x][new_y]==-1){
                    dist[new_x][new_y]=dist[cur_x][cur_y] + abs(dir[k][0]) + abs(dir[k][1]);
                    q.push({new_x, new_y});
                }
            }
        }

        // print(dist);


        int lo = 0, hi = (n+m);
        int ans = 0;
        // binary search
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(grid, mid)){
                ans = mid;
                lo = mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};
