#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    list<int> a{0};
    auto it = a.begin();
    for(int i=0; i<n; i++){
        if(s[i] == 'L'){
            it = a.insert(it, i+1);
        }else{
            it = a.insert(next(it), i+1);
        }
    }

    for(int &x: a) cout<<x<<' ';
    cout<<'\n';

}