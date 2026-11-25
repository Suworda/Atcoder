#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin >> a[i];

    vector<int> b;
    int last = a[1];
    int cnt = 1;
    for(int i=2; i<=n; i++){
        if(a[i] == last){
            cnt++;
        }
        else{
            b.push_back(cnt);
            cnt = 1;
        }
        last = a[i];
    }

    if(cnt) b.push_back(cnt);

    // for(int x: b) cout << x << ' ';

    vector<int> ans;
    for(int i=0; i<b[0]; i++) ans.push_back(b[0] - i);
    if(b.size() > 2){
        for(int i=1; i<(int)b.size()-1; i++){

            if(b[i] % 2 == 0){
                int m = (b[i])/2;
                for(int j=1; j<=m; j++) ans.push_back(j);
                for(int j=m; j>=1; j--) ans.push_back(j);
            }
            else{
                int m = (b[i]+1)/2;
                for(int j=1; j<m; j++) ans.push_back(j);
                ans.push_back(m);
                for(int j=m-1; j>=1; j--) ans.push_back(j);

            }
        }
    }
    if(b.size() > 1) for(int i=0; i<b.back(); i++) ans.push_back(i+1);

    for(int x: ans) cout << x << ' ' ;
    cout << '\n';
    
}