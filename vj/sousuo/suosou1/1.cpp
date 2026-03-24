#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
const int N=10;
#define LL long long
int mp[N];
int n,k;
int cnt;
void dfs(int x,int d,int num){
    for(int i=0;i<=n-1;i++){
        int y=(1<<i);
        if(y&x){
            continue;
        }
        if(y&mp[d]){
            // printf("{%d %d %d}",x,y,d);
            if(num==1&&d<=n){
                cnt++;
                continue;
            }           
            if(d+1>n){
                continue;
            }
            dfs(x^y,d+1,num-1);    
        }

    }
    if(d+1<=n){
        dfs(x,d+1,num);
    }        
}
void solve(){
    cin>>n>>k;
    while(n!=-1&&k!=-1){
        cnt=0;
        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            mp[i]=0;
            for(int j=0;j<n;j++){
                if(s[j]=='#'){
                    mp[i]=mp[i]^(1<<(n-j-1));
                }
            }
            // cout<<mp[i]<<'\n';
        }
        dfs(0,1,k);
        cout<<cnt<<'\n';
        cin>>n>>k;
    }
}
int main(){
    solve();
    return 0;
}