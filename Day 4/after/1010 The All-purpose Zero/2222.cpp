#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[100007],d[100007];
int main()
{
	int t,n,zs,s=0,ct;
	scanf("%d",&t);
	while (t--)
	{
		s++; ct=0;
		scanf("%d",&n);
		zs=0;
		for (int i=1;i<=n;i++)
		{
			int k;
		    scanf("%d",&k);
		    if (k!=0)
			{
				ct++;
				a[ct]=k-zs;
			}
			else zs++;
		}
		if (zs==n)
		{
			printf("Case #%d: %d\n",s,n);
			continue;
		}
		int len=1,j;
		d[1]=a[1];
		for (int i=2;i<=ct;i++)
		{
			if (a[i]>d[len]) j=++len;
			else j=lower_bound(d+1,d+1+len,a[i])-d;
			d[j]=a[i];
		}
		printf("Case #%d: %d\n",s,len+zs);
	}
}
