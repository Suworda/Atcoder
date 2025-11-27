#include <bits/stdc++.h>
using namespace std;

set<int> st[200005];
multiset<int> mst[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();


    int n,q;
    cin>>n>>q;


    while(q--){
        int ty;
        cin>>ty;
        if(ty==1){
            int i,j;
            cin>>i>>j;
            mst[j].insert(i);
            st[i].insert(j);

        }else if(ty==2){
            int i;
            cin>>i;
            for(int x: mst[i]) cout<<x<<' ';
            cout<<'\n';

        }else if(ty==3){
            int i;
            cin>>i;
            for(int x: st[i]) cout<<x<<' ';
            cout<<'\n';

        }
    }



}
