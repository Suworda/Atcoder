#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,t;
int a[45];
vector<int> v1, v2;
ll ans;

void get_ans(){
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int j = (int)v2.size()-1;
    for(int i=0; i<v1.size(); i++){
        while(j > 0 && v1[i] + v2[j] > t) j--;
        if(v1[i] + v2[j] <= t) ans = max(ans, v1[i] + v2[j]);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>t;
    int m1 = n/2;
    for(int i=0; i<n; i++) cin>>a[i];

    for(int i=0; i<(1<<m1); i++){
        int rst = 0;
        for(int j=0; j<m1; j++){
            if((i>>j) & 1) rst += a[j];
        }
        v1.push_back(rst);
    }
    
    int m2 = n - n/2;
    for(int i=0; i<(1<<m2); i++){
        int rst = 0;
        for(int j=0; j<m2; j++){
            if((i>>j) & 1) rst += a[j+m1];
        }
        v2.push_back(rst);
    }

    get_ans();

    cout<<ans<<'\n';
}