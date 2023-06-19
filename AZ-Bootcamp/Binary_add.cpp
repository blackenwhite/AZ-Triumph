#include <bits/stdc++.h>
using namespace std;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   string s1,s2;
   vector<int>ans;
   int carry = 0;
   cin>>s1>>s2;
   int i = s1.length()-1;
   int j = s2.length()-1;
   while(i>=0 or j>=0 or carry){
       if(i>=0){
           carry+=s1[i]-'0';
           i--;
       }
       if(j>=0){
           carry+=s2[j]-'0';
           j--;
       }
       ans.push_back(carry%2);
       carry/=2;
   }
   for(int i=ans.size()-1;i>=0;i--){
       cout<<ans[i];
   }
}
