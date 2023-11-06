#include <bits/stdc++.h>
using namespace std;


long long int memo[1000];

long long int fib(int n){

    if(memo[n] != -1)
        return f[n];

    if(n <= 1)
        return n;
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int main(){

    for(int i = 0; i<1000; i++)
        memo[i] = -1;

    int n;
    cin>>n;

    cout<<fib(n);
}
