#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n , m;
    cin >> n >> m;
    vector<string> a;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        a.push_back(s);
    }

    for(int i=0; i<n; i++){
        bool b = 1;
        for(int j=0; j<m; j++){
            if(a[i][j] == 'o') b = 0;
        }

        if(b){
            cout << "Faucet " << i+1 << '\n';
        }
    }
    
    for(int i=0; i<m; i++){
        bool b = 1;
        for(int j=0; j<n; j++){
            if(a[j][i] == 'o') b = 0;
        }
        
        if(b){
            cout << "Drain " << i+1 << '\n';
        }
    }
    
}