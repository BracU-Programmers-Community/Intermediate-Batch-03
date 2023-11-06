
#include <bits/stdc++.h>
using namespace std;

int a[100+5];
const int mod = 1e9+7;

int memo[100000+10][100+5];


///O(n^2)
int dp(int k, int n){
    if(memo[k][n] != -1)
        return memo[k][n];

    if(n == 0)
        return k == 0 ? 1 : 0;


    int ans = 0;
    for(int x = 0; x<= a[n]; x++){
        if(k-x < 0) continue;

        ans += dp(k-x, n-1);
        ans %= mod;
    }

    memo[k][n] = ans;
    return memo[k][n];
}


int main(){



    cin>>n;
    int target;
    cin>>target;

    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }


    cout<<dp(target, n)<<endl;


    return 0;
}


