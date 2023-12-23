/*
there are 3 types of queries

0 X add a number X, 1 X remove the number X (X always exist), 2 X return the number of subsets that sum to X,

0<=X<=10^3 0<=number of queries <=10^3
*/

vector<int> dp(1001,0);
    dp[0] = 1;
    const int mod = 1e9 + 7;
    int Q;
    cin >> Q;
    while(Q--) {
        int tt,x;
        cin >> tt >> x;
        if(tt == 0) {
            for(int i=1000;i>=x;--i)
                dp[i] = (dp[i] + dp[i-x]) % mod;
        }
        else if(tt == 1) {
            for(int i=x;i<=1000;++i)
                dp[i] = (dp[i] - dp[i-x] + mod) % mod;
        }
        else {
            cout << dp[x] << "\n";
        }
    }
