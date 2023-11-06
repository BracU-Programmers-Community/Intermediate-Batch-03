#include <bits/stdc++.h>
using namespace std;

int coins[105];
int n;

int memo[1000000 + 10];

const int mod = 1e9+7;

int dp(int x){
    if(memo[x] != -1)
        return memo[x];

    if(x == 0)
        return 1;

    int ans = 0;

    for(int i = 0; i<n; i++){
        if(x < coins[i])
            continue;
        int candidate = dp(x-coins[i]);
        ans = (ans + candidate) % mod;
    }

    memo[x] = ans;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));

    int x;
    cin>>n>>x;

    for(int i = 0; i<n; i++)
        cin>>coins[i];

    int ans = dp(x);

    cout<<ans<<endl;


    return 0;
}

