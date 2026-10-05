#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int q;
string s,t;
int a[400005];
int b[400005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>q>>s>>t;
    int n = s.size();
    int m = t.size();
    
    for(int i=0; i<n-m+1; i++){
        a[i] = max((i-1 >= 0 ? a[i-1] : 0), (i-m >= 0 ? a[i-m] : 0));
        if(s.substr(i, m) == t){
            a[i]++;
        }
    }

    for(int i=n-m+1; i<n; i++) a[i] = a[i-1];
    
    for(int i=m-1; i<n; i++){
        b[i] = max((i-1 >= 0 ? b[i-1] : 0), (i-m >= 0 ? b[i-m] : 0));
        if(s.substr(i-m+1, m) == t){
            b[i]++;
        }
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        r--; l--;

        int x = b[r];
        int y = (l-1 >= 0 ? a[l-1] : 0);
        cout << (x - y > 0 ? "Yes" : "No") << '\n';
    }

}