#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int gcd(int x,int y)
{
	if (x%y==0) return y;
	return gcd(y,x%y);
}

int main()
{
	int t,n,m;
	int a[107][2],b[107],c[107];
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int k,l,s;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		k=l=s=0;
		for (int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			a[i][1]=x; a[i][2]=y;
			b[x]=y;
			c[x]=1;
		}
		if (m==0)
		{
			b[1]=100; b[2]=100;
		}
		if (a[1][1]>=3)
		{
			b[1]=100; b[2]=100;
		}
		if (a[1][1]==2)
		{
			b[1]=100; b[2]=a[1][2];
		}
		if (a[1][1]==1 && a[2][1]>2)
		{
			b[1]=b[2]=a[1][2];
		}
		for (int i=n-1;i>=3;i--)
		  if (c[i]==0) b[i]=b[i+1];
		for (int i=1;i<=n;i++)
		  s+=b[i];
		k=b[1]+b[2];
		if (s!=0) l=gcd(k,s);
		if (l!=0) printf("%d/%d\n",k/l,s/l);
		else printf("%d/%d\n",k,s);
	}
}
