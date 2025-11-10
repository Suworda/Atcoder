#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();

    int cnt[1024]={};
    cnt[0]=1;
    int now=0;
    long long ans=0;
    for(int i=1; i<=n; i++){
        now ^= (1 << s[i-1]-'0');
        ans+=cnt[now]++;
    }

//    int pxor[n+1]={};
//    int sum_0[n+1]={};
//    for(int i=1; i<=n; i++){
//        pxor[i] = pxor[i-1]^(s[i-1]-'0');
//        sum_0[i] = sum_0[i-1] + (s[i-1]=='0');
//    }
//
//    long long ans=0;
//
//    for(int l=0; l<n; l++){
//        for(int r=l+2; r<=n; r++){
//            ans+=((pxor[r] == pxor[l]) && (sum_0[r] - sum_0[l]) % 2 ==0 );
//        }
//    }
//
    cout<<ans<<'\n';
}
