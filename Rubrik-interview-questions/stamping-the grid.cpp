//  leetcode 2132
class NumMatrix {
public:
    vector<vector<int>>mat;
    int n,m;
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        n = mat.size();
        m = mat[0].size();

        for(int j=1;j<m;j++){
            mat[0][j]+=mat[0][j-1];
        }

        for(int i=1;i<n;i++){
            mat[i][0]+=mat[i-1][0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+= mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
            }
        }
    }

    int getPref(int x, int y) {
        if(x<0 || x>=n || y<0 || y>=m) return 0;
        return mat[x][y];
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return getPref(r2,c2) - getPref(r1-1,c2) - getPref(r2,c1-1) + getPref(r1-1,c1-1);
    }
};

class Solution {
    int n,m;
public:
    bool possibleToStamp(vector<vector<int>>& g, int h, int w) {
        n = g.size();
        m = g[0].size();
        vector<vector<int>> stamps(n,vector<int>(m));
        NumMatrix mat1(g);
        for(int i=h-1;i<n;i++){
            for(int j=w-1;j<m;j++){

                if(g[i][j]==0 && mat1.sumRegion(i-h+1,j-w+1,i,j) == 0) {
                    stamps[i][j]=1;
                    // printf("putting stamps at %d, %d\n", i,j);
                }
            }
        }

        NumMatrix mat2(stamps);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==0 && mat2.sumRegion(i,j,min(n-1,i+h-1), min(m-1,j+w-1))==0) return false;
            }
        }
        return true;
    }
};
