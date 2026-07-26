#include<bits/stdc++.h>
using ll=long long;
const int N=1e6+10;
ll x[N],sum[N];
void solve(){
    int n;
    std::cin>>n;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        std::cin>>x[i];
        sum[i]=sum[i-1]+x[i];
    }
    if(n==1){
        std::cout<<"NO"<<'\n';
        return ;
    }
    if(n==2){
        std::cout<<"YES"<<'\n';
        return ;
    }
    if(n%2==1){
        int mid=(n/2)+1;
        ll sum1=sum[mid-1];
        ll sumr=sum[n]-sum[mid];
        if(n==3){
            if(sum1>sumr){
                std::cout<<"YES"<<'\n';
            }else{
                std::cout<<"NO"<<'\n';
            }
            return;
        }
        if(sum1!=sumr){
            if(sum1>sumr){
                std::cout<<"YES"<<'\n';
            }else {
                std::cout<<"NO"<<'\n';
            }
        }else{
            if(sum[mid-2]>sum[n]-sum[mid+1]){
                std::cout<<"YES"<<'\n';
            }else{
                std::cout<<"NO"<<'\n';
            }
        }
    }else{
        int mid=n/2;
        ll suml=sum[mid],sumr=sum[n]-sum[mid+1];
        if(n==4){
            if(x[4]<=sum[2]){
                std::cout<<"YES"<<'\n';
            }else{
                std::cout<<"NO"<<'\n';
            }
            return;
        }
        if(suml>sumr){
            std::cout<<"YES"<<'\n';
        }else if(suml<sumr){
            std::cout<<"NO"<<'\n';
        }else{
            ll sumx=sum[mid-1],sumy=sum[n]-sum[mid+2];
            if(sumx>=sumy)std::cout<<"YES"<<'\n';
            else{
                std::cout<<"NO"<<'\n';
            }
        }
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T=1;
    std::cin>>T;
    while(T--){
        solve();
    }
    return 0;
}