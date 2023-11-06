#include <bits/stdc++.h>
using namespace std;

int arr[1000+5];
int memo[1000+5];


///O(n^2)
int dp(int n){
    if(memo[n] != -1)
        return memo[n];

    int ans = 1;

    for(int i = 0; i<n; i++){
        if(arr[i] < arr[n])
            ans = max(ans, dp(i)+1);
    }

    memo[n] = ans;
    return memo[n];
}


int main(){

    memset(memo, -1, sizeof(memo));

    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }


    int ans = 0;

    for(int i = 0; i<n; i++){
        ans = max(ans, dp(i));
    }

    cout<<ans<<endl;


    return 0;
}


