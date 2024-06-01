class Solution {
public:
    long long int count;

    void checkCount(vector<int>& nums, int start, int mid, int end, int d) {

        int l = start, r = mid + 1;
        while (l <= mid && r <= end) {
            if (nums[l] <=
                (nums[r] +
                 d)) // if (nums[l]<=nums[r]+d) then all values from nums[r] to
                     // nums[end] will be be having their summation with d
                     // greater than or equal to nums[l]
            {
                count += (end - r + 1);
                l++;
            } else // otherwise we need to increment r so that we can find match
                   // for nums[l]
            {
                r++;
            }
        }
        // sort all values from start to end
        sort(nums.begin() + start,
             nums.begin() + end +
                 1); // (Sort using two-pointers for better time complexity)
        return;
    }
    void mergeSort(vector<int>& nums, int start, int end, int d) {
        if (start == end)
            return;

        int mid = (start + end) / 2;
        mergeSort(nums, start, mid, d);
        mergeSort(nums, mid + 1, end, d);

        checkCount(nums, start, mid, end, d);
        return;
    }
    long long numberOfPairs(vector<int>& a, vector<int>& b, int d) {
        count = 0;
        int n = a.size();
        vector<int> c(n);

        for (int i = 0; i < n; i++)
            c[i] = a[i] - b[i];

        mergeSort(c, 0, n - 1, d);

        return count;
    }
};
