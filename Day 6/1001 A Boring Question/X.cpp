#include <cstdio>

int c(int m,int n) {
	int p=1;
	for (int i=n-m+1;i<=n;i++)
	  p*=i;
	for (int i=1;i<=m;i++)
	  p/=i;
	return p;
}
int main() {
	int n,m;
	int s=0;
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++)
	for (int j=i;j<=n;j++)
	for (int k=j;k<=n;k++)
	for (int l=k;l<=n;l++)
	{
		s+=c(i,j)*c(j,k)*c(k,l);
	}
	printf("%d\n",s);
	return 0;
}
