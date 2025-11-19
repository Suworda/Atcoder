#include <bits/stdc++.h>
using namespace std;

long long x;
int ty,k;
multiset<long long> mst;

void sol(){
    cin>>ty;
        if(ty==1){
            cin>>x;
            mst.insert(x);

        }else if(ty==2){
            cin>>x>>k;
            auto it = mst.upper_bound(x);
            while(k--){
                if(it == mst.begin()){
                    cout<<-1<<'\n';
                    return;
                }
                it--;
            }

            cout<<*it<<'\n';

        }else{
            cin>>x>>k; k--;
            auto it = mst.lower_bound(x);
            while(k--){
                if(it == mst.end()){
                    cout<<-1<<'\n';
                    return;
                }
                it++;
            }

            if(it == mst.end()){
                cout<<-1<<'\n';
                return;
            }

            cout<<*it<<'\n';
        }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin>>q;
    while(q--) sol();
}


