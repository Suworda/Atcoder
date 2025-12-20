#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005 , MAXM = 200005;
int n,m;
pair<int,int> nxt[MAXN];
bitset<MAXN> apr;
int pre;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    queue<int> q;
    for(int i=1; i<=m; i++){
        int k,x;
        cin>>k;
        pre = 0;
        while(k--){
            cin>>x;

            
            if(!pre){
                if(apr[x]){
                    q.push(x);
                }
                apr[x] = true;
            }else{
                if(!nxt[pre].first) nxt[pre].first = x;
                else nxt[pre].second = x;
            }
            pre = x;
        }
    }

    int cnt=0;
    while(q.size()){
        cnt++;
        int x = q.front();
        q.pop();

        int a = nxt[x].first;
        int b = nxt[x].second;

        if(apr[a]) q.push(a);
        else if(a) apr[a] = true;

        if(apr[b]) q.push(b);
        else if(b) apr[b] = true;
        
    }
        
    bool ans = (cnt == n);
    //cout<<cnt<<'\n';
    cout<<(ans ? "Yes" : "No")<<'\n';




}