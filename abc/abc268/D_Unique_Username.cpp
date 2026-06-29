#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
string s[10];
set<string> st;
bitset<10> used;
string cur;

void check(){
    if(cur.size() < 3) return;
    if(!st.count(cur)){
        cout<<cur<<'\n';
        exit(0);
    }
}

void cur_rm(int i, int d){
    int sz = s[i].size() + d;
    while(sz--){
        cur.pop_back();
    }
}

void dfs(int id, int len){
    if(len > 16) return;

    if(id == n){
        check();
        return;
    }

    for(int i=0; i<n; i++){
        if(!used[i]){
            cur += '_';
            cur += s[i];
            used[i] = 1;
            dfs(id+1, len+s[i].size()+1);
            cur_rm(i,1);
            used[i] = 0;
        }
    }
    cur+='_';
    dfs(id, len+1);
    cur.pop_back();

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>s[i];
    
    for(int i=0; i<m; i++){
        string t;
        cin>>t;
        st.insert(t);
    }

    for(int i=0; i<n; i++){
        used[i] = 1;
        cur += s[i];
        dfs(1, s[i].size());
        cur_rm(i,0);
        used[i] = 0;
    }

    cout<<-1<<'\n';
}
