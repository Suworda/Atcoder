#include <iostream>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,A,B;
    string s;
    cin>>n>>A>>B>>s;

    int cnt_a=0, cnt_b=0, l=n, r=n-1;
    for(int i=0; i<n; i++){
        cnt_a+=(s[i]=='a');
        if(cnt_a>=A){
            l=i;
            break;
        }
    }

    for(int i=0; i<n; i++){
        cnt_b+=(s[i]=='b');
        if(cnt_b==B){
            r=i-1;
            break;
        }
    }

    long long ans=0;
    for(int i=0; i<n; i++){
        //cout<<l<<' '<<r<<'\n';
        ans+=max(r-l+1 , 0);

        if(s[i]=='a'){
            do{
                if(l<n) l++;
            }while(l<n && s[l]!='a');
        }
        else{//s[i]=='b'
            do{
                if(r+1<n) r++;
            }while(r+1<n && s[r+1]!='b');
        }
    }

    cout<<ans<<'\n';

}
