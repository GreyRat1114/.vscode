#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL h,w;
    cin>>h>>w;
    vector<string> a(h+1);
    string s;
    for(int i=0;i<h;i++){
        cin>>a[i];
    }
    LL ans=0;
    for(int len1=1;len1<=h;len1++){
        for(int len2=1;len2<=w;len2++){
            for(int x=0;x+len1-1<h;x++){
                for(int y=0;y+len2-1<w;y++){
                    LL tag=1;
                    for(int i=x;i<=x+len1-1;i++){
                        for(int j=y;j<=y+len2-1;j++){
                            if(a[i][j]!=a[x+x+len1-1-i][y+y+len2-1-j]){
                                tag=0;
                            }
                        }
                    }       
                    if(tag)ans++;             
                }
                
            }

        }
    }
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}