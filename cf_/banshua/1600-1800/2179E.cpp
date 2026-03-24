#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n,x,y;
    cin>>n>>x>>y;
    vector<LL> p(n+1),a(n+1),b(n+1);
    
    string s;
    cin>>s;
    int tag0=1;
    int tag1=1;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    for(int i=1;i<=n;i++){
        if(s[i-1]=='1'){
            y-=p[i]/2+1;
            b[i]=p[i]/2+1;
            a[i]=p[i]-b[i];
            x-=a[i];
            tag0=0;
        }else{
            x-=p[i]/2+1;
            a[i]=p[i]/2+1;
            b[i]=p[i]-a[i];
            y-=b[i];
            tag1=0;
        }

    }
    // for(int i=1;i<=n;i++){
    //     printf("{%d %d}",a[i],b[i]);
    // }
    //printf("{%d,%d}",x,y);
    if(x>=0&&y>=0){
        if(tag1){
            LL s0=0;
            for(int i=1;i<=n;i++){
                s0+=b[i]-a[i]-1;
            }
            x-=s0;
            if(x>0){
                if(y>=x){
                    cout<<"YES"<<'\n';
                }else{
                    cout<<"NO"<<'\n';
                }
                
            }else{
                cout<<"YES"<<'\n';
            }
        }else if(tag0){
            LL s1=0;
            for(int i=1;i<=n;i++){
                s1+=a[i]-b[i]-1;
            }
            y-=s1;
            if(y>0){
                if(x>=y){
                    cout<<"YES"<<'\n';
                }else{
                    cout<<"NO"<<'\n';
                }
                
            }else{
                cout<<"YES"<<'\n';
            }
        }else{
            cout<<"YES"<<'\n';
        }
        return;
    }
    if(x<0&&y>=0){
        LL s0=0;
        for(int i=1;i<=n;i++){
            if(b[i]>a[i]){
                s0+=a[i];
            }
        }
        if(s0>=abs(x)&&y-abs(x)>=0){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
    }else if(x>=0&&y<0){
        LL s1=0;
        for(int i=1;i<=n;i++){
            if(a[i]>b[i]){
                s1+=b[i];
            }
        }
        if(s1>=abs(y)&&x-abs(y)>=0){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }  
    }else{
        cout<<"NO"<<'\n';
    }


}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}