/*
You are given a 0-indexed array of positive integers nums and a positive integer limit.

In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] because they differ at index 0 and 2 < 10.
*/ 

using pii = pair<int,int>;
#define F first
#define S second 
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
       vector<pii>v;
       vector<int> ans;
       int n = nums.size();
       for(int i=0;i<n;i++){
           v.push_back({nums[i],i});
       }

       sort(v.begin(),v.end());

       vector<vector<pii>>v1={{v[0]}};
       for(int i=1;i<n;i++){
           if((v[i].F-v[i-1].F)<=limit){
               v1.back().push_back(v[i]);
           }else {
               v1.push_back({v[i]});
           }
       }

        for (auto c:v1){
            vector<int>ind;
            for(auto t:c){
                ind.push_back(t.S);
            }
            sort(ind.begin(),ind.end());
            for(int j=0;j<c.size();j++) {
                nums[ind[j]] = c[j].F;
            }
        }

       return nums;
    }
};
