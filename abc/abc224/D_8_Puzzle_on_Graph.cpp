#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int m;
vector<char> nxt[128];
unordered_set<string> vis;
string valid{"12345678"};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>m;
    while(m--){
        char u,v;
        cin>>u>>v;
        nxt[u].push_back(v);
        nxt[v].push_back(u);

    }

    string p;
    for(int i=0; i<8; i++){
        char x;
        cin>>x;
        p += x;
    }
    queue<pair<string,int>> q;
    q.push({p,0});
    vis.insert(p);

    while(q.size()){
        auto [cur,cnt] = q.front();
        q.pop();

        // cout<<cur<<'\n';

        if(cur == valid){
            cout<<cnt<<'\n';
            return 0;
        }

        int tg = 477;
        for(int i=0; i<8; i++) tg -= cur[i];

        for(int i=0; i<8; i++){
            for(char v: nxt[cur[i]]){
                if(v == tg){
                    char tmp;
                    tmp = cur[i];
                    cur[i] = v;
                    if(vis.count(cur) != 1){
                        vis.insert(cur);
                        q.push({cur,cnt+1});
                    }
                    cur[i] = tmp;
                }
            }
        }
    }

    cout<<-1<<'\n';
}
