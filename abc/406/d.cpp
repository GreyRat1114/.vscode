#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
using LL=long long;
struct node{
    int x,y;
}a[N];
vector<int> qx[N];
vector<int> qy[N];  
void solve(){

    int h,w,n;

    cin>>h>>w>>n;
    vector<int> sx(h+10,0);
    vector<int> sy(w+10,0);    
 
    vector<int> vis(n+10,1); 
    int x,y;
    int dx=0,dy=0;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        a[i].x=x;
        a[i].y=y;
        sx[x]++;
        sy[y]++;
        qx[x].push_back(i);
        qy[y].push_back(i);
    }
    int q;
    cin>>q;
    int op,z;
    for(int i=1;i<=q;i++){
        cin>>op>>z;
        if(op==1){
            if(sx[z]==0){
                cout<<0<<'\n';
            }
            else{
                cout<<sx[z]<<'\n';
                for(int j:qx[z]){
                    // printf("{%d}",j);
                    int b=a[j].y;
                    if(vis[j]){
                        sx[z]--;
                        sy[b]--;
                        // printf("<%d,%d>",b,sy[b]);
                        vis[j]=0;
                    }
                    else{
                        continue;
                    }
                }        
            }
        }
        else if(op==2){
            if(sy[z]==0){
                cout<<0<<'\n';
            }
            else{
                cout<<sy[z]<<'\n';
                for(int j:qy[z]){
                    int b=a[j].x;
                    if(vis[j]){
                        sx[b]--;
                        sy[z]--;
                        vis[j]=0;
                    }
                    else{
                        continue;
                    }
                }                     
            }

        }
    }

}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}