using ll = long long;
const ll mod = 1e9+7;
class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        cost2 = min(cost2, 2*cost1);
        ll n = nums.size();
        ll sumval = 0;
        ll maxval = 0;
        ll minval = 1e9;

        for(int i=0;i<n;i++) {
            sumval+=nums[i];
            maxval = max(maxval, 1LL*nums[i]);
            minval = min(minval, 1LL*nums[i]);
        }

        ll final_ans = 2e18;
        for(int x = maxval; x<=(2*maxval);x++) {
            ll sum = n*x - sumval;
            ll maxi = x-minval;
            if(maxi>(sum-maxi)) {
                ll combine = (sum-maxi);
                ll left = maxi - (sum-maxi);
                final_ans = min(final_ans, combine*cost2+left*cost1);
            } else {
                ll combine = sum/2;
                ll left = sum%2;
                final_ans = min(final_ans, combine*cost2+left*cost1);
            }
        }
        return final_ans%mod;
    }
};
