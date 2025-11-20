#include <bits/stdc++.h>
using namespace std;

int n,k;
string s;
long long ans=0;
bool ok;

void check(int l, int r){
    int len=0;
    if(l==r){
        len++;
        l--; r++;
    }
    while(l>=0 && r<n){
        if(s[l]==s[r]) len+=2;
        else break;
        l--;
        r++;
        if(len==k) ok=false;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    cin>>s;
    sort(s.begin(), s.end());

    //cout<<s<<'\n';

    do{
        ok=true;
        for(int i=0; i<n; i++){
            check(i,i+1);
            check(i,i);
        }
        ans+=ok;
    }while(next_permutation(s.begin(), s.end()));

    cout<<ans<<'\n';
}


