#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
int mex(int x,int y,int z){
    std::set<int>s;
    s.insert(x),s.insert(y),s.insert(z);
    for(int i=0;i<4;i++){
        if(s.find(i)==s.end()){
            return i;
        }
    }
    return 0;
}
void solve(){
    LL n,k;
    cin>>n>>k;
    vector<LL>a(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i];
    }
    vector<LL> pre(n),nxt(n);
    auto work=[&]()->LL{
        swap(pre,a);
        swap(a,nxt); 
        for(int i=0;i<n;i++){
            nxt[i]=mex(a[i],a[(i+1)%n],a[(i-1+n)%n]);
        }   
        LL tag=1;
        for(int i=0;i<n;i++){
            if(nxt[i]!=pre[i]){
                tag=0;
                break;
            }
        }             
        return tag;  
    };
    for(int i=0;i<n;i++){
        nxt[i]=mex(a[i],a[(i+1)%n],a[(i-1+n)%n]);
    }
    if(k==1){
        for(int i=0;i<n;i++){
            cout<<nxt[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    LL cnt=1;
    while(1){
        cnt++;
        LL tag=work();
        if(tag){
            k-=cnt;
            break;
        }
    }
    if(k%2==0){
        for(int i=0;i<n;i++){
            cout<<nxt[i]<<' ';
        }
        cout<<'\n';
    }else{
        for(int i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}