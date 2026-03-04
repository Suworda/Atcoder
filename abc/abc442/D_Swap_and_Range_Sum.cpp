#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,q;
int a[200005];
ll sum[200005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];
    }

    while(q--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int x;
            cin>>x;
            sum[x] += a[x+1] - a[x];
            swap(a[x], a[x+1]);

        }else{
            int l, r;
            cin>>l>>r;
            cout<<sum[r] - sum[l-1]<<'\n';;
        }
    }

}
