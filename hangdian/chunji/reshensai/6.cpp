#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define lc u<<1
#define rc u<<1|1
#define ll llong
#define rl rlong
#define ml t
#define len siz1
#define lc1 ld
#define rc1 rd
const int N=2e5+5;
struct node{
    LL l,r;
    LL siz1=0;
    LL rd=0;
    LL ld=0;
    LL rlong=0;
    LL llong=0;
    LL t=0;
    LL x=0;//f[]的值
    LL add=0;
}tr[N*4];
LL a[N];
LL f[N];
void pushup(int p)
{
    tr[p].lc1=tr[p<<1].lc1==0?tr[p<<1|1].lc1:tr[p<<1].lc1;
	tr[p].rc1=tr[p<<1|1].rc1==0?tr[p<<1].rc1:tr[p<<1|1].rc1;
	tr[p].ml=max(tr[p<<1].ml,tr[p<<1|1].ml);
	if(tr[p<<1].rc1==tr[p<<1|1].lc1)tr[p].ml=max(tr[p].ml,tr[p<<1].rl+tr[p<<1|1].ll);
	tr[p].len=tr[p<<1].len+tr[p<<1|1].len;
	if((tr[p<<1].lc1==tr[p<<1|1].lc1&&tr[p<<1].ll==tr[p<<1].len)||tr[p<<1].len==0)
	{
		tr[p].ll=tr[p<<1].len+tr[p<<1|1].ll;
	}
	else
		tr[p].ll=tr[p<<1].ll;
	if((tr[p<<1|1].rc1==tr[p<<1].rc1&&tr[p<<1|1].rl==tr[p<<1|1].len)||tr[p<<1|1].len==0)
	{
		tr[p].rl=tr[p<<1|1].len+tr[p<<1].rl;
	}
	else
		tr[p].rl=tr[p<<1|1].rl;
}
void build(int u,int l,int r)
{
    tr[u]={l,r,0,0,0,0,0,0,0,0};
    if(l==r)
    {
		tr[u].lc1=tr[u].rc1=0;
		tr[u].ll=tr[u].rl=tr[u].ml=tr[u].len=0;
		return;
    }
    int m=l+r>>1;
    build(lc,l,m);
    build(rc,m+1,r);
    pushup(u);

}
void update(int p,int l,int r,int L,int K)
{
	if(l==r)
	{
		tr[p].lc1=tr[p].rc1=K;
		int u=K?1:0;
		tr[p].ll=tr[p].rl=tr[p].ml=tr[p].len=u;
		return;
	}
	int mid=(l+r)>>1;
	if(L<=mid)update(p<<1,l,mid,L,K);
	else update(p<<1|1,mid+1,r,L,K);
	pushup(p);
}
LL n,q1;
set<LL> s,v;
void add1(LL x){
	//cout<<x<<'+'<<endl;
	auto it=s.lower_bound(x);
	auto tl=s.lower_bound(x);
	if(it!=s.begin()){
		it--;
		//cout<<x-(*it)<<'='<<endl;
		update(1,1,n,(*it),x-(*it));
	}
	if(tl!=s.end())
	{
		//cout<<(*it)-x<<'='<<endl;
		update(1,1,n,x,(*tl)-x);
	}
	s.insert(x);
}
void solve(){
    s.clear();
    v.clear();
    cin>>n>>q1;
    build(1,1,n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            v.insert(i);
        }else{
            add1(i);
        }
    }

    // for(int i=1;i<=n;i++){
    //     printf("{%lld}",f[i]);
    // }
    LL l,r;
    
    for(int i=1;i<=q1;i++){
        cin>>l>>r;
        auto it=v.lower_bound(l);
        queue<LL> q;
        for(;it!=v.end()&&(*it)<=r;it++){
            if((*it)>=l&&(*it)<=r){
                q.push((*it));
                add1(*it);
            }
        }
        while(!q.empty())
        {
            int u=q.front();
            v.erase(u);
            q.pop();
        }
        LL ans=0;
        if(tr[1].siz1!=0){
            ans=tr[1].t;
        }      
        cout<<ans+1<<'\n';
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