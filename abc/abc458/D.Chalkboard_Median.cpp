#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int x;
priority_queue<int, vector<int>, greater<int>> s;
priority_queue<int> f;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin>>x;
    s.push(x);
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        f.push(a);
        s.push(b);
        while(f.top() > s.top()){
            int x = f.top();
            int y = s.top();
            f.pop();
            s.pop();
            f.push(y);
            s.push(x);
        }
        cout<<s.top()<<'\n';
        
    }


    
    
}
