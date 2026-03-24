#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
LL work(LL x,LL y){
    LL pos=0;
    LL x1=x,y1=y;
    LL cnt=0;
    LL pos2=0;
    while(x1&&y1){  
        if(x1&1==1&&y1&1==1){
            pos=cnt;
        }
        cnt++;
        x1=x1>>1;
        y1=y1>>1;
    }
    for(int i=31;i>=pos;i--){
        LL pt1=(1ll<<i);
        if((x&pt1)==0&&(y&pt1)==0){
            pos2=i;
        }   
    }
    //cout<<'\n';
    //printf("{%d,%d}",pos,pos2);
    LL p1=0;
    LL ans1=0;
    for(int i=31;i>=0;i--){
        LL pt1=(1ll<<i)&x;
        LL pt2=(1ll<<i)&y;
        if(i<=pos){
            if(pt1==0){
                ans1=ans1|(1ll<<i);
            } 
        }else{
            ans1=ans1|pt2;
        }
    }
    LL ans2=0;
    for(int i=30;i>=0;i--){
        LL pt1=(1ll<<i)&x;
        LL pt2=(1ll<<i)&y;
        if(i==pos2){
            ans2=ans2|(1ll<<i);
        }else if(i>pos2){
            ans2=ans2|pt2;
        }
    }
    //cout<<ans1<<'\n';
    //cout<<ans2<<'\n';    
    if(y-ans1<ans2-y){
        return ans1;
    }else{
        return ans2;
    }
    // LL ans=min(y-ans1,);
    // cout<<ans<<'\n';

}
void solve(){
    LL x,y;
    cin>>x>>y;
    if(x==0&&y==0){
        cout<<0<<' '<<0<<'\n';
        return;
    }
    if(x==0){
        cout<<x<<' '<<y<<'\n';
        return;
    }    
    if(y==0){
        cout<<x<<' '<<y<<'\n';
        return;
    }    
    LL ans1=work(x,y);
    LL ans2=work(y,x);
    //printf("{%lld,%lld}",ans1,ans2);
    if(abs(ans1-y)<(abs(ans2-x))){
        cout<<x<<' '<<ans1<<'\n';
    }else{
        cout<<ans2<<' '<<y<<'\n';        
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}