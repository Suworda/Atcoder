#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 300005;
int n,m;
set<pair<int,int>> st;
set<int> st_r[N];
set<int> st_c[N];
int mp_r[N], mp_c[N];

void rm(int r, int c){
    if(st_r[r].size()){
        for(int x: st_r[r]){
            if(st.count({r,x})) st.erase({r,x});
        }
        st_r[r].clear();
    }

    if(st_c[c].size()){
        for(int x: st_c[c]){
            if(st.count({x,c})) st.erase({x,c});
        }
        st_c[c].clear();
    }
}

void place(int r, int c){
    st.insert({r,c});
    st_r[r].insert(c);
    st_c[c].insert(r);
}

void op(int r, int c){
    rm(r,c);
    place(r,c);
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int r, c;
        cin>>r>>c;
        op(r,c);
    }

    cout<<st.size()<<'\n';
    
}