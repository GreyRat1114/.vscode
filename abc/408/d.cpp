#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
using LL=long long;
int a1[N];
int a0[N];
int s1[N];
int s0[N];
int s3[N];
void solve(){

    string s;
    int n;
    cin>>n;
    for(int i=0;i<=n+5;i++){
        a1[i]=0;
        a0[i]=0;
    }
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            a1[i+1]++;
        }
        else{
            a0[i+1]++;
        }
    }
    s0[0]=0;
    s1[0]=0;
    for(int i=1;i<=n;i++){
        s0[i]=s0[i-1]+a0[i];
        s1[i]=s1[i-1]+a1[i];
        s3[i]=s0[i]-s1[i];

    }
    int maxn=0;
    int ans=1e9;

    for(int i=0;i<=n;i++){
        ans=min(ans,s3[i]-maxn);
        maxn=max(maxn,s3[i]);
    }
    cout<<ans+s1[n]<<'\n';

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}