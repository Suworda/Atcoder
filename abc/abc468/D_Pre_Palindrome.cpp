#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

string s;
int n;
int ans;

void check(int l, int r){
    int wrong = 0;
    while(l >= 0 && r < n){
        wrong += (s[l] != s[r]);
        if(wrong == 2) break;
        ans++;
        // cout << l << ' ' << r << '\n';
        l--;
        r++;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>s;
    n = s.size();
    for(int i=0; i<n; i++){
        check(i,i);
        check(i,i+1);
    }

    cout << ans << '\n';
} 