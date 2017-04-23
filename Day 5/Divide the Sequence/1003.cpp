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
		memset(s,0,sizeof(s));
		for (int i=1;i<=n;i++)
		{
		    scanf("%d",&a[i]);
		    s[i]=s[i-1]+a[i];
		}
		for (int i=1;i<=n;i++)
		{
			if (a[i]>=0)
			    if (f[i-1]+1>f[i]) f[i]=f[i-1]+1;
			if (a[i]<0)
			{
				int k=a[i];
				if (s[i]>=0)
				for (int j=i-1;j>=1;j--)
				{
					k+=a[j];
					if (k>=0)
					{
						if (f[j-1]+1>f[i]) f[i]=f[j-1]+1;
						break;
					}
				}
				k=a[i];
				if (s[n]-s[i-1]>=0)
				for (int j=i+1;j<=n;j++)
				{
					k+=a[j];
					if (k>=0)
					{
						if (f[i-1]+1>f[j]) f[j]=f[i-1]+1;
						break;
					}
				}
			}
		}
		printf("%d\n",f[n]);
		for (int i=1;i<=n;i++) f[i]=0;
	}
	return 0;
}
