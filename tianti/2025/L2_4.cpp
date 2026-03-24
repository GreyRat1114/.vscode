#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using PII=std::pair<ll,ll>;
PII get(ll x){
    int cm=0;
    int r;
    while(x){
        cm++; 
        r=x%10;
        x/=10;
    }
    PII d=std::make_pair(cm,r);
    return d;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin>>n;
    ll l,r;
    std::cin>>l>>r;
    PII pos1=get(l);
    PII pos2=get(r);
    if(pos1.first<n){
        std::cout<<"No Soultion"<<endl;
        return 0;
    }
    ll st,end;
    if(pos1.first==pos2.first){
        st=pos1.second,end=pos2.second;
    }
    else{
        st=1,end=9;
    }
    std::array<ll,5>as;
    std::array<ll,2>sa;
    int ts=0;
    for(int i=0;i<5;i++){
        as[i]=ts;
        ts+=2;
    }
    sa[0]=0,sa[1]=5;
    std::vector<ll>ans;
    auto dfs=[&](auto &&self,ll step,ll num)->void{
        if(step==n+1){
            if(num>=l&&num<=r){
               ans.push_back(num);
            }
            return ;
        }
        if(step==1){
            for(int i=st;i<=end;i++){
                num=i;
                self(self,step+1,num);
            }
            return ;
        }
        else if(step==10){
            self(self,step+1,num*10ll);
            return;
        }
        else if(step==5){
            for(int i=0;i<2;i++){
                ll ms=num*10ll+sa[i];
                self(self,step+1,ms);
            }
            return ;
        }
        else if(step%2==0){
            for(int i=0;i<5;i++){
                  ll ms=num*10ll+as[i];
                  if(ms%step!=0){
                     continue;
                  }
                 self(self,step+1,ms);
            }
            return ;
        }
        else if(step%2==1){
            for(int i=0;i<10;i++){
                ll ms=num*10ll+i;
                if(ms%step!=0){
                    continue;
                }
                self(self,step+1,ms);
            }
            return ;
        }
    };
    dfs(dfs,1,0);
    if(ans.size()==0){
        std::cout<<"No Solution"<<endl;
        return 0;
    }
    for(auto x:ans){
        std::cout<<x<<endl; 
    }
    return 0;
}