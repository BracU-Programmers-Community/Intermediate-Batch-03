#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5+10;

vector<pair<int, int>> queries[nmax];



int tree[4*nmax];


void update(int id, int l, int r, int k, int u) {
    if(l == r){
        tree[id] = u;
        return;
    }

    int mid = (l+r)/2;

    if(k <= mid)
        update(2*id, l, mid, k, u);
    else
        update(2*id+1, mid+1, r, k, u);

    tree[id] = (tree[2*id] + tree[2*id+1]);
}


int query(int id, int l, int r, int a, int b) {

    if(a <= l && r <= b){       /// (l, r) is inside (a, b)
        return tree[id];
    }

    if(r < a || b < l){         /// (l, r) is disjoint to (a, b)
        return 0;
    }

    int mid = (l+r)/2;


    int p = query(2*id, l, mid, a, b);          /// contribution from left child
    int q = query(2*id+1, mid+1, r, a, b);      /// contribution from right child

    return (p + q);
}






int answers[nmax];




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin>>n>>q;

    vector<int> input(n+1);

    for(int i = 1; i<=n; i++){
        cin>>input[i];
    }


    for(int i = 0; i<q; i++){
        int a, b;
        cin>>a>>b;

        queries[b].push_back(make_pair(a, i));      /// queries[r] (l, r)   -> (l, i)

        /// cannot answer here
    }


    map<int, int> last;
    for(int r = 1; r<=n; r++){
        update(1, 1, n, r, 1);      /// put 1 at index r

        if(last.count(input[r])){
            update(1, 1, n, last[input[r]], 0);
        }

        last[input[r]] = r;


        for(int j = 0; j<queries[r].size(); j++){
            int l = queries[r][j].first;
            int qid = queries[r][j].second;


            int ans = query(1, 1, n, l, r);
            answers[qid] = ans;
        }
    }


    for(int i = 0; i<q; i++){
        cout<<answers[i]<<"\n";
    }


    return 0;
}
