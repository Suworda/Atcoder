#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int h[200005];
int ans[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>h[i];

    int stk[n+5]={};
    int top = 0;
    for(int i=n; i>=1; i--){
        ans[i] = top;
        while(top && h[i] > h[stk[top]]){
            top--;
        }
        stk[++top] = i;
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
    cout<<'\n';

}