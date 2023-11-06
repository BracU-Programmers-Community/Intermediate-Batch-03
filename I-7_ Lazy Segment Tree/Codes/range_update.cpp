#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int nmax = 2e5+10;

ll arr[nmax];
ll tree[4*nmax];
ll lazy[4*nmax];


void build(int id, int l, int r) {
    lazy[id] = 0;

    if(l == r){
        tree[id] = arr[l];
        return;
    }


    int mid = (l+r)/2;

    build(2*id, l, mid);        /// left child
    build(2*id+1, mid+1, r);        /// right child

    tree[id] = (tree[2*id] + tree[2*id+1]);
}

void propagate(int id, int l, int r) {
    tree[id] += (r-l+1) * lazy[id];

    if(l != r){
        lazy[2*id] += lazy[id];
        lazy[2*id+1] += lazy[id];
    }

    lazy[id] = 0;
}


void update(int id, int l, int r, int a, int b, ll x) {
    propagate(id, l, r);

    if(a <= l && r <= b){       /// (l, r) is inside (a, b)
        lazy[id] += x;
        propagate(id, l, r);
        return;
    }

    if(r < a || b < l){         /// (l, r) is disjoint to (a, b)
        return;
    }

    int mid = (l+r)/2;


    update(2*id, l, mid, a, b, x);          /// contribution from left child
    update(2*id+1, mid+1, r, a, b, x);      /// contribution from right child

    return;
}


ll query(int id, int l, int r, int a, int b) {
    propagate(id, l, r);

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin>>n>>q;


    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }


    build(1, 1, n);


    for(int i= 0; i<q; i++){
        int type;
        cin>>type;

        if(type == 2){
            int l;
            cin>>l;
            cout<<query(1, 1, n, l, l)<<"\n";
        }
        else{
            int l, r, x;
            cin>>l>>r>>x;

            update(1, 1, n, l, r, x);
        }
    }
}
