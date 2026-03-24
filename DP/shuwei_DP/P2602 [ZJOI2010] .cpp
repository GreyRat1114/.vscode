// P2602 [ZJOI2010] 数字计数
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=25;
LL ten[N],f[N];
LL cnta[N],cntb[N];
void getans(LL x,LL *cnt){
    vector<LL> num(N+10,0);
    int len=0;  
    while(x){
        num[++len]=x%10;
        x=x/10;
    }    
    for(int i=len;i>=1;i--){
        for(int j=0;j<=9;j++){
            cnt[j]+=f[i-1]*num[i];

        }
        for(int j=0;j<num[i];j++){
            cnt[j]+=ten[i-1];

        }
        LL num2=0;
        for(int j=i-1;j>=1;j--){
            num2=num2*10+num[j];
        }
        cnt[num[i]]+=num2+1;
        cnt[0]-=ten[i-1];
    }    
}
void solve(){
    LL a,b;
    cin>>a>>b;
    ten[0]=1;
    for(int i=1;i<=15;i++){
        f[i]=f[i-1]*10+ten[i-1];
        ten[i]=10*ten[i-1];
    }
    getans(a-1,cnta);
    getans(b,cntb);
    for(int i=0;i<=9;i++){
        cout<<cntb[i]-cnta[i]<<' ';
    }
}
int main(){

    solve();
    return 0;
}