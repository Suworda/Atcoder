#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0; i<s.size()-n; i++){
        s.insert(s.begin(),'o');
    }

    cout<<s<<'\n';
}