#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    int n;
    std::cin>>n;
    std::vector<int>d(n+1);
    std::vector<std::vector<int>>cnt(n+1),adj(n+1);
    std::vector<std::array<int,2>>vec(n+1);
    int maxn=0;
    int minn=n;
    for(int i=1;i<=n;i++){
        std::cin>>d[i];
        maxn=std::max(maxn,d[i]);
        minn=std::min(minn,d[i]);
        cnt[d[i]].emplace_back(i);
    }
    if(minn<(maxn+1)/2){
        std::cout<<"No"<<'\n';
        return ;
    }else{
        //可以分成无数个叉
        if(maxn%2==1){
            for(int j=maxn/2+1;j<=maxn;j++){
                if(j==maxn/2+1){
                    if(cnt[j].size()!=1){
                        std::cout<<"No"<<'\n';
                        return ;
                    }
                }
                else if(cnt[j].size()<2){
                    std::cout<<"No"<<'\n';
                    return ;
                }
            }
            std::cout<<"Yes"<<'\n';
            int u=cnt[maxn].back();
            cnt[maxn].pop_back();
            for(int j=maxn-1;j>=maxn/2+1;j--){
                adj[u].emplace_back(cnt[j].back());
                vec[j][0]=cnt[j].back();
                u=cnt[j].back();
                cnt[j].pop_back();
            }
           for(int j=maxn/2+2;j<=maxn;j++){
                adj[u].emplace_back(cnt[j].back());
                u=cnt[j].back();
                cnt[j].pop_back();
            }
            for(int j=maxn;j>=maxn/2+2;j--){
                while(cnt[j].size()>0){
                    adj[vec[j-1][0]].emplace_back(cnt[j].back());
                    cnt[j].pop_back();
                }
            }
        for(int i=1;i<=n;i++){
            for(auto v:adj[i]){
                std::cout<<i<<" "<<v<<'\n';
            }
        }
        }else{
            for(int j=maxn/2+1;j<=maxn;j++){
                if(j==maxn/2+1){
                    if(cnt[j].size()!=2){
                        std::cout<<"No"<<'\n';
                        return ;
                    }
                }else if(cnt[j].size()<2){
                    std::cout<<"No"<<'\n';
                    return ;
                }
            }
            std::cout<<"Yes"<<'\n';
            int u=cnt[maxn].back();
            cnt[maxn].pop_back();
            for(int j=maxn-1;j>=maxn/2+1;j--){
                adj[u].emplace_back(cnt[j].back());
                vec[j][0]=cnt[j].back();
                u=cnt[j].back();
                cnt[j].pop_back();
            }
            for(int j=maxn/2+1;j<=maxn;j++){
                adj[u].emplace_back(cnt[j].back());
                u=cnt[j].back();
                cnt[j].pop_back();
            }
            for(int j=maxn;j>=maxn/2+2;j--){
                while(cnt[j].size()>0){
                    adj[vec[j-1][0]].emplace_back(cnt[j].back());
                    cnt[j].pop_back();
                }
            }
        for(int i=1;i<=n;i++){
            for(auto v:adj[i]){
                std::cout<<i<<" "<<v<<'\n';
            }
        }
        } 
    }
    
    
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