#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    char c;
    cin>>c;
    int x = c-'A';
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s[x] == 'o'){
            cout<<"Yes\n";
            return 0;
        }
    }

    cout<<"No\n";
}