// leetcode 2025
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<long long> pref(n), suff(n);

        //store prefix and suffix sum
        pref[0] = nums[0]; suff[n-1] = nums[n-1];
        for(int i=1; i<n; ++i) { 
            pref[i]     = pref[i-1] + nums[i]; 
            suff[n-1-i] = suff[n-i] + nums[n-1-i];
        } 
        // for(int i=n-2; i>=0; --i) suff[i] = suff[i+1] + nums[i];
 
        long long ans = 0;
        unordered_map<long long,long long> left, right;
        
        //intially store the differences in the hashmap right
        for(int i=0;i<n-1; ++i) right[pref[i] - suff[i+1]]++;
        
        
        if(right.count(0)) ans = right[0];
        for(int i=0; i<n; ++i){

            //find the number of pivot indexes when nums[i] is changed to k
            long long curr = 0, diff = k-nums[i];
            if(left.count(diff)) curr+=left[diff];
            if(right.count(-diff)) curr+=right[-diff];

            //update answer
            ans = max(ans, curr);
            
            //transfer the current element from right to left
            if(i<n-1){
                long long dd = pref[i]-suff[i+1]; 
                left[dd]++; right[dd]--;
                if(right[dd] == 0) right.erase(dd);

            }
        }
        return ans;
        
    }
};
