#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5+10;

int a[nmax], b[nmax], c[nmax];

int memo[nmax][3];

int dp(int i, int x){

    if(memo[i][x] != -1)
        return memo[i][x];

    if(i == 0){
        if(x == 0) return a[0];
        if(x == 1) return b[0];
        if(x == 2) return c[0];
    }

    if(x == 0){
        memo[i][x] =  max(dp(i-1, 1) + a[i], dp(i-1, 2) + a[i]);
    }

    if(x == 1){
        memo[i][x] =  max(dp(i-1, 0) + b[i], dp(i-1, 2) + b[i]);
    }

    if(x == 2){
        memo[i][x] =  max(dp(i-1, 0) + c[i], dp(i-1, 1) + c[i]);
    }

    return memo[i][x];
}


int main(){

    memset(memo, -1, sizeof(memo));

    int n;
    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }


    int x = dp(n-1, 0);
    int y = dp(n-1, 1);
    int z = dp(n-1, 2);

    int ans = max(x, y);
    ans =max(ans, z);

    cout<<ans<<endl;

}
