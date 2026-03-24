#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
char op[]={'d','r','l','u'};
int jc[]={0,1,2,6,24,120,720,5040,40320};

#define mp make_pair
string js,ks;
queue<string>qwer;
bool vis[N];
string ans[N];

int cantuo(string s)
{
	int cnt;
	int sum=0;
	for(int i=0;i<8;i++){
		cnt=0;
		for(int j=i+1;j<9;j++)
			if(s[i]>s[j])  
				cnt++;
		sum+=(jc[8-i]*cnt); 
	}
	return sum;
}
void bfs(){
    int jsq=cantuo(js);
    qwer.push(js);
    vis[jsq]=1;
    ans[jsq]="";
    while(!qwer.empty()){
        auto t=qwer.front();
        qwer.pop();
        int q=t.find("x");
        int x=q/3+1;
        int y=q%3+1;
        //printf("{%d %d}",x,y);
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1<1||x1>3||y1<1||y1>3){
                continue;
            }
            auto str=t;
            swap(str[q],str[(x1-1)*3+y1-1]);
            int de=cantuo(str);
            int cs=cantuo(t);
            if(vis[de]){
                continue;
            }            
            vis[de]=1;
            ans[de]=ans[cs];
            ans[de]+=op[i];
            qwer.push(str);
        }
    }
}
void solve(){
    memset(vis,false,sizeof(vis));
    string cs="123456789";
    js="12345678x";
    bfs();
    char c;
    // for(int i=1;i<=50;i++){
    //     cout<<ans[i]<<'\n';
    // }
    while(cin>>c){
        cs[0]=c;
        for(int i=1;i<9;i++){
            cin>>c;
            cs[i]=c;
        }
        int t=cantuo(cs);
        if(vis[t]){
            for(int i=ans[t].size()-1;i>=0;i--){
                cout<<ans[t][i];
            }
            
            cout<<'\n';
        }else{
            cout<<"unsolvable"<<'\n';
        }
    }
}
int main(){
    solve();
    return 0;
}//康拓展开