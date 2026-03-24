#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
using LL=long long;
LL a[N];
LL s[N];
int n,q;
int find(LL x){
    int l=1;
    int r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(x==a[mid]){
            return mid;
        }
        if(a[mid]<x){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return l-1;
}
int find2(LL x){
    int l=1;
    int r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(x==s[mid]){
            return mid;
        }
        if(s[mid]<x){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return l-1;
}
void solve(){
    memset(s,0,sizeof(s));
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=a[i]-a[i-1]-1+s[i-1];
    }
    LL x,y,z;
    int p1,p2;
    LL ans;
    for(int i=1;i<=q;i++){    
        cin>>x>>y;
        p1=find(x);
        if(x==a[p1]){
            z=s[p1]+y;
            p2=find2(z);
            //printf("{%d %d}",p1,p2);
            if(s[p2]==z){
                ans=a[p2]-1;
            }else{
                ans=a[p2]+z-s[p2];
            }
        }else{
            z=s[p1]+y+(x-a[p1]-1);
            p2=find2(z);
            //printf("{%d %d}",p1,p2);
            if(s[p2]==z){
                ans=a[p2]-1;
            }else{
                ans=a[p2]+z-s[p2];
            }      
        }
        cout<<ans<<'\n'; 
        // cout<<p2<<'\n';
    }
    
    // cout<<'\n';
}
int main(){
    solve();
    return 0;
}