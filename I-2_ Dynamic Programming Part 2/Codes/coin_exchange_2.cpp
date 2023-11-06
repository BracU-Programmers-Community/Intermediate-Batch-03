
#include <bits/stdc++.h>
using namespace std;

int coins[105];
int n;

int memo[1000000+10][105];

const int mod = 1e9+7;

int dp(int x, int i){

    if(memo[x][i] != -1)
        return memo[x][i];

    if(x == 0)
        return 1;

    int ans = 0;

    if(x-coins[i] >= 0)
        ans = (ans + dp(x-coins[i], i))%mod;

    if(i-1 >= 0)
        ans = (ans + dp(x, i-1))%mod;

    memo[x][i] = ans;
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

    int ans = dp(x, n-1);

    cout<<ans<<endl;


    return 0;
}

