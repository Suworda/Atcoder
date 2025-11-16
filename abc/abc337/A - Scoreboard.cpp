#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;

    int X[n], Y[n];
    for(int i=0; i<n; i++){
        cin>>X[i]>>Y[i];
    }

    int t=accumulate(X,X+n,0);
    int a=accumulate(Y,Y+n,0);

    if(t>a){
        cout<<"Takahashi"<<'\n';
    }else if(t==a){
        cout<<"Draw"<<'\n';
    }else{
        cout<<"Aoki"<<'\n';
    }
}

