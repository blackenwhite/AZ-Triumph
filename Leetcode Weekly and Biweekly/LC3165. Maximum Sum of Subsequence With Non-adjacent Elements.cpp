const long long inf = 1e18;
const long long mod = 1e9 + 7;

// Modified from https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LazySegmentTree.h
struct Node {
    Node *l = nullptr, *r = nullptr;
    unsigned int lo, hi;
    long long selected[2][2];

    Node(const vector<int> &nums, unsigned int lo, unsigned int hi) : lo(lo), hi(hi) {
        if (lo < hi) {
            unsigned int mid = (lo + hi) / 2;
            l = new Node(nums, lo, mid);
            r = new Node(nums, mid + 1, hi);

            combine();
        } else {
            selected[0][0] = 0;
            selected[0][1] = -inf;
            selected[1][0] = -inf;
            selected[1][1] = nums[lo];
        }
    }

    void combine() {
        selected[0][0] = max(l->selected[0][0] + r->selected[0][0], max(l->selected[0][1] + r->selected[0][0], l->selected[0][0] + r->selected[1][0]));
        selected[0][1] = max(l->selected[0][0] + r->selected[0][1], max(l->selected[0][1] + r->selected[0][1], l->selected[0][0] + r->selected[1][1]));
        selected[1][0] = max(l->selected[1][0] + r->selected[0][0], max(l->selected[1][1] + r->selected[0][0], l->selected[1][0] + r->selected[1][0]));
        selected[1][1] = max(l->selected[1][0] + r->selected[0][1], max(l->selected[1][1] + r->selected[0][1], l->selected[1][0] + r->selected[1][1]));
    }

    void update(int i, long long x) {
        if (i < lo || hi < i) {
            return;
        }

        if (lo == hi) {
            selected[0][0] = 0;
            selected[1][1] = x;
            return;
        }

        l->update(i, x);
        r->update(i, x);

        combine();
    }
};

class Solution {
  public:
    int maximumSumSubsequence(vector<int> &nums, vector<vector<int>> &queries) {
        Node segmentTree(nums, 0, nums.size() - 1);

        long long res = 0;
        for (auto &query : queries) {
            segmentTree.update(query[0], query[1]);
            res += max(segmentTree.selected[0][0], max(segmentTree.selected[0][1], max(segmentTree.selected[1][0], segmentTree.selected[1][1])));
            res %= mod;
        }
        return static_cast<int>(res);
    }
};
