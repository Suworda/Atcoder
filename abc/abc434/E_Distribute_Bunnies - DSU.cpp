#include <bits/stdc++.h>
using namespace std;

map<int,int> parent;
map<int,int> cnt_v;
map<int,int> cnt_e;


int find_parent(int x){
    if(!parent.count(x)){
        parent[x] = x;
        cnt_v[x]=1;
    }
    if(x == parent[x]) return x;
    return parent[x] = find_parent(parent[x]);
}

void merge(int a, int b){
    int pa = find_parent(a);
    int pb = find_parent(b);
    
    if(pa != pb){
        parent[pa] = pb;
        cnt_v[pb] += cnt_v[pa];
        cnt_e[pb] += cnt_e[pa]+1;
    }else{
        cnt_e[pb]++;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int x,r;
    for(int i=0; i<n; i++){
        cin>>x>>r;
        merge(x+r,x-r);
    }

    int ans=0;
    for(auto v: parent){
        //cout<<v.first<<":";
        //cout<<cnt_v[v.first]<<' '<<cnt_e[v.first]<<'\n';
        if(parent[v.first] == v.first) ans += min(cnt_v[v.first], cnt_e[v.first]);
    }

    cout<<ans<<'\n';

}