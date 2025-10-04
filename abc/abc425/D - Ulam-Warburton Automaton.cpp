#include <iostream>
#include <vector>
using namespace  std;
int h,w;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};

#define x first

int main(){
    cin>>h>>w;
    vector<vector<int>> a(h+2,vector<int>(w+2,-1));
    vector<pair<int,int>> check ,draw;
    char c;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>c;
            if(c=='#'){
                draw.push_back({i,j});
            }else{
                a[i][j]=0;
            }
        }
    }

    int nr,nc,cnt,ans=0;
    while(!draw.empty()){
        for(auto [r,c]:draw){
            a[r][c]=1;
            ans++;
            for(int k=0; k<4; k++){
                nr=r+dr[k];
                nc=c+dc[k];
                if(a[nr][nc]==0) check.push_back({nr,nc});
            }
        }
        draw.clear();

        for(auto [r,c]:check){
//            cout<<r<<' '<<c<<'\n';
            cnt=0;
            for(int k=0; k<4; k++){
                nr=r+dr[k];
                nc=c+dc[k];
                if(a[nr][nc]==1) cnt++;
            }
            if(cnt==1) draw.push_back({r,c});
        }

        check.clear();
    }

    cout<<ans<<'\n';

}
