#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

struct Point{
    ll x,y;
};
Point p[200005];


struct Node{
    int l,r;
    Node *left, *right;
    int id[4]; 
};
Node *root = new Node;


void pull(Node *rt){

    Point pl = p[rt->left->id[0]], pr = p[rt->right->id[0]];
    if(pl.x + pl.y > pr.x + pr.y){
        rt->id[0] = rt->left->id[0];
    }else{
        rt->id[0] = rt->right->id[0];
    }

    pl = p[rt->left->id[1]], pr = p[rt->right->id[1]];
    if(-pl.x + pl.y > -pr.x + pr.y){
        rt->id[1] = rt->left->id[1];
    }else{
        rt->id[1] = rt->right->id[1];
    }

    pl = p[rt->left->id[2]], pr = p[rt->right->id[2]];
    if(-pl.x - pl.y > -pr.x - pr.y){
        rt->id[2] = rt->left->id[2];
    }else{
        rt->id[2] = rt->right->id[2];
    }

    pl = p[rt->left->id[3]], pr = p[rt->right->id[3]];
    if(pl.x - pl.y > pr.x - pr.y){
        rt->id[3] = rt->left->id[3];
    }else{
        rt->id[3] = rt->right->id[3];
    }
}

void build(int l, int r, Node *rt){
    
    rt->l = l;
    rt->r = r;

    if(l == r){
        for(int i=0; i<4; i++) rt->id[i] = l;
        return;
    }

    rt->left = new Node;
    rt->right = new Node;
    int m = (l+r)/2;
    build(l, m, rt->left);
    build(m+1, r, rt->right);

    pull(rt);
}

void update(int tg, Node *rt){

    if(rt->l == tg && rt->r == tg) return;
    
    if(tg <= rt->left->r){
        update(tg, rt->left);

    }else{
        update(tg, rt->right);

    }

    pull(rt);
}

ll query(int ql, int qr, int x, int y, Node *rt){

    if(qr < rt->l ||  rt->r < ql){
        return -1;
    }

    if(ql <= rt->l && rt->r <= qr){
        ll ans = 0;
        for(int i=0; i<4; i++){
            ll px = p[rt->id[i]].x;
            ll py = p[rt->id[i]].y;

            ans = max(ans, abs(x-px) + abs(y-py));
        }
        return ans;
    }

    ll rst1 = query(ql, qr, x, y, rt->left);
    ll rst2 = query(ql, qr, x, y, rt->right);

    return max(rst1, rst2);
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>p[i].x>>p[i].y;
    }

    build(1, n, root);
    
    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int i,x,y;
            cin>>i>>x>>y;
            p[i] = {x,y};
            update(i, root);
            
        }else{
            int L,R,x,y;
            cin>>L>>R>>x>>y;
            cout<<query(L, R, x, y, root)<<'\n';

        }
    }

}