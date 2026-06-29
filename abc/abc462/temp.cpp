#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    string a = "0.3";
    string b = "0.20";
    if(a > b) cout << "a > b";
    else if(a < b) cout << "a < b";
    else cout << "a = b";
    
}


/*
vector<tuple<int,int,int>> p;
bool vis[100][100];

void dfs(int x, int y, int id, int v){
    // cout<<x<<' '<<y<<'\n';
    if(v > 103){
        return;
    }
    if(x == X && y == Y){
        for(auto [r,c,val]: p) cout<<r<<' '<<c<<' '<<val<<'\n';
        cout<<"found\n";
        exit(0);
    }

    if(id%2 == 1){
        p.push_back({x+1,y,v+a});
        dfs(x+1, y, id+1, v+a);
        p.pop_back();
        p.push_back({x-1,y,v+a});
        dfs(x-1, y, id+1, v+a);
        p.pop_back();
        p.push_back({x,y+1,v+b});
        dfs(x, y+1, id+1, v+b);
        p.pop_back();
        p.push_back({x,y-1,v+b});
        dfs(x, y-1, id+1, v+b);
        p.pop_back();

    }else{
        p.push_back({x+1,y,v+b});
        dfs(x+1, y, id+1, v+b);
        p.pop_back();
        p.push_back({x-1,y,v+b});
        dfs(x-1, y, id+1, v+b);
        p.pop_back();
        p.push_back({x,y+1,v+a});
        dfs(x, y+1, id+1, v+a);
        p.pop_back();
        p.push_back({x,y-1,v+a});
        dfs(x, y-1, id+1, v+a);
        p.pop_back();
        
    }

}
*/