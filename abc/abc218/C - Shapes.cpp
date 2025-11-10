#include <bits/stdc++.h>
using namespace std;

bool ans=false;
int n;
char a[500][500];
char b[500][500];
// int maxr=0,maxc=0;
int aminr=1000,aminc=1000,bminr=1000,bminc=1000;
int amaxr=0,amaxc=0,bmaxr=0,bmaxc=0;
//int nr,nc;
vector<string> x,y;
//int r,c;

void rot(){
    vector<string> cur;
    int nr=amaxr-aminr, nc=amaxc-aminc;
    for(int i=nc; i>=0; i--){
       cur.push_back("");
       for(int j=0; j<=nr; j++){
           cur[nc-i]+=x[j][i];
       }
    }
    swap(aminr,aminc);
    swap(amaxr,amaxc);
    swap(nr,nc);
    //for(int i=aminr; i<=amaxr; i++){
        //r=i-aminr;
        //cur.push_back("");
        //for(int j=aminc; j<=amaxc; j++){
            //c=j-aminc;
            //cur[r][c]+=x[(amaxc-j)-c][r];
        //}
    //}
    //return;
    x.clear();
    for(int i=0; i<=nr; i++){
        x.push_back("");
        for(int j=0; j<=nc; j++){
            x[i]+=cur[i][j];
        }
    }
}

void check(){
    for(int k=0; k<4; k++){
        bool ok=true;
        //if(amaxr-aminr==bmaxr-bminr && amaxc-aminc==bmaxc-bminc){
            for(int i=0; i<=amaxr-aminr; i++){
                for(int j=0; j<=amaxc-aminc; j++){
                    //cout<<i<<' '<<j<<'\n';
                    if( !(amaxr-aminr==bmaxr-bminr && amaxc-aminc==bmaxc-bminc) || x[i][j]!=y[i][j]) ok=false;
                }
            }
        //}
        if(ok){
            ans=true;
            return;
        }
        rot();
    }

}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
            if(a[i][j]=='#'){
                amaxr=max(i,amaxr);
                amaxc=max(j,amaxc);
                aminr=min(i,aminr);
                aminc=min(j,aminc);
            }
        }
    }
    for(int i=aminr; i<=amaxr; i++){
        x.push_back("");
        for(int j=aminc; j<=amaxc; j++){
            x[i-aminr]+=a[i][j];
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>b[i][j];
            if(b[i][j]=='#'){
                bmaxr=max(i,bmaxr);
                bmaxc=max(j,bmaxc);
                bminr=min(i,bminr);
                bminc=min(j,bminc);
            }
        }
    }
    for(int i=bminr; i<=bmaxr; i++){
        y.push_back("");
        for(int j=bminc; j<=bmaxc; j++){
            y[i-bminr]+=b[i][j];
        }
    }


    //for(int i=0; i<4; i++) rot();
    //for(int i=0; i<=amaxr-aminr; i++){
        //for(int j=0; j<=amaxc-aminc; j++){
            //cout<<x[i][j];
        //}
        //cout<<'\n';
    //}




    check();
    cout<<(ans ? "Yes\n" : "No\n");
    // for(int i=minr; i<n; i++){
    //     for(int j=minc; j<n; j++){
    //     }
    // }
    return 0;
    for(int i=0; i<=bmaxr-bminr; i++){
        for(int j=0; j<=bmaxc-bminc; j++){
            cout<<y[i][j];
        }
        cout<<'\n';
    }
}
