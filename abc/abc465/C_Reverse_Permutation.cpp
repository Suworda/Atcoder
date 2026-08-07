#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
string s;
int a[2000005];
int l = 1000000;
int r = 1000000;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>s;
    int cur = 0;
    for(int i=0; i<n; i++) cur += s[i] == 'o';
    int ty;
    a[l] = 1;

    for(int i=0; i<n-1; i++){
        if(s[i] == 'o') cur--;

        // cout<<cur<<'\n';

        ty = (cur+1)%2;

        if(ty == 0){
            l--;
            a[l] = i+2;
        }else{
            r++;
            a[r] = i+2;
        }
    }

    bool flag = 0;
    for(int i=l; i<=r; i++){
        // if(a[i] == 1 && flag) continue;
        cout<<a[i]<<' ';
        // if(a[i] == 1) flag = 1;
    }
    cout<<'\n';

    
}