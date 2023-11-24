// Leetcode 2940 HARD --> Segment Tree + Binary Search 
using pii = pair<int,int>;
// class node{
//     vector<pii>v;
// };

void pr(vector<pii>&v){
    for(auto it:v){
        cout<<"{"<<it.first<<","<<it.second<<"}";
    }
    cout<<"\n";
}

class Solution {
public:
    int N = 50005;
    vector<int> t;
    vector<int> base;

    // void merge(vector<pii>&v, vector<pii>&a, vector<pii>&b){
    //     int k = 0;
    //     int n = a.size();
    //     int m = b.size();

    //     int i=0,j=0;
    //     while(i<n && j<m) {
    //         if(a[i].first<=b[j].first){
    //             v[k]=a[i];
    //             k++;
    //             i++;
    //         } else{
    //             v[k] = b[j];
    //             j++;
    //             k++;
    //         }
    //     }

    //     while(i<n) {
    //         v[k++] = a[i++];
    //     }

    //     while(j<m) {
    //         v[k++] = b[j++];
    //     }
    // }

    void build(int id, int l, int r){
        // cout<<"hello at l = "<<l<<" r= "<<r<<"\n";
        if(l==r){
            // cout<<"reached a leaf node\n";
            t[id] = base[l];
            return;
        }

        int mid = (l+r)/2;
        build(2*id,l,mid);
        build(2*id+1,mid+1,r);
        t[id] = max(t[id<<1], t[id<<1|1]);
        // cout<<"hello " << t[id].size()<<"\n";
        // merge(t[id<<1].begin(),t[id<<1].end(), t[id<<1|1].begin(), t[id<<1|1].end(), t[id].begin());
        // cout<<"Merged and got --- \n";
        // pr(t[id]);
}

    pii bin_search(vector<pii>&v, int x) {
        pii ans={-1,-1};
        int lo = 0,hi = v.size()-1;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(v[mid].first>x) {
                ans = v[mid];
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return ans;
    }

    int query(int id,int l, int r, int lq, int rq) {
        // printf("Query at id= %d, l=%d, r=%d, lq=%d, rq=%d \n", id,l,r,lq,rq);
        if(l>rq ||lq>r) {
            return -1;
        }
        if(lq<=l && r<=rq) {
            // printf("Found ans p.first = %d, p.second = %d", p.first, p.second);
            return t[id];
        }
        int mid = (l+r)/2;
        int left = query(2*id,l,mid,lq,rq);
        int right = query(2*id+1, mid+1, r, lq,rq);
        return max(left,right);
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int>ans;
        t.resize(4*N);
        base.resize(N);
        // base bhoro
        for(int i=0;i<n;i++){
            base[i+1] = heights[i];
        }

        // build the segment tree
        build(1,1,n);
        

        // process queries online
        for(int i=0;i<queries.size();i++){
            int a = queries[i][0];
            int b = queries[i][1];
            if(a>b) {
                swap(a,b);
            }
            int ha = heights[a] , hb = heights[b];
            
            if(a==b || hb>ha){
                ans.push_back(b);
                continue;
            }
            int lo = b, hi = n-1;
            int min_target = max(ha,hb) + 1;
            int temp = -1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                int maxi = query(1,1,n,b+1,mid+1);
                // printf("Max value in range %d to %d = %d", b, mid, maxi);
                if(maxi>=min_target) {
                    temp = mid;
                    hi = mid-1;
                }else{
                    lo = mid+1;
                }
            }
            ans.push_back(temp);
            // break;
        }
        return ans;
    }
};

