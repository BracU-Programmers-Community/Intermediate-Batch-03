using ll = long long int;

const int nmax =;

T arr[nmax];
T tree[4*nmax];
T lazy[4*nmax];


void build(int id, int l, int r) {
    lazy[id] = 0;

    if(l == r){
        tree[id] = arr[l];
        return;
    }


    int mid = (l+r)/2;

    build(2*id, l, mid);        /// left child
    build(2*id+1, mid+1, r);        /// right child

    tree[id] = max(tree[2*id], tree[2*id+1]);
}

void propagate(int id, int l, int r) {
    //tree[id] += (r-l+1) * lazy[id];

    tree[id] += lazy[id];             /// apply lazy[id] to tree[id]

    if(l != r){
        lazy[2*id] += lazy[id];      /// push lazy to child
        lazy[2*id+1] += lazy[id];
    }

    lazy[id] = 0;
}


void update(int id, int l, int r, int a, int b, T x) {
    propagate(id, l, r);

    if(a <= l && r <= b){       /// (l, r) is inside (a, b)
        lazy[id] += x;        /// apply x to lazy
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


T query(int id, int l, int r, int a, int b) {
    propagate(id, l, r);

    if(a <= l && r <= b){       /// (l, r) is inside (a, b)
        return tree[id];
    }

    if(r < a || b < l){         /// (l, r) is disjoint to (a, b)
        return -1e9;
    }

    int mid = (l+r)/2;


    T p = query(2*id, l, mid, a, b);          /// contribution from left child
    T q = query(2*id+1, mid+1, r, a, b);      /// contribution from right child

    return max(p, q);
}

