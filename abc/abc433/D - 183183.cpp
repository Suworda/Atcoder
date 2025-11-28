#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

auto MAXV=10000000000000000000;

unordered_map<int,int> cnt[20];

unsigned long long f(int x, int y){
    string s = to_string(x) + to_string(y);

    return stoull(s);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        unsigned long long x=a[i];
        for(int i=0; i<20; i++){
            //cout<<i<<' '<<x<<'\n';
            cnt[i][x%m]++;

            if(x > MAXV/10) break;
            x*=10;
        }
    }

    long long ans=0;
    for(int i=0; i<n; i++){
        string s=to_string(a[i]);
        int sz=s.size();

        ans += cnt[sz][m - a[i]%m];
        if(a[i]%m == 0) ans += cnt[sz][0];
    }

    cout<<ans<<'\n';
}
