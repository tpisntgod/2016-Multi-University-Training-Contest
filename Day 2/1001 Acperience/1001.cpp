#include<iostream>
#include<stdio.h>

using namespace std;

long long gcd(long long x,long long y)
{
	if (x%y==0) return y;
	return gcd(y,x%y);
}
int main()
{
	int t,n;
	int w[100007],b[100007];
	long long sw,sb,swb,k,l;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		sw=sb=swb=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&w[i]);
			if (w[i]>=0) b[i]=1; else b[i]=-1;
			sw+=w[i]*w[i];
			sb+=b[i]*b[i];
			swb+=w[i]*b[i];
		}
		k=sb*sw-swb*swb;
		if (swb==0) printf("%lld/1\n",sw);
		else if (k==0) printf("0/1\n");
		else
		{
		if (k>=sb) l=gcd(k,sb); else l=gcd(sb,k);
		printf("%lld/%lld\n",k/l,sb/l);
	    }
	}
}
