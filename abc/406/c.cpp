#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
LL p[N];
LL d[N];
void solve(){

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    if(n<=3){
        cout<<0<<'\n';
        return;
    }
    d[1]=p[1];
    for(int i=2;i<=n;i++){
        d[i]=p[i]-p[i-1];
        // printf("%lld ",d[i]);
    }
    int tag=0;
    LL s1=0,s2=0;
    int pos;
    LL ans=0;
    for(int i=2;i<=n;){
        // printf("{%d,%d,%lld}",i,pos,ans);
        pos=0;
        if(d[i]<=0){
            i++;
            continue;
        }
        if(d[i]>0){
            s1=0;
            s2=0;
            // printf("[%d]",i);
            while(d[i]>0&&i<=n){
                s1++;
                i++;
            }
            
            if(i>n){
                cout<<ans<<'\n';
                
                return;
            }
            
            while(d[i]<0&&i<=n){
                i++;
            }
            if(i>n){
                cout<<ans<<'\n';
                // printf("{**}");
                return;
            }
            if(d[i]>0&&i<=n){
                pos=i;
            }
            while(d[i]>0&&i<=n){
                i++;
                s2++;
            }
            ans+=s1*s2;
            // printf("<%d,%d>",s1,s2);
        }
        i=pos;
        // printf("{%d}",pos);
    }      
    
    cout<<ans<<'\n';

}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}