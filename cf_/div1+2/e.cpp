#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    cout<<0<<'\n';
    cout.flush();
    auto check=[&]()->LL{
        LL l=1;
        LL r=(1ll<<n)-1;
        LL ans=1;
        while(l<=r){
            LL mid=(l+r)/2;
            cout<<'Q'<<' '<<mid<<'\n';
            cout.flush();
            LL a;
            cin>>a;
            if(a){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    };
    cout<<'I'<<' '<<0<<'\n';
    LL siz;
    cin>>siz;
    if(siz==1){
        LL pre=1;
        LL ans=0;
        for(LL i=0;i<n;i++){
            cout<<'I'<<' '<<(1ll<<i)<<'\n';
            cout.flush();
            LL s;
            cin>>s;
            if(s!=pre){
                ans|=(1ll<<i);
            }
            pre=s;
        }
        cout<<'A'<<' '<<1<<' '<<ans<<'\n';
        
    }else{
        LL c=check();    
        if(c==(1ll<<n)-1){
            cout<<'I'<<' '<<1<<'\n';
            cout.flush();
            LL s;
            cin>>s;     
            if(s>=3){
                cout<<'A'<<' '<<3<<' '<<c<<'\n';
            }else{
                cout<<'A'<<' '<<2<<' '<<c<<'\n';
            }    
        }else{
            cout<<'I'<<' '<<(1ll<<n)-1<<'\n';
            cout.flush();
            LL s;
            cin>>s;
            cout<<'Q'<<' '<<(1ll<<n)-1<<'\n';
            cout.flush();  
            cin>>s;               
            if(s>=1){
                cout<<'A'<<' '<<2<<' '<<c<<'\n';
            }else{
                cout<<'A'<<' '<<3<<' '<<c<<'\n';
            }                
        }
    }
    cout.flush();
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}