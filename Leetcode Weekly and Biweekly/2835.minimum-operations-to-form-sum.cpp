/*

You are given a 0-indexed array nums consisting of non-negative powers of 2, and an integer target.

In one operation, you must apply the following changes to the array:

Choose any element of the array nums[i] such that nums[i] > 1.
Remove nums[i] from the array.
Add two occurrences of nums[i] / 2 to the end of nums.
Return the minimum number of operations you need to perform so that nums contains a subsequence whose elements sum to target. If it is impossible to obtain such a subsequence, return -1.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

GREEDY / ADHOC/BIT MANIPULATION
*/

class Solution {
public:
void print(vector<int>&v){
    cout<<"Printing vector\n";
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
}
    int minOperations(vector<int>& nums, int target) {
        vector<int>bit_count(32);
        for(int i:nums){
            bit_count[log2(i)]++;
        }
        // print(bit_count);
        
        // for(int i=0;i<31;i++){
        //     if(bit_count[i]>1){
        //         bit_count[i+1]+=(bit_count[i]-1)/2;
        //         bit_count[i]=1;
        //     }
        // }
        // print(bit_count);
        int steps = 0;
        for(int i=0;i<31;i++){
            if(target&(1<<i)){
                if(bit_count[i]>0){
                    // cout<<i<<" okay\n";
                    bit_count[i]--;
                }else {
                    int j=i+1;
                    while(j<31 && bit_count[j]==0) {
                        j++;
                    }
                    if(j==31){
                        return -1;
                    }
                    // cout<<"Found j at "<<j<<"\n";
                    bit_count[j]-=1;
                    steps+=(j-i);
                    j--;
                    while(j>i){
                        bit_count[j]++;
                        j--;
                    }
                    bit_count[i]=1;
                }
            }
            bit_count[i+1]+=bit_count[i]/2;
            bit_count[i]=0;
        }
        return steps;
    }
};
