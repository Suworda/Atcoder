#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int,vector<int>> p;
    int n,q;
    cin>>n>>q;
    int a;
    for(int i=1; i<=n; i++){
        cin>>a;
        p[a].push_back(i);
    }

    int x,k;
    while(q--){
        cin>>x>>k;
        if(k > p[x].size()){
            cout<<-1<<'\n';
        }else{
            cout<<p[x][k-1]<<'\n';;
        }
    }

}
