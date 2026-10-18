#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

char a[2][2];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    pair<int,int> A, D;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            char c;
            cin>>c;
            if(c == 'A') A = {i,j};
            if(c == 'D') D = {i,j};
        }
    }

    if((A.first == D.second) + (A.second == D.first) == 1) cout << "Yes\n";
    else cout << "No\n";
    
} 