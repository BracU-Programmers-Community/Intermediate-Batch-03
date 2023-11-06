
#include <bits/stdc++.h>
using namespace std;

const int nmax = 3000+5;

string s, t;

int memo[nmax][nmax];
int link[nmax][nmax];


int dp(int x, int y){
    if(memo[x][y] != -1)
        return memo[x][y];

    if(x == 0 || y == 0)
        return 0;

    int ans;

    if(dp(x-1, y) > dp(x, y-1)){
        ans = dp(x-1, y);
        link[x][y] = 1;
    }
    else{
        ans = dp(x, y-1);
        link[x][y] = 2;
    }

    if(s[x-1] == t[y-1] && dp(x-1, y-1) + 1 > ans){
        ans = dp(x-1, y-1) + 1;
        link[x][y] = 3;
    }


    memo[x][y] = ans;
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));

    cin>>s>>t;

    int len = dp(s.size(), t.size());


    int x = s.size(), y = t.size();

    string ans;
    while(x != 0 && y != 0){

//        cout<<x<<" "<<y<<endl;
        if(link[x][y] == 1){
            x = x-1;
        }
        else if(link[x][y] == 2){
            y = y-1;
        }
        else{
            ans.push_back(s[x-1]);
            x = x-1;
            y = y-1;
        }
    }

    reverse(ans.begin(), ans.end());

    cout<<ans<<endl;
}
