// 2024睿抗
// 热 热 热 
// #include<bits/stdc++.h>
// using namespace std;
// int a[100];
// int main()
// {
// 	int n,w;
// 	int day;
// 	int t;
// 	int s1=0;
// 	int s2=0;
// 	scanf("%d%d",&n,&w);
// 	w=w%7;
// 	for(int i=0;i<n;i++)
// 	{
// 		scanf("%d",&t);
// 		day=(w+i)%7;
// 		if(t>=35)
// 		{		
			
// 			if(day==4)
// 			{
// 				s2++;
// 				continue;;
// 			}
// 			s1++;
// 		}
// 	}
// 	printf("%d %d",s1,s2);
// 	return 0;
// }

// 谁进线下了
// #include<bits/stdc++.h>
// using namespace std;
// int a[]={0,12,9,7,5,4,3,3,2,2,2,1,1,1,1,1,0,0,0,0,0};
// struct node{
// 	int num;
// 	int point;
// }b[100];
// void init()
// {
// 	for(int i=1;i<=99;i++)
// 	{
// 		b[i].num=i;
// 		b[i].point=0;
// 	}
// }
// bool cmp(node a,node b)
// {
// 	if(a.point>b.point)
// 	{
// 		return 1;
// 	}
// 	return 0;
// }
// int main()
// {
// 	int n;
// 	int k,p;
// 	scanf("%d",&n);
// 	init();

// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=20;j++)
// 		{
// 			scanf("%d%d",&p,&k);
// 			b[j].point+=a[p]+k;
// 		}
		
// 	}
// 	// sort(b+1,b+21,cmp);
// 	for(int i=1;i<=20;i++)
// 	{
// 		printf("%d %d\n",i,b[i].point);
// 	}
// }

// 暖炉和水豚
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// char a[1005][1005];
// struct node{
// 	int r;
// 	int l;
// }ans[100000];
// bool vis[1005][1005];
// int dx[8]={-1,-1,-1,0,0,1,1,1};
// int dy[8]={-1,0,1,-1,1,-1,0,1};
// bool cmp(node a,node b)
// {
// 	if(a.r<b.r)
// 	{
// 		return 1;
// 	}
// 	else if(a.r==b.r)
// 	{
// 		if(a.l<b.l)
// 		{
// 			return 1;

// 		}
// 	}
// 	return 0;
// }
// int main()
// {
// 	memset(ans,0,sizeof(ans));
// 	memset(vis,false,sizeof(vis));
// 	char g;
// 	scanf("%d%d",&n,&m);
// 	for(int i=1;i<=n;i++)
// 	{
// 		g=getchar();

// 		scanf("%s",a[i]+1);

// 	}
// 	int x1,y1;
// 	int x2,y2;
// 	x2=0;
// 	y2=0;
// 	int x3,y3;
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=m;j++)
// 		{
// 			if(a[i][j]=='c')
// 			{
// 				x3=i;
// 				y3=j;
// 			}
// 			if(a[i][j]=='w')
// 			{
// 				// printf("\n(%d,%d)",i,j);
// 				int tag=0;
// 				for(int k=0;k<8;k++)
// 				{
// 					x1=i+dx[k];
// 					y1=j+dy[k];
// 					if(x1<1||x1>n||y1<1||y1>m)
// 					{
// 						continue;
// 					}
// 					if(a[x1][y1]=='m')
// 					{
// 						tag=1;
// 						// printf("{%d,%d}",x1,y1);
// 						break;
// 					}

// 				}
// 				if(tag==0)
// 				{
// 					x2=i;
// 					y2=j;
// 				}
// 				// printf("[%d]",tag);				
// 			}
// 		}	
// 	}	
// 	if(x2==0&&y2==0)
// 	{
// 		printf("Too cold!");
// 		return 0;
// 	}
// 	// printf("%d,%d\n",x2,y2);
// 	for(int i=0;i<8;i++)
// 	{
// 		x1=x3+dx[i];
// 		y1=y3+dy[i];
// 		if(x1<1||x1>n||y1<1||y1>m)
// 		{
// 			continue;
// 		}
// 		vis[x1][y1]=true;		
// 	}
// 	int tot=0;
// 	for(int i=0;i<8;i++)
// 	{
// 		x1=x2+dx[i];
// 		y1=y2+dy[i];
// 		if(x1<1||x1>n||y1<1||y1>m)
// 		{
// 			continue;
// 		}
// 		if(vis[x1][y1]==true)
// 		{
// 			continue;
// 		}
// 		if(a[x1][y1]=='w')	
// 		{
// 			continue;
// 		}	
// 		tot++;
// 		ans[tot].r=x1;
// 		ans[tot].l=y1;
// 	}
// 	if(tot==0)
// 	{
// 		printf("Too cold!");
// 		return 0;
// 	}
// 	sort(ans+1,ans+1+tot,cmp);
// 	for(int i=1;i<=tot;i++)
// 	{
// 		printf("%d %d\n",ans[i].r,ans[i].l);
// 	}	

// 	// for(int i=1;i<=n;i++)
// 	// {
// 	// 	for(int j=1;j<=m;j++)
// 	// 	{
// 	// 		printf("%c",a[i][j]);
// 	// 	}
// 	// 	printf("\n");
// 	// }	
// 	return 0;
// }


// 2024睿抗国赛
// 大家一起查作弊
// #include<bits/stdc++.h>
// using namespace std;
// const int N=6e4+5;
// char s[N];
// int main()
// {
// 	int ans=0;
// 	int point=0;	
// 	int sum=0;
// 	int cnt=0;	
// 	while(scanf("%s",s+1)!=EOF)
// 	{
// 		int len=strlen(s+1);
// 		// printf("|%d|",len);
// 		int tag1=0;
// 		int tag2=0;
// 		int tag3=0;
// 		int tag=0;

// 		for(int i=1;i<=len;i++)
// 		{
// 			if(s[i]>='0'&&s[i]<='9')
// 			{
// 				if(tag==0)
// 				{
// 					tag=1;
// 					cnt++;
// 				}
// 				tag1=1;
// 				sum++;
				
// 			}
// 			else if(s[i]>='a'&&s[i]<='z')
// 			{
// 				tag2=1;
// 				sum++;
// 				if(tag==0)
// 				{
// 					tag=1;
// 					cnt++;
// 				}
// 			}
// 			else if(s[i]>='A'&&s[i]<='Z')
// 			{
// 				tag3=1;
// 				sum++;
// 				if(tag==0)
// 				{
// 					tag=1;
// 					cnt++;
// 				}
// 			}
// 			else
// 			{
// 				if(tag==1)
// 				{
// 					tag=0;
// 					if(tag2&&tag3&&tag1==0)
// 					{
// 						point+=1;
// 					}
// 					else if(tag1&&tag2&&tag3)
// 					{
// 						point+=5;
// 					}
// 					else if((tag1&&tag2&&tag3==0)||(tag1&&tag3&&tag2==0))
// 					{
// 						point+=3;
// 					}
// 					tag1=0;
// 					tag2=0;
// 					tag3=0;
// 					// printf("!%d,%d!\n",point,i);
// 				}
// 			}
// 		}
// 		if(tag==1)
// 		{
// 			tag=0;
// 			if(tag2&&tag3&&tag1==0)
// 			{
// 				point+=1;
// 			}
// 			else if(tag1&&tag2&&tag3)
// 			{
// 				point+=5;
// 			}
// 			else if((tag1&&tag2&&tag3==0)||(tag1&&tag3&&tag2==0))
// 			{
// 				point+=3;
// 			}
// 			tag1=0;
// 			tag2=0;
// 			tag3=0;

// 		}
// 		// printf("{%d,%d,%d}",point,sum,cnt);
// 	}
// 	printf("%d\n%d %d",point,sum,cnt);
// 	return 0;
// }


// 谁进线下了
// #include<bits/stdc++.h>
// using namespace std;
// const int N=35;
// struct node{
// 	int num;
// 	int point;
// }a[N];
// int pt[]={0,25,21,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
// bool vis[N];
// bool cmp(node a,node b)
// {
// 	if(a.point>b.point)
// 	{
// 		return true;
// 	}
// 	else if(a.point==b.point)
// 	{
// 		if(a.num<b.num)
// 		{
// 			return true;
// 		}
// 	}
// 	return false;
// }
// int main()
// {
// 	for(int i=1;i<=30;i++)
// 	{
// 		a[i].num=i;
// 		a[i].point=0;
// 	}
// 	int n;
// 	int c,p;
// 	int m=30;
// 	scanf("%d",&n);
// 	for(int i=1;i<=n;i++)
// 	{
// 		for(int j=1;j<=20;j++)
// 		{
// 			scanf("%d%d",&c,&p);
// 			a[c].point+=pt[p];
// 			if(!vis[c])
// 			{
// 				vis[c]=true;
// 			}
// 		}
// 	}
// 	sort(a+1,a+1+m,cmp);
// 	for(int i=1;i<=m;i++)
// 	{
// 		if(vis[a[i].num])
// 		{
// 			printf("%d %d\n",a[i].num,a[i].point);
// 		}
// 	}
// 	return 0;
// }


// 势均力敌
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+5;
// using LL=long long;
// int a[N];
// int b[N];
// bool vis[N];
// int n;
// // void dfs(int x)
// // {
// // 	for(int i=1;i<=n;i++)
// // 	{

// // 	}
// // }
// int main()
// {
	
// 	scanf("%d",&n);
// 	LL s1;
// 	LL s2;
// 	for(int i=1;i<=n;i++)
// 	{
// 		scanf("%d",&a[i]);
// 	}
// 	int tot=0;
// 	for(int i=1;)
// 	return 0;
// }


// city
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+5;
// const int M=5e3+5;
// using LL=long long;
// #define mp make_pair
// int last[N];
// bool vis[N];
// int tot;
// int val[N];
// int dist[N];
// int res[N];

// struct node{
// 	int v,w,next;
// }a[M*2];
// void add(int u,int v,int w)
// {
// 	tot++;
// 	a[tot]={v,w,last[u]};
// 	last[u]=tot;
// }
// int n,m,k;
// void dijkstra(int s)
// {
// 	for(int i=1;i<=n;i++)
// 	{
// 		dist[i]=1e9;
// 	}
// 	vis[s]=true;
// 	priority_queue<pair<int,int>> q;
// 	res[s]=0;

// 	dist[s]=0;
// 	q.push(mp(-dist[s],s));
// 	while(!q.empty())
// 	{
		
// 		int u=q.top().second;
// 		printf("%d,",u);
// 		q.pop();
// 		vis[u]=false;
// 		for(int i=last[u];i>0;i=a[i].next)
// 		{
// 			int v=a[i].v;
// 			int w=a[i].w;
// 			if(dist[u]+w<dist[v])
// 			{
// 				dist[v]=dist[u]+w;
// 				res[v]=max(res[u],val[v]);
// 				if(!vis[v])
// 				{
// 					q.push(mp(-dist[v],v));
// 				}
// 			}
// 			else if(dist[u]+w==dist[v])
// 			{
// 				res[v]=min(res[v],max(res[u],val[v]));
// 			}
			
// 		}
// 	}

// }
// int main()
// {
// 	int s,t;
// 	memset(vis,false,sizeof(vis));
// 	int u,v,w;
// 	scanf("%d%d%d%d",&n,&m,&s,&t);
// 	for(int i=1;i<=n;i++)
// 	{
// 		scanf("%d",&val[i]);
// 	}
// 	for(int i=1;i<=m;i++)
// 	{
// 		scanf("%d%d%d",&u,&v,&w);
// 		add(u,v,w);
// 		add(v,u,w);

// 	}
// 	dijkstra(s);
// 	printf("%d %d",dist[t],res[t]);
// 	return 0;
// }


// 
// #include<iostream>
// using namespace std;
// #define OK 1
// #define ERROR 0
// #define OVERFLOW -2
// typedef int Status;        //Status 是函数返回值类型，其值是函数结果状态代码。
// typedef int ElemType;     //ElemType 为可定义的数据类型，此设为int类型

// #define MAXSIZE 100            //顺序表可能达到的最大长度

// typedef struct {
//     ElemType* elem;         //存储空间的基地址
//     int length;                //当前长度
// }SqList;

// Status InitList_Sq(SqList& L) {                //算法2.1 顺序表的初始化
//     //构造一个空的顺序表L
//     L.elem = new ElemType[MAXSIZE];        //为顺序表分配一个大小为MAXSIZE的数组空间
//     if (!L.elem)  exit(OVERFLOW);        //存储分配失败
//     L.length = 0;                            //空表长度为0
//     return OK;
// }
// bool Del_Min(SqList &L,ElemType &value)
// {
// 	if(L.length==0)
// 	{
// 		return false;
// 	}
// 	value=L.elem[0];
// 	int pos=0;
// 	for(int i=1;i<L.length;i++)
// 	{
// 		if(L.elem[i]<value)
// 		{
// 			value=L.elem[i];
// 			pos=i;
// 		}

// 	}
// 	L.elem[pos]=L.elem[L.length-1];
// 	L.length--;			
// 	return true;
// }
// // Status ListInsert_Sq(SqList &L,int i,ElemType e)
// // {
// //     if(i<1)
// // }
// int main()
// {
//     SqList L;
//     if (InitList_Sq(L))                        //创建顺序表
//         cout << "成功建立顺序表\n\n";
//     else
//         cout << "顺序表建立失败\n\n";
//     int a[5] = { 1,2,3,4,5 };
//     for (int i = 0; i < 5; i++) {
//         L.elem[i] = a[i];
//         L.length++;
//     }
//     ElemType e = 3;
//     // ListDelete_Sq(L, 1, e);
//     ElemType minn=1e9;

//     cout << "当前顺序表为:\n";            //顺序表的输出
//     for (int i = 0; i < L.length; i++) {
//         cout << L.elem[i] << " ";
//     }
// 	Del_Min(L,minn);	
// 	cout<<minn;

//     cout << "当前顺序表为:\n";            //顺序表的输出
//     for (int i = 0; i < L.length; i++) {
//         cout << L.elem[i] << " ";
//     }
//     cout << endl << endl;
//     return 0;
// }


// 
// #include<bits/stdc++.h>
// using namespace std;

// #define OK 1
// #define ERROR 0
// typedef int Status;        //Status 是函数返回值类型，其值是函数结果状态代码。
// typedef int ElemType;     //ElemType 为可定义的数据类型，此设为int类型

// typedef struct LNode
// {
//     ElemType data;                            //结点的数据域
//     struct LNode* next;                        //结点的指针域
// }LNode, * LinkList;                            //LinkList为指向结构体LNode的指针类型


// Status InitList_L(LinkList& L) {                //算法2.5 单链表的初始化
//     //构造一个空的单链表L
//     L = new LNode;                            //生成新结点作为头结点，用头指针L指向头结点
//     L->next = NULL;                            //头结点的指针域置空
//     return OK;
// }
// void CreateList_L(LinkList& L, int a[]) {        //算法2.11 后插法创建单链表
//     //建立到头结点的单链表L
//     LNode* r, * p;
//     L = new LNode;
//     L->next = NULL;
//     r = L;
//     for (int i = 0; i < 5; i++) {
//         p = new LNode;
//         p->data = a[i];
//         p->next = NULL; r->next = p;
//         r = p;
//     }
// }        //CreateList_L
// Status GetElem_L(LinkList L,int i,ElemType &e)
// {
//     int j=0;
//     LNode *p=L->next;

//     while(j<i&&p)
//     {
//         j++;
//         p=p->next;
//     }
//     if(p==0||j>i)
//     {
//         return ERROR;
//     }
//     e=p->data;
//     return OK;
// }
// int main()
// {
//     LinkList L;
//     int a[] = { 1,2,3,4,5 };
//     CreateList_L(L, a);

//     ElemType e = GetElem_L(L, 1, e);
//     cout << e;
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #define ERROR 0
// #define OK 1
// #define N 5
// typedef int ElemType;

// typedef struct node {
// 	ElemType data;
// 	struct node *next;
// } LinkList;

// LinkList *InitList() {
// 	LinkList *head;
// 	head = ( LinkList *)malloc( sizeof(LinkList));
// 	head->next = NULL;
// 	return head;
// }

// LinkList *CreateList(int n) {
// 	int i;
// 	LinkList *head, *p, *r;
// 	head = ( LinkList *)malloc(sizeof(LinkList));
// 	r = head;

// 	for ( i = 1; i <= n; i++) {

// 		p = ( LinkList *)malloc( sizeof( LinkList));
// 		scanf("%d", &( p->data));
// 		r->next = p;
// 		r = p;
// 	}

// 	r->next = NULL;
// 	return head;
// }

// void PrintLinkList(LinkList *head) {
// 	LinkList *p;
// 	p = head->next;
// 	while ( p != NULL) {
// 		printf("%d,", p->data);
// 		p = p->next;
// 	}
// }

// int InsertElem( LinkList *head, int i, ElemType e) {
//     int j=0;
//     node* p=head;
//     node* a=new node;
    
// 	while(p&&j<i-1)
//     {
//         p=p->next;
//         j++;
//     }
//     if(!p||j>i-1)
//     {
//         return 0;
//     }
//     a->next=p->next; 
//     p->next=a;
//     a->data=e;     
           

//     return 1;
// }

// int main() {
// 	LinkList *head;
// 	int i;
// 	ElemType e;
// 	head = CreateList(N);
// 	scanf("%d %d", &i, &e);
// 	if (!InsertElem( head, i, e))
// 		printf("Failed!\n");
// 	else 
// 		printf("Success!\n");
// 	PrintLinkList(head);
// }


// typedef struct{
//     ElemType *elem;
//     int length;
//  }SqList;


// ### 裁判测试程序样例：
// ```c++
// #include<bits/stdc++.h>
// #define MAXSIZE 5
// typedef int ElemType;
// typedef struct{
//     ElemType *elem;
//     int length;
//  }SqList;
// void InitList(SqList &L);/*细节在此不表*/
// int LocateElem(SqList L,ElemType e);

// int main()
// {
//     SqList L;
//     InitList(L);
//     ElemType e;
//     int p;
//     scanf("%d",&e);
//     p=LocateElem(L,e);
//     printf("The position of %d in SequenceList L is %d.",e,p);
//     return 0;
// }
// int LocateElem(SqList L,ElemType e)
// {
// 	if(L.length)
// }
/* 请在这里填写答案 */



// #include <stdio.h>
// #include <stdlib.h>
// struct stud_node {
//      int    num;
//      char   name[20];
//      int    score;
//      struct stud_node *next;
// };

// struct stud_node *createlist();
// struct stud_node *deletelist( struct stud_node *head, int min_score );

// int main()
// {
//     int min_score;
//     struct stud_node *p, *head = NULL;

//     head = createlist();
//     scanf("%d", &min_score);
//     head = deletelist(head, min_score);
//     for ( p = head; p != NULL; p = p->next )
//         printf("%d %s %d\n", p->num, p->name, p->score);

//     return 0;
// }

// /* 你的代码将被嵌在这里 */
// struct stud_node *createlist()
// {
//     struct stud_node *L=( struct stud_node*)malloc(sizeof(struct stud_node));
//     L->next=NULL;
//     int num;
//     int sc;
//     char s[20];
//     struct stud_node *r=L;
//     struct stud_node *p;
//     while(1)
//     {
// scanf("%d",&num);  
//     if(num==0)
//     {
// break;}
//     getchar();
//     scanf("%s",s);
//     scanf("%d",&sc);
//     p=(struct stud_node*)malloc(sizeof(struct stud_node));
//     p->num=num;
//     p->score=sc;
//     p->next=NULL;
//     int pos=0;
//     while(s[pos]!='\0')
//     {
// p->name[pos]=s[pos];
//     pos++;
//     }
//     p->name[pos]='\0';
//     r->next=p;
//     r=p;
//     }
// return L;
// }

// struct stud_node *deletelist(struct stud_node *head,int min_score)
// {
//     struct stud_node *p=head->next;
//     struct stud_node *q=head;
//     while(p)
//     {

//         if(p->score<min_score)
//         {
//             q->next=p->next;
// 			p=q->next;
//         }
//         else
// 		{
// 			q=p;
// 			p=p->next;
// 		}

//         }
//     return head->next;
    
// }


// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// /* 建立单链表并返回单链表的头指针 */
// struct Node* buildLinkedList(int* arr, int n);

// /* 求单链表值最大的结点 */
// struct Node* getMax(struct Node* head);

// int main(int argc, char const *argv[]) 
// {
//     int *a, n, i;
//     scanf("%d", &n);
//     a = (int*)malloc(n * sizeof(int));
//     for (i = 0; i < n; ++i) {
//         scanf("%d", &a[i]);
//     }

//     struct Node* head = NULL;

//     head = buildLinkedList(a, n);

//     struct Node* pMax = getMax(head);
//     if (pMax)
//         printf("%d\n", pMax->data);
//     else
//         printf("-1\n");

//     free(a);

//     return 0;
// }

// struct Node* buildLinkedList(int*arr,int n)
// {
//     Node *L=new Node;
//     Node *r;
//     Node *p;
//     L->next=NULL;
//     r=L;
//     for(int i=0;i<n;i++)
//     {
//         p=new Node;
//         p->data=arr[i];
//         p->next=NULL;
//         r->next=p;
//         r=p;
// }
    
//     return L;
// }
// struct Node* getMax(struct Node* head)
// {
//     Node *p=head;
//     int maxn=0;
//     Node *q=0;
//     while(p!=NULL)
//     {
//         if(p->data>maxn)
//         {
//             maxn=p->data;
//             q=p;
// }
//         p=p->next;
// }
//     return q;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int a[100005];
// struct node{
// int num;
// node* next;};
// node* createlist(int n)
// {
// node *L=new node;
// L->next=NULL;
//     node* p;
//     node *r;
//     r=L;
//     for(int i=1;i<=n;i++)
//     {
//         p=new node;
//         p->num=a[i];
//         p->next=NULL;
//         r->next=p;
//         r=p;
//     }
//     return L;
// }
// void cha(node* head,int k,int d,int n)
// {

//     int s=0;
//     node* p=head;
//     if(k==0)
//     {
//         node* x=new node;
//         x->next=p->next;
//         p->next=x;
//         x->num=d;
//         return;
//     }
//     while(p->next!=NULL)
//     {
//         p=p->next;
//         s++;
//         if(s==k)
//         {
//             node *x=new node;
//             x->next=p->next;
//             p->next=x;
//             x->num=d;
//             break;
// }
// }
// }
// void shan(node* head,int k,int n)
// {

//     int s=0;
//     node *p=head;
//     node *q;
//     while(p->next!=NULL)
//     {
//         q=p;
//         p=p->next;
//         s++;
//         if(s==k)
//         {
//             q->next=p->next;
// }
// }
// }
// int main()
// {
//     int n,m;
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//     }
//     node* head=createlist(n);
//     cin>>m;
//     int x;
//     int k,d;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>x;
//         if(x==0)
//         {
//             cin>>k>>d;
//             cha(head,k,d,n);
// }
//         else if(x==1)
//         {
//             cin>>k;
//             shan(head,k,n);
            
// }
        
// }
//     node *p;
//     for(p=head->next;p!=NULL;p=p->next)
//     {
//         printf("%d ",p->num);
//     }
//     return 0;
// }


// 
// #include<bits/stdc++.h>
// using namespace std;
// int a[100005];
// int b[100005];
// struct node{
//     int num;
//     node *next;
// };
// node *createlist(int m,int n)
// {
//     node *L=new node;
//     L->next=NULL;
//     L->num=0;
//     node *p;
//     node *r;
//     r=L;
//     int p1=1;
//     int p2=1;
//     while(p1<=m&&p2<=n)
//     {
//         p=new node;
//         int minn;
//         if(a[p1]<b[p2])
//         {
//             minn=a[p1];
//             p1++;
// }
//         else
//         {
//             minn=b[p2];
//             p2++;
// }
//         p->num=minn;
//         p->next=NULL;
//         r->next=p;
//         r=p;
        
// }
//     while(p1<=m&&p2>n)
//     {
//         p=new node;
//         p->num=a[p1];
//         p1++;
//         p->next=NULL;
//         r->next=p;
//         r=p;
        
// }
//     while(p2<=n&&p1>m)
//     {
//         p=new node;
//         p->num=b[p2];
//         p2++;
//         p->next=NULL;
//         r->next=p;
//         r=p;
// }
//     return L;
// }
// int main()
// {
//     int n,m;
//     while(scanf("%d %d",&m,&n)!=EOF)
//     {
//         for(int i=1;i<=m;i++)
//         {
// cin>>a[i];}
//         for(int i=1;i<=n;i++)
//         {
// cin>>b[i];
//         }
//         node *head=createlist(m,n);
//         node *p;
//         for(p=head->next;p!=NULL;p=p->next)
//         {
//             if(p!=head->next)
//             {
//                 printf(" ");
// }
//             printf("%d",p->num);
// }
// }
//     return 0;
// }



// #include<stdio.h>
// #include<stdlib.h>

// typedef int DataType;
// struct Node {
//     DataType      data;
//     struct Node*  next;
// };
// typedef struct Node  *PNode;
// typedef struct Node  *LinkStack;

// LinkStack SetNullStack_Link() 
// {
//     LinkStack top = (LinkStack)malloc(sizeof(struct Node));
//     if (top != NULL) top->next = NULL;
//     else printf("Alloc failure");
//     return top; 
// }

// int IsNullStack_link(LinkStack top) 
// {
//     if (top->next == NULL)
//         return 1;
//     else
//         return 0;
// }

// void Push_link(LinkStack top, DataType x) 
// {
//     PNode p;
//     p = (PNode)malloc(sizeof(struct Node));
//     if (p == NULL)
//         printf("Alloc failure");
//     else
//     {
//         p->data = x;
//         p->next = top->next;
//         top->next = p;
//     }
// }
// void Pop_link(LinkStack top)
// {
//     PNode p;
//     if (top->next == NULL)
//         printf("it is empty stack!");
//     else
//     {
//         p = top->next;
//         top->next = p->next;
//         free(p);
//     }
// }
// DataType Top_link(LinkStack top)
// {
//     if (top->next == NULL)
//     {
//         printf("It is empty stack!");
//         return 0;
//     }
//     else
//         return top->next->data;
// }

// int main()
// {
//     LinkStack stackA = SetNullStack_Link();
//     DataType data;
//     scanf("%d,", &data);
//     while (data != -1)
//     {
        
//         Push_link(stackA,data);

//         scanf("%d,", &data);
//     }
//     while (!IsNullStack_link(stackA))
//     {
//         DataType a=Top_link(stackA);
//         Pop_link(stackA);
//         printf("%d ",a);
        

//     }
//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// #define MaxSize 100        /* 栈最大容量 */
// int top;                /* 栈顶指针 */
// int mystack[MaxSize];    /* 顺序栈 */

// /*判栈是否为空，空返回true，非空返回false */
// bool isEmpty();

// /* 元素x入栈 */
// void Push(int x);

// /* 取栈顶元素 */
// int getTop();

// /* 删除栈顶元素 */
// void Pop();

// /* 十进制正整数转换为二进制 */
// void dec2bin(int x) {
//     top = -1;            /* 初始化栈顶指针 */
//     while (x) {
//         Push(x % 2);
//         x >>= 1;
//     }
//     while (!isEmpty()) {
//         int t = getTop();
//         Pop();
//         printf("%d", t);
//     }
//     printf("\n");
// }

// int main(int argc, char const *argv[])
// {
//     int n;
//     while (scanf("%d", &n) != EOF) {
//         dec2bin(n);
//     }
//     return 0;
// }

// /* 请在这里填写答案 */
// bool isEmpty()
// {
//     if(top==-1)
//     {
//         return 1;
// }
//     return 0;
// }

// void Push(int x)
// {
//     if(top==MaxSize-1)
//     {
//         return;
// }
//     top++;
//     mystack[top]=x;
// }

// int getTop()
// {
//     return mystack[top];
//     top--;
// }

// void Pop()
// {
// top--;
// }


// 
// #include<bits/stdc++.h>
// using namespace std;
// typedef int DataType;
// struct Node{
//     DataType data;
//     struct Node* next;
// };
// typedef struct Node *PNode;
// typedef struct Node *LinkStack;
// LinkStack init()
// {
// LinkStack top=(LinkStack)malloc(sizeof(struct Node));
// if(top!=NULL)top->next=NULL;
// return top;
// }
// void Push(LinkStack top,DataType x)
// {
//     PNode p;
//     p=new Node;
//     p->data=x;
//     p->next=top->next;
//     top->next=p;
    
// }
// void Pop(LinkStack top)
// {
//     PNode p;
//     if(top->next==NULL)
//     {
//         printf("错误：栈为空。\n");
// }
//     else
//     {
//         p=top->next;
//         top->next=p->next;
//         free(p);
// }
// }
// DataType Top(LinkStack top,DataType &val)
// {
//     if(top->next==NULL)
//     {
// printf("错误：栈为空。\n");
//         return 0;
//     }else
//     {
//         val=top->next->data;
//         return 1;
// }
// }
// int main()
// {
//     int n,x;
//     cin>>n;
//     LinkStack stackA=init();
//     for(int i=1;i<=n;i++)
//     {
//         cin>>x;
//         Push(stackA,x);
        
// }
//     for(int i=1;i<=n+1;i++)
//     {
//         DataType val;
        
//         if(Top(stackA,val))
//         {
//             printf("%d\n",val);
// }
//         else
//         {
//             printf("-1\n");
// }
//         Pop(stackA);
//         }
    
    
// return 0;}



// #include<bits/stdc++.h>
// using namespace std;
// using LL=long long;
// const int N=2e5+5;
// struct node{
//     LL l;
//     LL r;
    
// }a[N];
// int b[N];
// int ans[N];
// void solve()
// {
//     memset(ans,0,sizeof(ans));
//     int n;
//     int q;
//     cin>>n>>q;
//     int x;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>x;
//         b[i]=x;

//     }
//     sort(b+1,b+1+n);
//     int m=unique(b+1,b+1+n)-b;
//     for(int i=1;i<=q;i++)
//     {
//         cin>>x;
//         int p=lower_bound(b+1,b+1+m,x)-b-1;
//         printf("{%d}",p);
//     }
    

// }
// int main()
// {
// solve();
    
//     return 0;
// }



// 

// #include <stdio.h>
// #include <stdlib.h>
// typedef char DataType;
// struct Queue
// {
//     int Max;  
//     int f;   
//     int r;  
//     DataType *elem; 
// };
// typedef struct Queue *SeqQueue;

// SeqQueue SetNullQueue_seq(int m) 
// {
//     SeqQueue squeue;
//     squeue = (SeqQueue)malloc(sizeof(struct Queue));
//     if (squeue == NULL)
//     {
//         printf("Alloc failure\n");
//         return NULL;
//     }
//     squeue->elem = (char*)malloc(sizeof(DataType)*m);
//     if (squeue->elem != NULL)
//     {
//         squeue->Max = m;
//         squeue->f = 0;
//         squeue->r = 0;
//         return squeue;
//     }
// }

// int IsNullQueue_seq(SeqQueue squeue) 
// {
//     return (squeue->f == squeue->r);
// }
// void EnQueue_seq(SeqQueue squeue, DataType x)  
// {
//     if((squeue->r+1)%squeue->Max==squeue->f)
//     {
//         printf("It is FULL Queue!");
//         return;
//     }
//     squeue->elem[squeue->r]=x;
//     squeue->r=(squeue->r+1)%squeue->Max;


// }
// void DeQueue_seq(SeqQueue squeue)  
// {
//     if(squeue->f==squeue->r)
//     {
//         printf("It is empty queue!");
//         return;
//     }
//     squeue->f=(squeue->f+1)%squeue->Max;

// }
// DataType FrontQueue_seq(SeqQueue squeue) 
// {
//     if(squeue->f==squeue->r)
//     {
//         printf("It is empty queue!");
//     }
//     return squeue->elem[squeue->f];

// }

// int main()
// {
//     char ch;
//     SeqQueue queueA = SetNullQueue_seq(5);
//     ch = getchar();
//     while (ch != '#')
//     {
//         EnQueue_seq(queueA, ch);
//         ch = getchar();
//     }
//     DeQueue_seq(queueA);
//     printf("%c" ,FrontQueue_seq(queueA));
//     return 0;
// }



// 
// #include <stdio.h>
// #include <stdlib.h>
// typedef char DataType;
// typedef struct SNode
// {  
//     DataType data;            
//     struct SNode *next;        
// }SNode,*LinkStack;            
// int InitLinkStack( LinkStack *top )
// {
//     *top = (LinkStack)malloc( sizeof(SNode) );
//     if( *top == NULL ) 
//     { 
//         printf("初始化链栈出错");
//         return 0;    
//     }
//     (*top)->next = NULL;
//     return  1;
// }
// int LinkStackEmpty( LinkStack top )
// {
//     if( top->next == NULL ) 
//         return 1;
//     else
//         return 0;
// }
// int Push(LinkStack top, DataType e)
// {
//     SNode *p;
//     p = (SNode*)malloc(sizeof(SNode));
//     if (!p)
//     {
//         printf("入栈操作出错!\n");
//         return 0;
//     }
//     p->data = e;
//     p->next = top->next;
//     top->next = p;
//     return 1;
// }
// int Pop(LinkStack top, DataType *e)
// {
//     SNode *p;
//     if (!top->next)
//     {
//         printf("栈已空，无法完成出栈操作!\n");
//         return 0;
//     }
//     p = top->next;
//     top->next = p->next;
//     *e = p->data;
//     free(p);
//     return 1;
// }
// int Destroy(LinkStack top)
// {
//     SNode *p;
//     while (top)
//     {
//         p = top;
//         top = top->next;
//         free(p);
//     }
//     return 1;
// }
// typedef struct QNode
// {
//     DataType data;            
//     struct QNode *next;        
// }LQNode,*PQNode ;
// typedef struct 
// { 
//     PQNode front, rear;        
// }LinkQueue;
// int InitLinkQueue(LinkQueue* Q)
// {
//     Q->front = Q->rear = (PQNode)malloc(sizeof(LQNode));
//     if (!Q->front)
//     {
//         printf("初始化队列失败！\n");
//         return 0;
//     }
//     Q->front->next = NULL;
//     return 1;
// }
// int LinkQueueEmpty(LinkQueue Q)
// {
//     if (Q.front == Q.rear) return 1;
//     else return 0;
// }
// int EnLinkQueue(LinkQueue* Q, DataType e)
// {
//     PQNode p;
//     p = (PQNode)malloc(sizeof(LQNode));
//     if (!p)
//     {
//         printf("内存分配失败，不能完成入队操作！\n");
//         return 0;
//     }
//     p->data = e;
//     p->next = NULL;//初始化入队结点
//     Q->rear->next = p;
//     Q->rear = p;
//     return 1;
// }
// int DeLinkQueue(LinkQueue* Q, DataType* e)
// {
//     PQNode p;
//     if (Q->front == Q->rear)
//     {
//         printf("队列已空，不能完成出队操作！\n");
//         return 0;
//     }
//     p = Q->front->next;
//     *e = p->data;
//     Q->front->next = p->next;
//     free(p);
//     if (Q->rear == p) //若删除的队列是最后一个结点，则移动队尾指针
//     {
//         Q->rear = Q->front;
//     }
//     return 1;
// }
// int DestroyLinkQueue(LinkQueue* Q)
// {
//     while (Q->front)
//     {
//         Q->rear = Q->front->next;
//         free(Q->front);
//         Q->front = Q->rear;

//     }
//     return 1;
// }
// /* 本题要求函数 */
// int JudgePalindrome(LinkStack st,LinkQueue qu)
// {
//     DataType e1;
//     DataType e2;
//     LinkQueue* dir=&qu;
//     while((!LinkQueueEmpty(qu))&&(!LinkStackEmpty(st)))
//     {
//         DeLinkQueue(dir,&e1);
//         Pop(st,&e2);
//         if(e1!=e2)
//         {
//             return -1;

//         }

//     }
//     return 2;
// }
// int main()
// {
//     LinkStack s;
//     LinkQueue q;
//     char ch;
//     int rst;
//     InitLinkStack(&s);
//     InitLinkQueue(&q);
//     while((ch=getchar())!='\n')
//     {
//         Push(s,ch);
//         EnLinkQueue(&q,ch);
//     }
//     rst = JudgePalindrome(s,q);
//     if ( rst == -1 )
//     {
//         printf("不是回文字符串\n");
//     } 
//     else if ( rst == 2 )
//     {
//         printf("是回文字符串\n");
//     }
//     Destroy(s);
//     DestroyLinkQueue(&q);
//     return 0;
// }

// /* 请在这里填写答案 */



// 
// #include<bits/stdc++.h>
// using namespace std;

// typedef struct QNode
// {
//     char data;                    
//     struct QNode *next;
// }QNode;
// typedef struct
// {
//     QNode *front;
//     QNode *rear;
// }LinkQueue;
// int init(LinkQueue &qu)
// {
//     qu.front=qu.rear=new QNode;
//     qu.front->next=NULL;
//     return 1;
// }

// int Push(LinkQueue &qu,char e)
// {
//     QNode *p=new QNode;
//     p->data=e;
//     p->next=NULL;
//     qu.rear->next=p;
//     qu.rear=p;
//     return 1;
// }
// int Pop(LinkQueue &qu,char &e)
// {
//     if(qu.rear==qu.front)
//     {
//         return 0;
//     }
//     QNode *p=qu.front->next;
//     e=p->data;
//     qu.front->next=p->next;
//     if(qu.rear==p)
//     {
//         qu.rear=qu.front;
//     }
//     delete p;
//     return 1;
// }
// int Front(LinkQueue &qu,char &e)
// {
//     if(qu.rear==qu.front)
//     {
//         return 0;
//     }
//     QNode *p=qu.front->next;
//     e=p->data;

//     return 1;
// }
// int Empty(LinkQueue &qu)
// {
//     if(qu.rear==qu.front)
//     {
//         return 0;
//     }    
//     return 1;
// }
// int main()
// {
//     LinkQueue qu;
//     init(qu);

//     int n;
//     char ch;
//     cin>>ch;

//     while(ch!='#')
//     {
//         Push(qu,ch);
//         cin>>ch;

//     }
//     char e1;
//     if(Front(qu,e1))
//     {
//         cout<<"Head:"<<e1<<'\n';
//     }
//     else
//     {
//         cout<<"Head:NULL"<<'\n';
//     }
//     cout<<"Pop:";
//     if(Empty(qu))
//     {
//         while(Pop(qu,e1))
//         {
//             cout<<e1;
//         }
//     }
//     else
//     {
//         cout<<"NULL";
//     }
//     cout<<'\n';
//     return 0;

// }



// #include<iostream>
// using namespace std;

// //二叉树的二叉链表存储表示
// typedef struct BiNode
// {                
//     char data;                        //结点数据域
//     struct BiNode *lchild,*rchild;    //左右孩子指针
// }BiTNode,*BiTree;

// //用算法5.3建立二叉链表
// void CreateBiTree(BiTree &T,const char* values,int &i)
// {    
//     //按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
//     if (values[i] == '#') {  
//         T = NULL;  
//         i++; // 移动到下一个字符  
//     } else {  
//         T = new BiTNode;  
//         T->data = values[i++]; // 读取当前字符作为节点值 
//         CreateBiTree(T->lchild, values, i); // 递归创建左子树  
//         CreateBiTree(T->rchild, values, i); // 递归创建右子树  
//     } 
// }


// int main()
// {
//     const char* values = "ABD##E##C#F##";
//     int i=0;
//     BiTree tree;
//     cout<<"请输入建立二叉链表的序列：\n";
//     cout<<"ABD##E##C#F##"<<endl;
//     CreateBiTree(tree,values,i);
//     cout<<"结点个数为："<<NodeCount(tree)<<endl;
//     return 0;

// }

// #include<iostream>
// using namespace std;
// typedef struct BiNode{
//     char data;
//     struct BiNode *lchild,*rchild;
// }BiTNode,*BiTree;

// void CreateBiTree(BiTree &T);//根据输入的字符串，创建二叉树。 
// void PreOrder(BiTree T);//先序遍历二叉树 
// void InOrder(BiTree T);//中序遍历二叉树 
// void PostOrder(BiTree T);//后序遍历二叉树 
// void LevelOrder(BiTree T);//层次遍历二叉树  

// int main(){
//  BiTree T;
//  CreateBiTree(T);
//  cout<<"PreOrder:"; 
//  PreOrder(T);
//  cout<<endl<<"InOrder:";
//  InOrder(T);
//  cout<<endl<<"PostOrder:";
//  PostOrder(T);
//  cout<<endl<<"LevelOrder:";
//  LevelOrder(T);
//  return 0;
// } 
// /* 请在这里填写答案 */
// void CreateBiTree(BiTree &T)
// {
//     char c;
//     cin>>c;
//     if(c=='#')
//     {
//         T=NULL;
// }
//     else{
// T=new BiTNode;
//     T->data=c;
//     CreateBiTree(T->lchild);
//     CreateBiTree(T->rchild);
//     }
// }

// void PreOrder(BiTree T)
// {
// {
//     if(T==NULL)
    
//     return;
// }
// cout<<T->data;
// PreOrder(T->lchild);
// PreOrder(T->rchild);

// }

// void InOrder(BiTree T)
// {
//     if(T==NULL)
//     {
//         return;
// }
//     InOrder(T->lchild);
//     cout<<T->data;
//     InOrder(T->rchild);
    
// }
// void PostOrder(BiTree T)
// {
//     if(T==NULL)
//     {
//         return;
// }
//     PostOrder(T->lchild);
//     PostOrder(T->rchild);
//     cout<<T->data;
    
// }

// void LevelOrder(BiTree T)
// {
//     BiTNode *a[1000];
//     int l=-1;
//     int r=0;
//     l++;
//     a[l]=T;
//     while(l<=r)
//     {
//         BiTNode *t=a[l];
//         l++;
//         if(t==NULL)
//         {
//             continue;
// }
//         cout<<t->data;
//         r++;
//         a[r]=t->lchild;
//         r++;
//         a[r]=t->rchild;
        
// }
// }


// 
// #include<bits/stdc++.h>
// using namespace std;
// typedef struct BiNode{
//     char data;
//     struct BiNode *lchild,*rchild;
// }BiTNode,*BiTree;
// void CreateBiTree(BiTree &T)
// {
// char c;
// cin>>c;
// if(c=='#')
// {
//     T=NULL;
// }
// else
// {
//     T=new BiTNode;
//     T->data=c;
//     CreateBiTree(T->lchild);
//     CreateBiTree(T->rchild);
    
// }}
// char s[1000];
// int p;
// void InOrder(BiTree T)
// {
//     if(T==NULL)
//     {
//         return;
// }
//     InOrder(T->lchild);
//     p++;
//     s[p]=T->data;
//     InOrder(T->rchild);
    
// }
// int main()
// {
//     BiTree T;
//     p=0;
//     CreateBiTree(T);
//     InOrder(T);
//     for(int i=1;i<=p;i++)
//     {
//         cout<<s[i];
// }
//     cout<<'\n';
//     for(int i=p;i>=1;i--)
//     {
//         cout<<s[i];
// }
//     cout<<"\n";
// return 0;
// }



// #include <stdio.h>
// #include <string.h>
// #include <malloc.h>
// typedef struct
//  {   
//  int weight;         // 结点权值?   
//  int parent, lc, rc; // 双亲结点和左 右子节点
// } HTNode, *HuffmanTree; 
// void Select(HuffmanTree *HT, int n, int *s1, int *s2)
// {    
// int minum,i;      // 定义一个临时变量保存最小值?    
// for(i=1; i<=n; i++)     // 以下是找到第一个最小值    
// {        if((*HT)[i].parent == 0)        
    
//     {    minum = i;            
//          break;        
//     }   
//  }    
// for(i=1; i<=n; i++)   
//  {       if((*HT)[i].parent == 0)           
//          if((*HT)[i].weight < (*HT)[minum].weight)                
//          minum = i;    
// }   
//  *s1 = minum;    // 以下是找到第二个最小值，且与第一个不同    
// for( i=1; i<=n; i++)         
// {       if((*HT)[i].parent == 0 && i != *s1)        
//     {    minum = i;            
//          break;        
//     }    
// }    
// for( i=1; i<=n; i++)   
//  {        if((*HT)[i].parent == 0 && i != *s1)           
//           if((*HT)[i].weight < (*HT)[minum].weight)                
//           minum = i;    
// }    
// *s2 = minum;
// }
// void CreatHuff(HuffmanTree *HT, int *w, int n){
//     if(n<=1){
//         return;
//     }
//     int m=2*n-1;
//     int s1,s2;
    
//     *HT=(HuffmanTree) malloc ((m+1) * sizeof(HTNode));
//     for(int i=1;i<=n;i++)
//     {
//         (*HT)[i].weight=w[i];
//         (*HT)[i].lc=0;
//         (*HT)[i].rc=0;
//         (*HT)[i].parent=0;

//     }
//     for(int i=n+1;i<=m;i++)
//     {
//         (*HT)[i].weight=0;
//         (*HT)[i].lc=0;
//         (*HT)[i].rc=0;
//         (*HT)[i].parent=0;

//     }
//     for(int i=n+1;i<=m;i++){
//         Select(HT,i-1,&s1,&s2);
//         (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
//         (*HT)[s1].parent=i;
//         (*HT)[s2].parent=i;
//         (*HT)[i].lc=s1;
//         (*HT)[i].rc=s2;
//         printf("%d(%d,%d),",(*HT)[i].weight,(*HT)[s1].weight,(*HT)[s2].weight);
//     }
// }
// int main()
// {    
//     HuffmanTree HT;        
//     int *w, n, wei,i;    
//     //printf("input the number of node\n");    
//     scanf("%d", &n);    
//     //w = new int[n+1];   
//     w=(int *) malloc ((n+1) * sizeof(int));
//     //printf("\ninput the %dth node of value\n", n);     
//     for(i=1; i<=n; i++)    
//     {        
//         scanf("%d", &wei);        
//         w[i] = wei;    }    
//     CreatHuff(&HT, w, n);       
//     return 0;
// }
// /* 请在这里填写答案 */



// #include<bits/stdc++.h>
// using namespace std;
// typedef struct node{
//     char data;
//     struct node *lc,*rc;
// }tnode,*ptnode;
// char s[105];
// void ct(ptnode &T){
//     char c;
//     cin>>c;
//     if(c=='@'){
//         T=NULL;
//     }
//     else{
//         T=new tnode;
//         T->data=c;
//         ct(T->lc);
//         ct(T->rc);
//     }
// }
// void pre(ptnode T){
//     if(T==NULL)
//     {
//         return;
//     }
//     cout<<T->data;
//     pre(T->lc);
//     pre(T->rc);
// }
// void mid(ptnode T){
//     if(T==NULL)
//     {
//         return;
//     }
//     mid(T->lc);
//     cout<<T->data;
//     mid(T->rc);
// }
// void last(ptnode T){
//     if(T==NULL)
//     {
//         return;
//     }
//     last(T->lc);
    
//     last(T->rc);
//     cout<<T->data;
// }
// void solve(char *s){
//     printf("%s",s);
// }
// int main(){
//     ptnode T;
//     ct(T);
//     pre(T);
//     cout<<'\n';
//     mid(T);
//     cout<<'\n';
//     last(T);
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define INF 1e9
// typedef int WeightType;
// typedef int VertexType;
// typedef struct {
//     int Nv;
//     WeightType G[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];
// } GNode, * MGraph;

// VertexType FindMinDist(MGraph Graph, WeightType dist[]) {
//     VertexType MinV = -1, V;
//     WeightType MinDist = INF;
//     for (V = 0; V < Graph->Nv; V++) {
//         if (dist[V] != 0 && dist[V] < MinDist) {
//             MinDist = dist[V];
//             MinV=V;
//         }
//     }
//     if (MinDist < INF) {
//         return MinV;
//     } else {
//         return ERROR;
//     }
// }

// int Prim(MGraph Graph) {
//     int dist[MAX_GRAPH_SIZE];
//     int TotalWeight = 0, VCount = 0;
//     VertexType  V, W;
//     for (V = 0; V < Graph->Nv; V++) {
//         dist[V] = Graph->G[0][V];
//     }
//     dist[0] = 0;
//     VCount++;
//     while (1) {
//         VertexType MinV;
//         if ((MinV = FindMinDist(Graph, dist)) == ERROR) {
//             break;
//         }
//         TotalWeight += dist[MinV];
//         dist[MinV]=0;
//         VCount++;
//         for (W = 0; W < Graph->Nv; W++) {
//             if (dist[W] != 0 &&Graph->G[MinV][W] < dist[W] ) {
//                 dist[W] = Graph->G[MinV][W];
//             }
//         }
//     }
//     if (VCount != Graph->Nv) {
//         return ERROR;
//     } else {
//         return TotalWeight;
//     }
// }

// #include <stdio.h>


// #define MVNum 100                           
// typedef struct{ 
//     char vexs[MVNum];          
//     int arcs[MVNum][MVNum];   
//     int vexnum,arcnum;      
// }AMGraph;

// void CreateUDN(AMGraph &G);
// int main(){
//     AMGraph G;     
//     int i , j,sum=0;
//     CreateUDN(G);
//     for(i = 0 ; i < G.vexnum ; ++i){
//         sum=0;
//         for(j = 0; j < G.vexnum; ++j){
//             if(G.arcs[i][j]==1)
//                 sum+=1;
//         }
//         if(i==0)
//             printf("%d",sum);
//         else
//             printf(" %d",sum);
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// void CreateUDN(AMGraph &G){
//     int n,m;
//     cin>>n>>m;
//     G.vexnum=n;
//     G.arcnum=m;
//     string s;
//     cin>>s;
//     map<char,int> mp;
//     for(int i=0;i<s.size();i++){
//         mp[s[i]]=i;
//         G.vexs[i]=s[i];

//     }

//     for(int i=1;i<=m;i++){
//         cin>>s;
//         int u=mp[s[0]];
//         int v=mp[s[1]];
//         G.arcs[u][v]=1;
//         G.arcs[v][u]=1;

//     }
// }

// #include <stdio.h>
// #include <stdlib.h>
// #define MVNum 100 
// typedef struct ArcNode{
//     int adjvex; 
//     struct ArcNode *nextarc; 
//     int info; 
// }ArcNode; 

// typedef struct VNode{ 
//     char data; 
//     ArcNode *firstarc; 
// }VNode, AdjList[MVNum]; 

// typedef struct{ 
//     VNode vertices[MVNum]; 
//     int vexnum, arcnum; 
// }ALGraph;

// void CreateUDG(ALGraph &G);

// int main(){
//     ALGraph G;     
//     int i , j,sum=0;
//     CreateUDG(G);
//     ArcNode * p; 
//     for(i = 0 ; i < G.vexnum ; ++i){
//         sum=0;
//         p=G.vertices[i].firstarc;
//         for(; p!=NULL; p=p->nextarc){
//                 sum+=1;
//         }
//         if(i==0)
//             printf("%d",sum);
//         else
//             printf(" %d",sum);
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// void CreateUDG(ALGraph &G){
//     int n,m;
//     cin>>n>>m;
//     G.vexnum=n;
//     G.arcnum=m;
//     string s;
//     cin>>s;
//     map<char,int> mp;
//     for(int i=0;i<s.size();i++){
//         mp[s[i]]=i;
//         G.vertices[i].data=s[i];
//         G.vertices[i].firstarc=NULL;
        
// }
//     for(int i=1;i<=m;i++){
//         cin>>s;
//         int u=mp[s[0]];
//         int v=mp[s[1]];
//         ArcNode* a=new ArcNode;
//         a->nextarc=G.vertices[u].firstarc;
//         G.vertices[u].firstarc=a;
//         ArcNode* b= new ArcNode;
//         b->nextarc=G.vertices[v].firstarc;
//         G.vertices[v].firstarc=b;
// }
// }



// #include <stdio.h>
// #include <stdlib.h>
// #define MVNum 10
// int visited[MVNum]; 
// typedef struct ArcNode{
//     int adjvex;
//     struct ArcNode *nextarc;
//     int info; 
// }ArcNode; 

// typedef struct VNode{ 
//     char data;
//     ArcNode *firstarc;
// }VNode, AdjList[MVNum];

// typedef struct{ 
//     AdjList vertices; 
//     int vexnum, arcnum;
// }ALGraph;

// int CreateUDG(ALGraph &G);//实现细节隐藏
// void DFS(ALGraph G, int v);

// void DFSTraverse(ALGraph G){ 
//  int v;
//  for(v = 0; v < G.vexnum; ++v)  
//    visited[v] = 0;    
//  for(v = 0; v < G.vexnum; ++v)
//    if(!visited[v])  
//      DFS(G, v);
// } 

// int main(){
//  ALGraph G;
//  CreateUDG(G);
//  DFSTraverse(G);
//  return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// void DFS(ALGraph G,int u){
//     visited[u]=1;
//     cout<<G.vertices[u].data<<' ';
//     ArcNode *p;
//     p=G.vertices[u].firstarc;
//     for(;p!=NULL;p=p->nextarc){
//         int x=p->adjvex;
//         if(!visited[x]){
//             DFS(G,x);
//         }
//     }
// }



// #include <stdio.h>
// #include <stdlib.h>
// #define MVNum 10
                        
// int visited[MVNum];
// typedef struct{ 
//     char vexs[MVNum];                    
//     int arcs[MVNum][MVNum]; 
//     int vexnum,arcnum;             
// }Graph;
 
// void CreateUDN(Graph &G);//实现细节隐藏
// void BFS(Graph G, int v);
// void BFSTraverse(Graph G){ 
//     int v;
//     for(v = 0; v < G.vexnum; ++v)  visited[v] = 0;    
//     for(v = 0; v < G.vexnum; ++v)
//         if(!visited[v])  BFS(G, v); 
// }
// int main(){
//     Graph G;
//     CreateUDN(G);
//     BFSTraverse(G);
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;
// void BFS(Graph G,int v){
//     queue<int> q;
//     q.push(v);
//     visited[v]=1;
//     while(!q.empty()){
//         int u=q.front();
//         q.pop();
//         cout<<G.vexs[u]<<' ';
//         for(int i=0;i<G.vexnum;i++){
//             if(visited[i]){
//                 continue;
//             }
//             if(G.arcs[u][i]){
//                 q.push(i);
//                 visited[i]=1;
//             }
//         }
//     }
// }

// /* 请在这里填写答案 */


// #include <stdio.h>
// #include <stdlib.h>
// #define MAX_VERTEX_NUM 20
// #define TRUE 1
// #define FALSE 0
// typedef struct ArcNode
// {
//     int adjvex;              /* 该弧所指向的顶点的位置 */
//     struct ArcNode *nextarc; /* 指向下一条弧的指针 */
// } ArcNode;                   /* 邻接表结点 */

// typedef struct
// {
//     char data;         /* 顶点信息 */
//     ArcNode *firstarc; /* 指向第一条依附该顶点的弧 */
// } VNode;               /* 顶点数组元素类型 */

// typedef struct
// {
//     VNode vertices[MAX_VERTEX_NUM]; /* 顶点数组 */
//     int vexnum, arcnum;             /* 图的当前顶点数和弧数 */
// } ALGraph;

// /* 求顶点在图中的位置 */
// int LocateVex(ALGraph G, char u)
// {
//     int i;
//     for (i = 0; i < G.vexnum; ++i)
//     {
//         if (G.vertices[i].data == u)
//             return i;
//     }
//     return -1;
// }

// /* 求顶点的信息 */
// char GetVex(ALGraph G, int v)
// {
//     if (v >= G.vexnum || v < 0)
//         return '\0';
//     return G.vertices[v].data;
// }

// /* 求顶点的第一个邻接点的序号 */
// int FirstAdjVex(ALGraph G, char v)
// {
//     ArcNode *p;
//     int i;
//     i = LocateVex(G, v);
//     if (i == -1)
//         return -1;
//     p = G.vertices[i].firstarc;
//     if (p)
//         return p->adjvex;
//     else
//         return -1;
// }

// /* 求顶点v相对于顶点w的下一个邻接顶点的序号 */
// int NextAdjVex(ALGraph G, char v, char w)
// {
//     ArcNode *p;
//     int v1, w1;
//     v1 = LocateVex(G, v);
//     w1 = LocateVex(G, w);
//     if (v1 == -1 || w1 == -1)
//         return -1;
//     p = G.vertices[v1].firstarc;
//     while (p && p->adjvex != w1) /* p指针不为空且所指结点不是w */
//         p = p->nextarc;
//     if (!p || !p->nextarc) /* 没找到w或者w是最后一个邻接点 */
//         return -1;
//     else
//         return p->nextarc->adjvex;
// }

// /* 插入新的顶点 */
// void InsertVex(ALGraph *G, char v)
// {
//     if (G->vexnum >= MAX_VERTEX_NUM)
//         return; // 防止超出数组界限
//     G->vertices[G->vexnum].data = v;
//     G->vertices[G->vexnum].firstarc = NULL;
//     G->vexnum++;
// }

// /* 插入新的边 */
// void InsertArc(ALGraph *G, char va, char vb)
// {
//     int i, j;
//     ArcNode *p;

//     i = LocateVex(*G, va); /* 弧尾 */
//     j = LocateVex(*G, vb); /* 弧头 */
//     if (i == -1 || j == -1)
//         return; // 顶点不存在

//     p = (ArcNode *)malloc(sizeof(ArcNode));
//     p->adjvex = j;
//     p->nextarc = G->vertices[i].firstarc; /* 头插法 */
//     G->vertices[i].firstarc = p;          /* 插表头 */

//     // 由于是无向图，还需要插入vb到va的边
//     p = (ArcNode *)malloc(sizeof(ArcNode));
//     p->adjvex = i;
//     p->nextarc = G->vertices[j].firstarc; /* 头插法 */
//     G->vertices[j].firstarc = p;          /* 插表头 */

//     G->arcnum++;
// }

// /* 删除顶点 */
// void DeleteVex(ALGraph *G, char v)
// {
//     int i, j;
//     ArcNode *p, *q, *r;

//     // 找到顶点v的位置
//     i = LocateVex(*G, v);
//     if (i == -1)
//         return; // 顶点不存在

//     // 删除顶点v的所有出边
//     while (G->vertices[i].firstarc != NULL)
//     {
//         p = G->vertices[i].firstarc;
//         G->vertices[i].firstarc = p->nextarc;
//         G->arcnum--;

//         // 删除其他顶点到v的边
//         j = p->adjvex;
//         q = G->vertices[j].firstarc;
//         if (q->adjvex == i)
//         { // 第一个邻接点就是要删除的点
//             G->vertices[j].firstarc = q->nextarc;
//         }
//         else
//         {
//             while (q->nextarc && q->nextarc->adjvex != i)
//             {
//                 q = q->nextarc;
//             }
//             if (q->nextarc)
//             {
//                 r = q->nextarc;
//                 q->nextarc = r->nextarc;
//             }
//         }
//         free(p);
//     }

//     // 删除顶点v，并移动其他顶点
//     for (j = i + 1; j < G->vexnum; ++j)
//     {
//         G->vertices[j - 1] = G->vertices[j];
//     }
//     G->vexnum--;

//     // 更新顶点数组中各个链表的adjvex值
//     for (j = 0; j < G->vexnum; ++j)
//     {
//         p = G->vertices[j].firstarc;
//         while (p)
//         {
//             if (p->adjvex > i)
//             {
//                 p->adjvex--;
//             }
//             p = p->nextarc;
//         }
//     }
// }
// /* 删除边 */
// void DeleteArc(ALGraph *G, char va, char vb)
// {
//     int i, j;
//     ArcNode *p, *q;

//     // 找到顶点va和vb的位置
//     i = LocateVex(*G, va);
//     j = LocateVex(*G, vb);
//     if (i == -1 || j == -1)
//         return; // 顶点不存在

//     // 删除va到vb的边
//     p = G->vertices[i].firstarc;
//     if (p && p->adjvex == j)
//     { // 第一个邻接点就是要删除的点
//         G->vertices[i].firstarc = p->nextarc;
//         free(p);
//     }
//     else
//     {
//         while (p && p->nextarc && p->nextarc->adjvex != j)
//         {
//             p = p->nextarc;
//         }
//         if (p && p->nextarc)
//         {
//             q = p->nextarc;
//             p->nextarc = q->nextarc;
//             free(q);
//         }
//     }

//     // 删除vb到va的边（因为是无向图）
//     p = G->vertices[j].firstarc;
//     if (p && p->adjvex == i)
//     {
//         G->vertices[j].firstarc = p->nextarc;
//         free(p);
//     }
//     else
//     {
//         while (p && p->nextarc && p->nextarc->adjvex != i)
//         {
//             p = p->nextarc;
//         }
//         if (p && p->nextarc)
//         {
//             q = p->nextarc;
//             p->nextarc = q->nextarc;
//             free(q);
//         }
//     }

//     G->arcnum--;
// }

// /* 创建图 */
// void CreateGraph(ALGraph *G)
// {
//     int i, k;
//     int w;
//     char va, vb;
//     scanf("%d %d", &G->vexnum, &G->arcnum);
//     while (getchar() != '\n');
//     for (i = 0; i < G->vexnum; ++i)
//     {
//         scanf(" %c", &G->vertices[i].data); // 前面的空格用于跳过任何空白符
//         G->vertices[i].firstarc = NULL;
//     }
//     for (k = 0; k < G->arcnum; ++k)
//     {
//         scanf(" %c %c", &va, &vb); // 读取弧尾、弧头
//         getchar();                 // 清缓存区
//         // 插入边
//         int vaIndex = LocateVex(*G, va); // 使用LocateVex函数查找顶点va的索引
//         int vbIndex = LocateVex(*G, vb); // 使用LocateVex函数查找顶点vb的索引

//         // 插入va到vb的边
//         if (vaIndex != -1 && vbIndex != -1)
//         {
//             ArcNode *newArcNode = (ArcNode *)malloc(sizeof(ArcNode));
//             newArcNode->adjvex = vbIndex;
//             newArcNode->nextarc = G->vertices[vaIndex].firstarc;
//             G->vertices[vaIndex].firstarc = newArcNode;

//             // 由于是无向图，还需要插入vb到va的边
//             newArcNode = (ArcNode *)malloc(sizeof(ArcNode));
//             newArcNode->adjvex = vaIndex;
//             newArcNode->nextarc = G->vertices[vbIndex].firstarc;
//             G->vertices[vbIndex].firstarc = newArcNode;
//         }
//     }
// }

/* 打印图的邻接表表示 */
// void PrintGraph(ALGraph G)
// {
//     int i;
//     ArcNode *p;

//     printf("顶点数：%d\n", G.vexnum);
//     printf("边数：%d\n", G.arcnum);

//     printf("邻接表：\n");
//     for (i = 0; i < G.vexnum; ++i)
//     {
//         printf("%c -> ", G.vertices[i].data);
//         p = G.vertices[i].firstarc;
//         while (p)
//         {
//             printf("%c ", G.vertices[p->adjvex].data);
//             p = p->nextarc;
//         }
//         printf("\n");
//     }
// }
// void DFS(ALGraph G, int v)
// {
// 	ArcNode *p;
//     int visited[MAX_VERTEX_NUM] = {FALSE}; // 定义并初始化visited数组
//     int stack[MAX_VERTEX_NUM];             // 定义栈
//     int top = -1;                          // 栈顶指针初始化
//     // 起始顶点入栈
//     stack[++top] = v;
//     visited[v] = TRUE;
//     printf("%c ", G.vertices[v].data); // 打印顶点信息

//     while (top != -1) // 栈不为空时循环
//     {
//         int cur = stack[top]; 
//         top--;
//                          // 查看栈顶元素但不出栈
//         /*语句1，请补充*/;

//         // 寻找未访问的邻接点
//         while (p != NULL && visited[p->adjvex])
//         {
//             top++;
//             stack[top]=p->adjvex;
//             /*语句2，请补充*/;
//         }

//         if (p != NULL) // 找到了未访问的邻接点
//         {
//             visited[p->adjvex] = TRUE;
//             printf("%c ", G.vertices[p->adjvex].data); // 打印顶点信息
            
//             /*语句3，请补充*/;                  
//         }
//         else
//         {
//             top--; // 没有未访问的邻接点，当前顶点出栈
//         }
//     }
// }

// int main()
// {
//     ALGraph G;
//     CreateGraph(&G);
//     //PrintGraph(G);
//     DFS(G, 0); // 从顶点0开始DFS
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// #define ERROR -1

// typedef int ElementType;
// typedef struct Node *PtrToNode;
// struct Node {
//     ElementType Data;
//     PtrToNode   Next;
// };
// typedef PtrToNode List;

// List Read(); /* 细节在此不表 */
// void Print( List L ); /* 细节在此不表 */

// ElementType Find( List L, int m );

// int main()
// {
//     List L;
//     int m;
//     L = Read();
//     scanf("%d", &m);
//     printf("%d\n", Find(L,m));
//     Print(L);
//     return 0;
// }

// ElementType Find( List L, int m ){
//     PtrToNode p1=L;
//     PtrToNode p2=L;
//     for(int i=1;i<=m;i++){
//         if(p2->Next==NULL){
//             return ERROR;
//         }
//         p2=p2->Next;

//     }
//     while(p2!=NULL){
//         p1=p1->Next;
//         p2=p2->Next;
//     }
//     return p1->Data;
// }
// /* 你的代码将被嵌在这里 */




// #include<bits/stdc++.h>
// using namespace std;
// int a[1000];
// int main(){
//     int n,x;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//     }
//     cin>>x;
//     int l=1;
//     int r=n;
//     while(l<=r){
//         int mid=(l+r)/2;
//         if(a[mid]>=x){
//             r=mid-1;
//         }
//         else{
//             l=mid+1;
//         }
//     }
//     if(r+1>=1&&r+1<=n){
//         if(a[r+1]==x){
//             printf("It's position is %d!",r+1);  
//         }
//         else{
//             printf("No data!");  
//         }
//     }
//     else{
//         printf("No data!");  
//     }
//     return 0;
// }


// #include<iostream>
// using namespace std;
// #define OK 1
// #define ERROR 0
// typedef int ElemType;

// typedef struct LNode {
//     ElemType data;
//     struct LNode *next; 
// } LNode, *LinkList; 

// void CreateList(LinkList &L, int n) ;//该函数未显示细节 

// int ListDelete_L(LinkList &L, int i) {
//     LinkList p, q;
//     int j;
//     p = L;
//     j = 0;
//     while (p->next&&j<i-1) 
//     {
//         p = p->next;
//         ++j;
//     }
//     if (!(p->next) || (j > i - 1))
//         return ERROR; 
//     q = p->next;  
//     p->next=q->next;
//     delete q; 
//     return OK;
// } 


// void print(LinkList &L)
// {
//     LinkList p;
//     int flag=1;
//     p = L->next;
//     while (p) {
//         if(flag)
//             cout << p->data;
//         else
//             cout << " "<< p->data;
//         flag=0;
//         p = p->next;
//     }
// }

// int main() {
//     LinkList L;
//     ElemType e;
//     int length;
//     int i;
//     cin >> length;
//     CreateList(L, length);    
//     cin >> i;
//     ListDelete_L(L,i);
//     print(L);
//     return 0;
// }


// #include<iostream>
// using namespace std;

// #define MAXSIZE  100
// typedef int Status;
// typedef char SElemType;

// typedef struct {
//     SElemType *base;
//     SElemType *top;
//     int stacksize;
// } SqStack;

// Status InitStack(SqStack &S) {
//     S.base = new SElemType[MAXSIZE];
//     if (!S.base)
//         exit(-2);
//     S.top = S.base;
//     S.stacksize = MAXSIZE;
//     return 1;
// }

// Status Push(SqStack &S, SElemType e) {
//     if (S.top - S.base == S.stacksize)
//         return 0; 
//     *S.top++=e; 
//     return 1;
// }

// Status Pop(SqStack &S, SElemType &e) {
//     if (S.base == S.top)
//         return 0;
//     e=*--S.top;
//     return 1;
// }

// int main() {
//     SqStack s;
//     int n, i;
//     char c;
//     InitStack(s);
//     cin >> n;
//     for(i=0;i<n;i++){
//         cin >> c;
//         Push(s,c);        
//     }
//     for(i=0;i<n;i++){
//          Pop(s,c);
//         cout << c << " ";
//     }
//     return 0;
// }


// #include <stdio.h>
// #define MVNum 100                 //最大顶点数 
// typedef struct{ 
//   char vexs[MVNum];           //存放顶点的一维数组 
//   int arcs[MVNum][MVNum];     //邻接矩阵 
//   int vexnum,arcnum;          //图的当前顶点数和边数 
// }MGraph; 
// void CreatMGraph(MGraph *G);/* 创建图 */
// void printGraph(MGraph G);/*输出图 */
// int main()
// {
//     MGraph G;
//     CreatMGraph(&G);
//     printGraph(G);
//     return 0;
// }
// void CreatMGraph(MGraph *G)
// {
//     int i,j,k;
//     char a;
//     scanf("%d%d",&G->vexnum,&G->arcnum);
//     getchar();
//     for(i=0;i<G->vexnum;i++)
//          scanf("%c",G->vexs[i]);
//     for(i=0;i<G->vexnum;i++)
//          for(j=0;j<G->vexnum;j++)
//             G->arcs[i][j]=0;
//     for(k=0;k<G->arcnum;k++) {  
//         scanf("%d%d",&i,&j);     
//         G->arcs[i][j]=1;    
//         G->arcs[j][i]=1; 
//     }
// }
// void printGraph(MGraph G)
// {
//     int i,j;
//     for(i=0;i<G.vexnum;i++)
//     {
//        printf("%c:",G.vexs[i]);
//        for(j=0;j<G.vexnum;j++)
//           if (G.arcs[i][j])  printf(" %c",G.vexs[j]);
//        printf("\n");
//     }
// }




// #include<iostream>
// using namespace std;
// #define MAXSIZE 100

// typedef struct{
//     int key;
// }ElemType;

// typedef struct{
//     ElemType *R;
//     int length;
// }SSTable;

// int Create_SSTable(SSTable &L) 
// {    int n;
//     cin >> n; 
//     for(int i=1;i<=n;i++)
//     {
//         cin >> L.R[i].key;
//         L.length++;
//     }
//     return 1;
// }

// int Search_Bin(SSTable ST,int key) {
//    int low=1,high=ST.length;
//    int  mid;
//    while(low<=high) {
//       mid=(low+high) / 2;
//       if (ST.R[mid].key==key)  return mid; 
//       else if (ST.R[mid].key>key)  high = mid -1;
//       else  low =mid +1; 
//    }
//    return 0;
// }

// int main()
// {
//     SSTable ST;
//     int key;
//     int result;    
//     ST.R=new ElemType[MAXSIZE];
//     ST.length=0;    
//     Create_SSTable(ST);
//     cin >> key;
//     result=Search_Bin(ST, key);
//     if(result)
//         cout << "search success，The key is located in "<< result;
//     else
//         cout << "search failed";
//     return 0;
// }


// #include<iostream>
// #include<fstream>
// using namespace std;
// #define MAXSIZE 100
// #define ERROR 0

// typedef struct
// {
//     int *elem;
//     int length;
// } SqList;


// void InitList_Sq(SqList &L, int n)
// {
//     L.elem = new int[MAXSIZE];
//     if (!L.elem)
//         exit(0);
//     L.length = 0;
// }

// void input(SqList &L, int n) 
// {    int i=0;
//     while (i<n) {
//         cin >> L.elem[i];
//         i++;
//     }
//     L.length = i;
// }

// void output(SqList L) 
// {
//     int i;
//     for (i = 0; i < L.length; i++) {
//         if (i)
//             cout << ",";
//         cout << L.elem[i];
//     }
// }

// void MergeList_Sq(SqList LA, SqList LB, SqList &LC)
// {
//     int *pa, *pb, *pc, *pa_last, *pb_last;
//     pa = LA.elem;
//     pb = LB.elem; 
//     LC.length = LA.length + LB.length; 
//     LC.elem = new int[LC.length]; 
//     pc = LC.elem; 
//     pa_last = LA.elem + LA.length - 1; 
//     pb_last = LB.elem + LB.length - 1; 
//     while ((pa<=pa_last)&&(pb<=pb_last)) 
//     {
//         if (*pa <= *pb) 
//             *pc++=*pa++;
//         else
//             *pc++=*pb++;
//     }
//     while (pa<=pa_last) 
//         *pc++ = *pa++;
//     while (pb<=pb_last)
//         *pc++ = *pb++;
// } 

// int main() {
//     SqList La, Lb, Lc;
//     int num_a = 0, num_b = 0;
//     cin >> num_a >> num_b;    
//     InitList_Sq(La, num_a); 
//     input(La, num_a); 

//     InitList_Sq(Lb, num_b);     
//     input(Lb, num_b); 

//     MergeList_Sq(La, Lb, Lc); 

//     output(Lc);
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <queue>
// #include <stack>
// using namespace std;

// struct TreeNode
// {
//     char data;
//     TreeNode* left;
//     TreeNode* right;
// };

// void levelOrder(struct TreeNode* root)
// {
//     queue<struct TreeNode*> que;
//     if (root == NULL)return;
//     que.push(root);
//     while (!que.empty()) {
//         struct TreeNode* tmp = que.front();
//         que.pop();
//         printf(" %c", tmp->data);
//         if (tmp->left)
//             levelOrder(tmp->left);
//         if (tmp->right)
//             levelOrder(tmp->right);
//     }
// }



// #include <iostream>
// #include <stack>
// using namespace std;

// #define maxnum 20

// struct  node
// {  //边表节点的定义
//     int  vex;
//     node* next; //指向下一个边表节点
// };
// struct vernode
// {
//     char vex ;   //存放顶点信息
//     node* first;    //指向第一个边表节点
//     int indegree;
// };
// struct graph
// {
//     vernode v[maxnum];
//     int vnums,enums;
// };

// //创建有向图的邻接表
// void creategraph(graph &g, int n , int  e)
// {
//     int  i , j , k;
//     g.vnums = n;
//     g.enums = e;
//     for(i = 1 ; i <= n ; i++)
//     {
//         cin >>g.v[i].vex;
//         g.v[i].first = NULL;  //初始化为空
//     }
//     for( k = 1 ; k <= e; k++)
//     {
//         node *p ;
//         cin >> i >> j;
//         p = new node();
//         p->vex = j;
//         p->next = g.v[i].first;
//         g.v[i].first = p;   //头插法
//     }
// }

// void  toposort(graph &g)
// {
//     std::stack<int> s;
//     node *p;
//     int counts = 0;
//     int i , j ;
//     for( i = 1 ; i <= g.vnums ; i++)
//         g.v[i].indegree = 0 ;   //初始化入度为0
//     for(i  = 1 ; i <= g.vnums ; i++)
//     {     //计算各个顶点的入度
//             p = g.v[i].first;
//             while(p)
//             {
//                 g.v[p->vex].indegree++;   //计算入度
//                 p=p->next;
//             }
//     }
//     for(i = 1 ; i <= g.vnums ; i++)
//         if(g.v[i].indegree ==0 )
//             s.push(i);  //将度为0 的顶点入栈，这里进栈的是入度为0的顶点在数组的位置
//     while(!s.empty())
//     {
//         j = s.top();
//         s.pop();  //出栈
//         cout << g.v[j].vex << " ";   //将栈顶的元素出栈且输出
//         counts++;
//         p = g.v[ j ].first;  //让p指向入度为0 的第一个节点
//         while(p)
//         {
//             g.v[p->vex].indegree--;
//             if(g.v[p->vex].indegree == 0 )
//                 s.push(p->vex);
//             p = p->next;
//         }
//     }
//     if( counts < g.vnums)
//         cout << "图中有环" << endl;
// }

// int main()
// {
//     graph g;
//     creategraph(g,6,8);
//     toposort(g);
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
vector<int> e[N];
map<char,int> mp;
map<int,char> pm;
int ux[N];
int vx[N];
bool vis[N];
void bfs(int s){
  queue<int> q;
  q.push(s);
  vis[s]=true;
  while(!q.empty()){
    int u=q.front();
    cout<<pm[u]<<' ';
    q.pop();
    for(auto v:e[u]){
      if(vis[v]){
        continue;
      }
      q.push(v);
      vis[v]=true;
    }
  }   
}
void solve(){
  memset(vis,false,sizeof(vis));
  int n,m;
  cin>>n>>m;
  char c,c1,c2;
  for(int i=1;i<=n;i++){
    cin>>c;
    mp[c]=i;
    pm[i]=c;
  }
  for(int i=1;i<=m;i++){
    cin>>c1>>c2;
    int u=mp[c1];
    int v=mp[c2];
    ux[i]=u;
    vx[i]=v;
  }
  for(int i=m;i>=1;i--){
    int u=ux[i];
    int v=vx[i];
    e[u].push_back(v);
    e[v].push_back(u);
}
  bfs(1);
}
int main(){
  solve();
  return 0;
}