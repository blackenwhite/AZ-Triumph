#include <bits/stdc++.h> 
using namespace std; 
int main(){
    long long int n,c;
cin>>n>>c;
long long int vals[n][2];
for (int i=0;i<n;i++)
{
    cin>>vals[i][0]>>vals[i][1];
}
long long int dp[n+1][c+1];
for (int i=0;i<=n;i++){
	for(int j=0;j<=c;j++){
		
		dp[i][j]=0;
	}
}
for (int i=1;i<n+1;i++){
	
	for(int j=1;j<c+1;j++){
		if (vals[i-1][0]>j){
			dp[i][j]=dp[i-1][j];
		}
		else{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-vals[i-1][0]]+vals[i-1][1]);
		}
		
	}
	
}
cout<<dp[n][c];
}
