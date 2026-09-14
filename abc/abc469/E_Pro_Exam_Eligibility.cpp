#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
string s;

bool valid(double m){
    vector<double> v(n+1);
    vector<double> sum(n+1);
    vector<int> w_sum(n+1);
    for(int i=1; i<=n; i++){
        if(s[i] == 'o') v[i] = (1-m);
        else v[i] = -m;
        sum[i] = sum[i-1] + v[i];
        w_sum[i] = w_sum[i-1] + (s[i] == 'o');
    }

    int cnt = 0;
    int l = 0, r = 0;
    double mi = 0;

    while(1){
        r++;
        if(r > n) return false;

        while(w_sum[r] - w_sum[l] >= k){
            l++;
            mi = min(mi, sum[l]);
            if(sum[r] - mi >= 0){
                return true;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k>>s;
    s = ' ' + s;
    double l=0, r = 1;
    int round = 25;
    while(round--){
        double m = (l+r)/2;
        if(valid(m)){
            l = m;
        }else{
            r = m;
        }
    }

    cout << fixed << setprecision(8) << l << '\n';
    
} 