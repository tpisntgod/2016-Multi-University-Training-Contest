#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int mod = 1000000007;

int a[1007],b[1007];
long long f[1007][1007];
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)
		    scanf("%d",&a[i]);
		for (int i=1;i<=m;i++)
		    scanf("%d",&b[i]);
		for (int i=1;i<=n;i++)
		    for (int j=1;j<=m;j++)
		        if (a[i]==b[j])
		            f[i][j]=(f[i-1][j]+f[i][j-1]+1) % mod;
		        else f[i][j]=(f[i-1][j]+f[i][j-1]-f[i-1][j-1] + mod) % mod;
	    printf("%lld\n",f[n][m]);
	}
}
