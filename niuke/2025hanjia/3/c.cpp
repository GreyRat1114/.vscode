#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
#define mp make_pair
int check(queue<int> &q){
    int c0=0;
    int c1=0;
    while(!q.empty()){
        
        int x=q.front();
        //printf("{%d}",x);
        q.pop();
        if(x==1){
            if(c0){
                c0--;
                c1++;
            }else{
                c1++;
            }
        }else{
            if(c1){
                c1--;
                c0++;
            }else{
                c0++;
            }
        }
    }
    return c0+c1;
}
void solve(){
    LL n;
    cin>>n;
    string s;
    cin>>s;
    queue<int> q1,q2;
    for(int i=0;i<n;i++){
        if(!((s[i]=='1'&&i%2==1)||(s[i]=='0'&&i%2==0))){
            q1.push(s[i]-'0');
        }
        if(!((s[i]=='1'&&i%2==0)||(s[i]=='0'&&i%2==1))){
            q2.push(s[i]-'0');
        }        
    }
    int ans=min(check(q1),check(q2));

    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}