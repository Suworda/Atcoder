#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
int sum[1000005];
int p10[] = {1, 10, 100, 1000, 10000, 100000};

int query(string x, string y){
    for(int i=0; i<6; i++){
        if(x[i] > y[i]) return 0;
    }

    int rst = 0;
    for(int i=0; i<(1 << 6); i++){
        int cnt_L = 0;
        int idx = 0;
        bool sp = 0;
        for(int j=0; j<6; j++){
            if((i >> j) & 1){
                idx += (y[j] - '0') * p10[5-j];
            }
            else{
                if((x[j] - '0' - 1) < 0) sp = 1;
                idx += (x[j] - '0' - 1) * p10[5-j];
                cnt_L++;
            }
        }

        if(sp) continue;

        if(cnt_L & 1){
            rst -= sum[idx];
        }
        else{
            rst += sum[idx];
        }
    }

    return rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++){
        string s;
        int v;
        cin>>s>>v;
        int x = stoi(s);
        sum[x] = v;
    }

    for(int i=0; i<=5; i++){
        for(int j=0; j<100000; j++){
            int a = j/p10[i];
            int b = j%p10[i];
            int x = a * p10[i+1] + b;
            for(int k = 1; k<=9; k++){
                x += p10[i];
                sum[x] += sum[x - p10[i]];
            }
        }
    }

    int q;
    cin>>q;
    while(q--){
        string x,y;
        cin>>x>>y;
        cout << query(x,y) << '\n';
    }
    
} 