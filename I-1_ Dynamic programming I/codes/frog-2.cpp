#include <bits/stdc++.h>
using namespace std;

int input[100000+10];
int k;

int memo[100000+10];

int dp(int i){
    if(memo[i] != -1)
        return memo[i];

    if(i == 0)
        return 0;

    int mn = 1e9;
    for(int j = max(i-k, 0); j<i; j++){
        int cand = dp(j) + abs(input[i] - input[j]);
        mn = min(mn, cand);
    }

    memo[i] = mn;
    return memo[i];
}

/// number of state = n
/// time per state = k
/// n*k

int main(){

    for(int i = 0; i<100000+10; i++)
        memo[i] = -1;

    int n;

    cin>>n>>k;

    for(int i = 0; i<n; i++)
        cin>>input[i];

    cout<<dp(n-1);

}
