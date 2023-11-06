#include <bits/stdc++.h>
using namespace std;


long long int memo[1000];


int main(){

    int n;
    cin>>n;


    memo[0] = 0;
    memo[1] = 1;

    for(int i = n; i>=2; i--){
        memo[i] = memo[i-1] + memo[i-2];
    }

    cout<<memo[n];
}

