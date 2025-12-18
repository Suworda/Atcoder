#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> nxt[MAXN];
int indeg[MAXN];
int ans[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        nxt[a].push_back(b);
        indeg[b]++;
    }

    int cur = 1;
    int cnt = 0;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while(q.size()){
        if(q.size() != 1){
            cout<<"No\n";
            return 0;
        }

        int v = q.front();
        q.pop();
        ans[v] = cur++;
        cnt++;

        for(int u: nxt[v]){
            indeg[u]--;
            if(indeg[u] == 0){
                q.push(u);
            }
        }
    }

    if(cnt == n){
        cout<<"Yes\n";
        for(int i=1; i<=n; i++) cout<<ans[i]<<(i==n ? '\n' : ' ');
    }else{
        cout<<"No\n";
    }



}