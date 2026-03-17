#include <bits/stdc++.h>
using namespace std;

int n;
int x;
pair<int,int> stk[200005];
int top = 0;
int cur=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cur++;
        cin>>x;
        if(x == stk[top].first) stk[top].second++;
        else stk[++top] = {x,1};

        if(stk[top].first == stk[top].second){
            cur -= stk[top].first;
            top--;
        }
        cout<<cur<<'\n';
    }

}