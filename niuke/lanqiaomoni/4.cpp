#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=998244353;
const int N=2e5+5;


void solve(){
    LL n;
    string s;
    cin>>s;
    n=s.size();
    int tag=0;
    // LL l=0;
    // LL r=1;
    // while(s[l]!='('){
    //     l++;
    // }
    // r=l+1;
    // while(r<n){
        
    // }
    LL x=0;
    LL pt1=0;
    LL ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            tag=1;
            x=0;
            pt1=0;
            continue;
        }else if(s[i]==')'){
            pt1+=x;
            //printf("{%lld,%lld}",i,pt1);
            x=0;            
            tag=0;
            ans=max(pt1,ans);
            //printf("{%lld}",pt1);
            pt1=0;
            continue;
        }
        if(tag){
            if(s[i]>='0'&&s[i]<='9'){
                x=x*10+(s[i]-'0');
            }else if(s[i]=='.'){
                pt1+=x;
                //printf("{%lld,%lld}",i,pt1);
                x=0;
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}