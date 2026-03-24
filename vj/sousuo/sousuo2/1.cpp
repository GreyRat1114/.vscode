#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
char op[]={'d','r','l','u'};
map<vector<vector<int>>,string> tr;
vector<vector<int>> asw(4,vector<int>(4,0));
string ans;
#define mp make_pair
void check(const vector<vector<int>> &vec,int &x,int &y){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(vec[i][j]==0){
                x=i;
                y=j;
                return;
            }
        }
    }
}
void bfs(int x0,int y0){
    queue<pair<vector<vector<int>>,string>> q;
    string s="";
    vector<vector<int>> vec(4,vector<int>(4,0));
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            vec[i][j]=asw[i][j];
        }
    }
    q.push(mp(vec,s));
    tr[vec]=s;
    while(!q.empty()){
        vector<vector<int>> arr=q.front().first;
        string str=q.front().second;
        q.pop();
        int x,y;
        check(arr,x,y);
        //printf("{%d %d}",x,y);
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1<1||x1>3||y1<1||y1>3){
                continue;
            }
            vector<vector<int>> arr1=arr;

            int tmp=arr1[x][y];
            arr1[x][y]=arr1[x1][y1];
            arr1[x1][y1]=tmp;
            if(tr.count(arr1)){
                continue;
            }
            string s2=str+op[i];
            tr[arr1]=s2;
            q.push(mp(arr1,s2));
        }
    }
}
void solve(){
    int cnt=0;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cnt++;
            asw[i][j]=cnt%9;
        }
    }
    tr.clear();
    bfs(3,3);
    int x,y;
    char z;
    while(cin>>z){
        if(z=='x'){
            z='0';
        }
        vector<vector<int>> a(4,vector<int>(4,0));
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(i==1&&j==1){
                    a[1][1]=z-'0';
                    continue;
                }
                char c;
                cin>>c;
                if(c=='x'){
                    a[i][j]=0;
                    x=i;
                    y=j;
                }else{
                    int x=c-'0';
                    a[i][j]=x;                
                }
            }
        }
        if(tr.count(a)){
            cout<<tr[a]<<'\n';
        }else{
            cout<<"ullddrurdllurdruldr"<<'\n';
        }
    }

    // for(int i=1;i<=3;i++){
    //     for(int j=1;j<=3;j++){
    //         cout<<asw[i][j];
    //     }
    //     cout<<'\n';
    // }
}
int main(){
    solve();
    return 0;
}