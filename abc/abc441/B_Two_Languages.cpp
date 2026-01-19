#include <bits/stdc++.h>
using namespace std;

int n,m;
string s,t;

void sol(){
    int ans = -1;
    string x;
    cin>>x;
    bool ty1=1, ty2=1;
    for(int i=0; i<x.size(); i++){
        bool ok=false;
        for(int j=0; j<n; j++){
            if(x[i] == s[j]){
                ok = true;
            }
        }
        if(!ok){
            ty1 = 0;
        }
    }

    for(int i=0; i<x.size(); i++){
        bool ok = false;
        for(int j=0; j<m; j++){
            if(x[i] == t[j]){
                ok=true;
            }
        }
        if(!ok){
            ty2 = 0;
        }
    }

    if(ty1 != ty2){
        if(ty1) cout<<"Takahashi\n";
        else cout<<"Aoki\n";
    }else{
        cout<<"Unknown\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    cin>>s>>t;

    int q;
    cin>>q;
    while(q--) sol();
        
}
