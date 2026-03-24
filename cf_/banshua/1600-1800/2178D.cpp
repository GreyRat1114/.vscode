#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define mp make_pair

void solve(){
    LL n,m;
    cin>>n>>m;
    vector<pair<LL,LL>> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin()+1,a.end());
    // for(int i=1;i<=n;i++){
    //     printf("{%lld}",a[i].first);
    // }
    if(m>n/2){
        cout<<-1<<'\n';
        return;
    }
    queue<pair<LL,LL>> op;
    if(m==0){
        for(int i=1;i<=n-1;i++){
            op.push(mp(a[i].second,a[n].second));
            a[n].first-=a[i].first;
            if(a[n].first<=a[n-1].first&&i!=n-1){
                for(int j=i+1;j<=n-1;j++){
                    op.push(mp(a[j].second,a[j+1].second));
                }
                int k=op.size();
                cout<<k<<'\n';
                while(!op.empty()){
                    cout<<op.front().first<<' '<<op.front().second<<'\n';
                    op.pop();
                } 
                return;                  
            }
        }
        cout<<-1<<'\n';
    }else{
        for(int i=1;i<=n-2*m;i++){
            op.push(mp(a[i].second,a[i+1].second));
        }
        for(int i=n-m+1;i<=n;i++){
            op.push(mp(a[i].second,a[i-m].second));
        }
        int k=op.size();
        cout<<k<<'\n';
        while(!op.empty()){
            cout<<op.front().first<<' '<<op.front().second<<'\n';
            op.pop();
        }
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