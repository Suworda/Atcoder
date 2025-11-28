#include <bits/stdc++.h>
using namespace std;

string s;

char fix(long long c){
    return char((c-'A')%3 + 'A');
}

char f(long long t, long long k){
    if(k==1) return fix(s[0] + t%3);
    if(t==0) return s[k-1];

    if(k%2 == 1) return fix(f(t-1, (k+1)/2) +1);
    else return fix(f(t-1, (k+1)/2) +2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>s;

    int q;
    cin>>q;
    while(q--){
        long long t,k;
        cin>>t>>k;
        cout<<f(t,k)<<'\n';
    }
}
