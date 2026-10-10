#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    cin>>n>>x;
    vector<bool> a(20005), b(20005);

    a[0] = 1;

    for(int i=1; i<=n; i++){
        int c, d;
        cin>>c>>d;
        for(int j=0; j<=x; j++){
            if(a[j]){
                b[j+c] = 1;
                b[j+d] = 1;
            }
        }

        for(int j=0; j<=x; j++) a[j] = 0;
        swap(a, b);
    }


    if(a[x]) cout << "Yes\n";
    else cout << "No\n";


}