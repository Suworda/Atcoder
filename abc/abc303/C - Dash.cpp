#include <bits/stdc++.h>
using namespace std;

map<char,int> dx{
    {'R',+1},
    {'L',-1},
    {'U',0},
    {'D',0},
};

map<char,int> dy{
    {'R',0},
    {'L',0},
    {'U',+1},
    {'D',-1},
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    set<pair<int,int>> st;
    int n,m,h,k;
    cin>>n>>m>>h>>k;
    string s;
    cin>>s;

    int x,y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        st.insert({x,y});
    }

    x=0, y=0;
    int step=0;

    for(int i=0; i<s.size() && h ; i++){
        step++; h--;
        x += dx[s[i]];
        y += dy[s[i]];
        //cout<<x<<' '<<y<<'\n';
        if(st.count({x,y}) == 1){
            if(h < k){
                h=k;
                st.erase({x,y});
            }
        }
    }

    cout<<(step == n ? "Yes\n" : "No\n");



}

/*
5 2 3 1
RUDL
-1 -1
1 0
*/
