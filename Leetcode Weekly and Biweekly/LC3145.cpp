/*
A powerful array for an integer x is the shortest sorted array of powers of two that sum up to x. For example, the powerful array for 11 is [1, 2, 8].

The array big_nums is created by concatenating the powerful arrays for every positive integer i in ascending order: 1, 2, 3, and so forth. Thus, big_nums starts as [1, 2, 1, 2, 4, 1, 4, 2, 4, 1, 2, 4, 8, ...].

You are given a 2D integer matrix queries, where for queries[i] = [fromi, toi, modi] you should calculate (big_nums[fromi] * big_nums[fromi + 1] * ... * big_nums[toi]) % modi.

Return an integer array answer such that answer[i] is the answer to the ith query.

*/

typedef long long int ll;

class Solution {
    
    ll CountOf2TillX (ll x) {
        if (x <= 1) return 0;
        if (x == 2) return 1;
        if (x == 3) return 2;
        
        ll largest_i = 0;
         for (ll i = 2; i < 61; i ++) {
            if ((1LL << i) <= x) continue;
            largest_i = i;
            break;
        }
        largest_i --;
        
        ll ans = (1LL << (largest_i-2))*largest_i*(largest_i-1);
        ll lft = x - ((1LL << largest_i) - 1);
        return (ans + lft*largest_i + CountOf2TillX(lft-1));
    }
    
    ll TermsTillX (ll x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        
        ll largest_i = 0;
         for (ll i = 0; i < 61; i ++) {
            if ((1LL << i) <= x) continue;
            largest_i = i;
            break;
        }
        largest_i --;
        
        ll ans = (1LL << (largest_i-1))*largest_i;
        ll lft = x - ((1LL << largest_i) - 1);
        return (ans + lft + TermsTillX(lft-1));
    }
    
    ll CountOf2TillIndex (ll ind) {
        if (ind == 1) return 0;
        
        ll l = 0, r = 1e15;
        while (l < r) {
            ll m = (l+r) >> 1;
            if (TermsTillX(m) >= ind) r = m;
            else l = m+1;
        }
        if (TermsTillX(l) > ind) l --;
        
        ll ans = CountOf2TillX(l);
        
        ind -= TermsTillX(l);
        for (int i = 0; ind > 0 && i < 61; i ++) {
            if (((1LL << i) & (l+1)) == 0) continue;
            ind --;
            ans += i;
        }
        
        return ans;
    }
    
    ll FastPower (ll a, ll b, ll M) {
        ll ans = 1;
        while (b) {
            if (b&1) ans = (ans * a) % M;
            a = (a * a) % M;
            b /= 2;
        }
        return ans % M;
    }
    
public:
    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        vector<int> ans;
        
        for (auto q: queries) {
            ll cnt_2 = CountOf2TillIndex(q[1]+1) - CountOf2TillIndex(q[0]);
            ans.push_back(FastPower(2, cnt_2, q[2])); 
        }
        return ans;
    }
};
