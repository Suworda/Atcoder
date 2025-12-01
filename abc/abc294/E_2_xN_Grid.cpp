#include <bits/stdc++.h>
using namespace std;

struct Seg{
    long long len,val;
};


int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    long long L,n1,n2;
    cin>>L>>n1>>n2;
    vector<Seg> v1,v2;

    long long l, val;
    for(int i=0; i<n1; i++){
        cin>>val>>l;
        v1.push_back({l,val});
    }

    for(int i=0; i<n2; i++){
        cin>>val>>l;
        v2.push_back({l,val});
    }

    long long ans=0;
    int it1=0, it2=0;
    while(it1 < n1 || it2 < n2){
        //cout<<it1<<' '<<it2<<' '<<ans<<'\n';
        if(v1[it1].len < v2[it2].len){
            ans += (v1[it1].val == v2[it2].val) * v1[it1].len;
            v2[it2].len -= v1[it1].len;
            it1++;

        }else if(v1[it1].len > v2[it2].len){
            ans += (v1[it1].val == v2[it2].val) * v2[it2].len;
            v1[it1].len -= v2[it2].len;
            it2++;

        }else{
            ans += (v1[it1].val == v2[it2].val) * v1[it1].len;
            it1++; it2++;

        }
    }

    cout<<ans<<'\n';

}