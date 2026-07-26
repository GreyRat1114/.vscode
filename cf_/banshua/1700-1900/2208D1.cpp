#include<bits/stdc++.h>
using namespace std;
using LL=long long;
struct DSU{
    vector<LL> fa;
    LL cnt;//连通块数量
    void init(LL n){
        fa.resize(n+1); 
        cnt=n;  
        for(int i=0;i<=n;i++){
            fa[i]=i;
        }
    }
    LL find(LL x){
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    LL merge(LL x,LL y){
        LL fx=find(x);
        LL fy=find(y);
        if(fx!=fy){
            fa[fx]=fy;
            return 1;
        }else{
            return 0;
        }
    }
};
void solve(){
    LL n;
    cin>>n;
    DSU fa;
    fa.init(n+10);

    vector<vector<LL>> a(n+1,vector<LL>(n+1)),b(n+1,vector<LL>(n+1));

    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            a[i][j+1]=s[j]-'0';
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i][i]==0){
            cout<<'No'<<'\n';
            return;                
        }
        for(int j=1;j<=n;j++){
            b[i][j]=a[i][j];
            if(i==j)b[i][j]=0;
            for(int k=1;k<=n;k++){
                if(k==j||k==i)continue;
                if(a[k][j]==1&&a[i][k]==1){
                    if(a[i][j]==0){
                        cout<<"No"<<'\n';
                        return;
                    }
                    b[i][j]=0;
                }
            }                 

        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j]==0)continue;
            if(!fa.merge(i,j)){
                cout<<"No"<<'\n';
                return;
            }
        }
    }
    set<LL> st;
    for(int i=1;i<=n;i++){
        st.insert(fa.find(i));
    }
    if(st.size()>1){
        cout<<"No"<<'\n';
        return;
    }
    cout<<"Yes"<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(b[i][j])cout<<i<<' '<<j<<'\n';
        }
    }
      
}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    cin>>t;

    while(t--){
        solve();
    }
    return 0;
}