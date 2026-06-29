#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n1, n2, n3;
string s[3];
string ans;
char changed[130];
bool found = 0;
bitset<130> used;
clock_t st, ed;

void check(){
    string a,b,c;
    if(changed[s[0][0]] == '0') return;
    if(changed[s[1][0]] == '0') return;
    if(changed[s[2][0]] == '0') return;

    for(int i=0; i<s[0].size(); i++) a += changed[s[0][i]];
    for(int i=0; i<s[1].size(); i++) b += changed[s[1][i]];
    for(int i=0; i<s[2].size(); i++) c += changed[s[2][i]];
    
    int x = stoll(a);
    int y = stoll(b);
    int z = stoll(c);

    if(x + y == z){
        cout<<a<<'\n'<<b<<'\n'<<c<<'\n';
        // ed = clock();
        // cout<<ed - st<<'\n';
        exit(0);
    }
}

void dfs(int x, int id){
    if(id >= s[x].size()){
        if(x == 2){
            check();
            return;
        }
        dfs(x+1, 0);
        return;
    }
    // cerr<<x<<' '<<id<<'\n';
    // dfs(x, id+1);
    if(changed[s[x][id]]){
        dfs(x, id+1);

    }else{
        for(char i='0'; i<='9'; i++){
            if(!used[i]){
                changed[s[x][id]] = i; 
                used[i] = 1;
                dfs(x, id+1);
                used[i] = 0;
                changed[s[x][id]] = 0;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    for(int i=0; i<3; i++) cin>>s[i];
    
    // st = clock();
    memset(changed, 0, sizeof(changed));
    dfs(0,0);
    
    cout<<"UNSOLVABLE\n";

    // ed = clock();

    // cout<<ed - st<<'\n';
    
}
