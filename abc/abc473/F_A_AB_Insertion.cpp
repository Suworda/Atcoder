#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 500005;
int n;
int a[N];

// struct ST{

struct Node{
    int l, r, mi, tag;
    Node *left, *right;
};

Node *root = new Node;

void pull(Node *rt){
    rt->mi = min(rt->left->mi, rt->right->mi);
}

void build(int l, int r, Node *rt){
    rt->tag = 0;
    rt -> l = l;
    rt -> r = r;

    if(l == r){
        rt->mi = a[l];
        return;
    }

    rt -> left = new Node;
    rt -> right = new Node;
    int m = (l+r)/2;
    build(l, m, rt->left);
    build(m+1, r, rt->right);
    
    pull(rt);
    // cout << l << ' ' << r << ' ' << rt->mi << ' ' << rt->tag << '\n';
}

void push_down(Node *rt){
    if(rt->tag){
        rt->left->mi += rt->tag;
        rt->left->tag += rt->tag;
        rt->right->mi += rt->tag;
        rt->right->tag += rt->tag;

        rt->tag = 0;
    }
}

void update(int ql, int qr, int v, Node *rt){
    if(rt->r < ql || qr < rt->l) return;

    if(ql <= rt->l && rt->r <= qr){
        rt->mi += v;
        rt->tag += v;
        return;
    }
    
    push_down(rt);
    update(ql, qr, v, rt->left);
    update(ql, qr, v, rt->right);
    pull(rt);
}

int query(int ql, int qr, Node*rt){
    if(rt->r < ql || qr < rt->l) return 2e9;
    // cerr << rt->l << ' ' << rt->r << ' ' << rt -> mi << '\n';
    // cerr << rt->l << ' ' << rt->r << '\n';

    if(ql <= rt->l && rt->r <= qr){
        return rt->mi;
    }

    push_down(rt);
    int rst1 = query(ql, qr, rt->left);
    int rst2 = query(ql, qr, rt->right);
    return min(rst1, rst2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    int q;
    cin>>n>>s>>q;
    s = ' ' + s;

    a[0] = 0;
    for(int i=1; i<=n; i++){
        a[i] = a[i-1] + (s[i] == 'A' ? 1 : -1);
    }

    build(0,n,root);

    query(1,n,root);

    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int id;
            char c;
            cin>>id>>c;
            if(c == s[id]) continue;
            s[id] = c;
            if(c == 'A'){
                update(id, n, 2, root);
            }
            else{
                update(id, n, -2, root);
            }
        }
        else{ //2
            int l,r;
            cin>>l>>r;
            // cout << query(l,r,root) << ' ' << query(l-1,l-1,root) << '\n';
            if(query(l,r,root) < query(l-1,l-1,root)){
                cout << "No\n";
            }else{
                cout << "Yes\n";
            }
        }
    }

    // cout << "ok\n";
    
} 