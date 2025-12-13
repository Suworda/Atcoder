#include <bits/stdc++.h>
using namespace std;

unordered_map<int , list<int>::iterator> p;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    list<int> lst;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        p[x] = lst.insert(lst.end(),x);
    }
    
    int q;
    cin>>q;
    while(q--){
        int ty;
        cin>>ty;
        if(ty==1){
            int x,y;
            cin>>x>>y;
            p[y] = lst.insert(next(p[x]),y);

        }else{
            int y;
            cin>>y;
            lst.erase(p[y]);

        }
    }
    
    for(int &v: lst){
        cout<<v<<' ';
    }
    cout<<'\n';
    
}