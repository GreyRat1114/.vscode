#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
void solve(){
    string s;
    cin>>s;
    LL n=s.size();
    string s1(n+1,' '),s2(n+1,' ');
    for(int i=0;i<n;i++){
        if(i%2==0){
            s1[i]='a';
        }else{
            s1[i]='b';
        }
    }
    for(int i=0;i<n;i++){
        if(i%2==0){
            s2[i]='b';
        }else{
            s2[i]='a';
        }
    }    
    s1[n]=1;
    s2[n]=1;
    s[n]=1;
    int tag=0;
    LL cnt1=0;
    LL ans1=1;
    LL ans2=1;
    for(int i=0;i<=n;i++){
        if(s[i]!=s1[i]&&tag==0){
            tag=1;
        }
        if(s[i]==s1[i]&&tag){
            //printf("{%lld}",i);
            tag=0;
            cnt1++;
        }
    }
    if(cnt1>1){
        ans1=0;
    }
    
    LL cnt2=0;
    tag=0;
    for(int i=0;i<=n;i++){
        if(s[i]!=s2[i]&&tag==0){
            tag=1;
        }
        if(s[i]==s2[i]&&tag){
            tag=0;
            cnt2++;
        }
    }    
    if(cnt2>1){
        ans2=0;
    }
    //printf("{%lld,%lld}",cnt1,cnt2);
    if(ans1||ans2){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}