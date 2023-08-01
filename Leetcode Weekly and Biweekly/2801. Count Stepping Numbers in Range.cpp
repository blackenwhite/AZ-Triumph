class Solution {
public:
    int mod = 1e9+7;
    int n;
    int dp[105][2][2][11][2];
    string L,R;
    int countSteppingNumbers(string L, string R) {
        this->L=L;
        this->R=R;
        int cnt = R.length()-L.length();
        string temp="";
        while(cnt--){
            temp+="0";
        }
        this->L=temp+L;
        // cout<<L<<"\n";
        n=R.length();
        memset(dp,-1,sizeof(dp));
        return rec(0,1,1,-1,1);
    }
    
    int rec(int lvl, int tlo, int thi, int prev, int leadingZ){
        // cout<<"rec for "<<lvl<<" "<<tlo<<" "<<thi<<" "<<prev<<endl;
        if(lvl==n){
            return 1;
        }

        if(dp[lvl][tlo][thi][prev+1][leadingZ]!=-1){
            return dp[lvl][tlo][thi][prev+1][leadingZ];
        }

        int ans=0;
        int lo=0;
        if(tlo==1){
            lo=L[lvl]-'0';
        }
        int hi=9;
        if(thi==1){
            hi=R[lvl]-'0';
        }
        // cout<<"lo and hi "<<lo<<" "<<hi<<endl;
        for(int i=lo;i<=hi;i++){
            int dig=i;
            if(prev!=-1 && leadingZ==0){
                if(abs(dig-prev)!=1) continue;
            }
            // cout<<"hello"<<endl;
            int ntlo = tlo;
            if(i!=L[lvl]-'0') ntlo=0;
            int nthi=thi;
            if(i!=R[lvl]-'0') nthi=0;
            int nlz=0;
            if(dig==0 && leadingZ==1){
                nlz=1;
            }
            ans+=rec(lvl+1,ntlo,nthi,dig,nlz);
            ans%=mod;
        }
        return dp[lvl][tlo][thi][prev+1][leadingZ]=ans;

    }
};
