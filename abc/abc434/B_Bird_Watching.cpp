#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    vector<int> v[m+1];
    int a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        v[a].push_back(b);
    }

    for(int i=1; i<=m; i++){
        int tot=0;
        for(auto x: v[i]){
            tot+=x;
        }
        cout << fixed << setprecision(8) << 1.0*tot/v[i].size() << '\n';
    }

}