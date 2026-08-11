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
    std::vector<int>b(n);
    for(int i=0;i<n;i++){
        b[i]=mex(a[i],a[(i+1)%n],a[(i+n-1)%n]);
      // std::cout<<b[i]<<'\n';
    }
    std::vector<int>c;
    c=b;
    std::vector<std::vector<int>>d;
    d.push_back(c);
    int cnt=1;
    if(cnt==k){
        for(int i=0;i<n;i++){
             std::cout<<b[i]<<" ";
        }
            return ;
        }
    int pos;
    while(1){
        
        ++cnt;
         for(int i=0;i<n;i++){
          b[i]=mex(c[i],c[(i+1)%n],c[(i+n-1)%n]);
        }
        if(cnt==k){
            for(int i=0;i<n;i++){
                std::cout<<b[i]<<" ";
            }
            return ;
        }
        bool vis=false;
        for(int j=d.size()-1;j>=0;j--){
            bool flag=true;
            for(int i=0;i<n;i++){
                if(b[i]!=d[j][i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                pos=j;
                vis=true;
                break;
            }
        }
        if(vis){
            cnt--;
            break;
        }
        c=b;
        d.push_back(c);
    }
    k-=pos;
    int len=cnt-pos+1;
    k%=len;
    for(int i=0;i<n;i++){
        std::cout<<d[k+pos][i]<<" ";
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