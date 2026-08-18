//st表&&RMO问题
#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5+5;
const int K=20;
struct ST{
    vector<vector<LL>> st; 
    vector<LL> lg;
    void init(vector<LL>& a,LL n){
        st.assign(n+1,vector<LL>(30,0));
        lg.assign(n+1,0);
        lg[1]=0;
        for(int i=2;i<=n;i++)lg[i]=lg[i/2]+1;

        for(int i=1;i<=n;i++)st[i][0]=a[i];

        for(int j=1;(1<<j)<=n;j++){
            for(int i=1;i+(1<<j)-1<=n;i++){
                st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
    }
    LL query(LL l,LL r){
        LL k=lg[r-l+1];
        return max(st[l][k],st[r-(1<<k)+1][k]);
    }
};