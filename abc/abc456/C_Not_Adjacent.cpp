#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 998244353;

int n;
string s;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>s;
    n = s.size();
    ll ans = 0;
    int len = 0;
    for(int i=0; i<n; i++){
        if(i == 0 || s[i] != s[i-1]) len++;
        else{
            ans += (len)*(len+1)/2%M;
            len = 1;
        }
    }

    cout<<(ans + (len)*(len+1)/2%M)%M<<'\n';

}
