#include <bits/stdc++.h>
using namespace std;

map<int , vector<int>> edge;
set<int> vis;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    vis.insert(1);
    int ans = 0;
    while(q.size()){
        int v = q.front();
        q.pop();
        
        ans = max(ans,v);
        for(int next: edge[v]){
            if(!vis.count(next)){
                q.push(next);
                vis.insert(next);
            }
        }
    }

    cout<<ans<<'\n';

}