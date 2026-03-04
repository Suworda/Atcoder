#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

int H,W,h[200005],w[200005],n;
pair<int,int> ans[200005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>H>>W>>n;    
    for(int i=0; i<n; i++){
        cin>>h[i]>>w[i];
    }

    int idH[n+1], idW[n+1];
    iota(idH, idH+n,0);
    iota(idW, idW+n,0);
    stable_sort(idH, idH+n, [](int x, int y){
        return h[x] > h[y];
    });
    stable_sort(idW, idW+n, [](int x, int y){
        return w[x] > w[y];
    });

    int x=0, y=0;
    idH[n] = 2e9;
    idW[n] = 2e9;
    for(int i=0; i<n; i++){
        // cout<<H<<' '<<W<<' '<<x<<' '<<idH[x]<<' '<<y<<' '<<idH[y]<<'\n';
        while(ans[idH[x]] != mp(0,0)) x++;
        while(ans[idW[y]] != mp(0,0)) y++;

        if(h[idH[x]] == H){
            ans[idH[x]] = {H-h[idH[x]], W-w[idH[x]]};
            W-=w[idH[x]];
            x++;

        }else if(w[idW[y]] == W){
            ans[idW[y]] = {H-h[idW[y]], W-w[idW[y]]};
            H-=h[idW[y]];
            y++;
        }
    }

    for(int i=0; i<n; i++){
        cout<<ans[i].first+1<<' '<<ans[i].second+1<<'\n';
    }
}
