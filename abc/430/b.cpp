// B - Count Subgrid
#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N][N];
struct node{
    int b[N][N];
}c[20005];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='#'){
                a[i][j]=1;
            }
            else{
                a[i][j]=0;
            }
        }
    }
    int tot=0;
    for(int i=0;i<=n-m;i++){
        for(int j=0;j<=n-m;j++){
            int tag2=1;                    
            for(int cnt=1;cnt<=tot;cnt++){
                int tag=1;
                for(int i1=0;i1<m;i1++){
                    for(int j1=0;j1<m;j1++){
                        if(a[i1+i][j1+j]!=c[cnt].b[i1][j1]){
                            tag=0;
                        }
                    }
                }           
                if(tag){
                    tag2=0;
                }       

            }
            if(tag2){
                tot++;
                for(int i1=0;i1<m;i1++){
                    for(int j1=0;j1<m;j1++){
                        c[tot].b[i1][j1]=a[i1+i][j1+j];
                    }
                }                        
            }            
  
        }
    }    
    cout<<tot<<'\n';
}
int main(){
    solve();
    return 0;
}