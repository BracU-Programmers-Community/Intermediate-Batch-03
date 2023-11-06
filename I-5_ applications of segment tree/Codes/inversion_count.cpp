#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5+10;

using ll = long long int;
ll input[nmax];
ll arr[nmax];
ll tree[4*nmax];

/// O(n)
void build(int id, int l, int r) {
    if(l == r){
        tree[id] = 0;
        return;
    }


    int mid = (l+r)/2;

    build(2*id, l, mid);        /// left child
    build(2*id+1, mid+1, r);        /// right child

    tree[id] = (tree[2*id] + tree[2*id+1]);
}


void update(int id, int l, int r, int k, int u) {
    if(l == r){
        tree[id] += u;
        return;
    }

    int mid = (l+r)/2;

    if(k <= mid)
        update(2*id, l, mid, k, u);
    else
        update(2*id+1, mid+1, r, k, u);

    tree[id] = (tree[2*id] + tree[2*id+1]);
}


ll query(int id, int l, int r, int a, int b) {

    if(a <= l && r <= b){       /// (l, r) is inside (a, b)
        return tree[id];
    }

    if(r < a || b < l){         /// (l, r) is disjoint to (a, b)
        return 0;
    }

    int mid = (l+r)/2;


    ll p = query(2*id, l, mid, a, b);          /// contribution from left child
    ll q = query(2*id+1, mid+1, r, a, b);      /// contribution from right child

    return (p + q);
}




int main(){

    int tc;
    cin>>tc;

    for(int cs = 1; cs<= tc; cs++){
        int n;
        cin>>n;

        for(int i = 1; i<= n; i++){
            cin>>input[i];
        }

        /// compression

        set<int> values;

        for(int i = 1; i<=n; i++)
            values.insert(input[i]);

        map<int, int> mp;
        int cnt = 0;
        for(int x: values){         /// loop will be in sorted order
            cnt++;
            mp[x] = cnt;
        }


        for(int i = 1; i<=n; i++){
            input[i] = mp[input[i]];
        }

        ll ans = 0;

        build(1, 1, n);

        for(int i = 1; i<=n; i++){
            update(1, 1, n, input[i], +1);

            if(input[i]+1 <= n)
                ans += query(1, 1, n, input[i]+1, n);
        }

        cout<<ans<<"\n";


    }
    return 0;
}


