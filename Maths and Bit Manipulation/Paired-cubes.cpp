/*
Description

You have given n positive integers A1, A2, …, An. Your task is to find the number of pairs (i, j) such that Ai * Aj is a cube number.


Input Format

The first line of input contains n - the size of the array.
The second line of input contains n space-separated integers A1, A2, …, An.


Output Format

Print the answer on a new line.


Constraints

1 ≤ n ≤ 105
1 ≤ Ai ≤ 106
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define pii pair<int,int>
#define N 1009
struct less_than_key {
    bool operator()(const pii& a, const pii& b){
        return (a.first-a.second)>(b.first-b.second);
    }
};

// void print(vector<vector<int>> arr) {
//     cout<<"Printing vector---\n";
//     int n=arr.size();
//     int m=arr[0].size();
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
// }

int primes[N];
vector<int>p;

void getNorm(int x, int* norm, int* invNorm){
    *norm = 1;
    *invNorm = 1;
    for(auto p1:p){
        // cout<<"hello . p1= "<<p1<<"\n";
        if(p1>x){
            break;
        }
        if(x%p1!=0) continue;
        int cnt=0;
        while(x>0 && x%p1==0){
            x/=p1;
            cnt++;
        }
        // cout<<"cnt= "<<cnt<<"\n";
        cnt%=3;
        
        for(int j=0;j<cnt;j++){
            *norm*=p1;
        }

        for(int j=0;j<(3-cnt)%3;j++){
            *invNorm*=p1;
        }

    }

    if(x>0){
        // cout<<"hi\n";
        *norm*=x;
        *invNorm *= (x*x);
    }

}

void solve()
{
    int n;
    cin>>n;
    memset(primes,1, sizeof(primes));
    for(int i=2;i<N;i++){
        if(primes[i]){
            p.push_back(i);
            for(int j=i*i;j<=N;j+=i){
                primes[j]=0;
            }
        }
    }

    map<int,int>mp;
    int ans=0;


    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        int invNorm, norm;
        getNorm(x, &norm,&invNorm);
        // cout<<norm<<" "<<invNorm<<"\n";
        ans+=mp[invNorm];
        mp[norm]++;
    }
    cout<<ans<<"\n";
    
   
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
