#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int tsx,tsy,tgx,tgy,asx,asy,agx,agy;
double dis_t, dis_a;

double f(double t){
    double tx,ty,ax,ay;
    if(t<dis_t){
        tx=tsx+(tgx-tsx)*t/dis_t;
        ty=tsy+(tgy-tsy)*t/dis_t;
    }else{
        tx=tgx;
        ty=tgy;
    }

    if(t<dis_a){
        ax=asx+(agx-asx)*t/dis_a;
        ay=asy+(agy-asy)*t/dis_a;
    }else{
        ax=agx;
        ay=agy;
    }

    return sqrt( pow((tx-ax),2) + pow(ty-ay,2) );
}

void sol(){
    cin>>tsx>>tsy>>tgx>>tgy>>asx>>asy>>agx>>agy;
    dis_t=sqrt( pow((tgx-tsx),2) + pow(tgy-tsy,2) );
    dis_a=sqrt( pow((agx-asx),2) + pow(agy-asy,2) );
    double l=0, r=min(dis_t , dis_a);

    double ans1,ans2;
    for(int i=0; i<50; i++){
        double ml=(2*l+r)/3, mr=(l+2*r)/3;
        if(f(ml) > f(mr)){
            l=ml;
        }else{
            r=mr;
        }
    }
    ans1=f(l);

    l=min(dis_t , dis_a); r=max(dis_t , dis_a);
    for(int i=0; i<50; i++){
        double ml=(2*l+r)/3, mr=(l+2*r)/3;
        if(f(ml) > f(mr)){
            l=ml;
        }else{
            r=mr;
        }
    }
    ans2=f(l);

    cout<<fixed<<setprecision(7) << min(ans1,ans2)<<'\n';
}

int main(){
    int t;
    cin>>t;
    while(t--) sol();
}
