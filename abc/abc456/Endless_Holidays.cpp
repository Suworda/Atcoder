#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int ty[100005][11];
vector<pair<int,int>> nxt[100005][11];
string s[100005];
int n,m;
bool ans = 0;

void init(){
    ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<11; j++){
            nxt[i][j].clear();
            ty[i][j] = 0;
        }
    }
}

void dfs(int x1, int y1){

    ty[x1][y1] = 1;
    for(auto &[x2,y2]: nxt[x1][y1]){
        if(ty[x2][y2] == 1){
            ans = 1;
        }
        if(ty[x2][y2] == 0) dfs(x2,y2);
    }
    ty[x1][y1] = 2;
}

void sol(){
    cin>>n>>m;
    init();
    vector<pair<int,int>> v(m);
    for(auto &[a,b]: v){
        cin>>a>>b;
        a--;
        b--;
    }

    int w;
    cin>>w;
    for(int i=0; i<n; i++){
        cin>>s[i];

        for(int j=0; j<w; j++){
            if(s[i][j] == 'o' && s[i][(j+1)%w] == 'o'){
                nxt[i][j].push_back({i,(j+1)%w});
            }
        }

        
    }
    for(auto &[a,b]: v){
        for(int j=0; j<w; j++){
            if(s[a][j] == 'o' && s[b][(j+1)%w] == 'o'){
                nxt[a][j].push_back({b,(j+1)%w});
                // cout<<"ty1: "<<i<<' '<<j<<' '<<b<<' '<<(j+1)%w<<'\n';
            }

            if(s[b][j] == 'o' && s[a][(j+1)%w] == 'o'){
                nxt[b][j].push_back({a,(j+1)%w});
                // cout<<"ty2: "<<i<<' '<<j<<' '<<a<<' '<<(j+1)%w<<'\n';
            }
        }
    }
    // cout<<'\n';

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<11; j++){
    //         for(auto &[a,b]: nxt[i][j]){
    //             cout<<i<<' '<<j<<" : "<<a<<' '<<b<<'\n';
    //         }
    //     }
    // }
    // cout<<'\n';
    // return;

    for(int i=0; i<n; i++){
        for(int j=0; j<w; j++){
            if(ty[i][j] == 0) dfs(i,j);
        }
    }
    
    cout << (ans ? "Yes" : "No") << '\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();
}
