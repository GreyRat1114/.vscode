// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+5;
// struct node{
//     int x;
//     int y;
// };
// char a[N][N];
// char b[N][N];
// int dx[]={-1,0,0,1};
// int dy[]={0,-1,1,0};
// bool vis[N][N];
// int pre[N][N];
// int h,w;

// node bfs(int x,int y){
//     memset(vis,false,sizeof(vis));
//     queue<pair<int,int>> q;
//     q.push({x,y});
//     vis[x][y]=true;
//     while(!q.empty()){
//         int x1=q.front().first;
//         int y1=q.front().second;
//         q.pop();
//         for(int i=0;i<4;i++){
//             int x2=x1+dx[i];
//             int y2=y1+dy[i];
//             if(x2<1||x2>h||y2<1||y2>w||a[x2][y2]=='#'||vis[x2][y2]){
//                 continue;
//             }
//             pre[x2][y2]=i;
//             if(a[x2][y2]=='E'){
//                 //printf("(%d,%d)",x2,y2);
//                 return {x2,y2};
//             }
//             vis[x2][y2]=true;
//             q.push({x2,y2});
//         }
//     }
//     return {0,0};
// }
// void solve(){
//     cin>>h>>w;
//     string s;
//     for(int i=1;i<=h;i++){
//         cin>>s;
//         for(int j=1;j<=w;j++){
//             a[i][j]=s[j-1];
//             b[i][j]=s[j-1];
//         }
//     }
    
//     for(int i=1;i<=h;i++){
//         for(int j=1;j<=w;j++){
//             if(b[i][j]=='.'){
//                 //printf("{%d %d}",i,j);
//                 node nd=bfs(i,j);
//                 int x=nd.x;
//                 int y=nd.y;
//                 if(x==0&&y==0){
//                     continue;
//                 }
//                 while(!(x==i&&y==j)){
                    
//                     int x1=x-dx[pre[x][y]];
//                     int y1=y-dy[pre[x][y]];                         
//                     if(pre[x][y]==0){
//                         b[x1][y1]='^';

//                     }else if(pre[x][y]==1){
//                         b[x1][y1]='<';

//                     }else if(pre[x][y]==2){
//                         b[x1][y1]='>';

//                     }else if(pre[x][y]==3){
//                         b[x1][y1]='v';

//                     }
//                     x=x1;
//                     y=y1;
//                     //printf("<%d,%d>",x,y);

//                 }
//             }

//         }
//     }
//     for(int i=1;i<=h;i++){
        
//         for(int j=1;j<=w;j++){
//             cout<<b[i][j];
//         }
//         cout<<'\n';
//     }
// }
// int main(){
//     solve();
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct node{
    int x;
    int y;
};
char a[N][N];
char b[N][N];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
char da[]={'v','>','<','^'};
bool vis[N][N];
int h,w;
queue<pair<int,int>> q;
void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1<1||y1<1||x1>h||y1>w){
                continue;
            }
            if(vis[x1][y1]||a[x1][y1]=='#'){
                continue;
            }
            q.push({x1,y1});
            vis[x1][y1]=true;
            b[x1][y1]=da[i];
        }
    }
}
void solve(){
    memset(vis,false,sizeof(vis));
    cin>>h>>w;
    string s;
    for(int i=1;i<=h;i++){
        cin>>s;
        for(int j=1;j<=w;j++){
            a[i][j]=s[j-1];
            b[i][j]=s[j-1];
        }
    }
    
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(a[i][j]=='E'){
                q.push({i,j});
                vis[i][j]=true;
            }

        }
    }
    bfs();
    for(int i=1;i<=h;i++){
        
        for(int j=1;j<=w;j++){
            cout<<b[i][j];
        }
        cout<<'\n';
    }
}
int main(){
    solve();
    return 0;
}