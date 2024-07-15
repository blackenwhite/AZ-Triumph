
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        return atLeastK(nums, k) - atLeastK(nums, k + 1);
    }
    long long atLeastK(vector<int>& nums, int k){
        long long ans = 0;
        vector<int> temp(32, 0);

        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            for (int i = 0; i < 32; i++)
            {
                if ((1 << i) & nums[r])
                {
                    temp[i]++;
                }
            }

            while ((r - l + 1) > 0 && calc(temp, r - l + 1) < k)
            {
                for (int i = 0; i < 32; i++)
                {
                    if ((1 << i) & nums[l])
                    {
                        temp[i]--;
                    }
                }
                l++;
            }
            ans += (r - l + 1);
        }
 
        return ans;
    }

    //function to calculate the AND from frequency vector
    int calc(vector<int>& temp, int w){
        int ans = 0;
        for (int i = 0; i < 32;i++){
            if(temp[i]==w)
                ans += (1 << i);
        }

        return ans;
    }
};
