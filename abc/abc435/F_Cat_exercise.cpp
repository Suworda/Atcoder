#include <bits/stdc++.h>
using namespace std;

int n;
int p[200005];

struct Node{
    int l,r,val;
    int idx;
    Node *left, *right;  
};

Node *root = new Node;

void build(int l, int r, Node *rt){
    rt->l = l;
    rt->r = r;

    if(l == r){
        rt->val = p[l];
        rt->idx = l;
        return;
    }

    int m = (l+r)/2;
    rt->left = new Node();
    rt->right = new Node();
    build(l, m, rt->left);
    build(m+1, r, rt->right);
    if(rt->left->val > rt->right->val){
        rt->val = rt->left->val;
        rt->idx = rt->left->idx;

    }else{
        rt->val = rt->right->val;
        rt->idx = rt->right->idx;

    }
}

int query(int l, int r, Node *rt){
    if(rt->r < l || r < rt->l){
        return 0;
    }

    if(l <= rt->l && rt->r <= r){
        return rt->idx;
    }

    int rst1 = query(l, r, rt->left);
    int rst2 = query(l, r, rt->right);
    if(p[rst1] > p[rst2]){
        return rst1;
    }else{
        return rst2;
    }


}

long long dfs(int l, int r, int idx){

    //cout<<l<<' '<<r<<' '<<idx<<'\n';

    if(l == r) return 0;

    int idx_l = query(l, idx-1, root);
    int idx_r = query(idx+1, r, root);
    if(idx-1 < l){
        return dfs(idx+1, r, idx_r) + idx_r - idx;
    }else if(idx+1 > r){
        return dfs(l, idx-1, idx_l) + idx - idx_l;
    }
    return max(dfs(l, idx-1, idx_l) + idx - idx_l , dfs(idx+1, r, idx_r) + idx_r - idx);  
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    p[0] = -1;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }
    build(1, n, root);
    
    cout<<dfs(1, n, query(1, n, root));
}