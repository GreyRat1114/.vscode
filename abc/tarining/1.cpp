// D - Gathering Children
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

string s;
bool vis[N];
int ans[N];

void solve(){
    memset(vis,false,sizeof(vis));
    memset(ans,0,sizeof(ans));
    cin>>s;
    int len=s.length();
    int p1=0;
    int p2=0;
    int mx=0;
    for(int i=0;i<len-1;i++){
        if(s[i+1]=='L'&&s[i]=='R'){
            vis[i]=true;
            vis[i+1]=true;
            mx=max(mx,i-p1-2);
            p1=i;
            int l=i-1;;
            int r=i+2;
            int s1=0;
            int s2=0;
            int tag=1;
            while(1){
                if(s[r]=='R'&&s[min(r+1,len-1)]=='L'){
                    break;
                }
                if(s[r]=='L'){
                    int k=i+tag;
                    ans[k]++;
                    // printf("<%d,%d>",ans[i],ans[i+1]);
                }
                r++;
                if(r>=len){
                    break;
                }       
                tag++;
                tag=tag%2;         
            }
            tag=0;
            while(1){
                
                if(s[max(l-1,0)]=='R'&&s[l]=='L'){
                    break;
                }
                if(s[l]=='R'){
                    int k=i+tag;
                    ans[k]++;
                    // printf("<%d,%d>",ans[i],ans[i+1]);
                }
                l--;
                if(l<0){
                    break;
                }
                tag++;
                tag=tag%2;
            }           

            // printf("{%d,%d,%d}\n",i,s1,s2); 
        }
    }
    // cout<<mx<<'\n';
    for(int i=0;i<len;i++){
        if(vis[i]&&vis[i+1]){
            cout<<ans[i+1]+1<<' '<<ans[i]+1<<' ';
            i++;
        }
        else{
            cout<<0<<' ';
        }
    }
    // for(int i=0;i<len;i++){
    //     cout<<ans[i]<<' ';
    // }
}
int main(){
    solve();
    return 0;

}