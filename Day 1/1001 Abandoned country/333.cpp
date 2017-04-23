#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
struct edge
{
	int x,y,d;
}   a[1000007];
struct EE
{
	int ed,len,next;
}   e[1000007];
int f[1000007],head[1000007],sum[1000007],pd[1000007];
int cmp(edge c,edge d)
{
	return c.d<d.d;
}
int findf(int x)
{
	if (f[x]==x) return x;
	f[x]=findf(f[x]);
	return f[x];
}
int cnt;
void add(int st,int ed,int d)
{
	e[cnt].ed=ed;
	e[cnt].len=d;
	e[cnt].next=head[st];
	head[st]=cnt++;
}
double tot;
int t,n,m;
void dfs(int x,int fa)
{
	sum[x]=1;
	for (int h=head[x];h!=-1;h=e[h].next)
	{
		int k=e[h].ed;
		if (k==fa) continue;
		dfs(k,x);
		tot+=double (e[h].len)*(sum[k])*(n-sum[k]);
		sum[x]+=sum[k];
	}
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++)
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].d);

		if(n==1&&m==0)
		{
            printf("0 0.00\n");
            continue;
        }
        
		for (int i=1;i<=n;i++)	
		{
		    f[i]=i;
		    //sum[i]=1;
		}
		memset(head,-1,sizeof(head));
		memset(pd,0,sizeof(pd));
		
		sort(a+1,a+1+m,cmp);
		long long ans=0; 
		cnt=0;
		for (int i=1;i<=m /*&& t<n-1*/;i++)
		{
			int xx=findf(a[i].x),yy=findf(a[i].y);
			if (xx!=yy)
			{
				f[xx]=yy;
				ans=ans+a[i].d;
				add(a[i].x,a[i].y,a[i].d);
				add(a[i].y,a[i].x,a[i].d);
			}
		}
		tot=0.0;
		dfs(1,1);
		double con=(double) n*(n-1)/2;
		tot/=con;
		printf("%lld %.2lf\n",ans,tot);
	}
}
