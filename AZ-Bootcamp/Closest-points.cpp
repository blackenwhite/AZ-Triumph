#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Point{
    public:
    ll x;
    ll y;

    ll getDistance() {
        return x*x + y*y;
    }
};

class Compare {
    public:
    bool operator()(Point& a, Point& b){
        if(a.getDistance()==b.getDistance()){
            return a.x < b.x;
        }
        return a.getDistance() < b.getDistance();
    }
};

int main() {
    ll n,k;
    cin>>n>>k;
    priority_queue<Point, vector<Point>, Compare> pq;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        Point temp;
        temp.x =a;
        temp.y = b;
        pq.push(temp);

        if(pq.size()>k){
            pq.pop();
        }
    }

    vector<Point> v(k);
    for(ll i=0;i<k;i++){
        v[i]=pq.top();
        pq.pop();
    }
    reverse(v.begin(), v.end());
    for(auto it:v){
        cout<<it.x<<" "<<it.y<<endl;
    }
    return 0;
}

=================================================
  #include <bits/stdc++.h>
using namespace std;
long long int distance(int x, int y){
    return 1LL*x*x + 1LL*y*y;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    priority_queue< pair < long long int , pair < int , int > > > heap;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        long long int dist = distance(x,y);
        if(heap.size()<k){
            heap.push({dist,{x,y}});
        } else {
            pair< long long int , pair < int , int > > topElement = heap.top();
            pair<long long int, pair < int , int > > currentElement = {dist,{x,y}};
            if(topElement>currentElement){
                heap.pop();
                heap.push(currentElement);
            }
        }
    }
    vector < pair < int , int > > answer;
    while(heap.size()){
        pair< long long int , pair < int , int > > topElement = heap.top();
        answer.push_back(topElement.second);
        heap.pop();
    }
    reverse(answer.begin(),answer.end());
    for(auto v:answer){
        cout<<v.first<<" "<<v.second<<"\n";
    }
}
