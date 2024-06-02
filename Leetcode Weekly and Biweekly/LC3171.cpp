/*
You are given an array nums and an integer k. You need to find a 
subarray
 of nums such that the absolute difference between k and the bitwise AND of the subarray elements is as small as possible. In other words, select a subarray nums[l..r] such that |k - (nums[l] AND nums[l + 1] ... AND nums[r])| is minimum.

Return the minimum possible value of the absolute difference.

A subarray is a contiguous non-empty sequence of elements within an array.



*/
class Solution {
public:
    void changeBitCount(int n,int f,vector<int> &countBits){
        
        int j=0;
        while(n>0){
            if(n&1){
                countBits[j] += f;
            }
            n = n/2;
            j++;
        }
    }
    int minimumDifference(vector<int>& nums, int k) {
        
        vector<int> countBits(35,0);
        int ans = INT_MAX;
        int st = 0;
        int cur = nums[0];
        for(int i=0;i<nums.size();i++){
            cur = cur & nums[i];
            changeBitCount(nums[i],1,countBits);
            
            ans = min(ans, abs(k-cur));
            
            if( cur == k) return 0;
            
            if(cur>k){
                continue;
            }
            else{
                while(st<=i && cur<k){
                     changeBitCount(nums[st],-1,countBits);
                    st++;
                
                cur = 0;
                for(int j=0;j<32;j++){
                    if( (i-st+1) == countBits[j]){
                        cur = cur | (1<<j);
                    }
                }
                ans = min(ans, abs(k-cur));
                }
            }
            
            
        }
        return ans;
        
        
    }
};
