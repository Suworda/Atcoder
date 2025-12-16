#include <bits/stdc++.h>
using namespace std;

vector<int> nxt[200005];
int indeg[200005];
vector<int> ans;

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

    priority_queue<int , vector<int> , greater<> > pq;
    for(int i=1; i<=n; i++){
        if(indeg[i] == 0){
            pq.push(i);
        }
    }

    while(pq.size()){
        int v = pq.top();
        pq.pop();
        ans.push_back(v);

        for(int u: nxt[v]){
            if(--indeg[u] == 0){
                pq.push(u);
            }
        }
    }

    if(ans.size() == n){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<(i==n-1 ? '\n' : ' ');
        }
    }else{
        cout<<-1<<'\n';
    }

}