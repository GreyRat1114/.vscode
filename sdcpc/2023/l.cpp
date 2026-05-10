#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL tot;
vector<vector<LL>> ans(1e6+5,vector<LL>(5,0));
void print(LL l1,LL l2,LL r1,LL r2,LL l3,LL l4,LL r3,LL r4,LL px,LL py,LL tag){
    //printf("<%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld,%lld>\n",l1,l2,r1,r2,l3,l4,r3,r4,tag);
    //printf("{%lld,%lld}",px,py);
    if(tag==0){
        for(int i=1;l1-i>=l3;i++){
            LL x=px-i;
            LL y=py-i;
            tot++;
            ans[tot]={x,y,l2-x,r2-y};
            //cout<<x<<' '<<y<<' '<<l2-x<<' '<<r2-y<<'\n';
        }
    }else if(tag==1){
        for(int i=1;l1-i>=l3;i++){
            LL x=px-i;
            LL y=py+i;
            tot++;
            ans[tot]={x,y,l2-x,r1-y};            
            //cout<<x<<' '<<y<<' '<<l2-x<<' '<<r1-y<<'\n';
        }
    }else if(tag==2){
        for(int i=1;l2+i<=l4;i++){
            LL x=px+i;
            LL y=py-i;
            tot++;
            ans[tot]={x,y,l1-x,r2-y};
            //cout<<x<<' '<<y<<' '<<l1-x<<' '<<r2-y<<'\n';
        }        
    }else{
        for(int i=1;l2+i<=l4;i++){
            LL x=px+i;
            LL y=py+i;
            //printf("|%lld,%lld|",x,y);
            tot++;
            ans[tot]={x,y,l1-x,r1-y};
            //cout<<x<<' '<<y<<' '<<l1-x<<' '<<r1-y<<'\n';
        }        
    }
}
void check(LL l1,LL l2,LL r1,LL r2,LL bi,LL bj){ 
    if(l1==l2||r1==r2){
        return;
    }
    //printf("{%lld,%lld,%lld,%lld}\n",l1,l2,r1,r2);
    if(bi*2>=l1+l2){
        if(bj*2>=r1+r2){
            LL maxn=max(l2-bi,r2-bj);
            check(l2-maxn,l2,r2-maxn,r2,bi,bj);
            print(l2-maxn,l2,r2-maxn,r2,l1,l2,r1,r2,l2-maxn,r2-maxn,0);
        }else{
            LL maxn=max(l2-bi,bj-r1);
            check(l2-maxn,l2,r1,r1+maxn,bi,bj);
            print(l2-maxn,l2,r1,r1+maxn,l1,l2,r1,r2,l2-maxn,r1+maxn,1);
        }
    }else{
        if(bj*2>=r1+r2){
            LL maxn=max(bi-l1,r2-bj);
            //printf("{%lld,%lld,%lld,%lld,%lld}",0,l1,l1+maxn,r2-maxn,r2);
            check(l1,l1+maxn,r2-maxn,r2,bi,bj);
            print(l1,l1+maxn,r1-maxn,r2,l1,l2,r1,r2,l1+maxn,r2-maxn,2);
        }else{
            LL maxn=max(bi-l1,bj-r1);
            check(l1,l1+maxn,r1,r1+maxn,bi,bj);
            print(l1,l1+maxn,r1,r1+maxn,l1,l2,r1,r2,l1+maxn,r1+maxn,3);
        }   
    }
}
void solve(){
    LL n,bi,bj;
    cin>>n>>bi>>bj;
    tot=0;
    if(n==1){
        cout<<"Yes"<<'\n';
        cout<<0<<'\n';
        return;
    }
    cout<<"Yes"<<'\n';
    check(1,n,1,n,bi,bj);
    cout<<tot<<'\n';
    for(int i=1;i<=tot;i++){
        cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<' '<<ans[i][3]<<'\n';
    }

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}