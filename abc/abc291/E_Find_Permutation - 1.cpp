#include <bits/stdc++.h>
using namespace std;

int n,m;
const int MAXN = 200005;
set<int> child[MAXN];
int nxt[MAXN];
int ans[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        
        child[a].insert(b);
        
        if(child[a].size() > 1 || (nxt[b] && nxt[b] != a)){
            cout<<"No\n";
            return 0;
        }
        nxt[b] = a;
    }

    int cnt=0;
    int cur = n;
    for(int i=1; i<=n; i++){
        int x = i;
        if(child[x].empty()){
            while(x){
                if(ans[x]){
                    cout<<"No\n";
                    return 0;
                }
                ans[x] = cur--;
                x = nxt[x];
                cnt++;
            }
            break;
        }
    }

    if(cnt == n){
        cout<<"Yes\n";
        for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
        cout<<'\n';

    }else{
        cout<<"No\n";

    }

    

}