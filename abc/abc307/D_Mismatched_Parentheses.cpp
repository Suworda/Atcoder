#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
string s;
pair<int,char> stk[200005];
int top = 0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>s;
    int cur = 0;
    for(int i=0; i<n; i++){
        char c = s[i];
        if('a' <= c && c <= 'z') stk[++top] = {cur, c};
        else if(c == '(') stk[++top] = {++cur, c};

        else{
            if(cur){
                while(top && cur == stk[top].first) top--;
                cur--;
            }
            else stk[++top] = {cur, c};

        }
    }

    for(int i=1; i<=top; i++) cout<<stk[i].second;

}