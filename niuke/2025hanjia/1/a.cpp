#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL p[N];
set<int> num[15];
LL pnum[15];
void init(){
    for(int i=1;i<=7;i++){
        if(i==4){
            continue;
        }
        num[0].insert(i);
    }
    for(int i=1;i<=7;i++){
        if(i==3||i==6){
            num[1].insert(i);
        }
    }    
    for(int i=1;i<=7;i++){
        if(i==2||i==6){
            continue;
        }
        num[2].insert(i);
    }  
    for(int i=1;i<=7;i++){
        if(i==2||i==5){
            continue;
        }
        num[3].insert(i);
    }  
    for(int i=1;i<=7;i++){
        if(i==1||i==5||i==7){
            continue;
        }
        num[4].insert(i);
    }  
    for(int i=1;i<=7;i++){
        if(i==3||i==5){
            continue;
        }
        num[5].insert(i);
    }  
    for(int i=1;i<=7;i++){
        if(i==3){
            continue;
        }
        num[6].insert(i);
    }  
    for(int i=1;i<=7;i++){
        if(i==3||i==1||i==6){
            num[7].insert(i);
        }
        
    }  
    for(int i=1;i<=7;i++){
        num[8].insert(i);
    }  
    for(int i=1;i<=7;i++){
        if(i==5){
            continue;
        }
        num[9].insert(i);
    }  
}
LL qpow(LL a,LL b)
{
    a=a%mod;
    LL ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b=b>>1;
    }
    ans=ans%mod;
    return ans;
}
LL getans(LL a,LL b){
    a=a%mod;
    LL ans=(a*qpow(b,mod-2))%mod;
    return ans;
}


void solve(){
    LL c;
    cin>>c;
    for(int i=1;i<=7;i++){
        cin>>p[i];
    }
    LL p1=1;
    for(int i=1;i<=7;i++){
        p1=(p1*getans((100-p[i]),100))%mod;
    }
    p1=(1-p1)%mod;
    p1=qpow(p1,8);   
    if(p1==0){
        cout<<0<<'\n';
        return;
    }
    LL p2=0;
    for(int i=0;i<=9;i++){
        LL pp2=1;
        for(int j=1;j<=7;j++){
            if(num[i].count(j)){
                pp2=(pp2*getans(p[j],100))%mod;
            }else{
                pp2=(pp2*getans(100-p[j],100))%mod;
            }
        }
        pnum[i]=pp2;
        p2=(p2+pp2)%mod;
    }
    if(p2==0){
        cout<<0<<'\n';
        return;
    }
    // for(int i=0;i<=9;i++){
    //     printf("{%lld}",pnum[i]);
    // }
    
    p2=qpow(p2,8);
    //printf("{%lld}",p2);
    LL p3=0;
    for(int i=0;i<=c;i++){
        LL l=i;
        LL r=c-i;
        LL p31=1;
        LL p32=1;
        int cnt=4;
        while(cnt--){
            LL x=l%10;
            p31=(p31*pnum[x])%mod;
            l=l/10;
            //printf("{%d,%lld,%lld}",i,l,x);
        }
        cnt=4;
        while(cnt--){
            LL x=r%10;
            p32=(p32*pnum[x])%mod;
            r=r/10;
        }
        p3=(p3+(p31*p32)%mod)%mod;
        //printf("|%lld %lld|",p31,p32);
    }
    //printf("(%lld %lld %lld)",p1,p2,p3);
    //LL ans=((p1*p2)%mod*p3)%mod;
    cout<<p3<<'\n';
    // LL x;
    // cin>>x;
    // cout<<getans(1,x)<<'\n';
}
int main(){
    init();
    // for(int i=0;i<=9;i++){
    //     printf("{%d}",i);
    //     for(auto x:num[i]){
    //         cout<<x<<' ';
    //     }
    //     cout<<'\n';
    // }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}