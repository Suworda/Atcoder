#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
int p[200005];

struct Node{
    int mi_id, mx_id;
    int mi, mx, l, r;
    Node *left, *right;
};
Node *root = new Node;

void pull(Node *rt){
    Node *L = rt->left;
    Node *R = rt->right;

    if(L->mi < R->mi){
        rt->mi = L->mi;
        rt->mi_id = L->mi_id;
    }
    else{
        rt->mi = R->mi;
        rt->mi_id = R->mi_id;
    }

    if(L->mx > R->mx){
        rt->mx = L->mx;
        rt->mx_id = L->mx_id;
    }
    else{
        rt->mx = R->mx;
        rt->mx_id = R->mx_id;
    }
}

void build(int l, int r, Node *rt){
    rt->l = l;
    rt->r = r;
    if(l == r){
        rt->mi = p[l];
        rt->mi_id = l;
        rt->mx = p[l];
        rt->mx_id = l;
        return;
    }

    rt->left = new Node;
    rt->right = new Node;

    int m = (l+r)/2;
    build(l,m,rt->left);
    build(m+1, r, rt->right);
    pull(rt);
}

void upd(int x, int v, Node *rt){
    if(rt->l == x && rt->r == x){
        rt->mi = v;
        rt->mx = v;
        return;
    }

    if(x <= rt->left->r) upd(x,v,rt->left);
    else upd(x,v,rt->right);

    pull(rt);
}

pair<int,int> query(int ql, int qr, Node *rt){
    if(qr < rt->l || rt->r < ql) return {-1,-1};
    
    if(ql <= rt->l &&  rt->r <= qr){
        return {rt->mi_id, rt->mx_id};
    }
    
    auto [mi_id1,mx_id1] = query(ql, qr, rt->left);
    auto [mi_id2,mx_id2] = query(ql, qr, rt->right);

    if(mi_id1 == -1 && mx_id1 == -1) return {mi_id2, mx_id2};
    if(mi_id2 == -1 && mx_id2 == -1) return {mi_id1, mx_id1};

    int mi1 = p[mi_id1];
    int mx1 = p[mx_id1];
    int mi2 = p[mi_id2];
    int mx2 = p[mx_id2];
    
    int rst1 = -1;
    int rst2 = -1;
    
    if(mi1 < mi2) rst1 = mi_id1;
    else rst1 = mi_id2;
    
    if(mx1 > mx2) rst2 = mx_id1;
    else rst2 = mx_id2;
    
    return {rst1, rst2};
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }
    
    build(1,n,root);

    while(m--){
        int l, r;
        cin>>l>>r;
        auto [mi_id, mx_id] = query(l,r,root);
        int mi = p[mi_id];
        int mx = p[mx_id];

        upd(mi_id, mx, root);
        upd(mx_id, mi, root);
        swap(p[mi_id], p[mx_id]);
    }

    for(int i=1; i<=n; i++){
        cout << p[i] << ' ';
    }

    cout << '\n';
} 