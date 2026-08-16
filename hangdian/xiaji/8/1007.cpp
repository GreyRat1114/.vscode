#include<bits/stdc++.h>
using namespace std;
using LL=long long;

namespace IO{
    const int S=1<<20;
    char ib[S],ob[S];int ip,il,op;
    inline int gc(){
        if(ip==il)il=fread(ib,1,S,stdin),ip=0;
        return il?ib[ip++]:EOF;
    }
    inline void pc(char c){
        if(op==S)fwrite(ob,1,op,stdout),op=0;
        ob[op++]=c;
    }
    template<class T>
    inline void read(T&x){
        x=0;int c=gc(),f=1;
        while(c!=EOF&&(c<'0'||c>'9'))f=c=='-'?-1:f,c=gc();
        while(c>='0'&&c<='9')x=x*10+c-'0',c=gc();
        if(f<0)x=-x;
    }
    inline void read(string&s){
        s.clear();int c=gc();
        while(c!=EOF&&c<=' ')c=gc();
        while(c!=EOF&&c>' ')s+=c,c=gc();
    }
    inline void read(char&c){
        int x=gc();
        while(x!=EOF&&x<=' ')x=gc();
        c=x;
    }
    template<class T,class...A>
    inline void read(T&x,A&...a){read(x);read(a...);}
    template<class T>
    inline void write(T x,char c='\n'){
        if(x<0)pc('-'),x=-x;
        if(!x)pc('0');
        else{
            char s[50];int n=0;
            while(x)s[n++]=x%10+'0',x/=10;
            while(n)pc(s[--n]);
        }
        if(c)pc(c);
    }
    inline void write(const string&s,char c='\n'){
        for(char x:s)pc(x);
        if(c)pc(c);
    }
    inline void write(const char*s,char c='\n'){
        while(*s)pc(*s++);
        if(c)pc(c);
    }
    inline void write(char x,char c='\n'){
        pc(x);if(c)pc(c);
    }
    struct F{~F(){fwrite(ob,1,op,stdout);}}f;
}
using IO::read;
using IO::write;

vector<vector<LL>> a;
vector<bitset<200>> e;
LL dx[]={-1,0,0,1};
LL dy[]={0,-1,1,0};
LL tot,n,m,k,q,cnt;

void bfs(LL sx,LL sy){
    queue<pair<LL,LL>> q;
    q.push({sx,sy});
    a[sx][sy]=tot;
    while(!q.empty()){
        LL x=q.front().first;
        LL y=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            LL x1=x+dx[i];
            LL y1=y+dy[i];
            if(x1<1||x1>n||y1<1||y1>m)continue;
            if(a[x1][y1]!=0)continue;
            a[x1][y1]=tot;
            q.push({x1,y1});
        }
    }
}
void chuandi(){
    for(int j=1;j<=cnt;j++){
        for(int i=1;i<=cnt;i++){
            if(e[i][j]){
                e[i]|=e[j];
            }
        }
    }
}
void solve(){
    read(n,m,k,q);
    //cin>>n>>m>>k>>q;
    a.assign(n+1,vector<LL>(m+1,0));
    tot=0;
    cnt=0;
    for(int i=1;i<=n;i++){
        string s;
        read(s);
        for(int j=0;j<m;j++){
            if(s[j]=='#')a[i][j+1]=-1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==0){
                tot++;
                bfs(i,j);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<a[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }    
    vector<LL> vis(tot+1,0);
    
    vector<pair<LL,LL>> dir(k+1);
    for(int i=1;i<=k;i++){
        LL x1,y1,x2,y2;
        read(x1,y1,x2,y2);
        //cin>>x1>>y1>>x2>>y2;
        LL u=a[x1][y1];
        LL v=a[x2][y2];
        dir[i]={u,v};
        if(vis[u]==0)vis[u]=++cnt;
        if(vis[v]==0)vis[v]=++cnt;
    }
    e.assign(cnt+1,bitset<200>());
    for(int i=1;i<=k;i++){
        LL u=vis[dir[i].first];
        LL v=vis[dir[i].second];
        //printf("{%lld,%lld}",u,v);
        e[u][v]=1;
    }
    chuandi();
    for(int i=1;i<=q;i++){
        LL x1,y1,x2,y2;
        read(x1,y1,x2,y2);
        //cin>>x1>>y1>>x2>>y2;
        if(a[x1][y1]==a[x2][y2]){
            write(1);
            //cout<<1<<'\n';
            continue;
        }
        LL u=vis[a[x1][y1]];
        LL v=vis[a[x2][y2]];
        if(e[u][v]){
            write(1);
            //cout<<1<<'\n';
        }else{
            write(0);
           // cout<<0<<'\n';
        }
    }

}
int main(){
    //ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t=1;
    read(t);
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}