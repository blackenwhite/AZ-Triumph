//User function Template for C++
const int N = 1e5+7;
class Solution{
public:
    
    long long T[4*N];
    int arr[N];
    void build(int id, int l, int r){
        if(l==r){
            T[id]=arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        T[id]=(T[id<<1]+T[id<<1|1]);
    }
    
    void update(int id, int l, int r, int idx, int val){
        if(l>idx || r<idx) return;
        if(l==r){
            T[id]=val;
            return;
        }
        int mid = (l+r)/2;
        update(id<<1,l,mid,idx,val);
        update(id<<1|1,mid+1,r,idx,val);
        T[id]=(T[id<<1]+T[id<<1|1]);
    }
    
    long long query(int id, int l, int r, int lq, int rq){
        if(l>rq || r<lq) return 0;
        if(l>=lq && r<=rq) return T[id];
        int mid = (l+r)/2;
        return (query(id<<1,l,mid,lq,rq)+query(id<<1|1,mid+1,r,lq,rq));
    }
    

  vector<int> maximumToys(int n,vector<int> A,int Q,vector<vector<int>> q){
      // code here
      vector<pair<int,int>> temp;
      for(int i=0; i<n; i++){
          temp.push_back({A[i],i});
      }
      sort(temp.begin(),temp.end());
      for(int i=0; i<n; i++){
          arr[i]=temp[i].first;
      }
      map<int,int> mp;
      for(int i=0; i<n; i++){
          mp[temp[i].second]=i;
      }
      vector<int> res;
      build(1,0,n-1);
      for(auto x: q){
          int a = x[0], b = x[1];
          for(int i=2; i<x.size(); i++){
              update(1,0,n-1,mp[x[i]-1],0);
          }
          int lo=0,hi=n-1;
          int ans = -1;
          while(lo<=hi){
              int mid = (lo+hi)/2;
              if(query(1,0,n-1,0,mid)<=a){
                  lo=mid+1;
                  ans = mid;
              }else{
                  hi=mid-1;
              }
          }
          for(int i=2; i<x.size(); i++){
              update(1,0,n-1,mp[x[i]-1],arr[mp[x[i]-1]]);
          }
          int t = 0;
          for(int i=2; i<x.size();i++){
              int idx = mp[x[i]-1];
              if(ans>=idx){
                  t++;
              }
          }
          ans-=t;
          res.push_back(ans+1);
      }
      return res;
  }
};
