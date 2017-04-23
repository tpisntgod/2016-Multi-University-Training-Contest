#include <cstdio>
#include <cstring>

using namespace std;

#define N 20
#define LL long long

LL a[N],m[N];
int s[N],n;

LL egcd(LL a,LL b,LL &x,LL &y) {
	if (b==0) {
		x=1; y=0;
		return a;
	}
	LL r=egcd(b,a%b,y,x);
	y-=x*(a/b);
	return r;
}
LL count(LL x,LL r,LL p)  {
	return (x-r)/p;
}
LL mult(LL a,LL k,LL m) {
	LL res=0;
	while(k) {
		if (k & 1LL)
		    res=(res + a) % m;
		k>>=1;
		a= (a << 1) % m;
	}
	return res;
}
LL china(LL l, LL r) {
	LL M=1, ans = 0;
	for (int i = 0; i <= n; i++)
	    if (s[i]) M*=m[i];
	for (int i = 0; i <= n; i++)
	if (s[i]) {
		LL nn = M/m[i];
		LL x,y;
		egcd(nn,m[i],x,y);
		x = (x%m[i] + m[i]) % m[i];
		ans = ((ans+ mult(a[i]*nn%M,x,M))%M + M) % M;
	}
	LL s= count(r+M, ans, M)-count(l-1+M,ans,M);
	return s;
}
int main() {
	int t, o = 0;
	scanf("%d",&t);
	while(t--) {
		LL l,r;
		scanf("%d%lld%lld",&n,&l,&r);
		memset(s,0,sizeof(s));
		m[n]=7; a[n]=0; s[n]=1;
		for (int i = 0; i < n;i++)
		    scanf("%lld%lld", &m[i], &a[i]);
		LL ans=0;
		int all = 1 << n;
		for (int i = 0; i < all;i++) {
			int t=i, k=0;
			for (int j = 0;j < n;j++) {
				s[j] =t & 1;
				t>>=1;
				k += s[j];
			}
			k = k & 1 ? -1 : 1;
			ans += 1LL * k * china(l,r);
		}
		printf("Case #%d: %lld\n", ++o, ans);
	}
	return 0;
}
