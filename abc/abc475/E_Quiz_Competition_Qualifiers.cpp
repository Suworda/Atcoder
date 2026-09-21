#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m,k;
multiset<string> mst;
string s[30005], t;

struct Node{
    int cnt=0;
    Node *Y=0, *N=0;
};
Node *root = new Node;

void add(string &x, int id, Node *rt){
    rt->cnt++;
    if(id == k) return;

    if(x[id] == '1'){
        if(!rt->Y) rt->Y = new Node;
        add(x, id+1, rt->Y);
    }
    else{
        if(!rt->N) rt->N = new Node;
        add(x, id+1, rt->N);
    }
}

void rm(string &x, int id, Node *rt){
    rt->cnt--;
    if(id == k) return;

    if(x[id] == '1'){
        if(!rt->Y) rt->Y = new Node;
        rm(x, id+1, rt->Y);
    }
    else{
        if(!rt->N) rt->N = new Node;
        rm(x, id+1, rt->N);
    }
}

int query(string &x, int id, Node *rt){
    if(id == k) return rt->cnt;

    if(x[id] == '1'){
        return query(x, id+1, rt->Y);
    }
    else{
        if(!rt->Y) return query(x, id+1, rt->N);
        return rt->Y->cnt + query(x, id+1, rt->N); 
    }
}

void print_cur(Node *rt, string sp){
    if(!rt) return;
    cerr << sp << rt->cnt << '\n';
    print_cur(rt->Y, sp+' ');
    print_cur(rt->N, sp+' ');
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>k;
    cin>>t;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        s[i] = "";
        for(int j=0; j<k; j++){
            s[i] += (x[j] == t[j] ? '1' : '0');
        }
        add(s[i], 0, root);
    }

    int q;
    cin>>q;
    while(q--){
        int i,j;
        cin>>i>>j;
        i--; j--;
        rm(s[i], 0, root);
        s[i][j] = (s[i][j] == '1' ? '0' : '1');
        add(s[i], 0, root);
        // cout << query(s[i], 0, root) << '\n';
        // print_cur(root, "");
        // cerr<<'\n';

        bool ans = 0;
        for(int _=0; _<k; _++) if(s[i][_] == '1') ans = 1;
        if(!ans){
            cout << "No\n";
            continue;
        }

        cout << (query(s[i], 0, root) <= m ? "Yes" : "No") << '\n';
    }

} 