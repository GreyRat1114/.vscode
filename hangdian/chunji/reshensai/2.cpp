#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=1e7+5;
LL fa[N];
void init(){
    for(int i=0;i<=N;i++){
        fa[i]=i;
    }
}
LL find(LL x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(LL x,LL y){
    //printf("<%lld,%lld>");
    LL fx=find(x);
    LL fy=find(y);
    if(fx!=fy){
        fa[fy]=fx;     
        //printf("<%lld,%lld>",fx,fy);
    }
}
void solve(){
    LL n;
    cin>>n;
    init();
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    LL m;
    cin>>m;
    vector<array<LL,3>> op(m+1);
    LL x,y,z;
    LL tot=n;
    for(int i=1;i<=m;i++){
        cin>>x;
        op[i][0]=x;
        if(x==1){
            cin>>y>>z;
            op[i][1]=y;
            op[i][2]=z;
        }else if(x==2){
            cin>>y;
            tot++;
            a.push_back(y);
            op[i][1]=y;         
        }else{
            cin>>y;
            op[i][1]=y;
        }
    }
    // for(int i=1;i<=tot;i++){
    //     printf("<%lld>",a[i]);
    // }
    stack<array<LL,3>> stk;
    vector<LL> ans(tot+1);
    LL siz=tot;
    for(int i=m;i>=1;i--){
        if(op[i][0]==1){
            stk.push(op[i]);
        }else if(op[i][0]==2){
            while(!stk.empty()){
                x=stk.top()[0];
                y=stk.top()[1];
                z=stk.top()[2];
                //printf("{%lld,%lld,%lld}",x,y,z);
                stk.pop();
                if(x==1){
                    merge(z,y);
                }else if(x==3){
                    merge(0,y);
                }
            }
            ans[tot]=find(a[tot]);
            //printf("{%lld}",fa[a[tot]]);
            tot--;
        }else{
            stk.push(op[i]);
        }
    }
    while(!stk.empty()){
        x=stk.top()[0];
        y=stk.top()[1];
        z=stk.top()[2];     
        stk.pop();
        if(x==1){
            merge(z,y);
        }else if(x==3){
            merge(0,y);
        }        
        //printf("{%lld}",fa[a[tot]]);
        tot--;        
    }
    for(int i=1;i<=n;i++){
        ans[i]=find(a[i]);
    }
    //cout<<'\n';
    for(int i=1;i<=siz;i++){
        if(ans[i]==0){
            continue;
        }
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}
int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);    
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}