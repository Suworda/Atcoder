#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<long long> v,cnt,ex;
    int n,c;
    long long m;
    cin>>n>>m>>c;

    long long x;
    for(int i=0; i<n; i++){
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    v.push_back(-1);
    ex.push_back(0);

    int cur=1;
    for(int i=1; i<=n; i++){
        if(v[i]==v[i-1]){
            cur++;
        }else{
            ex.push_back(v[i-1]);
            cnt.push_back(cur);
            cur=1;
        }
    }
    int cnt_sz=cnt.size();
    int sum[cnt_sz*2+1]={};
    for(int i=1; i<=cnt_sz*2; i++){
        //cout<<cnt[i-1]<<'\n';
        sum[i]=sum[i-1]+cnt[(i-1)%cnt_sz];
    }

    int ex_sz=ex.size();
    for(int i=1; i<ex_sz; i++){
        ex.push_back(ex[i]);
    }


    int l=0, r=1;
    long long ans=0;
    while(l<cnt_sz){
        if(sum[r]-sum[l]>=c){
            ans+=sum[r]-sum[l]*(ex[r]-ex[l]);
            l++;
        }else{
            r++;
        }
    }

    cout<<ans<<'\n';

}
