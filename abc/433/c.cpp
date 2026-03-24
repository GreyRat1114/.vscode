#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;

int a[N];
void solve(){
    string s;
    cin>>s;
    int len=s.length();
    if(len==1){
        cout<<0<<'\n';
        return;
    }
    int tag=0;
    for(int i=0;i<len;i++){
        a[i+1]=s[i]-'0';
        
    }
    // for(int i=1;i<=len;i++){
    //     cout<<a[i]<<'\n';
    // }
    int l1=1;
    int l2=0;
    int ans=0;
    for(int i=2;i<=len;i++){
        if(a[i]==a[i-1]){
            l1++;
            // printf("<%d>",i);
        }
        else{
            if(a[i]==a[i-1]+1){
                l2=l1;
                l1=1;
            }
            else{
                l1=1;
                l2=-1;
            }
        }
        if(l1<=l2){
            ans+=1;
            // printf("{%d,%d,%d,%d}",i,l1,l2,a[i]);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}