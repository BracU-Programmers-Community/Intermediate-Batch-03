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
        tree[id] = arr[l];
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

    int n, q;
    cin>>n>>q;

    for(int i = 1; i<=n; i++){
        cin>>input[i];
    }


    for(int i = 1; i<=n; i++){
        arr[i] = input[i] - input[i-1];     /// new format
    }

    build(1, 1, n);

    for(int i = 0; i<q; i++){
        int t;
        cin>>t;

        if(t == 1){
            int a, b, u;
            cin>>a>>b>>u;

            update(1, 1, n, a, +u);
            if(b+1 <= n)
                update(1, 1, n, b+1, -u);
        }
        else{
            int k;
            cin>>k;

            cout<<query(1, 1, n, 1, k)<<endl;
        }
    }


    return 0;
}
