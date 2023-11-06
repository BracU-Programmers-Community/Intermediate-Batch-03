#include <bits/stdc++.h>
using namespace std;

int n;
int coins[105];

bool memo[10000+5][100+5];
bool visited[10000+5][100+5];


/// O(ns)
bool dp(int s, int k){
    if(visited[s][k])
        return memo[s][k];


    if(s == 0)
        return true;

    if(k == 0)
        return coins[0] == s;

    visited[s][k] = true;

    if(dp(s, k-1)){
        memo[s][k] = true;
        return memo[s][k];
    }


    if(s >= coins[k] && dp(s-coins[k], k-1)){
        memo[s][k] = true;
        return memo[s][k];
    }

    memo[s][k] = false;
    return memo[s][k];
}

int main(){


    cin>>n;

    for(int i = 0; i<n; i++)
        cin>>coins[i];


    int x;
    cin>>x;

    if(dp(x)){
        cout<<"possible"<<endl;
    }
    else{
        cout<<"impossible"<<endl;
    }


    return 0;
}

