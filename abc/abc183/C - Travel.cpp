#include <bits/stdc++.h>
using namespace std;

vector<int> p;
int n,k;
int t[9][9];
long long ans=0;

void check(){
    int rst=0;
    int cur=1;
    for(int i=1; i<=n; i++){
        //cout<<cur<<' ';
        if(t[cur][p[i]] == 0) return;
        rst+=t[cur][p[i]];
        cur=p[i];
    }
    //cout<<'\n';

    ans += (rst == k);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    p.push_back(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>t[i][j];
        }
    }

    for(int i=0; i<n; i++) p.push_back(n-i);

    do{

        check();
    }while(prev_permutation(p.begin()+1, p.end()-1));

    cout<<ans<<'\n';
}


