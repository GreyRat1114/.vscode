#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL a[N];
LL b[N];
void solve(){
    LL n,m,l;
    cin>>n>>m>>l;
    LL c;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>c;
        a[i]=a[i-1]+c;
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    LL p2=0;    
    LL p3=0;
    int j=0;
    b[0]=0;
    for(int i=0;i<=n;i++){
        p2=p2+b[i];
        if(p2>=a[j]){
            while(a[j]<=p2){
                j++;
                if(j>n){
                    cout<<"NO"<<'\n';
                    return;
                }
            }
            //printf("{%d}",j);
        }
        p3=p2+l;
        //printf("{%d,%d,%d}",p2,p3,a[j]);
        if(p3>a[j]){
            cout<<"YES"<<'\n';
            return;
        }

    }
    cout<<"NO"<<'\n';
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}