// C - Truck Driver
#include<bits/stdc++.h>
using namespace std;
const int N=15;
using LL=long long;
int a[N][N];

void solve(){
    string s;
    int n,a,b;
    cin>>n>>a>>b;
    cin>>s;    
    int s1=0;
    int s2=0;
    LL ans=0;
    int l=0;
    int r=0;
    for(r=0;r<n;r++){
        
        if(s[r]=='b'){
            s2++;
        }
        else{
            s1++;
        }        
        if(s2<b&&s1>=a){
            ans+=s1-a;
        }        
        while(s1<a&&r<n){
            if(s[r]=='a'){
                s1++;
            }
            else{
                s2++;
            }
            r++;
            printf("{%d %d}",s1,s2);
        }        
        if(r>n){
            break;
        }     
        while(s2>=b&&l<=r){
            if(s[l]=='b'){
                s2--;
            }
            else{
                s1--;
            }
            l++;
        }             
    }
    cout<<ans<<'\n';
}
int main(){
    solve();
    return 0;
}