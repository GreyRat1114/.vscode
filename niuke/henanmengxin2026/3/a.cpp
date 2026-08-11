#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const LL N=1e7+10;
using i128=__int128_t;
struct node{
    LL h,d;
};
bool cmp1(node a,node b){
    if(a.h==b.h)return a.d>b.d; 
    return a.h<b.h;    
}
bool cmp2(node a,node b){
    if(a.d+a.h==b.d+b.h)return a.h>b.h; 
    return a.d+a.h>b.d+b.h;    
}
void solve(){
    LL n;
    cin>>n;
    vector<node> a(n+1);
    vector<node> fi,se;
    for(int i=1;i<=n;i++){
        cin>>a[i].h>>a[i].d;
        if(a[i].d>0){
            fi.push_back(a[i]);
        }else{
            se.push_back(a[i]);
        }
    }
    sort(fi.begin(),fi.end(),cmp1);
    sort(se.begin(),se.end(),cmp2);
    i128 l=0;
    i128 r=9e18;
    i128 ans=0;
    while(l<=r){
        i128 mid=(l+r)/2;
        LL tag=1;
        i128 cur=mid;
        for(int i=0;i<fi.size();i++){
            if(fi[i].h>cur){
                tag=0;
                break;
            }
            cur+=fi[i].d;
        }        
        for(int i=0;i<se.size();i++){
            if(se[i].h>cur){
                tag=0;
                break;
            }
            cur+=se[i].d;
        }
        if(tag){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    unsigned long long res=ans;
    cout<<res<<'\n';
    
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