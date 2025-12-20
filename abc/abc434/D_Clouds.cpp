#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n;
int ty[2005][2005];
int v[2005][2005];
int ans[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    int u,d,l,r;
    for(int i=1; i<=n; i++){
        cin>>u>>d>>l>>r;
        v[u][l]++;
        v[u][r+1]--;
        v[d+1][l]--;
        v[d+1][r+1]++;

        ty[u][l]+=i;
        ty[u][r+1]-=i;
        ty[d+1][l]-=i;
        ty[d+1][r+1]+=i;
    }

    for(int i=1; i<=2000; i++){
        int cur_v=0;
        int cur_ty=0;
        for(int j=1; j<=2000; j++){
            cur_v += v[i][j];
            cur_ty += ty[i][j];
            v[i][j] = cur_v;
            ty[i][j] = cur_ty;
        }
    }

    for(int i=1; i<=2000; i++){
        int cur_v=0;
        int cur_ty=0;
        for(int j=1; j<=2000; j++){
            cur_v += v[j][i];
            cur_ty += ty[j][i];
            v[j][i] = cur_v;
            ty[j][i] = cur_ty;
        }
    }

    int base=4e6;

    for(int i=1; i<=2000; i++){
        for(int j=1; j<=2000; j++){
            if(v[i][j] >= 1) base--;

            if(v[i][j] == 1){
                ans[ty[i][j]]++;
            }
        }
    }

    for(int i=1; i<=n; i++){
        ans[i]+=base;
        cout<<ans[i]<<'\n';
    }






    // for(int i=1; i<=10; i++){
    //     for(int j=1; j<=10; j++){
    //         //if(v[i][j] == 1){
    //             cout<<ty[i][j]<<' ';
    //         //}
    //     }
    //     cout<<'\n';
    // }


}