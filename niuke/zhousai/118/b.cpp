#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
using LL=long long;
void solve(){
    int n;
    cin>>n;
    int x,y;
    vector<pair<int,int>> p(n+10);
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        p[i]={x,y};
    }
    LL maxn=-1;
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            x1=p[i].first;
            y1=p[i].second;
            x2=p[j].first;
            y2=p[j].second;            
            if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)>maxn){
                x3=x1;
                y3=y1;
                x4=x2;
                y4=y2;
                maxn=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
            }
        }
    }
    cout<<x3<<' '<<y3<<' '<<x4<<' '<<y4<<'\n';
}
int main(){
    solve();
    return 0;
}