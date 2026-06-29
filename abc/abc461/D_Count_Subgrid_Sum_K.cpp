#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int h,w,k;
int a[505][505];
int sum[505][505];

bool valid1(int a, int b, int c, int d){
    return sum[c][d] - sum[c][b-1] - sum[a-1][d] + sum[a-1][b-1] >= k;
}

bool valid2(int a, int b, int c, int d){
    return sum[c][d] - sum[c][b-1] - sum[a-1][d] + sum[a-1][b-1] >= k+1;
}

bool check(int a, int b, int c, int d){
    return sum[c][d] - sum[c][b-1] - sum[a-1][d] + sum[a-1][b-1] == k;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>h>>w>>k;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            char c;
            cin>>c;
            a[i][j] = (c == '1');
        }
    }

    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
            // cout<<sum[i][j]<<' ';
        }
        // cout<<'\n';
    }

    int ans = 0;
    for(int c=1; c<=h; c++){
        for(int d=1; d<=w; d++){
            for(int a=1; a<=c; a++){
                int l = 0;
                int r = d;
                int rst1 = 0;
                while(l <= r){
                    int m = (l+r)/2;
                    if(valid1(a,m,c,d)){
                        rst1 = m;
                        l = m+1;
                    }else{
                        r = m-1;
                    }
                }
                l = 0;
                r = d;
                int rst2 = 0;
                while(l <= r){
                    int m = (l+r)/2;
                    if(valid2(a,m,c,d)){
                        rst2 = m;
                        l = m+1;
                    }else{
                        r = m-1;
                    }
                }
                // cout<<rst1<<' '<<rst2<<'\n';
                // if(rst1 == 0 || rst2 == 0) continue;
                ans += rst1 - rst2;
            }
        }
    }

    cout<<ans<<'\n';


}
