#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int nmax = 2e5+10;

T arr[nmax];
T tree[4*nmax];

/// O(n)
void build(int id, int l, int r) {
    if(l == r){
        tree[id] = arr[l];
        return;
    }


    int mid = (l+r)/2;

    build(2*id, l, mid);        /// left child
    build(2*id+1, mid+1, r);        /// right child

    tree[id] = op(tree[2*id], tree[2*id+1]);
}


void update(int id, int l, int r, int k, int u) {
    if(l == r){
        tree[id] = F(u);
        return;
    }

    int mid = (l+r)/2;

    if(k <= mid)
        update(2*id, l, mid, k, u);
    else
        update(2*id+1, mid+1, r, k, u);

    tree[id] = op(tree[2*id], tree[2*id+1]);
}


T query(int id, int l, int r, int a, int b) {

    if(a <= l && r <= b){       /// (l, r) is inside (a, b)
        return tree[id];
    }

    if(r < a || b < l){         /// (l, r) is disjoint to (a, b)
        return identity;
    }

    int mid = (l+r)/2;


    T p = query(2*id, l, mid, a, b);          /// contribution from left child
    T q = query(2*id+1, mid+1, r, a, b);      /// contribution from right child

    return op(p, q);
}




