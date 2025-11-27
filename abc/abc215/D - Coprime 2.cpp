#include <bits/stdc++.h>
using namespace std;
const int MAX_V=100000;

bitset<100001> banned;
bitset<100001> ok;
vector<int> prime;
int spf[MAX_V+5];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> ans;
    ok.set();

    int n,m;
    cin>>n>>m;
    for(int i=2; i<=MAX_V; i++){
        if(spf[i]==0){
            prime.push_back(i);
            spf[i]=i;
        }

        for(int &p: prime){
            if(p > spf[i] || 1LL*i*p > MAX_V) break;
            spf[i*p]=p;
        }
    }

    //for(int i=2; i<=m; i++) cout<<i<<':'<<spf[i]<<'\n';
    //cout<<m<<'\n';

    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        while(x>=2){
            if(!banned[spf[x]]){
                for(int i=spf[x]; i<=m; i+=spf[x]){
                    ok[i]=false;
                }
                banned[spf[x]]=true;
            }
            //cout<<x<<'\n';
            x/=spf[x];
        }
    }

    for(int i=1; i<=m; i++){
        if(ok[i]) ans.push_back(i);
    }

    cout<<ans.size()<<'\n';
    for(int &x: ans) cout<<x<<'\n';

}


