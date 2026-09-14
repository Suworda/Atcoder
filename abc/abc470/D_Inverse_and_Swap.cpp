#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 500005;
int n,q;
vector<int> a(N), b(N);

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) b[a[i]] = i;

    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int x,y;
            cin>>x>>y;
            swap(b[a[x]], b[a[y]]);
            swap(a[x],a[y]);
        }else{
            swap(a,b);
        }
    }

    for(int i=1; i<=n; i++) cout << a[i] << ' ';
    cout << '\n';
    
} 