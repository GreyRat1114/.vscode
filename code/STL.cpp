#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<set<int>> st(N);
bool vis[N];
int main()
{
    int n,m,q;
    int op;
    int x,y;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&x,&y);
            st[x].insert(y);
        }
        else if(op==2)
        {
            scanf("%d",&x);
            vis[x]=true;
        }
        else
        {
            scanf("%d%d",&x,&y);
            if(vis[x]==true)
            {
                printf("Yes\n");
            }
            else
            {
                if(st[x].count(y))
                {
                    printf("Yes\n");
                }
                else
                {
                    printf("No\n");
                }
            }
        }
    }
    return 0;
}