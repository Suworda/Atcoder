#include <bits/stdc++.h>
using namespace std;

map<char, int> dx{
    {'U',+1},
    {'D',-1},
    {'L', 0},
    {'R', 0}
};

map<char, int> dy{
    {'U',  0},
    {'D',  0},
    {'L', -1},
    {'R', +1},
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    string s;
    cin>>n>>s;
    set<pair<int,int>> st{{0,0}};

    int x=0, y=0;
    for(int i=0; i<n; i++){
        char c = s[i];
        x+=dx[c];
        y+=dy[c];

        if(st.count({x,y}) == 1){
            cout<<"Yes\n";
            return 0;
        }
        st.insert({x,y});
    }

    cout<<"No\n";


}
