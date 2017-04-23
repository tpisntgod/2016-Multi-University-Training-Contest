#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int t,n,ans=0;
	int a[100007],f[57][57];
	while (scanf("%d",&n) && n!=0)
	{
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)
		{
		    scanf("%d",&a[i]);
		    f[i][i]=a[i];
		    f[i][0]=a[i];
		}
		for (int i=2;i<=n;i++)
		    {
		        f[i][1]=f[i-1][0]*a[1];
		        f[i][0]+=f[i][1];
		        for (int k=2;k<i;k++)
		        {
		        	f[i][k]=f[i-1][k-1]/a[k-1]*a[k];
		            f[i][0]+=f[i][k];
		        }
		    }
		for (int i=1;i<=n;i++)
		    ans+=f[n][0];
		printf("%d\n",f[n][0]);
	}
}
