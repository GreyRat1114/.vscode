#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
void solve(){
    int n;
    std::cin>>n;
    std::vector<int>ans(n+1);
    if(n==1){std::cout<<1<<'\n';
        return;
    }
    else if(n==2){
        std::cout<<"1 2"<<'\n';
        return ;
    }else if(n==3){
        std::cout<<"1 3 2"<<'\n';
        return;
    }
    int pos;
    if(n%2==1){
        ans[1]=2;
        int cnt=1;
        int maxn=n,minn=3;
        for(int i=2;i<n-2;i++){
            ++cnt;
            if(i%2==0){
                ans[i]=maxn;
                maxn--;
            }else{
                ans[i]=minn;
                ++minn;
            }
        }
        ans[++cnt]=maxn;
        ans[++cnt]=1;
        pos=cnt;
        ans[++cnt]=minn;
    }else{
        ans[1]=n/2+1;
        int cnt=1;
        int maxn=n,minn=2;
        for(int i=2;i<n-2;i++){
            ++cnt;
            if(i%2==0){
                ans[i]=maxn;
                maxn--;
            }else{
                ans[i]=minn;
                ++minn;
            }
        }
        ans[++cnt]=minn;
        ans[++cnt]=maxn;
        ans[++cnt]=1;
        pos=n;
    }
    //std::cout<<pos<<'\n';
    for(int i=pos;i<=n;i++){
        std::cout<<ans[i]<<" ";
    }
    for(int j=1;j<pos;j++){
        std::cout<<ans[j]<<' ';
    }
    std::cout<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}