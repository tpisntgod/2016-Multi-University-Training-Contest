#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[1000007],f[1000007];
long long s[1000007];
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		//memset(s,0,sizeof(s));
		for (int i=1;i<=n;i++)
		{
		    scanf("%d",&a[i]);
		    //s[i]=s[i-1]+a[i];
		}
		for (int i=1;i<=n;i++)
		{
			if (a[i]>=0)
			    if (f[i-1]+1>f[i]) f[i]=f[i-1]+1;
			if (a[i]<0)
			{
				int k=a[i];
				int l,r;
				l=r=1;
				if (a[i-l]>=a[i+r])
				{
					k+=a[i-l];
					l++;
					if (k>=0) break;
				}
				else
				{
					k+=a[i+r];
					r++;
					if (k>=0) break;
				}
				l--; r--;
				if (f[i-l-1]+1>f[i+r]) f[i+r]=f[i-l-1];
			}
		}
		printf("%d\n",f[n]);
		for (int i=1;i<=n;i++) f[i]=0;
	}
	return 0;
}
