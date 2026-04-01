#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
// #pragma GCC optimize(3)
// #pragma GCC target("avx")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-fhoist-adjacent-loads")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
// #pragma GCC optimize(2)
int sq[N];
int tot;
void init(){
    tot=0;
    for(int i=0;i*i<=10000;i++){
        tot++;
        sq[tot]=i*i;
    }
}
void solve(){
    LL n;
    cin>>n;
    vector<LL> a(n+1),sum0(n+1,0);
    LL s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum0[i]=sum0[i-1]+a[i];
        s+=a[i];
    }
    //vector<vector<LL>> dp(n+1,vector<LL>(n+1,0));
    vector<vector<LL>> pref(s+1,vector<LL>(tot+1,-1));
    //LL premin=1e9;
    vector<vector<LL>> dp(s+1,vector<LL>(tot+1,1e18));
    for(int i=1;i<=tot;i++){
        dp[0][i]=0;
        pref[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        vector<vector<LL>> cur(s+1,vector<LL>(tot+1,1e18));
        // for(int j=0;j<=s;j++){
        //     for(int k=1;k<=tot;k++){
        //         cur[j][k]=1e9;
        //     }
        // }
        for(int j=0;j<=s;j++){
            for(int k=1;k<=tot;k++){
                if(j-sq[k]>=0&&pref[j-sq[k]][k]!=-1)cur[j][k]=pref[j-sq[k]][k]+abs(sum0[i]-j);
            }
        }
        swap(dp,cur);
        
        for(int j=0;j<=s;j++){
            LL minn=1e18;
            for(int k=1;k<=tot;k++){
                if(dp[j][k]!=1e18)minn=min(minn,dp[j][k]);
                pref[j][k]=minn;
            }
        }
        
    }
    LL ans=1e18;
    for(int i=1;i<=tot;i++){
        ans=min(ans,dp[s][i]);
    }
    cout<<(ans==1e18?-1:ans)<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}