#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Area{
    int y, l, r, d, id;

    bool operator< (const Area &b) const{
        return y < b.y;
    }
};

struct Node{
    int l, r, val=0, tag=0;
    Node *left=0, *right=0;
};
Node *root = new Node;

void pull(Node *rt){
    rt->val = rt->left->val + rt->right->val;
}

void push(Node *rt){
    auto L = rt->left;
    auto R = rt->right;

    L->tag += rt->tag;
    R->tag += rt->tag;
    
    L->val += rt->tag * (L->r - L->l + 1);
    R->val += rt->tag * (R->r - R->l + 1);

    rt->tag = 0;
}

void build(int l, int r, Node*rt){
    rt->l = l;
    rt->r = r;

    if(l == r){
        return;
    }

    rt->left = new Node;
    rt->right = new Node;

    int m = (l+r)/2;
    build(l, m, rt->left);
    build(m+1, r, rt->right);
    pull(rt);
}

void upd(int ql, int qr, int v, Node *rt){
    if(qr < rt->l || rt->r < ql) return;
    
    if(ql <= rt->l && rt->r <= qr){
        rt->val += v * (rt->r - rt->l + 1);
        rt->tag += v;
        return;
    }

    push(rt);
    upd(ql, qr, v, rt->left);
    upd(ql, qr, v, rt->right);
    pull(rt);

}

ll query(int ql, int qr, Node *rt){
    if(qr < rt->l || rt->r < ql) return 0;
    
    if(ql <= rt->l && rt->r <= qr){
        return rt->val;
    }

    push(rt);
    return query(ql, qr, rt->left) + query(ql, qr, rt->right);
}



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n,m,Q;
    cin>>n>>m>>Q;

    build(1,m,root);

    vector<pair<int,int>> v(1);
    for(int i=1; i<=n; i++){
        int l, r;
        cin>>l>>r;
        v.push_back({l,r});
    }

    vector<Area> q;
    for(int i=1; i<=Q; i++){
        int top,bottom,l,r;
        cin>>top>>bottom>>l>>r;
        q.push_back({bottom,l,r,1,i});
        q.push_back({top-1,l,r,-1,i});
    }
    
    sort(q.begin(), q.end());
    vector<int> ans(Q+1);

    int cur_q = 0;

    for(int i=0; i<=n; i++){
        upd(v[i].first, v[i].second, 1, root);
        while(cur_q < q.size() && q[cur_q].y == i){
            auto [y, l, r, d, id] = q[cur_q];
            int rst = query(l, r, root);
            ans[id] += d*rst;
            cur_q++;
        }
    }

    // for(int i=1; i<=m; i++){
    //     cout << query(i,i,root) << ' ';
    // }
    // cout << '\n';

    // cout << query(1,m,root) << '\n';

    for(int i=1; i<=Q; i++) cout << ans[i] << '\n';
    
    
} 