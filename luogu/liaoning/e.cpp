#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define mp make_pair
using LL=long long;
LL a[N];
LL mx[N];
int n;
LL get_max(LL x){
    LL maxn=0;
    while(x!=0){
        LL y=x%10;
        maxn=max(maxn,y);
        x=x/10;
    }
    return maxn;

}
vector<pair<int,int>> q(N+10);
int top;
bool vis[N];
LL cnt[100];
LL work(LL op){
    LL s=0;
    for(int j=1;j<=top;j++){
        memset(cnt,0,sizeof(cnt));
        LL x=0;
        int l,r;
        cnt[0]++;
        l=q[j].first;
        r=q[j].second; 
        for(int i=l;i<=r;i++){
            x+=a[i];
            s+=cnt[x%op];
            cnt[x%op]++;
        }        
    }
    top=0;
    for(int i=1;i<=n;i++){
        if(mx[i]==op){
            vis[i]=true;
        }
    }
    for(int l=1,r;l<=n;l++){
        if(vis[l]){
            continue;
        }
        r=l;
        while(!vis[r+1] && r < n){
            r++;
        }
        top++;
        q[top]=mp(l,r);
        l=r;
    }

    for(int j=1;j<=top;j++){
        memset(cnt,0,sizeof(cnt));
        LL x=0;
        int l,r;
        l=q[j].first;
        r=q[j].second; 
        cnt[0]=1;
        for(int i=l;i<=r;i++){
            x+=a[i];
            s-=cnt[x%op];
            cnt[x%op]++;        
        }                
    }
    return s;
}
void solve(){
    top=0;
    memset(cnt,0,sizeof(cnt));
    memset(vis,false,sizeof(vis));
    cin>>n;
    LL x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx[i]=get_max(a[i]);
    }
    
    LL ans=0;
    top++;
    q[top]=mp(1,n);
    for(int i=9;i>=1;i--){
        
        ans+=work(i);

    }
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}