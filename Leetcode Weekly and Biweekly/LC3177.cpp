/*
You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].

Return the maximum possible length of a good 
subsequence
 of nums.
*/

class Solution {
public:
    int dp[55][5005];
    int max_dp[55][5005] = {0};
    unordered_map<int,int>mp;
    
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        mp[nums[0]] = 0;
        
        for(int i=0;i<=k;i++){
            dp[i][0] = 1;
            max_dp[i][0] = 1;
        }
        
        for(int j=1;j<n;j++){
            int last_seen = mp.find(nums[j])==mp.end() ? j : mp[nums[j]];
            for(int i=k;i>=0;i--) {
                int ans = INT_MIN;
                if(last_seen!=j){
                    ans = max(ans, 1+dp[i][last_seen]);
                }
                ans = max(ans, 1 + (i>0 ? max_dp[i-1][j-1]:0));
                dp[i][j] = ans;
                max_dp[i][j] = max(max_dp[i][j-1], dp[i][j]);
            }
            mp[nums[j]] = j;
        }
        return max_dp[k][n-1];
    }
};
