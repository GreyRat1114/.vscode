#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int N=2e5+10;
int a[N];
int sum[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    std::cin>>n>>m;
    ll sumx=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        sumx+=a[i];
    }
    int ans=N;
    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            int ls=sum[j-1];
            int rs=sum[n]-sum[i];
            if((ls+rs)%m==0){
                ans=std::min(i-j+1,ans);
            }
        }
    }
    for(int j=2;j<=n;j++){
        int rs=sum[j-1];
        if(rs%m==0){
            ans=std::min(j-1,ans);
        }
    }
    if(ans==N){
        std::cout<<-1;
    }else{
        std::cout<<n-ans<<'\n';
    }
    return 0;
}