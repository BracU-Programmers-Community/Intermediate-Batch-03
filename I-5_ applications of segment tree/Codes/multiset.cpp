#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e6+10;

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


ll walk(int id, int l, int r, int k){

    if(l == r){
        return l;
    }


    int mid = (l+r)/2;

    if(tree[2*id] >= k)
        return walk(2*id, l, mid, k);
    else
        return walk(2*id+1, mid+1, r, k-tree[2*id]);
}




int main(){

    int n, q;
    cin>>n>>q;


    for(int i = 0; i<n; i++){
        int x;
        cin>>x;

        update(1, 1, n, x, +1);
    }



    for(int i = 0; i<q; i++){
        int k;
        cin>>k;

        if(k >= 1){
            update(1, 1, n, k, +1);
        }
        else{
            k = abs(k);

            int x = walk(1, 1, n, k);

            update(1, 1, n, x, -1);
        }
    }

    int sz = query(1, 1, n, 1, n);

    if(sz == 0)
        cout<<0<<endl;
    else
        cout<<walk(1, 1, n, 1)<<endl;

    return 0;
}

