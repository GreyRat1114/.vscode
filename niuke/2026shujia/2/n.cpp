#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,k;
    cin>>n>>k;
    vector<LL> a(n+1);
    vector<LL> s(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }    
    LL ans=s[n];
    LL maxn;
    LL tag=0;
    if(k%2==1){
        LL c=(k-1)/2;
        for(int i=n-c;i>=c+1;i--){
            if(tag==0){
                maxn=2*c*a[i]-(s[c]+s[i+c]-s[i]);
                tag=1;
            }else{
                maxn=max(maxn,2*c*a[i]-(s[c]+s[i+c]-s[i]));
            }
        }  
    }else{
        LL c=(k-2)/2;
        for(int i=n-c-1;i>=c+1;i--){
            if(tag==0){
                maxn=c*(a[i]+a[i+1])-(s[c]+s[i+1+c]-s[i+1]);
                tag=1;
            }else{
                maxn=max(maxn,c*(a[i]+a[i+1])-(s[c]+s[i+1+c]-s[i+1]));
            }
        }
    }
    cout<<ans+maxn<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}