#include <bits/stdc++.h>
using namespace std;

int n,m,l,x;
int a[101],b[101],c[101];
vector<int> v;

void sol(){
    cin>>x;
    if(binary_search(v.begin(), v.end(), x)){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    cin>>m;
    for(int i=0; i<m; i++){
        cin>>b[i];
    }

    cin>>l;
    for(int i=0; i<l; i++){
        cin>>c[i];
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<l; k++){
                v.push_back(a[i]+b[j]+c[k]);
            }
        }
    }
    sort(v.begin(), v.end());

    int q;
    cin>>q;
    while(q--) sol();


}

