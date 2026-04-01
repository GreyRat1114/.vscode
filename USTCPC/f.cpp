#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int d[4][8]={{0,0,0,1,1,1,1,2},{1,0,1,1,0,1,0,2},{1,3,0,1,1,2,0,2},{1,1,1,2,0,2,0,3}};
void shuchu(int x,int y,int op){
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j+=2){
            if(op==0){
                cout<<x+d[i][j]<<' '<<y+d[i][j+1]<<' ';
            }else{
                cout<<y+d[i][j+1]<<' '<<x+d[i][j]<<' ';
            }
        }
        cout<<'\n';
    }
}
void solve(){
    LL n,m;
    cin>>m>>n;
    if(n%4==0){
        LL pt1=n/4;
        if(m%2==0){
            LL pt2=m/2;
            LL ans=pt1*pt2;
            cout<<ans*4<<'\n';
            for(int i=0;i<m;i+=2){
                for(int j=0;j<n;j+=4){
                    shuchu(i,j,0);
                }
            }
        }else{
            cout<<"Impossible!"<<'\n';
        }
    }else if(m%4==0){
        LL pt1=m/4;
        if(n%2==0){
            LL pt2=n/2;
            LL ans=pt1*pt2;
            cout<<ans*4<<'\n';
            for(int i=0;i<n;i+=2){
                for(int j=0;j<m;j+=4){

                    shuchu(i,j,1);
                }
            }
        }else{
            cout<<"Impossible!"<<'\n';
        }
    }else{
        cout<<"Impossible!"<<'\n';
    }
}
int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}