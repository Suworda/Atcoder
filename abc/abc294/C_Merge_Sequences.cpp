#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    int a[n+1],b[m+1];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    a[n]=INF; b[m]=INF;

    vector<int> ans_a , ans_b;

    int x=0, y=0;
    int cur=1;
    while(x<n || y<m){
        if(a[x] < b[y]){
            ans_a.push_back(cur++);
            x++;
        }
        else{
            ans_b.push_back(cur++);
            y++;
        }
    }

    for(int &v: ans_a) cout<<v<<' ';
    cout<<'\n';
    for(int &v: ans_b) cout<<v<<' ';
    cout<<'\n';
    

}