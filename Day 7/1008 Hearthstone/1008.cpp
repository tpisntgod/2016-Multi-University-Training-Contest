#include<iostream>
#include<cstdio>

using namespace std;

typedef long long ll;

int p, n, m;
int x[25];
ll c[25][25], a[25], f[25][25];   //c: 组合数 a: 阶乘  f：i奥术j伤害组合数
ll ans;
void init() {
	c[0][0] = 1;
	for (int i=1;i<=20;i++) {
		c[i][0] = 1;
		for (int j=1;j<=i;j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	}
	a[0]=1;
	for (int i=1;i<=20;i++)
		a[i]=a[i-1]*i;
	f[0][0] = 0; f[0][1] = 1;
	for (int i=1;i<=20;i++) {
		f[i][0] = 1;
		for(int j=1;j<i;j++)
			f[i][j] = f[i-1][j] + f[i][j-1];
		f[i][i] = f[i][i+1] = f[i][i-1];
	}
}

void dfs(int now,int s,int k) {
	if (k > n+1)
		return;
	for (int i=now;i<=m;i++) {
		if (s+x[i]>=p) {
			if (k == 1)
				ans+=a[n+m-1];
			else
				ans+=f[k-1][k] * c[n][k-1] * a[k-1] * a[k] * a[n+m-2*k+1];
			if (k == m && n >= m)
				ans+=f[n][m] * a[n] * a[m];
		}
		dfs(i+1,s+x[i],k+1);
	}
}
ll gcd(ll a,ll b) {
	if (a%b==0) return b;
	return gcd(b,a%b);
}
int main() {
	init();
	int t;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&p,&n,&m);
		for (int i=1; i<=m; i++)
			scanf("%d",&x[i]);
		ans = 0;
		dfs(1, 0, 1);
		ll maxd = gcd(ans,a[n+m]);
		printf("%lld/%lld\n",ans/maxd,a[n+m]/maxd);
	}
}
