#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL a[N];
void solve(){
    map<LL,int> tr;
    int n;
    cin>>n;
    LL maxn=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        tr[a[i]]++;
    }
    int tag;
    if(tr[maxn]%2==0){
        tag=0;
    }else{
        tag=1;
    }
    for(int i=1;i<=n;i++){
        if(tag){
            if(a[i]==maxn){
                cout<<1;
            }else{
                cout<<0;
            }            
        }else{
            if(a[i]==maxn){
                cout<<0;
            }else{
                cout<<1;
            }
        }
    }
    cout<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}