#include <bits/stdc++.h>
using namespace std;

using ll = long long int;

const int nmax = 2e5+10;

int arr[nmax];
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

    tree[id] = tree[2*id] + tree[2*id+1];
}


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

    tree[id] = tree[2*id] + tree[2*id+1];
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

    return p+q;
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


    /// build segment tree      /// not necessary?
    build(1, 1, n);             /// O(n)

//    for(int i = 1; i<=n; i++){          /// O(n log n)
//        update(1, 1, n, i, arr[i]);
//    }


    for(int i = 0; i<q; i++){           /// q log n
        int t;
        cin>>t;

        if(t == 1){
            int k ,u;
            cin>>k>>u;

            update(1, 1, n, k, u);          /// log n
        }
        else{
            int l, r;
            cin>>l>>r;

            cout<<query(1, 1, n, l, r)<<"\n";   /// log n
        }
    }

    return 0;
}
