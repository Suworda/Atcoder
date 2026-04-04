#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int ty[400005];
int stk[400005]; 

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        int a,b;
        cin>>a>>b;
        ty[a] = ty[b] = i;
    }

    int top = 0;
    for(int i=1; i<=2*n; i++){
        if(top && ty[i] == ty[stk[top]]) top--;
        else stk[++top] = i;
    }

    cout << (top != 0 ? "Yes\n" : "No\n");

}