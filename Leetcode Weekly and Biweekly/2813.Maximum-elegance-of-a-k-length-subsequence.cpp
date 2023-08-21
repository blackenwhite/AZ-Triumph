/*
You are given a 0-indexed 2D integer array items of length n and an integer k.

items[i] = [profiti, categoryi], where profiti and categoryi denote the profit and category of the ith item respectively.

Let's define the elegance of a subsequence of items as total_profit + distinct_categories2, where total_profit is the sum of all profits in the subsequence, and distinct_categories is the number of distinct categories from all the categories in the selected subsequence.

Your task is to find the maximum elegance from all subsequences of size k in items.

Return an integer denoting the maximum elegance of a subsequence of items with size exactly k.

Note: A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order.

GREEDY + ADHOC + OPTIMISATION
*/

#define ll long long
class Solution {
public:
    void print(vector<vector<int>>&v){
        cout<<"printing vector\n";
        for(int i=0;i<v.size();i++){
            cout<<v[i][0]<<" ";
        }
        cout<<"\n";
    }
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();
        auto compare = [](vector<int>&a, vector<int>&b) {
            return a[0]>b[0];
        };

        sort(items.begin(), items.end(), compare);
        // print(items);
        unordered_set<int>seen;
        vector<int>dups;
        ll res = 0;
        ll cur = 0;
        int i=0;
        for(;i<k;i++){
            cur+=items[i][0];
            if(seen.find(items[i][1])!=seen.end()){
                dups.push_back(items[i][0]);
            }
            seen.insert(items[i][1]);
            ll dist=seen.size();
            res = fmax(res, cur+(dist*dist));
        }

        for(;i<n;i++){
            int category = items[i][1];
            if(seen.find(category)==seen.end()){
                if(dups.size()==0) {
                    return res;
                }

                cur-=dups.back();
                dups.pop_back();
                cur+=items[i][0];
                seen.insert(category);
                ll dist = seen.size();
                res = fmax(res, cur+(dist*dist));
            }
        }
        return res;
    }
};
