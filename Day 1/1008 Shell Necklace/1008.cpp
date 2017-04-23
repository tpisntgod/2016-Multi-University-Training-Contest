#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int t,n,ans=0;
	int a[100007],f[57][57][57];
	while (scanf("%d",&n) && n!=0)
	{
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)
		{
		    scanf("%d",&a[i]);
		    f[i][1][i]=a[i];
		    f[i][1][0]=a[i];
		}
		for (int i=2;i<=n;i++)
		    for (int j=2;j<=i;j++)
		    {
		        for (int k=1;k<=i-j+1;k++)
		        {
		        	if (k>=2) f[i][j][k]+=f[i-1][j][k-1]/a[k-1]*a[k];
		            f[i][j][k]+=f[i-1][j-1][0]*a[1];
		            f[i][j][0]+=f[i][j][k];
		        }
		    }
		for (int i=1;i<=n;i++)
		    ans+=f[n][i][0];
		printf("%d\n",ans);
	}
}
