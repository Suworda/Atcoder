#include <bits/stdc++.h>
using namespace std;

#define int long long

long long ans=0;

map<int,int> l,r;
int a[300005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int x;
    for(int i=0; i<n; i++){
        cin>>a[i];
        r[a[i]]++;
    }

    for(int i=0; i<n; i++){
        if(a[i]%5 == 0){
            ans += l[a[i]/5*3]*l[a[i]/5*7] + r[a[i]/5*3]*r[a[i]/5*7];
        }
        l[a[i]]++;
        r[a[i]]--;
    }
    cout<<ans<<'\n';

}