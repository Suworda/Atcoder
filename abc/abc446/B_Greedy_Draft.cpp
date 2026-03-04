#include <bits/stdc++.h>
using namespace std;

int l[101];
int used[101]={};

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>l[i];
        int x[101]={};
        bool found = 0;
        for(int j=0; j<l[i]; j++){
            cin>>x[j];
        }
        for(int j=0; j<l[i]; j++){
            if(!used[x[j]]){
                cout<<x[j]<<'\n';
                used[x[j]]=1;
                found=1;
                break;
            }
        }

        if(!found) cout<<0<<'\n';

    }
}
