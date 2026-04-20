#include<bits/stdc++.h>
using namespace std;
using LL=long long;
void solve(){
    LL n;
    cin>>n;
    vector<vector<LL>> a(n+1,vector<LL>(n+1,0));
    LL tot=0;
    LL px,py;
    vector<pair<LL,LL>> q;
    int tag=0;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            a[i][j+1]=(s[j]=='.'?0:1);
            if(a[i][j+1]){
                tot++;
                tag=1;
                q.push_back(make_pair(i,j+1));
            }
        }
    }
    if(n==1){
        cout<<"YES"<<'\n';
        return;
    }
    if(tag==0){
        cout<<"YES"<<'\n';
        return;
    }

    for (int sx : {-1, 1}) {
        for (int sy : {-1, 1}) {
            int mn = (int)1e9, mx = -(int)1e9;
            for (auto [x, y] : q) {
                int v = sx * x + sy * y;
                mn = min(mn, v);
                mx = max(mx, v);
            }
            if (mx - mn <= 1) {
                cout << "YES\n";
                return;
            }
        }
    }

    LL minx=1e9,maxx=0;
    LL miny=1e9,maxy=0;
    for(auto x:q){
        px=x.first;
        py=x.second;
        minx=min(minx,px);
        maxx=max(maxx,px);
        miny=min(miny,py);
        maxy=max(maxy,py);
    }
    if(maxx-minx<2&&maxy-miny<2){
        cout<<"YES"<<'\n';
    }else{
        cout<<"NO"<<'\n';
    }
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}