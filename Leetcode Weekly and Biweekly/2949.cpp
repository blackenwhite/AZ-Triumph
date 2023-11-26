class Solution {
public:
#define ll long long

    // void pr(vector<int>&v) {
    //     cout<<"Printing vector---\n";
    //     for(auto it:v){
    //         cout<<it<<" ";
    //     }
    //     cout<<"\n";
    // }
    long long beautifulSubstrings(string s, int k) {
        ll ans = 0;
        int n = s.size();
        vector<int>pref(n);
        set<char>vowels = {'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            if(vowels.find(s[i])!=vowels.end()){
                pref[i]=1;
            }else{
                pref[i]=-1;
            }
        }

        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1];
        }
        // pr(pref);

        unordered_map<int,vector<int>> mp;
        mp[0].push_back(-1);
        for(int i=0;i<n;i++){
            int val = pref[i];
            // vector<int> seen = mp[val];
            // for(auto it : seen){
            //     int l1 = i-it;
            //     if(l1%2==0){
            //         int l = l1/2;
            //         if((l*l)%k==0) ans++;
            //     }
            // }
            if(mp.find(val)!=mp.end()){
                for(auto &it:mp[val]){
                    int l1 = i-it;
                    if(l1%2==0) {
                        int l = l1>>1;
                        if((l*l)%k==0) ans++;
                    }
                }
            }
            mp[val].push_back(i);
        }
        return ans;
    }
};
