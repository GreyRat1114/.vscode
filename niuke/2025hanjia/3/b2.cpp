#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
map<LL,LL> tr;
LL a[N];
bool isprim(LL x){
    for(LL i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
void solve(){
    tr.clear();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        LL x=a[i];
        if(a[i]==1){
            continue;
        }
        if(isprim(x)){
            if(tr.count(x)){
                cout<<a[tr[x]]<<' '<<a[i]<<'\n';
                return;
            }else{
                tr[x]=i;
            }            
            continue;
        }
        for(LL j=2;j*j<=x;j++){
            if(x%j==0){
                while(x%j==0){
                    x=x/j;
                }
                if(tr.count(j)){
                    cout<<a[tr[j]]<<' '<<a[i]<<'\n';
                    return;
                }else{
                    tr[j]=i;
                }
            }
        }
        if(tr.count(x)&&tr[x]!=i){
            cout<<a[tr[x]]<<' '<<a[i]<<'\n';
            return;
        }else{
            tr[x]=i;
        }             
    }
    cout<<-1<<'\n';
}
int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}