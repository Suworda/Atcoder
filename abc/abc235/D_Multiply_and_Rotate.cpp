#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int a,N;
bitset<1000005> vis;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>a>>N;
    queue<pair<int,int>> q;
    q.push({1,0});
    vis[1] = 1;

    while(q.size()){
        auto [x,cnt] = q.front();
        q.pop();
        // cout<<x<<'\n';

        if(x == N){
            cout<<cnt<<'\n';
            return 0;
        }

        string s = to_string(x);
        rotate(s.begin(), s.begin()+s.size()-1, s.end());
        int x1 = x*a;
        int x2 = stoi(s);
        if(x1 <= 1e6 && !vis[x1]){
            vis[x1] = 1;
            q.push({x1,cnt+1});
        }
        if(x >= 10 && x%10 != 0 && x2 <= 1e6 && !vis[x2]){
            vis[x2] = 1;
            q.push({x2,cnt+1});
        }
    }

    cout<<-1<<'\n';

}