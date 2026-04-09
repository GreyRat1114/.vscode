#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=105;
int a[N][N];
int b[N][N];
void op1(LL x,LL y,LL len){

    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            LL x1=x+i-1;
            LL y1=y+j-1;
            LL i2=len-j+1;
            LL j2=i;
            LL x2=x+i2-1;
            LL y2=y+j2-1;
            b[x1][y1]=a[x2][y2];
        }
    }
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            LL x1=x+i-1;
            LL y1=y+j-1;
            a[x1][y1]=b[x1][y1];
        }
    }    
}
void op2(LL x,LL y,LL len){
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            LL x1=x+i-1;
            LL y1=y+j-1;
            LL i2=j;
            LL j2=len-i+1;
            LL x2=x+i2-1;
            LL y2=y+j2-1;
            b[x1][y1]=a[x2][y2];
        }
    }    
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            LL x1=x+i-1;
            LL y1=y+j-1;
            a[x1][y1]=b[x1][y1];
        }
    }    
}
void solve(){
    LL n,q;
    cin>>n;
    cin>>q;
    LL op,len,x,y;

    vector<vector<LL>> qx(q+1,vector<LL>(10,0));
    int tag=1;
    for(int i=1;i<=q;i++){
        cin>>op>>x>>y>>len;
        qx[i][1]=op;

        qx[i][2]=x;
        qx[i][3]=y;
        qx[i][4]=len;
        if(len!=1){
            tag=0;
        }
    }

    if(tag){
        //printf("Yes");
        LL d;
        cin>>d;
        LL dx,dy;
        for(int i=1;i<=d;i++){
            cin>>dx>>dy;
            cout<<(dx-1)*n+dy<<'\n';
        }
        return;
    }  

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=(i-1)*n+j;
        }
    }    

    for(int i=1;i<=q;i++){
        op=qx[i][1];
        x=qx[i][2];
        y=qx[i][3];
        len=qx[i][4];        
        if(tag){
            break;
        }else{
            if(op==1){
                op1(x,y,len);
            }else{
                op2(x,y,len);
            }
        }
    }
    LL d;
    cin>>d;
    LL dx,dy;
    for(int i=1;i<=d;i++){
        cin>>dx>>dy;
        cout<<a[dx][dy]<<'\n';
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}