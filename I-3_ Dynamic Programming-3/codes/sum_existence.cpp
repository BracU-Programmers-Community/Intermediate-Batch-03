#include <bits/stdc++.h>
using namespace std;

int n;
int coins[105];

bool memo[10000+5];
bool visited[10000+5];

bool dp(int s){
    if(visited[s])
        return memo[s];


    if(s == 0)
        return true;

    visited[s] = true;

    for(int i = 0; i<n; i++){
        if(s < coins[i])
            continue;

        if(dp(s-coins[i])){
            memo[s] = true;
            return memo[s];
        }

    }

    memo[s] = false;
    return memo[s];
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
