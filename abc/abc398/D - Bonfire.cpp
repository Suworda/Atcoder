#include <bits/stdc++.h>
using namespace std;

int n,R,C;
int dr=0, dc=0;
set<pair<int,int>> st{{0,0}};

void op(char c){

    if(c=='N'){
        dr--;

    }else if(c=='S'){
        dr++;

    }else if(c=='W'){
        dc--;

    }else if(c=='E'){
        dc++;

    }

    st.insert({-dr, -dc});
//    cout<<dr<<' '<<dc<<'\n';
    if(st.count({R-dr,C-dc})) cout<<1;
    else cout<<0;

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>R>>C;
    string s;
    cin>>s;
    for(int i=0; i<n; i++){
        op(s[i]);
    }

    cout<<'\n';
}


