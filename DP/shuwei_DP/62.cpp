#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=10;
LL f[N][5];
int getans(LL x){
    vector<int> num(N,0);
    LL a=x;
    int tot=0;
    while(a!=0){
        tot++;
        num[tot]=a%10;
        a=a/10;
    }
    num[tot+1]=0;
    LL sum=0;
    int tag=0;
    for(int i=tot;i>=1;i--){
        sum+=f[i-1][2]*num[i];
        if(tag){
            sum+=num[i]*f[i-1][0];
        }
        else{
            if(num[i]>4){
                sum+=f[i-1][0];
            }
            if(num[i]>6){
                sum+=f[i-1][1];
            }
            if(num[i+1]==6&&num[i]>2){
                sum+=f[i][1];
            }
        }
        if(num[i]==4||(num[i+1]==6&&num[i]==2)){
            tag=1;
        }
        // printf("<%lld>",sum);
    }
    return 1ll*x-sum;
}
void solve(){
    memset(f,0,sizeof(f));
    LL n,m;
    cin>>n>>m;
    f[0][0]=1,f[1][0]=9,f[1][1]=1,f[1][2]=1;    
    for(int i=2;i<=N;i++){
        f[i][0]=1ll*f[i-1][0]*9-f[i-1][1];
        f[i][1]=f[i-1][0];
        f[i][2]=10*f[i-1][2]+f[i-1][1]+f[i-1][0];
        // printf("(%lld)",f[i][0]);
    }    
    while(n!=0&&m!=0){
        LL s1=getans(n);
        LL s2=getans(m+1);
        // printf("{%d,%d}",s1,s2);
        cout<<s2-s1<<'\n';
        cin>>n>>m;
    }
}
int main(){
    solve();
    return 0;
}