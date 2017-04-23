#include<iostream>
#include<cstdio>

using namespace std;

int a[1000007];
int main()
{
	int n,ans;
	long long s;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=1;i<=n;i++)
		    scanf("%d",&a[i]);
		s=0; ans=0;
		for (int i=n;i>=1;i--)
		{
			s+=a[i];
			if (s>=0)
			{
				ans++;
				s=0;
			}
		}
		printf("%d\n",ans);
	}
}
