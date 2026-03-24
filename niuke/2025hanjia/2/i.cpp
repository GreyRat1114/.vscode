#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
using LL=long long;
#define mp make_pair
const LL mod=998244353;
LL a[N];
char c[N];
void solve(){
    int n,m;
    cin>>n>>m;
    int s0=0;
    int s1=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            c[i*m+j]=s[j-1];
            if(s[j-1]=='0'){
                s0++;
            }else{
                s1++;
            }
        }
    }
    if(s0==1){
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                if(c[i*m+j]=='0'){
                    cout<<'N';
                }else{
                    cout<<'Y';
                }
            }
            cout<<'\n';
        }        
    }else if(s1==1){
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                if(c[i*m+j]=='1'){
                    cout<<'N';
                }else{
                    cout<<'Y';
                }
            }
            cout<<'\n';
        }        
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<'Y';
            }
            cout<<'\n';
        }          
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