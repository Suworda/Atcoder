#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,A,B,C;
int ans = 2e9;
vector<int> l;

void dfs2(int id, int a, int b, int c, int d){
    if(id >= n){
        if(a == 0 || b == 0 || c == 0) return; 
        ans = min(ans, abs(A-a) + abs(B-b) + abs(C-c) + d*10);
        return;
    }

    int x = l[id];
    dfs2(id+1, a+x, b, c, d+(a != 0));
    dfs2(id+1, a, b+x, c, d+(b != 0));
    dfs2(id+1, a, b, c+x, d+(c != 0));
    dfs2(id+1, a, b, c, d);
}

void dfs1(int id, vector<int> v, int x){
    sort(v.begin(), v.end(), greater<int>());
    int sz = v.size();
    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            for(int k=j+1; k<sz; k++){
                int rst = abs(A - v[i]) + abs(B - v[j]) + abs(C - v[k]) + x;
                ans = min(ans, rst);
            }
        }
    }
    
    if(n - id < 3) return;

    for(int i=0; i<sz; i++){
        for(int j=i+1; j<sz; j++){
            vector<int> v2;
            for(int k=0; k<sz; k++) if(k != i && k != j) v2.push_back(v[k]);
            v2.push_back(v[i] + v[j]);
            dfs1(id+1, v2, x+10);
        }
    }


}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>A>>B>>C;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        l.push_back(x);
    }
    // sort(l.begin(), l.end(), greater<int>());

    // dfs1(1,l,0);
    dfs2(0,0,0,0,0);

    cout<<ans<<'\n';

}